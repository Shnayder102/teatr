#ifndef TICKETS_H
#define TICKETS_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class tickets;
}

class tickets : public QWidget
{
    Q_OBJECT

public:
    explicit tickets(QWidget *parent = nullptr);
    ~tickets();

private:
    Ui::tickets *ui;
};

#endif // TICKETS_H
