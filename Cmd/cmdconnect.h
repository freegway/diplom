#ifndef CMDCONNECT_H
#define CMDCONNECT_H

#include <QObject>
#include "cmddata.h"

class CmdConnect : public QObject
{
    Q_OBJECT
public:
    explicit CmdConnect(QObject *parent = 0);

    virtual bool sendRequestStatus(str::RequestStatus) = 0;
    virtual bool sendTask(str::TaskForOpr) = 0;

    virtual void getAnsStFrOprSignal(str::AnswerStatus) = 0;
    virtual void getReportFrOprSignal(str::ReportFromOpr) = 0;

};

#endif // CMDCONNECT_H
