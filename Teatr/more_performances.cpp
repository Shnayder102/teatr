#include "more_performances.h"
#include "ui_more_performances.h"
#include <QMessageBox>

more_performances::more_performances(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::more_performances)
{
    ui->setupUi(this);
}

more_performances::~more_performances()
{
    delete ui;
}
