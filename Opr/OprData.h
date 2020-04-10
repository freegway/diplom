#ifndef OPRDATA_H
#define OPRDATA_H

#include <QString>
#include <QtNetwork/QtNetwork>
#include "Opr_global.h"

#define online true
#define offline false

namespace str
{



    struct SocketOfCmp{
        SocketOfCmp(QHostAddress adr = QHostAddress::Null, quint16 prt = 0) :
            address(adr), port(prt)
        {

        }

        QHostAddress address;
        quint16 port;
    };

    struct RequestStatus{
        RequestStatus():statusCmd(false)
        {
        }

        QString dateTime;
        quint64 nRequest;
        quint16 idOperator;
        bool statusCmd;
    };

    struct AnswerStatus{
        AnswerStatus():statusOperator(false)
        {
        }

        QString dateTime;
        quint64 nRequest;
        quint16 idOperator;
        bool statusOperator;
    };

    struct TaskForOpr{
        QString dateTimeSend;
        quint16 idOperator;
        QString typeTask;
        QString dataTimeFlight;
        double coordL;
        double coordB;
        QString dataTimeState;
        QString statusPerform;

    };

    struct ReportFromOpr{
        QString dateTimeSend;
        QString dateTimeFinish;
        quint16 idOperator;
        QString statusPerform;
    };

    struct StatusTask{

    };


    //не известно нужна ли ????
    struct StOpr{
        StOpr(bool st = false) : statusOperator(st)
        {
        }

        quint16 idOperator;
        bool statusOperator;
    };
}

#endif // OPRDATA_H
