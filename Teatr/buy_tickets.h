#ifndef BUY_TICKETS_H
#define BUY_TICKETS_H

#include <QWidget>

namespace Ui {
class buy_tickets;
}

class buy_tickets : public QWidget
{
    Q_OBJECT

public:
    explicit buy_tickets(QWidget *parent = nullptr);
    ~buy_tickets();

private:
    Ui::buy_tickets *ui;
};

#endif // BUY_TICKETS_H
