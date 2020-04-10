#ifndef CMD_H
#define CMD_H

#include "Cmd_global.h"

#include <QObject>
#include <QDebug>
#include <QVector>
#include <QTimer>
#include <QTime>

#include "cmdconfiguration.h"
#include "cmdconnect.h"
#include "cmdnetwork.h"

class CMD_EXPORT Cmd : public QObject
{
    Q_OBJECT

public:
    Cmd(QObject *parent = 0, CmdConfiguration CmdConf1 = CmdConfiguration(),
        CmdNetConf CmdNtCnf1 = CmdNetConf());

    ~Cmd();


    bool setTask(str::TaskForOpr);

private:


//данная функция предназначена для инициализации вектора historyRequest и infoStOpr
    void initVec();

private slots:
    void getStatusOprFrCmCntSlot(str::AnswerStatus);
    void getReportFrCmCntSlot(str::ReportFromOpr);
    void periodRequestOprSlot();

signals:
    void changeStOprToCHstSignal(str::AnswerStatus);
    void getReportToCHstSignal(str::ReportFromOpr);

private:
    CmdConnect *CmdCnt;
    CmdNetwork *CmdNtwrk;

//два конфигурационных файла
    CmdConfiguration CmdConf;
    CmdNetConf CmdNtCnf;

//вектор, хранящий информацию о последнем запросе состояния оператора
    QVector <str::RequestStatus*> HistoryRequest;
//номер запроса
    quint64 nRequestSt;

//вектор, хранящий информацию о статусе операторов
    QVector <str::AnswerStatus*> InfoStOpr;
//номер ответа
    quint64 nAnswerSt;

    QTimer TimerForStOpr;
};

#endif // CMD_H
