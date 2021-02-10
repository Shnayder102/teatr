#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "users.h"
#include <QFile>
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    log(new Ui::login)
{
    log->setupUi(this);
}

login::~login()
{
    delete log;
}


void login::on_pushButton_clicked()
{
    if ((log->loginedit->text()=="admin")&&(log->passedit->text()=="admin"))
    {
        MainWindow *m=new MainWindow;
        m->show();
        this->close();
    }
    else
    {
        try
        {
            // Создаём объект inf, связанный с файлом fileName
            QFile inf("users.bin");
            // Открываем файл только для чтения
            if (!inf.open(QIODevice::ReadOnly))
            {
                throw std::runtime_error((tr("open(): ") + inf.errorString()).toStdString());
            }
            // Привязываем к файлу поток, позволяющий считывать объекты Qt
            QDataStream ist(&inf);
            QString l, p, h;
            int i=0;
            ist >> h;
            while ((i<h.size())&&(h[i]!=" "))
            {
                l+=h[i];
                i++;
            }
            i++;
            while ((i<h.size())&&(h[i]!=" "))
            {
                p+=h[i];
                i++;
            }
            while ((log->loginedit->text()!=l)&&(!ist.atEnd()))
            {
                i=0;
                ist >> h;
                while ((i<h.size())&&(h[i]==" "))
                {
                    l+=h[i];
                    i++;
                }
                i++;
                while ((i<h.size())&&(h[i]==" "))
                {
                    p+=h[i];
                    i++;
                }
            }
            if ((log->passedit->text()==p)&&(log->loginedit->text()==l))
            {
                MainWindow *m=new MainWindow;
                m->show();
                this->close();
            }
            else
            {
                QMessageBox::warning(this, "Логин или пароль не найдены", "Проверьте правильность введенных имени пользователя и пароля.");
            }

        }
        catch (const std::exception &e)
        {
            // Если при открытии файла возникла исключительная ситуация, сообщить пользователю
            QMessageBox::critical(this, "Ошибка октрытия файла", tr("Не удалось открыть файл users.bin"));
            return;
        }
    }
}
