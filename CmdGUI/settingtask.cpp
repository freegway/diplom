#include "settingtask.h"
#include "ui_settingtask.h"

#include <QString>

SettingTask::SettingTask(str::TaskForOpr *cur, QWidget *parent) :
    QDialog(parent), ui(new Ui::SettingTask), task(cur)
{
    ui->setupUi(this);
}

SettingTask::~SettingTask()
{
    delete ui;
}

void SettingTask::on_save_clicked()
{
    task->dataTimeState = this->ui->dataTimeState->text();
    task->idOperator = (quint16)this->ui->idOperator->text().toShort();
    task->typeTask = this->ui->typeTask->text();
    task->dataTimeFlight = this->ui->dataTimeFlight->text();
    task->coordB = this->ui->coordB->text().toDouble();
    task->coordL = this->ui->coordL->text().toDouble();
    task->dataTimeState = this->ui->dataTimeState->text();
    task->statusPerform = this->ui->statusPerform->text();

    this->close();
}

void SettingTask::on_cancel_clicked()
{
    this->close();
}
