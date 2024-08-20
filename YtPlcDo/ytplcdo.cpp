#include "ytplcdo.h"
#include <QDebug>

YtPlcDo::YtPlcDo()
{
    m_PlcDo=nullptr;
    flag_is_load_=false;
}

YtPlcDo::~YtPlcDo()
{
    if(flag_is_load_)
    {
        releaseDll();
        flag_is_load_=false;
    }

}

bool YtPlcDo::toLoadPlc(QString plcdllname)
{
    if(flag_is_load_)
    {
        releaseDll();
        flag_is_load_=false;
    }
    if (!QLibrary::isLibrary(plcdllname))
        return false;
    library_.setFileName(plcdllname);
    flag_is_load_ = library_.load();
    if (!flag_is_load_) {
        qDebug() << library_.errorString();
        return false;
    }
    CreatePLCObj plugin = (CreatePLCObj)library_.resolve("CreatePLCObj");
    m_PlcDo = plugin();
    if (nullptr == m_PlcDo)
        return false;
    return true;
}


int YtPlcDo::ConnectServer(QString ip, int port, int Clientport, int timeout)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ConnectServer(ip,port,Clientport,timeout);
    }
    return -1;
}
int YtPlcDo::ConnectClose()
{
    if(m_PlcDo)
    {
        return m_PlcDo->ConnectClose();
    }
    return -1;
}

bool YtPlcDo::ReadBool(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadBool(address);
    }
    return false;
}

QVector<bool> YtPlcDo::ReadBool(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadBool(address,length);
    }
    return QVector<bool>();
}

double YtPlcDo::ReadDouble(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadDouble(address);
    }
    return 0.0;
}

QVector<double> YtPlcDo::ReadDouble(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadDouble(address,length);
    }
    return QVector<double>();
}

float YtPlcDo::ReadFloat(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadFloat(address);
    }
    return 0.0;
}

QVector<float> YtPlcDo::ReadFloat(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadFloat(address,length);
    }
    return QVector<float>();
}

short YtPlcDo::ReadInt16(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadInt16(address);
    }
    return -1;
}

QVector<short> YtPlcDo::ReadInt16(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadInt16(address,length);
    }
    return QVector<short>();
}

int YtPlcDo::ReadInt32(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadInt32(address);
    }
    return -1;
}

QVector<int> YtPlcDo::ReadInt32(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadInt32(address,length);
    }
    return QVector<int>();
}

long YtPlcDo::ReadInt64(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadInt64(address);
    }
    return -1;
}

QVector<long> YtPlcDo::ReadInt64(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadInt64(address,length);
    }
    return QVector<long>();
}

QString YtPlcDo::ReadString(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadString(address,length);
    }
    return "";
}

QString YtPlcDo::ReadString(QString address, ushort length, QString encodetype)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadString(address,length,encodetype);
    }
    return "";
}

ushort YtPlcDo::ReadUInt16(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadUInt16(address);
    }
    return 1;
}

QVector<ushort> YtPlcDo::ReadUInt16(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadUInt16(address,length);
    }
    return QVector<ushort>();
}

uint YtPlcDo::ReadUInt32(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadUInt32(address);
    }
    return 0;
}

QVector<uint> YtPlcDo::ReadUInt32(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadUInt32(address,length);
    }
    return QVector<uint>();
}

ulong YtPlcDo::ReadUInt64(QString address)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadUInt64(address);
    }
    return 0;
}

QVector<ulong> YtPlcDo::ReadUInt64(QString address, ushort length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->ReadUInt64(address,length);
    }
    return QVector<ulong>();
}

bool YtPlcDo::WriteBool(QString address, bool value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteBool(address,value);
    }
    return false;
}

bool YtPlcDo::WriteBool(QString address, QVector<bool> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteBool(address,values);
    }
    return false;
}

bool YtPlcDo::WriteDouble(QString address, double value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteDouble(address,value);
    }
    return false;
}

bool YtPlcDo::WriteDouble(QString address, QVector<double> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteDouble(address,values);
    }
    return false;
}

bool YtPlcDo::WriteFloat(QString address, float value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteFloat(address,value);
    }
    return false;
}

bool YtPlcDo::WriteFloat(QString address, QVector<float> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteFloat(address,values);
    }
    return false;
}

bool YtPlcDo::WriteInt16(QString address, short value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteInt16(address,value);
    }
    return false;
}

bool YtPlcDo::WriteInt16(QString address, QVector<short> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteInt16(address,values);
    }
    return false;
}

bool YtPlcDo::WriteInt32(QString address, int value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteInt32(address,value);
    }
    return false;
}

bool YtPlcDo::WriteInt32(QString address, QVector<int> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteInt32(address,values);
    }
    return false;
}

bool YtPlcDo::WriteInt64(QString address, long value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteInt64(address,value);
    }
    return false;
}

bool YtPlcDo::WriteInt64(QString address, QVector<long> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteInt64(address,values);
    }
    return false;
}

bool YtPlcDo::WriteUInt16(QString address, ushort value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteUInt16(address,value);
    }
    return false;
}

bool YtPlcDo::WriteUInt16(QString address, QVector<ushort> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteUInt16(address,values);
    }
    return false;
}

bool YtPlcDo::WriteUInt32(QString address, uint value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteUInt32(address,value);
    }
    return false;
}

bool YtPlcDo::WriteUInt32(QString address, QVector<uint> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteUInt32(address,values);
    }
    return false;
}

bool YtPlcDo::WriteUInt64(QString address, ulong value)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteUInt64(address,value);
    }
    return false;
}

bool YtPlcDo::WriteUInt64(QString address, QVector<ulong> values)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteUInt64(address,values);
    }
    return false;
}

bool YtPlcDo::WriteString(QString address, QString value, int length)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteString(address,value,length);
    }
    return false;
}

bool YtPlcDo::WriteString(QString address, QString value, int length, QString encodeing)
{
    if(m_PlcDo)
    {
        return m_PlcDo->WriteString(address,value,length,encodeing);
    }
    return false;
}

void YtPlcDo::releaseDll()
{
    //qDebug() << "LoadPlugin::releaseDll start";
    if (m_PlcDo != nullptr) {
        delete m_PlcDo;
        m_PlcDo = nullptr;
    }
    //qDebug() << "LoadPlugin::releaseDll start 2";
    if (flag_is_load_) {
        flag_is_load_ = !library_.unload();
    }
    //qDebug() << "LoadPlugin::releaseDll start e";
}


