#include "setsctopr.h"
#include "ui_setsctopr.h"

setSctOpr::setSctOpr(str::SocketOfCmp *cur, QWidget *parent) :
    QDialog(parent), ui(new Ui::setSctOpr), sct(cur)
{
    ui->setupUi(this);

}

setSctOpr::~setSctOpr()
{
    delete ui;
}

void setSctOpr::on_pushButton_clicked()
{
    QString current;
    bool ok;

    current = ui->setAdr->text();
    sct->address = QHostAddress(current);

    current = ui->setPrt->text();
    quint16 per = current.toUShort(&ok);
    if (ok == true)
        sct->port = per;

    this->close();
}
