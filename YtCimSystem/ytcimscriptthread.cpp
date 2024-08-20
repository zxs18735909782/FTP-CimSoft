#include "ytcimscriptthread.h"

#include <QApplication>
#include <QFile>
#include <QDataStream>

YtCimScriptThread::YtCimScriptThread(QThread *parent)
{
    m_YtCimScript.m_YtPlcDo = &m_YtPlcDo;
}

YtCimScriptThread::~YtCimScriptThread()
{

}

void YtCimScriptThread::run()
{
    while(true)
    {
        m_Engine.evaluate(m_RunScript);
        if(m_Engine.hasUncaughtException())
        {
            QScriptValue Err = m_Engine.uncaughtException();
            toPrintLog(Err.toString(), Qt::yellow);
        }

        if(m_RunState == false)
        {
            m_YtCimScript.m_RunState = m_RunState;
            toPrintLog(u8"CIM_THREAD:--------终止CIM上传-------", Qt::red);
            break;
        }
    }

}

void YtCimScriptThread::toInitThread()
{
    QScriptValue ScriptVal;
    ScriptVal = m_Engine.newQObject(&m_YtCimScript);
    m_Engine.globalObject().setProperty("Yt", ScriptVal);
    m_YtCimScript.m_RunState = m_RunState;
}

void YtCimScriptThread::toStart(bool isOnce)
{
    toPrintLog(u8"CIM_THREAD:--------启动CIM上传-------", Qt::green);
    if(isOnce)
    {
        m_RunState = false;
    }
    else
    {
        m_RunState = true;
    }

    m_YtCimScript.m_RunState = m_RunState;

    start();
}

void YtCimScriptThread::toStop()
{
    m_RunState = false;
    m_YtCimScript.m_RunState = m_RunState;

}

void YtCimScriptThread::toSetScript(QString Script)
{
    m_RunScript = Script;
}

bool YtCimScriptThread::toLoadModel()
{
    QString ModelPath = QApplication::applicationDirPath() + "/CIM_Manger" ;

    QDir dir(ModelPath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(ModelPath + "/CIM_Script.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray array;
        while (!file.atEnd()) {
            array += file.readLine();
        }
        m_RunScript = QString(array);
        file.close();
    }

    return true;

}

void YtCimScriptThread::toSaveModel()
{
    QString ModelPath = QApplication::applicationDirPath() + "/CIM_Manger" ;

    QDir dir(ModelPath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(ModelPath + "/CIM_Script.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(m_RunScript.toUtf8());
        file.close();
    }
}

void YtCimScriptThread::toSetObject(YtNetWorkDo *tYtNetWork, int flag)
{
    if(flag == 0)
    {
        m_YtCimScript.m_YtFTPNetWorkDo = tYtNetWork;
    }

    if(flag == 1)
    {
        m_YtCimScript.m_YtShareFolderNetWorkDo = tYtNetWork;
    }

    if(flag == 2)
    {
        m_YtCimScript.m_YtSQLNetWork    = tYtNetWork;
    }
}

void YtCimScriptThread::toInitPLC()
{
    QString FilePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/Plc";
    QDir dir(FilePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(FilePath + "/PLC.dat");

    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream out(&file);
        out >> m_plc_param.DLL_NAME >> m_plc_param.PLC_IP >> m_plc_param.PLC_PORT >> m_plc_param.LOCAL_PORT;
    }

    file.close();
    QString temstr ="./Plc/" + m_plc_param.DLL_NAME;

    if(m_YtPlcDo.toLoadPlc(temstr))
    {
        toPrintLog(QString(u8"CIM_THREAD:--------PLC dll名称-------%1").arg(m_plc_param.DLL_NAME), Qt::green);
    }
    else
    {
        toPrintLog(QString(u8"CIM_THREAD:--------PLC加载失败 dll名称-------%1").arg(m_plc_param.DLL_NAME), Qt::red);
        return ;
    }
    int val = m_YtPlcDo.ConnectServer(m_plc_param.PLC_IP , m_plc_param.PLC_PORT.toInt(), m_plc_param.LOCAL_PORT.toInt());
    if(val == 0)
    {
        toPrintLog(QString(u8"CIM_THREAD:--------PLC连接成功-------%1").arg(m_plc_param.DLL_NAME), Qt::green);
    }
    else
    {
        toPrintLog(QString(u8"CIM_THREAD:--------PLC连接失败-------%1").arg(m_plc_param.DLL_NAME), Qt::red);
        return ;
    }

    toPrintLog(QString(u8"CIM_THREAD:--------PLC 信息-------%1---%2----%3")
               .arg(m_plc_param.PLC_IP).arg(m_plc_param.PLC_PORT).arg(m_plc_param.LOCAL_PORT), Qt::red);

}


void YtCimScriptThread::toSetRecordTime(QString tTime)
{
    m_YtCimScript.m_recordTime = tTime;
}


