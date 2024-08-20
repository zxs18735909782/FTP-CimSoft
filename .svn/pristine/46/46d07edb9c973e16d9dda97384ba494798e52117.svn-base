#ifndef YTNETWORKCLASS_H
#define YTNETWORKCLASS_H
#include <QStringList>
#include <QImage>
#include <QtGlobal>
struct ProVoidBase
{
    QString ClassName;
    void* Proptr;
};
class YtNetWorkvirtualclass
{
public:
    virtual bool openCommunication(QStringList InDataList)=0;
    virtual void closeCommunication()=0;
    virtual bool IsConnnect()=0;//连接状态
    virtual bool ReConnect()=0;//重ProVoidBase连
public:
    virtual bool sendMessage(QByteArray msg)=0;//发送数据
    virtual QByteArray toGetData(int timeoutsect=-1)=0;//请求数据
    virtual void toClearGetData()=0;//清除数据
public:
    virtual bool CmdPro(QString Procmd)=0;//执行指令，可以用于数据插入和ftp的关联处理
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1)=0;//需要对象穿透的指令访问
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2)=0;//需要对象穿透的指令访问
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2,ProVoidBase GetPtr3)=0;//需要对象穿透的指令访问
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2,ProVoidBase GetPtr3,ProVoidBase GetPtr4)=0;//需要对象穿透的指令访问
};

extern "C" {
    extern "C" Q_DECL_EXPORT  YtNetWorkvirtualclass *CreateYtNetWorkObj();
}
#endif // YTNETWORKCLASS_H
