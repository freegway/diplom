#ifndef OPRGUI_H
#define OPRGUI_H

#include <QMainWindow>
#include "../Opr/oprnetwork.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OprGUI; }
QT_END_NAMESPACE

class OprGUI : public QMainWindow
{
    Q_OBJECT

public:
    OprGUI(QWidget *parent = 0);
    ~OprGUI();

private slots:
    void on_confOprNet_clicked();

    void on_runOprCmp_clicked();

private:
    Ui::OprGUI *ui;
    OprNetConf netConf;
};
#endif // OPRGUI_H
