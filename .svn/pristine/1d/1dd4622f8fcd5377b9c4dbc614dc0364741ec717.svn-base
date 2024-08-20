#ifndef YTPLCDO_H
#define YTPLCDO_H
#include <QLibrary>
#include "ytplcdovirtualclass.h"
//这是PLC动态加载的执行接口类
//成员构造依赖虚类加载实现
class  __declspec(dllexport) YtPlcDo
{

public:
    YtPlcDo();
    ~YtPlcDo();
private:
    PlcVirtualClass *m_PlcDo;//根据dll动态加载对象完成连接使用
public:
    bool toLoadPlc(QString plcdllname);
public:
    //连接plc如果是udp需要提供自带的客户端ip
    int ConnectServer(QString ip,int port,int Clientport=0,int timeout=3000);
    //连接关闭成功为0 1为关闭失败
    int ConnectClose();
    //读取命令解析
    bool ReadBool(QString address);
    QVector<bool> ReadBool(QString address,ushort length);
    double ReadDouble(QString address);
    QVector<double> ReadDouble(QString address,ushort length);
    float ReadFloat(QString address);
    QVector<float> ReadFloat(QString address,ushort length);
    short ReadInt16(QString address);
    QVector<short> ReadInt16(QString address,ushort length);
    int ReadInt32(QString address);
    QVector<int> ReadInt32(QString address,ushort length);
    long ReadInt64(QString address);
    QVector<long> ReadInt64(QString address,ushort length);
    QString ReadString(QString address,ushort length);
    //应对特定情况下的解码
    QString ReadString(QString address,ushort length,QString encodetype);
    ushort ReadUInt16(QString address);
    QVector<ushort> ReadUInt16(QString address,ushort length);
    uint ReadUInt32(QString address);
    QVector<uint> ReadUInt32(QString address,ushort length);
    ulong ReadUInt64(QString address);
    QVector<ulong> ReadUInt64(QString address,ushort length);
    //////////////////////////////////////////
    bool WriteBool(QString address,bool value);
    bool WriteBool(QString address,QVector<bool> values);
    bool WriteDouble(QString address,double value);
    bool WriteDouble(QString address,QVector<double> values);
    bool WriteFloat(QString address,float value);
    bool WriteFloat(QString address,QVector<float> values);
    bool WriteInt16(QString address,short value);
    bool WriteInt16(QString address,QVector<short> values);
    bool WriteInt32(QString address,int value);
    bool WriteInt32(QString address,QVector<int> values);
    bool WriteInt64(QString address,long value);
    bool WriteInt64(QString address,QVector<long> values);
    bool WriteUInt16(QString address,ushort value);
    bool WriteUInt16(QString address,QVector<ushort> values);
    bool WriteUInt32(QString address,uint value);
    bool WriteUInt32(QString address,QVector<uint> values);
    bool WriteUInt64(QString address,ulong value);
    bool WriteUInt64(QString address,QVector<ulong> values);
    /////////////////
    bool WriteString(QString address,QString value,int length=-1);//如果为-1就是有多少读多少
    bool WriteString(QString address, QString value, int length,QString encodeing);//按照解码规则解码

private:
    void releaseDll();

private:
    typedef PlcVirtualClass* (*CreatePLCObj)();
    QLibrary library_;
    bool flag_is_load_;
};

#endif // YTPLCDO_H
