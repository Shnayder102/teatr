#include "list_of_users.h"
#include "ui_list_of_users.h"

list_of_users::list_of_users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_users)
{
    ui->setupUi(this);
}

list_of_users::~list_of_users()
{
    delete ui;
}
