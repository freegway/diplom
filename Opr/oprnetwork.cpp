#include "oprnetwork.h"

OprNetwork::OprNetwork(QObject *parent, OprNetConf cur) : OprConnect(parent), NetConf(cur)
{
    OprSocket.bind(NetConf.getOprAddress(), NetConf.getOprPort());

    connect(&OprSocket, SIGNAL(readyRead()), this, SLOT(readyReadFrCmdSlot()));


}

bool OprNetwork::sendReport(str::ReportFromOpr RData)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << qint16(1);
    out << RData.dateTimeSend;
    out << RData.dateTimeFinish;
    out << RData.idOperator;
    out << RData.statusPerform;

    if (OprSocket.writeDatagram(data, NetConf.getCmdAddress(), NetConf.getCmdPort()) == -1)
    {
        qDebug() << "Error in send report";
        return false;
    }
    else return true;
}

bool OprNetwork::sendAnswerStatus(str::AnswerStatus AsData)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << qint64(2);
    out << AsData.dateTime;
    out << AsData.nRequest;
    out << AsData.idOperator;
    out << AsData.statusOperator;

    if (OprSocket.writeDatagram(data, NetConf.getCmdAddress(), NetConf.getCmdPort()) == -1)
    {
        qDebug() << "Error in send answer status";
        return false;
    }
    else return true;
}

void OprNetwork::getTask(QDataStream& in)
{
//запись данных из потока в структуру
    str::TaskForOpr Tsk;

    in >> Tsk.dateTimeSend;
    in >> Tsk.idOperator;
    in >> Tsk.typeTask;
    in >> Tsk.dataTimeFlight;
    in >> Tsk.coordL;
    in >> Tsk.coordB;
    in >> Tsk.dataTimeState;
    in >> Tsk.statusPerform;

    emit getTaskFrCmdSignal(Tsk);
}

void OprNetwork::getRequestStatus(QDataStream& in)
{
//запись данных из потока в структуру
    str::RequestStatus reqSt;

    in >> reqSt.dateTime;
    in >> reqSt.nRequest;
    in >> reqSt.idOperator;
    in >> reqSt.statusCmd;

    emit getReqStFrCmdSignal(reqSt);
}

void OprNetwork::readyReadFrCmdSlot()
{
//создание дайтаграммы и определение её размера
    QByteArray datagram;

    while(OprSocket.hasPendingDatagrams())
    {
        datagram.resize(OprSocket.pendingDatagramSize());

        OprSocket.readDatagram(datagram.data(), datagram.size());
    }
//создание потока
    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_1);

//определение струтуры
    qint16 initStr;
    in >> initStr;
    if (initStr == 1)
        getTask(in);
    else if (initStr == 2)
        getRequestStatus(in);
}
