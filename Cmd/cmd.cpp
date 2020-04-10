#include "cmd.h"

Cmd::Cmd(QObject *parent, CmdConfiguration CmdConf1,
         CmdNetConf CmdNtCnf1) : QObject(parent), CmdConf(CmdConf1), CmdNtCnf(CmdNtCnf1),
         nRequestSt(0), nAnswerSt(0)
{
//полиморфизм
    CmdNtwrk = new CmdNetwork(0, CmdNtCnf);
    CmdCnt = CmdNtwrk;

    initVec();

//если появился отчёт, то вызвать слот
    connect(CmdCnt, SIGNAL(getReportFrOprSignal(str::ReportFromOpr)), this, SLOT(getReportFrCmCntSlot(str::ReportFromOpr)));

//если появится answerStatus, то вызвать слот
    connect(CmdCnt, SIGNAL(getAnsStFrOprSignal(str::AnswerStatus)), this, SLOT(getStatusOprFrCmCntSlot(str::AnswerStatus)));

//таймер для переодического опроса операторов на статус онлайн
    //connect(&TimerForStOpr, SIGNAL(timeout()), this, SLOT(periodRequestOprSlot()));
    //TimerForStOpr.start(CmdConf.getSecPer());

}


Cmd::~Cmd()
{
    HistoryRequest.clear();
    InfoStOpr.clear();
    TimerForStOpr.stop();
}

//функция для инициализации векторов
void Cmd::initVec()
{
    for (quint16 i = 1; i <= CmdConf.getCountOpr(); i++)
    {
        str::RequestStatus *cur1 = new str::RequestStatus;
        str::AnswerStatus *cur2 = new str::AnswerStatus;
        cur1->idOperator = cur2->idOperator = i;
        HistoryRequest.push_back(cur1);
        InfoStOpr.push_back(cur2);
    }
}


bool Cmd::setTask(str::TaskForOpr taskParam)
{
    if (CmdCnt->sendTask(taskParam) == true)
    {
        return true;
    }
    qDebug() << "error in setTask";
    return false;
}


//данная функция нужна для переодического запроса на статус оператора
void Cmd::periodRequestOprSlot()
{
    for (quint16 i = 1; i <= HistoryRequest.size(); i++)
    {
        HistoryRequest[i-1]->dateTime = QTime::currentTime().toString();
        HistoryRequest[i-1]->nRequest = ++nRequestSt;
        HistoryRequest[i-1]->statusCmd = CmdConf.getStCmd();

        CmdCnt->sendRequestStatus(*HistoryRequest[i-1]);
    }
}

void Cmd::getReportFrCmCntSlot(str::ReportFromOpr curReport)
{
    emit getReportToCHstSignal(curReport);
}

void Cmd::getStatusOprFrCmCntSlot(str::AnswerStatus curAS)
{
    if (curAS.statusOperator != InfoStOpr[curAS.idOperator-1]->statusOperator)
    {
        *InfoStOpr[curAS.idOperator-1] = curAS;
        emit changeStOprToCHstSignal(curAS);
    }
}

