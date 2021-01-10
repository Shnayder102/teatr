#include "tickets.h"
#include "ui_tickets.h"
#include <QMessageBox>

tickets::tickets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tickets)
{
    ui->setupUi(this);
}

tickets::~tickets()
{
    delete ui;
}
