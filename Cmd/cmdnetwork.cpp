#include "cmdnetwork.h"

CmdNetwork::CmdNetwork(QObject *parent, CmdNetConf NetConf1) :
    CmdConnect(parent), NetConf(NetConf1)
{
//привязка сокета к определённому порту и адресу
    CmSocket.bind(NetConf.getAddress(), NetConf.getPort());
//если поступят данные с сокета, вызвать слот
    connect(&CmSocket, SIGNAL(readyRead()), this, SLOT(readyReadFrOprSlot()));
}


//отправка структуры, чтобы узнать статус оператора
bool CmdNetwork::sendRequestStatus(str::RequestStatus RSData)
{
    if (RSData.idOperator >= NetConf.OprSockets.size())
    {
        qDebug() << "Error in sendRequestStatus. id_operator no correct";
        return false;
    }

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << qint16(2);
    out << RSData.dateTime;
    out << RSData.nRequest;
    out << RSData.idOperator;
    out << RSData.statusCmd;

    str::SocketOfCmp operatr = NetConf.OprSockets[RSData.idOperator-1];
    if (CmSocket.writeDatagram(data, operatr.address, operatr.port) == -1)
    {
        return false;
    }
    else return true;
    return false;
}

//отправка задания оператору
bool CmdNetwork::sendTask(str::TaskForOpr taskData)
{
    if (taskData.idOperator > NetConf.OprSockets.size())
    {
        qDebug() << "Error in sendTask. id_operator no correct";
        return false;
    }

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);

    out << qint16(1);
    out << taskData.dateTimeSend;
    out << taskData.idOperator;
    out << taskData.typeTask;
    out << taskData.dataTimeFlight;
    out << taskData.coordL;
    out << taskData.coordB;
    out << taskData.dataTimeState;
    out << taskData.statusPerform;

    str::SocketOfCmp operatr = NetConf.OprSockets[taskData.idOperator-1];
    if (CmSocket.writeDatagram(data, operatr.address, operatr.port) == -1)
    {
        qDebug() << "Error in sendTask. Error in send";
        return false;
    }
    else return true;
}


//получение ответа о статусе от оператора
void CmdNetwork::getAnswerStatus(QDataStream& in)
{
//запись данных из потока в структуру
    str::AnswerStatus ansSt;

    in >> ansSt.dateTime;
    in >> ansSt.nRequest;
    in >> ansSt.idOperator;
    in >> ansSt.statusOperator;

//передача структуры в класс cmd

    emit getAnsStFrOprSignal(ansSt);
}


//получение отчёта от оператора
void CmdNetwork::getReport(QDataStream& in)
{
//запись данных из потока в структуру
    str::ReportFromOpr Rt;

    in >> Rt.dateTimeSend;
    in >> Rt.dateTimeFinish;
    in >> Rt.idOperator;
    in >> Rt.statusPerform;

//передача структуры в класс cmd

    emit getReportFrOprSignal(Rt);
}


//слот, который вызывается при получении данных
void CmdNetwork::readyReadFrOprSlot()
{
//создание дайтаграммы и определение её размера
    QByteArray datagram;

    while(CmSocket.hasPendingDatagrams())
    {
        datagram.resize(CmSocket.pendingDatagramSize());

        CmSocket.readDatagram(datagram.data(), datagram.size());
    }
//создание потока
    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_1);

//определение струтуры
    qint16 initStr;
    in >> initStr;
    if (initStr == 1)
        getReport(in);
    else if (initStr == 2)
        getAnswerStatus(in);
}

