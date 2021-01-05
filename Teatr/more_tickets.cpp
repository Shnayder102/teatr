#include "more_tickets.h"
#include "ui_more_tickets.h"

more_tickets::more_tickets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::more_tickets)
{
    ui->setupUi(this);
}

more_tickets::~more_tickets()
{
    delete ui;
}
