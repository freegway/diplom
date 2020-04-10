#ifndef RUNNINGOPR_H
#define RUNNINGOPR_H

#include <QDialog>

#include "../Opr/opr.h"


namespace Ui {
class RunningOpr;
}

class RunningOpr : public QDialog
{
    Q_OBJECT

public:
    explicit RunningOpr(OprNetConf , QWidget *parent = 0);
    ~RunningOpr();

private slots:
    void on_settingReport_clicked();

    void getTaskFromCmpSlot(str::TaskForOpr);

    void getStatusCmdFromCmpSlot(bool);

private:
    Ui::RunningOpr *ui;
    OprNetConf cnf;
    Opr* oprt;

};

#endif // RUNNINGOPR_H
