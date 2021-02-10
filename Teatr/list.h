#ifndef LIST_H
#define LIST_H

#include <QMainWindow>
#include <QFile>

#include "list_users.h"

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

private slots:
    bool on_add_triggered();
    void refreshWindowTitle();
    void setlist(list_users *list);
    bool on_save_triggered();
    void saveListToFile();
    void setList(list_users *l);


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
    QString zag, f;
    std::unique_ptr<list_users> mlist;
};

#endif // LIST_H
