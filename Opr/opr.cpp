#include "opr.h"

Opr::Opr(QObject *parent, OprNetConf cur) : QObject(parent)
{
    OprNtwrk = new OprNetwork(0, cur);
    OprCnt = OprNtwrk;

//при получение сигнала о запросе состояния, вызвать слот, который обработает данную структуру и отправит ответ состояния
    connect(OprCnt, SIGNAL(getReqStFrCmdSignal(str::RequestStatus)), this, SLOT(initStCmdSlot(str::RequestStatus)));

//при получении задания вызвать слот
    connect(OprCnt, SIGNAL(getTaskFrCmdSignal(str::TaskForOpr)), this, SLOT(getTaskFrOprCmpSlot(str::TaskForOpr)));

}

//отправляет ответе состояния и сообщает хосту об изменении состояния командира
void Opr::initStCmdSlot(str::RequestStatus curStr)
{
    if(sendAnswerSt(curStr) == false)
        qDebug() << "Error in sendAnswerSt";
    if(curStr.statusCmd != ReqSt.statusCmd)
    {
        ReqSt = curStr;
        emit changeCmsStSignal(ReqSt.statusCmd);
        return;
    }
    ReqSt = curStr;
}

//отправка задания хосту
void Opr::getTaskFrOprCmpSlot(str::TaskForOpr task)
{
    Tsk = task;
    emit getTaskFrOprCmpSignal(task);
}

//отправка ответа состояния
bool Opr::sendAnswerSt(str::RequestStatus &curStr)
{
    str::AnswerStatus curStr1;
    curStr1.dateTime = QTime::currentTime().toString();
    curStr1.nRequest = curStr.nRequest;
    curStr1.idOperator = curStr.idOperator;
    curStr1.statusOperator = online;

    if (OprCnt->sendAnswerStatus(curStr1) == false)
        return false;
    return true;
}


bool Opr::sendReportForCmd(str::ReportFromOpr curStr)
{
    curStr.idOperator = Tsk.idOperator;
    if (OprCnt->sendReport(curStr) == false)
        return false;
    return true;
}
