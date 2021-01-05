#ifndef LIST_OF_USERS_H
#define LIST_OF_USERS_H

#include <QWidget>

namespace Ui {
class list_of_users;
}

class list_of_users : public QWidget
{
    Q_OBJECT

public:
    explicit list_of_users(QWidget *parent = nullptr);
    ~list_of_users();

private:
    Ui::list_of_users *ui;
};

#endif // LIST_OF_USERS_H
