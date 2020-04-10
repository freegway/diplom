#ifndef CMDGUI_H
#define CMDGUI_H

#include <QMainWindow>
#include "cmdconfig.h"

#include "../Cmd/cmd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CmdGUI; }
QT_END_NAMESPACE

class CmdGUI : public QMainWindow
{
    Q_OBJECT

public:
    CmdGUI(QWidget *parent = NULL);
    ~CmdGUI();

private slots:

    void on_ConfigCmp_clicked();

    void on_ConfigNet_clicked();

    void on_RunCmp_clicked();

private:
    Ui::CmdGUI *ui;

    CmdConfiguration cnf;

    CmdNetConf cnf1;
};
#endif // CMDGUI_H
