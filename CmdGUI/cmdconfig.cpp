#include "cmdconfig.h"
#include "ui_cmdconfig.h"

CmdConfig::CmdConfig(CmdConfiguration* cmdConf1, QWidget *parent) :
    QDialog(parent), ui(new Ui::CmdConfig), cmdConf(cmdConf1)
{
    ui->setupUi(this);
}

CmdConfig::~CmdConfig()
{
    delete ui;
}

void CmdConfig::on_save_clicked()
{
    bool ok;
    QString current;

    current = ui->countOpr->text();
    quint16 cntOpr = (quint16)current.toUShort(&ok);
    if (ok == true)
        cmdConf->setCountOpr(cntOpr);

    current = ui->secPer->text();
    quint16 secPer = (quint16)current.toUShort(&ok);
    if (ok == true)
        cmdConf->setSecPer(secPer);

    current = ui->stCmd->text();
    int stCmd = current.toInt(&ok);
    if (ok == true)
    {
        if (stCmd == 1)
            cmdConf->setStCmd(true);
        else cmdConf->setStCmd(false);
    }
    this->close();
}

void CmdConfig::on_cancel_clicked()
{
    this->close();
}
