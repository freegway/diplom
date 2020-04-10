#include "oprnetconfig.h"
#include "ui_oprnetconfig.h"

#include <QHostAddress>

OprNetConfig::OprNetConfig(OprNetConf *cur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OprNetConfig), NetCnf(cur)
{
    ui->setupUi(this);
}

OprNetConfig::~OprNetConfig()
{
    delete ui;
}

void OprNetConfig::on_save_clicked()
{
    QHostAddress adr(this->ui->addressOpr->text());
    NetCnf->setOprAddress(adr);
    NetCnf->setOprPort(this->ui->portOpr->text().toShort());

    adr = QHostAddress(this->ui->addressCmd->text());
    NetCnf->setCmdAddress(adr);
    NetCnf->setCmdPort(this->ui->portCmd->text().toShort());

    this->close();
}

void OprNetConfig::on_cancel_clicked()
{
    this->close();
}
