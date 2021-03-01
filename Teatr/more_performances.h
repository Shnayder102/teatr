#ifndef MORE_PERFORMANCES_H
#define MORE_PERFORMANCES_H

#include "performance.h"
#include "l_performance.h"

#include <QWidget>
#include <QDialog>

namespace Ui {
class more_performances;
}

class more_performances : public QDialog
{
    Q_OBJECT

public:
    explicit more_performances(QWidget *parent = nullptr);
    ~more_performances();

public slots:
    void setPerfomance(Performance perf);
    void editn();
    void disableButtons();
    void enableButtons();
    Performance perf();

private slots:
    void accept() Q_DECL_OVERRIDE;

private:
    Ui::more_performances *ui;
    Performance mPerformance;
};

#endif // MORE_PERFORMANCES_H
