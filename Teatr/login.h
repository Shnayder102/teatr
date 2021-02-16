#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <memory> // unique_ptr
#include "list_users.h"


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    bool prov();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *log;
    list_users l;
};

#endif // LOGIN_H
