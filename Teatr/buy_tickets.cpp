#include "buy_tickets.h"
#include "ui_buy_tickets.h"

buy_tickets::buy_tickets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buy_tickets)
{
    ui->setupUi(this);
}

buy_tickets::~buy_tickets()
{
    delete ui;
}
