#ifndef OPRCONNECT_H
#define OPRCONNECT_H

#include <QObject>
#include "OprData.h"
#include "Opr_global.h"

class OPR_EXPORT OprConnect : public QObject
{
    Q_OBJECT
public:
    explicit OprConnect(QObject *parent = 0);

    virtual bool sendAnswerStatus(str::AnswerStatus) = 0;
    virtual bool sendReport(str::ReportFromOpr) = 0;

    virtual void getReqStFrCmdSignal(str::RequestStatus) = 0;
    virtual void getTaskFrCmdSignal(str::TaskForOpr) = 0;

};

#endif // OPRCONNECT_H
