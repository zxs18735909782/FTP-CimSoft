#ifndef YTCIMSCRIPTTHREAD_H
#define YTCIMSCRIPTTHREAD_H

#include <QThread>
#include <QtScript>

#include "YtNetWorkDo.h"
#include "ytcimscript.h"
#include "ytplcdo.h"
#include "DataStruct.h"

class YtCimScriptThread : public QThread
{
    Q_OBJECT
public:
    explicit YtCimScriptThread(QThread *parent = nullptr);
    ~YtCimScriptThread();

    void run();

public:
    void toInitThread();

    void toStart(bool isOnce);

    void toStop();

    void toSetScript(QString Script);

    bool toLoadModel();

    void toSaveModel();

    void toSetObject(YtNetWorkDo *tYtNetWork, int flag = 0);

    void toInitPLC();

    void toSetRecordTime(QString tTime);

public:
    QScriptEngine   m_Engine;
    QString         m_RunScript;

    YtCimScript     m_YtCimScript;
    YtPlcDo         m_YtPlcDo;

    PLC_PARAM       m_plc_param;

    bool            m_RunState = false;

};

#endif // YTCIMSCRIPTTHREAD_H
