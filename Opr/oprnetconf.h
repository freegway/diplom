#ifndef OPRNETCONF_H
#define OPRNETCONF_H

#include "OprData.h"
#include <QtNetwork/QtNetwork>
#include <QVector>

#include "Opr_global.h"

class OPR_EXPORT OprNetConf
{
public:
    OprNetConf();

    QHostAddress getOprAddress();
    void setOprAddress(QHostAddress);

    quint16 getOprPort();
    void setOprPort(quint16);

    QHostAddress getCmdAddress();
    void setCmdAddress(QHostAddress);

    quint16 getCmdPort();
    void setCmdPort(quint16);


private:
    str::SocketOfCmp OprSocket;
    str::SocketOfCmp CmdSocket;

};

#endif // OPRNETCONF_H
