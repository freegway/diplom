#include "runningcmd.h"
#include "ui_runningcmd.h"

#include "settingtask.h"
#include "viewreport.h"

#include <iostream>

using namespace std;

RunningCmd::RunningCmd(CmdConfiguration cur1, CmdNetConf cur2,QWidget *parent) :
    QDialog(parent), ui(new Ui::RunningCmd), cmdConf(cur1), ntConf(cur2)
{
    ui->setupUi(this);

    cmdExe = new Cmd(0, cmdConf, ntConf);

    for (size_t i = 1; i <= ntConf.getCountOperators(); i++)
    {
        QLabel *label = new QLabel(this);
        QLabel *label1 = new QLabel(this);

        int x = this->height() - 10;
        int y = this->width() - i*(this->width()/ntConf.getCountOperators());

        label->move(x, y);
        label->setText("offline");
        label->show();

        QString op;
        op.setNum(i);
        label1->move(x-70, y);
        label1->setText(QString("operator") + op);
        label1->show();

        stOprLabels.push_back(label);

    }

    connect(cmdExe, SIGNAL(changeStOprToCHstSignal(str::AnswerStatus)), this, SLOT(changeStOprSlot(str::AnswerStatus)));

    connect(cmdExe, SIGNAL(getReportToCHstSignal(str::ReportFromOpr)), this, SLOT(getReportFromOpr(str::ReportFromOpr)));

}

RunningCmd::~RunningCmd()
{
    stOprLabels.clear();
    stOprLabels.resize(0);

    delete ui;
    delete cmdExe;
}

void RunningCmd::showAllLb()
{
    for (int i = 0; i < stOprLabels.size(); i++)
        stOprLabels[i]->show();
}

void RunningCmd::changeStOprSlot(str::AnswerStatus curAS)
{
    switch(curAS.idOperator)
    {
        case true:
            stOprLabels[curAS.idOperator]->setText(QString("online"));
        break;

        case false:
            stOprLabels[curAS.idOperator]->setText(QString("offline"));
        break;
    }

    stOprLabels[curAS.idOperator]->show();
}

void RunningCmd::on_settingTask_clicked()
{
    str::TaskForOpr task;
    SettingTask setTsk(&task);
    setTsk.exec();

    cmdExe->setTask(task);
}

void RunningCmd::getReportFromOpr(str::ReportFromOpr report)
{
    ViewReport rpt(report);
    rpt.exec();
}



