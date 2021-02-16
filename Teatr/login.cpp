#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "users.h"
//#include "list_users.h"
#include <QFile>
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    log(new Ui::login)
{
    log->setupUi(this);
    QFile file(QCoreApplication::applicationDirPath() + "/users.bin");
    if (!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error((tr("open(): ") + file.errorString()).toStdString());
    }
    // Привязываем к файлу поток, позволяющий считывать объекты Qt
    QDataStream ist(&file);
    l.load(ist);
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
        m->setLogin(log->loginedit->text());
        m->options_lvl(1);
        m->show();
        this->close();
    }
    else
    {
        int i=0;
        i = l.search(log->loginedit->text(), log->passedit->text());
        if (i!=0)
        {
            MainWindow *m=new MainWindow;
            m->setLogin(log->loginedit->text());
            m->options_lvl(i);
            m->show();
            this->close();
        }
        else
        {
            QMessageBox::warning(this, "Логин или пароль не найдены", "Проверьте правильность введенных имени пользователя и пароля.");
        }
    }
}
