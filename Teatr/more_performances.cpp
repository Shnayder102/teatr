#include "more_performances.h"
#include "ui_more_performances.h"
#include "performance.h"

#include <QMessageBox>
#include <QDate>

more_performances::more_performances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::more_performances)
{
    ui->setupUi(this);
}

more_performances::~more_performances()
{
    delete ui;
}

void more_performances::accept()
{
    if ((ui->Author->text()=="") || (ui->Producer->text()=="") || (ui->Actors->text()=="") || (ui->Name->text()==""))
    {
        QMessageBox::warning(this, "Ошибка добавления спектакля", "Проверьте правильность введенных данных.");
        return;
    }
    mPerformance.setAuthor(ui->Author->text());
    mPerformance.setName(ui->Name->text());
    mPerformance.setProducer(ui->Producer->text());
    QStringList act;
    std::vector<QString> a;
    act = ui->Actors->text().split(", ");
    for (int i=0; i < act.size(); i++)
    {
        a.push_back(act[i]);
    }
    mPerformance.setActors(a);
    QDate date = QDate::currentDate();
    a.clear();
    a.push_back(date.toString("dd.MM.yyyy"));
    for (int i=1; i<5 ; i++)
    {
        a.push_back(date.addDays(i).toString("dd.MM.yyyy"));
    }
    mPerformance.setDateTimes(a);
    QDialog::accept();
}

void more_performances::setPerfomance(Performance perf)
{
    mPerformance = perf;
}

void more_performances::editn()
{
    ui->Name->setText(mPerformance.name());
    ui->Author->setText(mPerformance.author());
    ui->Producer->setText(mPerformance.producer());
    QString buf;
    for (unsigned int i = 0; i < mPerformance.actors().size(); i++)
    {
        buf += mPerformance.actors()[i] + ", ";
    }
    buf.remove(buf.size()-2, buf.size());
    ui->Actors->setText(buf);
}

void more_performances::disableButtons()
{
    ui->buttonBox->setDisabled(true);
}

void more_performances::enableButtons()
{
    ui->buttonBox->setEnabled(true);
}

Performance more_performances::perf()
{
    return mPerformance;
}
