#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <memory> // unique_ptr


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
};

#endif // LOGIN_H
