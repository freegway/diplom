#include "settingreport.h"
#include "ui_settingreport.h"

settingReport::settingReport(str::ReportFromOpr* cur, QWidget *parent) :
    QDialog(parent), ui(new Ui::settingReport), rpt(cur)
{
    ui->setupUi(this);
}

settingReport::~settingReport()
{
    delete ui;
}

void settingReport::on_cancel_clicked()
{
    this->close();
}

void settingReport::on_save_clicked()
{
    rpt->dateTimeFinish = this->ui->dataTimeFinish->text();
    rpt->dateTimeSend = this->ui->dataTimeSend->text();
    rpt->statusPerform = this->ui->statusPerform->text();

    this->close();
}
