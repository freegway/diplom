#include "cmdgui.h"
#include "ui_cmdgui.h"
#include "ui_cmdconfig.h"
#include "cmdconfiguration.h"
#include "cmdnetconf.h"
#include "cmdnetconfig.h"
#include "runningcmd.h"

CmdGUI::CmdGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CmdGUI)
{
    ui->setupUi(this);

}

CmdGUI::~CmdGUI()
{
    delete ui;
}

void CmdGUI::on_ConfigCmp_clicked()
{
    CmdConfig curConf(&cnf);
    curConf.exec();
}



void CmdGUI::on_ConfigNet_clicked()
{
    CmdNetConfig curConf1(&cnf1);
    curConf1.exec();
}



void CmdGUI::on_RunCmp_clicked()
{
    RunningCmd runCmd(cnf, cnf1);
    runCmd.exec();
}
