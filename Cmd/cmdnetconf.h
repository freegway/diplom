#ifndef CMDNETCONF_H
#define CMDNETCONF_H

#include "cmddata.h"
#include <QtNetwork/QtNetwork>
#include <QVector>

#include "Cmd_global.h"

class CMD_EXPORT CmdNetConf
{
public:
    CmdNetConf();
    ~CmdNetConf();
    QHostAddress getAddress();
    void setAdress(QHostAddress);
    quint16 getPort();
    void setPort(quint16);
    void setCountOperators(size_t);
    size_t getCountOperators();

    void addSocket(str::SocketOfCmp);

private:
    str::SocketOfCmp CmdSocket;
    size_t countOperators;

public:
    QVector <str::SocketOfCmp> OprSockets;


};

#endif // CMDNETCONF_H
