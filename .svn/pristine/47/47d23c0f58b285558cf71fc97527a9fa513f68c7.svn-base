#ifndef YTPLCDOVIRTUALCLASS_H
#define YTPLCDOVIRTUALCLASS_H
#include <QString>
#include <QVector>
class PlcVirtualClass
{
public:
    //连接PLC，提供IP和端口以及超时，返回值0 为连接成功，1为连接失败，-1表示连接未关闭
    virtual int ConnectServer(QString ip,int port,int Clientport=0,int timeout=3000)=0;
    //连接关闭成功为0 1为关闭失败
    virtual int ConnectClose()=0;

    //读取命令解析
    virtual bool ReadBool(QString address)=0;
    virtual QVector<bool> ReadBool(QString address,ushort length)=0;

    virtual double ReadDouble(QString address)=0;
    virtual QVector<double> ReadDouble(QString address,ushort length)=0;

    virtual float ReadFloat(QString address)=0;
    virtual QVector<float> ReadFloat(QString address,ushort length)=0;

    virtual short ReadInt16(QString address)=0;
    virtual QVector<short> ReadInt16(QString address,ushort length)=0;

    virtual int ReadInt32(QString address)=0;
    virtual QVector<int> ReadInt32(QString address,ushort length)=0;

    virtual long ReadInt64(QString address)=0;
    virtual QVector<long> ReadInt64(QString address,ushort length)=0;

    virtual QString ReadString(QString address,ushort length)=0;
    //应对特定情况下的解码
    virtual QString ReadString(QString address,ushort length,QString encodetype)=0;

    virtual ushort ReadUInt16(QString address)=0;
    virtual QVector<ushort> ReadUInt16(QString address,ushort length)=0;

    virtual uint ReadUInt32(QString address)=0;
    virtual QVector<uint> ReadUInt32(QString address,ushort length)=0;

    virtual ulong ReadUInt64(QString address)=0;
    virtual QVector<ulong> ReadUInt64(QString address,ushort length)=0;

    //////////////////////////////////////////
    // 写入接口
    virtual bool WriteBool(QString address,bool value)=0;
    virtual bool WriteBool(QString address,QVector<bool> values)=0;

    virtual bool WriteDouble(QString address,double value)=0;
    virtual bool WriteDouble(QString address,QVector<double> values)=0;

    virtual bool WriteFloat(QString address,float value)=0;
    virtual bool WriteFloat(QString address,QVector<float> values)=0;

    virtual bool WriteInt16(QString address,short value)=0;
    virtual bool WriteInt16(QString address,QVector<short> values)=0;

    virtual bool WriteInt32(QString address,int value)=0;
    virtual bool WriteInt32(QString address,QVector<int> values)=0;

    virtual bool WriteInt64(QString address,long value)=0;
    virtual bool WriteInt64(QString address,QVector<long> values)=0;

    virtual bool WriteUInt16(QString address,ushort value)=0;
    virtual bool WriteUInt16(QString address,QVector<ushort> values)=0;

    virtual bool WriteUInt32(QString address,uint value)=0;
    virtual bool WriteUInt32(QString address,QVector<uint> values)=0;

    virtual bool WriteUInt64(QString address,ulong value)=0;
    virtual bool WriteUInt64(QString address,QVector<ulong> values)=0;

    virtual bool WriteString(QString address,QString value,int length=-1)=0;//如果为-1就是有多少读多少
    virtual bool WriteString(QString address, QString value, int length,QString encodeing)=0;//按照解码规则解码

};

extern "C" {
extern "C" __declspec(dllexport) PlcVirtualClass* CreatePLCObj();
}






#endif // YTPLCDOVIRTUALCLASS_H
