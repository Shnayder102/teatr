#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"
#include "login.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    list *l=new list(this);
    l->setTitle("Список пользователей");
    l->setFileName(QCoreApplication::applicationDirPath() + "/users.bin");
    l->openFile();
    l->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    login *log=new login;
    log->show();
    this->close();
}

void MainWindow::setLogin(QString s)
{
    ui->login_mainw->setText(s);
}

void MainWindow::options_lvl(int lvl)
{
    switch (lvl)
    {
        case 1:
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_6->setDisabled(true);
            ui->urd_mainw->setText("Администратор");
            break;
        case 2:
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_4->setDisabled(true);
            ui->pushButton_6->setDisabled(true);
            ui->urd_mainw->setText("Кассир");
            break;
        case 3:
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_4->setDisabled(true);
            ui->pushButton_6->setEnabled(true);
            ui->urd_mainw->setText("Зритель");
            break;
    }
}
