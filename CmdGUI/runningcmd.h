#ifndef RUNNINGCMD_H
#define RUNNINGCMD_H

#include <QDialog>
#include <QLabel>
#include <QVector>
#include "../Cmd/cmd.h"


#include "cmdnetconf.h"
#include "cmdconfiguration.h"

namespace Ui {
class RunningCmd;
}

class RunningCmd : public QDialog
{
    Q_OBJECT

public:
    explicit RunningCmd(CmdConfiguration, CmdNetConf, QWidget *parent = 0);
    ~RunningCmd();

private:
    void showAllLb();

private slots:
    void changeStOprSlot(str::AnswerStatus);
    void getReportFromOpr(str::ReportFromOpr);

    void on_settingTask_clicked();

private:
    Ui::RunningCmd *ui;
    CmdConfiguration cmdConf;
    CmdNetConf ntConf;
    QVector <QLabel*> stOprLabels;

    Cmd *cmdExe;
};

#endif // RUNNINGCMD_H
