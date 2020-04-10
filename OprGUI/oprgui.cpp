#include "oprgui.h"
#include "ui_oprgui.h"
#include "oprnetconfig.h"
#include "runningopr.h"

OprGUI::OprGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OprGUI)
{
    ui->setupUi(this);
}

OprGUI::~OprGUI()
{
    delete ui;
}


void OprGUI::on_confOprNet_clicked()
{
    OprNetConfig config(&netConf);
    config.exec();
}

void OprGUI::on_runOprCmp_clicked()
{
    RunningOpr runOpr(netConf);
    runOpr.exec();
}
