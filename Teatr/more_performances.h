#ifndef MORE_PERFORMANCES_H
#define MORE_PERFORMANCES_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class more_performances;
}

class more_performances : public QWidget
{
    Q_OBJECT

public:
    explicit more_performances(QWidget *parent = nullptr);
    ~more_performances();

private:
    Ui::more_performances *ui;
};

#endif // MORE_PERFORMANCES_H
