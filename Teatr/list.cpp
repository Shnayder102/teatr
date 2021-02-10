#include "list.h"
#include "ui_list.h"
#include "registration.h"
#include "list_users.h"

#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QSaveFile>

list::list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::list)
{
    // Присоединяем сигналы, соответствующие изменению статуса записной книжки,
    // к слоту, обеспечивающему обновление заголовка окна
    connect(this, &list::listReady, this, &list::refreshWindowTitle);
    connect(this, &list::listClosed, this, &list::refreshWindowTitle);
    // Присоединяем сигнал создания записной книжки к лямбда-выражению,
    // устанавливающему в главном окне признак изменения (имеет ли текущий
    // документ несохранённые изменения). В заголовке окна при наличии
    // несохранённых изменений будет отображаться звёздочка или другое
    // обозначение, в зависимости от системы. "[this]" в лямбда-выражении
    // означает, что оно обращается к методам данного класса (в данном случае к
    // методу MainWindow::setWindowModified()).
    //
    // Лямбда-выражение — это выражение, результатом которого является
    // функциональный объект (объект, действующий как функция). В фигурных
    // скобках записывается тело этой функции. Таким образом, в данном случае
    // сигнал MainWindow::notebookCreated будет вызывать код, записанный в
    // фигурных скобках, то есть метод MainWindow::setWindowModified() с параметром true.
    connect(this, &list::listCreated, [this] { setWindowModified(true); });
    // Отображаем GUI, сгенерированный из файла mainwindow.ui, в данном окне
    ui->setupUi(this);
    // Настраиваем таблицу заметок, чтобы её последняя колонка занимала всё доступное место
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

}

list::~list()
{
    delete ui;
}

bool list::on_add_triggered()
{
    registration r(this);
    Users user;
    r.setUser(&user);
    if (r.exec() != registration::Accepted)
    {
        return false;
    }
    // Вставляем заметку в записную книжку
    mlist->insert(user);
    return true;
}

void list::refreshWindowTitle()
{
    setWindowTitle(tr("%1 - %2[*]").arg("ИС Театр").arg(zag));
}

void list::setTitle(QString zagolovok)
{
    zag = zagolovok;
    refreshWindowTitle();
}
void list::setFileName(QString fileName)
{
    f=fileName;
}
void list::setlist(list_users *list)
{
    /*
     * Заменяем имеющийся указатель на объект записной книжки новым.
     * Если в mNotebook хранился какой-то ненулевой указатель на объект,
     * то метод reset() удалит его автоматически
     */
    mlist.reset(list);
    // Связываем новый объект записной книжки с таблицей заметок в главном окне
    ui->tableView->setModel(mlist.get());
}

bool list::on_save_triggered()
{
    saveListToFile();
    // Сигнализируем о готовности
    emit listReady();
    // Сигнализируем о сохранении записной книжки
    emit listSaved();
    return true;
}

void list::saveListToFile()
{
    // Блок обработки исключительных ситуаций
    try
    {
        /*
         * Создаём объект outf, связанный с файлом fileName.
         * QSaveFile обеспечивает безопасное сохранение (через промежуточный
         * временный файл), чтобы избежать потери данных в случае нештатного
         * завершения операции сохранения. Само сохранение происходит при вызове
         * метода commit().
         */
        QSaveFile outf(f);
        // Открываем файл только для записи
        outf.open(QIODevice::WriteOnly);
        // Привязываем к файлу поток, позволяющий выводить объекты Qt
        QDataStream ost(&outf);
        // Выводим записную книжку в файл
        ost << *mlist;
        // Запускаем сохранение и смотрим результат.
        // В случае неудачи запускаем исключительную ситуацию (блок прерывается,
        // управление передаётся в блок catch)
        if (!outf.commit())
        {
            throw std::runtime_error(tr("Unable to commit the save").toStdString());
        }
    }
    catch (const std::exception &e)
    {
        // Если при сохранении файла возникла исключительная ситуация, сообщить пользователю
        QMessageBox::critical(this, "ИС Театр", tr("Не удалось записать данные в %1: %2").arg(f).arg(e.what()));
    }
}

bool list::openFile()
{
    try
    {
        // Создаём объект inf, связанный с файлом fileName
        QFile inf(f);
        // Открываем файл только для чтения
        if (!inf.open(QIODevice::ReadOnly))
        {
            throw std::runtime_error((tr("open(): ") + inf.errorString()).toStdString());
        }
        // Привязываем к файлу поток, позволяющий считывать объекты Qt
        QDataStream ist(&inf);
        // Создаём новый объект записной книжки
        std::unique_ptr<list_users> nb(new list_users);
        // Загружаем записную книжку из файла
        ist >> *nb;
        // Устанавливаем новую записную книжку в качестве текущей.
        // Метод release() забирает указатель у объекта nb
        setList(nb.release());
    }
    catch (const std::exception &e)
    {
        // Если при открытии файла возникла исключительная ситуация, сообщить пользователю
        QMessageBox::critical(this, "ИС Театр", tr("Не удалось прочитать данные данные из %1: %2").arg(f).arg(e.what()));
        return false;
    }
    // Сигнализируем о готовности
    emit listReady();
    //Включаем все связанные с обработкой записной книжки виджеты
    // Сигнализируем об открытии записной книжки
    emit listOpened(f);
    return true;
}

void list::setList(list_users *l)
{
    /*
     * Заменяем имеющийся указатель на объект записной книжки новым.
     * Если в mNotebook хранился какой-то ненулевой указатель на объект,
     * то метод reset() удалит его автоматически
     */
    mlist.reset(l);
    // Связываем новый объект записной книжки с таблицей заметок в главном окне
    ui->tableView->setModel(mlist.get());
}
