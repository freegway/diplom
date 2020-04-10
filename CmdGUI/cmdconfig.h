#ifndef CMDCONFIG_H
#define CMDCONFIG_H

#include <QDialog>
#include "../Cmd/cmdconfiguration.h"

namespace Ui {
class CmdConfig;
}

class CmdConfig : public QDialog
{
    Q_OBJECT

public:
    explicit CmdConfig(CmdConfiguration*, QWidget *parent = 0);
    ~CmdConfig();

private slots:


    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::CmdConfig *ui;

    CmdConfiguration *cmdConf;


};

#endif // CMDCONFIG_H
