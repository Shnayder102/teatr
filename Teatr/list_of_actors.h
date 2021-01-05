#ifndef LIST_OF_ACTORS_H
#define LIST_OF_ACTORS_H

#include <QMainWindow>

namespace Ui {
class list_of_actors;
}

class list_of_actors : public QMainWindow
{
    Q_OBJECT

public:
    explicit list_of_actors(QWidget *parent = nullptr);
    ~list_of_actors();

private:
    Ui::list_of_actors *ui;
};

#endif // LIST_OF_ACTORS_H
