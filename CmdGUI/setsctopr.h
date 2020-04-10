#ifndef SETSCTOPR_H
#define SETSCTOPR_H

#include <QDialog>
#include "../Cmd/cmddata.h"

namespace Ui {
class setSctOpr;
}

class setSctOpr : public QDialog
{
    Q_OBJECT

public:
    explicit setSctOpr(str::SocketOfCmp*, QWidget *parent = 0);
    ~setSctOpr();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setSctOpr *ui;

    str::SocketOfCmp *sct;
};

#endif // SETSCTOPR_H
