#ifndef LIST_OF_PERFORMANCES_H
#define LIST_OF_PERFORMANCES_H

#include <QMainWindow>

namespace Ui {
class list_of_performances;
}

class list_of_performances : public QMainWindow
{
    Q_OBJECT

public:
    explicit list_of_performances(QWidget *parent = nullptr);
    ~list_of_performances();

private:
    Ui::list_of_performances *ui;
};

#endif // LIST_OF_PERFORMANCES_H
