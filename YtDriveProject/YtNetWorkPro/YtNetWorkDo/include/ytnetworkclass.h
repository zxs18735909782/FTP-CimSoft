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
    virtual bool IsConnnect()=0;//����״̬
    virtual bool ReConnect()=0;//��ProVoidBase��
public:
    virtual bool sendMessage(QByteArray msg)=0;//��������
    virtual QByteArray toGetData(int timeoutsect=-1)=0;//��������
    virtual void toClearGetData()=0;//�������
public:
    virtual bool CmdPro(QString Procmd)=0;//ִ��ָ������������ݲ����ftp�Ĺ�������
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1)=0;//��Ҫ����͸��ָ�����
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2)=0;//��Ҫ����͸��ָ�����
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2,ProVoidBase GetPtr3)=0;//��Ҫ����͸��ָ�����
    virtual bool CmdPro(QString Procmd,ProVoidBase GetPtr1,ProVoidBase GetPtr2,ProVoidBase GetPtr3,ProVoidBase GetPtr4)=0;//��Ҫ����͸��ָ�����
};

extern "C" {
    extern "C" Q_DECL_EXPORT  YtNetWorkvirtualclass *CreateYtNetWorkObj();
}
#endif // YTNETWORKCLASS_H
