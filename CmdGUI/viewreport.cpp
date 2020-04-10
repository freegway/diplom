#include "viewreport.h"
#include "ui_viewreport.h"

ViewReport::ViewReport(str::ReportFromOpr report, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewReport)
{
    ui->setupUi(this);

    this->ui->dataTimeSend->setText(report.dateTimeSend);
    this->ui->dataTimeFinish->setText(report.dateTimeFinish);
    QString cur;
    cur.setNum(report.idOperator);
    this->ui->idOperator->setText(cur);
    this->ui->statusPerform->setText(report.statusPerform);
    this->show();

}

ViewReport::~ViewReport()
{
    delete ui;
}

void ViewReport::on_close_clicked()
{
    this->close();
}
