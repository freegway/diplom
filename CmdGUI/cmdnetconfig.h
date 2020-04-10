#ifndef CMDNETCONFIG_H
#define CMDNETCONFIG_H

#include <QDialog>

#include "../Cmd/cmdnetconf.h"

namespace Ui {
class CmdNetConfig;
}

class CmdNetConfig : public QDialog
{
    Q_OBJECT

public:
    explicit CmdNetConfig(CmdNetConf *, QWidget *parent = 0);
    ~CmdNetConfig();

private slots:
    void on_save_clicked();

private:
    Ui::CmdNetConfig *ui;

    CmdNetConf *netCnf;
};

#endif // CMDNETCONFIG_H
