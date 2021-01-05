#include "more_actor.h"
#include "ui_more_actor.h"

more_actor::more_actor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::more_actor)
{
    ui->setupUi(this);
}

more_actor::~more_actor()
{
    delete ui;
}
