#ifndef MORE_TICKET_H
#define MORE_TICKET_H

#include <QWidget>
#include <QDialog>

#include "ticket.h"
#include "list_users.h"
#include "list_tickets.h"

namespace Ui {
class more_ticket;
}

class more_ticket : public QDialog
{
    Q_OBJECT

public:
    explicit more_ticket(QWidget *parent = nullptr);
    ~more_ticket();
    void setTicket(Ticket ticket);
    void more(int idx);
    void disableButtons();
    void enableButtons();
    Ticket ticket();

private slots:
    void accept() Q_DECL_OVERRIDE;

private:
    Ui::more_ticket *ui;
    Ticket mTicket;
    list_users l_u;
    list_tickets l_t;
};

#endif // MORE_TICKET_H
