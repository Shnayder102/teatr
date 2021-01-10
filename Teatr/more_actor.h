#ifndef MORE_ACTOR_H
#define MORE_ACTOR_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class more_actor;
}

class more_actor : public QWidget
{
    Q_OBJECT

public:
    explicit more_actor(QWidget *parent = nullptr);
    ~more_actor();

private:
    Ui::more_actor *ui;
};

#endif // MORE_ACTOR_H
