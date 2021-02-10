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
    l->setFileName("users.bin");
    l->openFile();
    l->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    login *log=new login;
    log->show();
    this->close();
}
