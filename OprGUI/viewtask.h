#ifndef VIEWTASK_H
#define VIEWTASK_H

#include <QDialog>

#include "../Opr/OprData.h"

namespace Ui {
class viewTask;
}

class viewTask : public QDialog
{
    Q_OBJECT

public:
    explicit viewTask(str::TaskForOpr, QWidget *parent = 0);
    ~viewTask();

private slots:
    void on_close_clicked();

private:
    Ui::viewTask *ui;
};

#endif // VIEWTASK_H
