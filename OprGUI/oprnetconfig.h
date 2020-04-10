#ifndef OPRNETCONFIG_H
#define OPRNETCONFIG_H

#include <QDialog>

#include "../Opr/oprnetconf.h"

namespace Ui {
class OprNetConfig;
}

class OprNetConfig : public QDialog
{
    Q_OBJECT

public:
    explicit OprNetConfig(OprNetConf *, QWidget *parent = 0);
    ~OprNetConfig();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::OprNetConfig *ui;
    OprNetConf *NetCnf;

};

#endif // OPRNETCONFIG_H
