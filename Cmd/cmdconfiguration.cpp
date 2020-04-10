#include "cmdconfiguration.h"

CmdConfiguration::CmdConfiguration(quint16 curCountOpr, quint16 curSecPer) :
    countOpr(curCountOpr), secPer(curSecPer)
{

}

void CmdConfiguration::setCountOpr(quint16 current)
{
    countOpr = current;
}

quint16 CmdConfiguration::getCountOpr()
{
    return countOpr;
}

void CmdConfiguration::setSecPer(quint16 current)
{
    secPer = current;
}

quint16 CmdConfiguration::getSecPer()
{
    return secPer;
}

bool CmdConfiguration::getStCmd()
{
    return stCmd;
}

void CmdConfiguration::setStCmd(bool current)
{
    stCmd = current;
}
