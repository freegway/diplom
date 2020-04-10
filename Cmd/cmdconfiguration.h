#ifndef CMDCONFIGURATION_H
#define CMDCONFIGURATION_H

#include <QtGlobal>
#include <QDebug>

#include "Cmd_global.h"

class CMD_EXPORT CmdConfiguration
{
public:
    CmdConfiguration(quint16 curCountOpr = 1, quint16 curSecPer = 60);

    void setCountOpr(quint16);
    quint16 getCountOpr();

    void setSecPer(quint16);
    quint16 getSecPer();

    void setStCmd(bool);
    bool getStCmd();

private:
    quint16 countOpr;
    quint16 secPer;
    bool stCmd;
};

#endif // CMDCONFIGURATION_H
