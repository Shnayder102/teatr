#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QDialog>
#include <memory> // unique_ptr
#include <users.h>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

public slots:
    void setUser(Users *user);

private slots:
    void on_radioButton_3_clicked(bool checked);
    void on_radioButton_2_clicked(bool checked);
    void on_radioButton_clicked(bool checked);
    void on_pushButton_clicked();


private:
    Ui::registration *ui;
    Users *mUser;
    int urd;
};

#endif // REGISTRATION_H
