#ifndef YTNETWORKDO_H
#define YTNETWORKDO_H

#include <QLibrary>
#include <QImage>
#include "ytnetworkclass.h"
#include <QMap>
#include <QObject>
#include <QtGlobal>
class  Q_DECL_EXPORT YtNetWorkDo
{
public:
    YtNetWorkDo();
    ~YtNetWorkDo();
private:
    YtNetWorkvirtualclass *m_YtNetWorkDo;
public:
    bool toLoadNetWork(QString NetWorkdllname);
public:
     bool openCommunication(QStringList InDataList);
     void closeCommunication();
     bool IsConnnect();//连接状态
     bool ReConnect();//重连
public:
     bool sendMessage(QByteArray msg);//发送数据
     QByteArray toGetData(int timeoutsect=-1);//请求数据
     void toClearGetData();//清除数据
public:
     bool CmdPro(QString Procmd);//执行指令，可以用于数据插入和ftp的关联处理
     bool CmdPro(QString Procmd,ProVoidBase GetPtr1);//需要对象穿透的指令访问
     bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2);//需要对象穿透的指令访问
     bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2,ProVoidBase GetPtr3);//需要对象穿透的指令访问
     bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2,ProVoidBase GetPtr3,ProVoidBase GetPtr4);//需要对象穿透的指令访问
private:
    void releaseDll();
private:
    typedef YtNetWorkvirtualclass *(*CreateYtNetWorkObj)();
    QLibrary m_library;
    bool m_flag_is_load;
    QString m_DlllName;//dll的名称
};


#endif // YTNETWORKDO_H
