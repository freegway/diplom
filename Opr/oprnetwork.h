#ifndef OPRNETWORK_H
#define OPRNETWORK_H

#include <QtNetwork/QtNetwork>

#include "oprconnect.h"
#include "oprnetconf.h"
#include "Opr_global.h"

class OPR_EXPORT OprNetwork : public OprConnect
{
    Q_OBJECT
public:
    OprNetwork(QObject *parent = 0, OprNetConf cur = OprNetConf());

    bool sendReport(str::ReportFromOpr);
    bool sendAnswerStatus(str::AnswerStatus);

signals:
    void getTaskFrCmdSignal(str::TaskForOpr);
    void getReqStFrCmdSignal(str::RequestStatus);

private:
    void getRequestStatus(QDataStream& in);
    void getTask(QDataStream& in);

private slots:
    void readyReadFrCmdSlot();

private:
    QUdpSocket OprSocket;
    OprNetConf NetConf;
};


#endif // OPRNETWORK_H
