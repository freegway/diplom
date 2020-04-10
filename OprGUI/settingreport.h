#ifndef SETTINGREPORT_H
#define SETTINGREPORT_H

#include <QDialog>

#include "../Opr/OprData.h"

namespace Ui {
class settingReport;
}

class settingReport : public QDialog
{
    Q_OBJECT

public:
    explicit settingReport(str::ReportFromOpr*, QWidget *parent = 0);
    ~settingReport();

private slots:
    void on_cancel_clicked();

    void on_save_clicked();

private:
    Ui::settingReport *ui;
    str::ReportFromOpr* rpt;
};

#endif // SETTINGREPORT_H
