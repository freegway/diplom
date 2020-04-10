#ifndef VIEWREPORT_H
#define VIEWREPORT_H

#include <QDialog>

#include "../Cmd/cmddata.h"

namespace Ui {
class ViewReport;
}

class ViewReport : public QDialog
{
    Q_OBJECT

public:
    explicit ViewReport(str::ReportFromOpr, QWidget *parent = 0);
    ~ViewReport();

private slots:
    void on_close_clicked();

private:
    Ui::ViewReport *ui;
};

#endif // VIEWREPORT_H
