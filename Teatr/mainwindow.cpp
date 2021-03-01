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


void MainWindow::setLogin(QString s)
{
    ui->login_mainw->setText(s);
}

void MainWindow::options_lvl(int lvl)
{
    level = lvl;
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

void MainWindow::on_pushButton_clicked()
{
    list *l=new list(this);
    l->setTitle("Список спектаклей");
    l->setFileName(QCoreApplication::applicationDirPath() + "/performance.bin");
    l->setListNum(2);
    l->setLevel(level);
    l->openFile();
    l->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    list *l=new list(this);
    l->setTitle("Список пользователей");
    l->setFileName(QCoreApplication::applicationDirPath() + "/users.bin");
    l->setListNum(1);
    l->setLevel(level);
    l->openFile();
    l->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    login *log=new login;
    log->show();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    list *l=new list(this);
    l->setTitle("Список актёров");
    l->setFileName(QCoreApplication::applicationDirPath() + "/actors.bin");
    l->setListNum(3);
    l->setLevel(level);
    l->openFile();
    l->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    list *l=new list(this);
    l->setTitle("Список билетов");
    l->setFileName(QCoreApplication::applicationDirPath() + "/viewers.bin");
    l->setListNum(4);
    l->setLevel(level);
    l->setLogin(ui->login_mainw->text());
    l->openFile();
    l->show();
}
