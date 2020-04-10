#include "runningopr.h"
#include "ui_runningopr.h"

#include <QString>
#include "settingreport.h"
#include "viewtask.h"

RunningOpr::RunningOpr(OprNetConf cur, QWidget *parent) :
    QDialog(parent), ui(new Ui::RunningOpr), cnf(cur)
{
    ui->setupUi(this);

    Opr* temp = new Opr(0, cnf);

    oprt = temp;

    this->ui->stCmd->setText(QString("false"));
    this->show();

    connect(oprt, SIGNAL(changeCmsStSignal(bool)), this, SLOT(getStatusCmdFromCmpSlot(bool)));
    connect(oprt, SIGNAL(getTaskFrOprCmpSignal(str::TaskForOpr)), this, SLOT(getTaskFromCmpSlot(str::TaskForOpr)));

}

RunningOpr::~RunningOpr()
{
    delete ui;
    delete oprt;
}

void RunningOpr::on_settingReport_clicked()
{
    str::ReportFromOpr report;

    settingReport setRpt(&report);

    setRpt.exec();

    oprt->sendReportForCmd(report);
}

void RunningOpr::getStatusCmdFromCmpSlot(bool temp)
{
    if (temp == true)
        this->ui->stCmd->setText(QString("online"));
    else this->ui->stCmd->setText(QString("offline"));

    this->show();

}

void RunningOpr::getTaskFromCmpSlot(str::TaskForOpr temp)
{
    viewTask vwTsk(temp);
    vwTsk.exec();
}
