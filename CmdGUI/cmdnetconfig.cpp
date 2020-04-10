#include "cmdnetconfig.h"
#include "ui_cmdnetconfig.h"
#include "setsctopr.h"

#include <QHostAddress>

CmdNetConfig::CmdNetConfig(CmdNetConf *cur, QWidget *parent) :
    QDialog(parent), ui(new Ui::CmdNetConfig), netCnf(cur)
{
    ui->setupUi(this);
}

CmdNetConfig::~CmdNetConfig()
{
    delete ui;
}

void CmdNetConfig::on_save_clicked()
{
    QString current;
    bool ok;

    current = ui->setAdr->text();
    netCnf->setAdress(QHostAddress(current));

    current = ui->setPrt->text();
    quint16 per = current.toUShort(&ok);
    if (ok == true)
        netCnf->setPort(per);

    current = ui->setCntOpr->text();
    size_t per1 = current.toUShort(&ok);
    if (ok == true)
        netCnf->setCountOperators(per1);

    netCnf->OprSockets.clear();
    netCnf->OprSockets.resize(0);

    for (size_t i = 1; i <= per1; i++)
    {
        str::SocketOfCmp cur1;
        setSctOpr cur2(&cur1);

        cur2.exec();

        netCnf->OprSockets.push_back(cur1);
    }

    this->close();
}
