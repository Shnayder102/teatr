#ifndef LIST_H
#define LIST_H

#include <QMainWindow>
#include <QFile>

#include "l_performance.h"
#include "list_users.h"
#include "list_actors.h"
#include "list_tickets.h"

namespace Ui {
class list;
}

class list : public QMainWindow
{
    Q_OBJECT

public:
    explicit list(QWidget *parent = nullptr);
    ~list();
    void setTitle(QString zagolovok);
    bool openFile();
    void setFileName(QString fileName);
    void setLevel(int lvl);
    void setListNum(int num);
    void setLogin(QString log);
    void enableAdminButtons();
    void disableAdminButtons();


private slots:
    bool on_add_triggered();
    bool addUser();
    bool addPerformance();
    bool addActor();
    void setList(list_users *list);
    void setList(l_performance *list);
    void setList(list_actors *list);
    void setList(list_tickets *list);
    bool on_save_triggered();
    void saveListToFile();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void deleteUser(int index);
    void deletePerf(int index);
    void deleteActor(int index);
    void editPerf(const QModelIndex &index);
    bool buyTicket(const QModelIndex &index);
    void morePerf(const QModelIndex &index);
    void editActor(const QModelIndex &index);
    void moreActor(const QModelIndex &index);
    void moreTicket(const QModelIndex &index);
    void openUsersFile(QDataStream &ist);
    void openPerfFile(QDataStream &ist);
    void openActorFile(QDataStream &ist);
    void openTicketFile(QDataStream &ist);
    void on_del_triggered();

signals:
    //! Сигнализирует, что записная книжка готова к работе с пользователем (после создания или открытия).
    void listReady();
    //! Сигнализирует, что записная книжка успешно создана.
    void listCreated();
    /*!
     * \brief Сигнализирует, что записная книжка успешно открыта.
     * \param fileName Имя файла открытой записной книжки.
     */
    void listOpened(QString fileName);
    //! Сигнализирует, что записная книжка успешно сохранена.
    void listSaved();
    //! Сигнализирует, что записная книжка успешно закрыта.
    void listClosed();

private:
    Ui::list *ui;
    QString f_name, login;
    std::unique_ptr<list_users> mList_u;
    std::unique_ptr<l_performance> mList_p;
    std::unique_ptr<list_actors> mList_a;
    std::unique_ptr<list_tickets> mList_t;
    int n_list, level, tickets_idx;
};

#endif // LIST_H
