#include "viewtask.h"
#include "ui_viewtask.h"

viewTask::viewTask(str::TaskForOpr task,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewTask)
{
    ui->setupUi(this);

    QString temp;

    this->ui->dataTimeSend->setText(task.dataTimeFlight);
    temp.setNum(task.idOperator);
    this->ui->idOperator->setText(temp);
    this->ui->typeTask->setText(task.typeTask);
    this->ui->dataTimeFlight->setText(task.dataTimeFlight);
    temp.setNum(task.coordL);
    this->ui->coordL->setText(temp);
    temp.setNum(task.coordB);
    this->ui->coordB->setText(temp);
    this->ui->dataTimeState->setText(task.dataTimeState);
    this->ui->statusPerform->setText(task.statusPerform);

    this->show();
}

viewTask::~viewTask()
{
    delete ui;
}

void viewTask::on_close_clicked()
{
    this->close();
}
