#include "list_of_performances.h"
#include "ui_list_of_performances.h"

list_of_performances::list_of_performances(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::list_of_performances)
{
    ui->setupUi(this);
}

list_of_performances::~list_of_performances()
{
    delete ui;
}
