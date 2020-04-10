#ifndef OPR_H
#define OPR_H

#include "Opr_global.h"
#include <QObject>

#include "oprconnect.h"
#include "oprnetwork.h"
#include "OprData.h"
#include <QTime>

class OPR_EXPORT Opr : public QObject
{
    Q_OBJECT

public:

    Opr(QObject *parent = 0, OprNetConf cur = OprNetConf());
    bool sendReportForCmd(str::ReportFromOpr);

private:
    bool sendAnswerSt(str::RequestStatus&);

signals:
    void changeCmsStSignal(bool);
    void getTaskFrOprCmpSignal(str::TaskForOpr);

private slots:
    void initStCmdSlot(str::RequestStatus);
    void getTaskFrOprCmpSlot(str::TaskForOpr);

private:
    OprConnect *OprCnt;
    OprNetwork *OprNtwrk;

    str::RequestStatus ReqSt;
    str::TaskForOpr Tsk;

};

#endif // OPR_H
