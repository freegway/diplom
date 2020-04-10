#ifndef SETTINGTASK_H
#define SETTINGTASK_H

#include <QDialog>

#include "../Cmd/cmddata.h"

namespace Ui {
class SettingTask;
}

class SettingTask : public QDialog
{
    Q_OBJECT

public:
    explicit SettingTask(str::TaskForOpr*, QWidget *parent = 0);
    ~SettingTask();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::SettingTask *ui;
    str::TaskForOpr *task;
};

#endif // SETTINGTASK_H
