#ifndef CMDNETWORK_H
#define CMDNETWORK_H

#include <QtNetwork/QtNetwork>
#include <vector>

#include "cmdnetconf.h"

#include "cmdconnect.h"

#include "Cmd_global.h"

class CMD_EXPORT CmdNetwork : public CmdConnect
{
    Q_OBJECT
public:
    CmdNetwork(QObject *parent = 0, CmdNetConf NetConf1 = CmdNetConf());
    bool sendRequestStatus(str::RequestStatus);
    bool sendTask(str::TaskForOpr);

private:
    void getAnswerStatus(QDataStream&);
    void getReport(QDataStream&);

private slots:
    void readyReadFrOprSlot();

signals:
    void getAnsStFrOprSignal(str::AnswerStatus);
    void getReportFrOprSignal(str::ReportFromOpr);

private:
    QUdpSocket CmSocket;
    CmdNetConf NetConf;

};

#endif // CMDNETWORK_H
