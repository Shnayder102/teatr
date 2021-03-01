#ifndef MORE_ACTOR_H
#define MORE_ACTOR_H

#include <QWidget>
#include <QDialog>

#include "actor.h"
#include "list_actors.h"

namespace Ui {
class more_actor;
}

class more_actor : public QDialog
{
    Q_OBJECT

public:
    explicit more_actor(QWidget *parent = nullptr);
    ~more_actor();

public slots:
    void setActor(Actor actor);
    void editn();
    Actor act();
    void disableButtons();
    void enableButtons();

private slots:
    void accept() Q_DECL_OVERRIDE;

private:
    Ui::more_actor *ui;
    Actor mActor;
};

#endif // MORE_ACTOR_H
