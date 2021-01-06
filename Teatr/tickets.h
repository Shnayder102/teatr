#ifndef MORE_TICKETS_H
#define MORE_TICKETS_H

#include <QWidget>

namespace Ui {
class more_tickets;
}

class more_tickets : public QWidget
{
    Q_OBJECT

public:
    explicit more_tickets(QWidget *parent = nullptr);
    ~more_tickets();

private:
    Ui::more_tickets *ui;
};

#endif // MORE_TICKETS_H
