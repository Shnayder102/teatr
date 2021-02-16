#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "list_users.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setLogin(QString s);
    void options_lvl(int lvl);

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();


private:
    Ui::MainWindow *ui;
    list_users *list_us;
};
#endif // MAINWINDOW_H
