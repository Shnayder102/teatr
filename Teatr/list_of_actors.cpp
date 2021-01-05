#include "list_of_actors.h"
#include "ui_list_of_actors.h"

list_of_actors::list_of_actors(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::list_of_actors)
{
    ui->setupUi(this);
}

list_of_actors::~list_of_actors()
{
    delete ui;
}
