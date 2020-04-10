#include "cmdnetconf.h"


CmdNetConf::CmdNetConf()
{
//Параметры по умолчанию
    QHostAddress mAddress("127.0.0.1");
    CmdSocket.address =  mAddress;
    CmdSocket.port = 2323;

    countOperators = 1;

//Для тестирования
    QHostAddress OprAdress("127.0.0.1");
    str::SocketOfCmp CurSct(OprAdress, 2324);
    OprSockets.push_back(CurSct);
}

CmdNetConf::~CmdNetConf()
{
    OprSockets.clear();
    OprSockets.resize(0);
}

QHostAddress CmdNetConf::getAddress()
{
    return CmdSocket.address;
}

void CmdNetConf::setAdress(QHostAddress address)
{
    CmdSocket.address = address;
}

void CmdNetConf::setPort(quint16 port)
{
    CmdSocket.port = port;
}

quint16 CmdNetConf::getPort()
{
    return CmdSocket.port;
}


void CmdNetConf::addSocket(str::SocketOfCmp addSctOpr)
{
    OprSockets.push_back(addSctOpr);
}

void CmdNetConf::setCountOperators(size_t cur)
{
    countOperators = cur;
}

size_t CmdNetConf::getCountOperators()
{
    return countOperators;
}
