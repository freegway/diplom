#include "oprnetconf.h"

OprNetConf::OprNetConf()
{
//параметры по умолчанию
    QHostAddress mAddress("127.0.0.1");
    OprSocket.address = mAddress;
    OprSocket.port = 2325;

    CmdSocket.address = mAddress;
    CmdSocket.port = 2323;
}

QHostAddress OprNetConf::getOprAddress()
{
    return OprSocket.address;
}

void OprNetConf::setOprAddress(QHostAddress address)
{
    OprSocket.address = address;
}

quint16 OprNetConf::getOprPort()
{
    return OprSocket.port;
}

void OprNetConf::setOprPort(quint16 port)
{
    OprSocket.port = port;
}

QHostAddress OprNetConf::getCmdAddress()
{
    return CmdSocket.address;
}

void OprNetConf::setCmdAddress(QHostAddress address)
{
    CmdSocket.address = address;
}

quint16 OprNetConf::getCmdPort()
{
    return CmdSocket.port;
}

void OprNetConf::setCmdPort(quint16 port)
{
    CmdSocket.port = port;
}
