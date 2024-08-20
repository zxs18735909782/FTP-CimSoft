#ifndef YTBLOBDEFINE_H
#define YTBLOBDEFINE_H
#include "ytoverplay.h"
#include <QFile>
#include <QDataStream>
struct YtBlobDefine
{
    char Type[32];      // 类型32个字符表示
    CMvRotatedRect Pos; // blob位置信息
    CMvRect  RectPos;   // 正矩形位置
    double Len1;        // 实际长轴长
    double Len2;        // 实际短轴长
    double Area;        // 缺陷面积
    double Compact;     // 紧实度
    double Reserve[4];  // 保留数据
};
struct YtAllBlob
{
    double Xscal=1.0;//记录X方向比例尺
    double yscal=1.0;//记录Y比例尺信息
    int OutTypeDefine;//输出最终定义,有可能就是true 和false
    CMvPoint m_GetPos[4];//四点定位的包络
    QVector<QString>    GetImInfo;//输出图像信息
    QVector<YtBlobDefine> GetBlob;//记录所有的blob信息
    void toGetOverPlay(YtStOverPlayObj &SetOverPlay)
    {
        SetOverPlay.ClearAll();
        TxtInfo teminfo;
        QString temstr;
        for(int i=0;i<GetBlob.size();i++)
        {
            SetOverPlay.m_RotateRectlist.append(GetBlob.at(i).Pos);
            teminfo.ltp=GetBlob.at(i).Pos.Center;
            temstr.sprintf("%1.2fx%1.2f",GetBlob.at(i).Len1,GetBlob.at(i).Len2);
            teminfo.data=temstr+QString::fromLocal8Bit(GetBlob.at(i).Type);
            SetOverPlay.m_TxtInfolist.append(teminfo);
        }
    }
    QByteArray toStreamData()
    {
        QByteArray OutData;
        QDataStream out(&OutData,QIODevice::ReadWrite);
        out << Xscal<<yscal<<OutTypeDefine<<GetImInfo<<GetBlob.size();
        QByteArray temByteData;
        YtBlobDefine temsetdata;

        for(int i=0;i<GetBlob.size();i++)
        {
            temsetdata=GetBlob.at(i);
            temByteData.setRawData((char *)&temsetdata,sizeof(YtBlobDefine));
            out<<temByteData;
        }
        //qDebug()<<OutData.size()<<"YYYYYYYYY";

        return  OutData;
    }
    //反序列化blob数据
    void toFromStreamData(QByteArray &Indata)
    {
        int SetSize=0;
        GetBlob.clear();
        QDataStream out(&Indata,QIODevice::ReadWrite);
        out >> Xscal>>yscal>>OutTypeDefine>>GetImInfo>>SetSize;
        QByteArray temByteData;
        YtBlobDefine temsetdata;
        //qDebug()<<Indata.size()<<"XXXXXXXXXXXXXX";
        for(int i=0;i<SetSize;i++)
        {
            out>>temByteData;
            memcpy(&temsetdata,temByteData.data(),temByteData.size());
            GetBlob.append(temsetdata);
        }
    }
    void toSaveData(QString filename)
    {
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly))
        {
            return;
        }
        QDataStream out(&file);
        out << Xscal<<yscal<<OutTypeDefine<<GetImInfo<<GetBlob.size();
        QByteArray temByteData;
        YtBlobDefine temsetdata;
        for(int i=0;i<GetBlob.size();i++)
        {
            temsetdata=GetBlob.at(i);
            temByteData.setRawData((char *)&temsetdata,sizeof(YtBlobDefine));
            out<<temByteData;
        }
        file.close();
    }
    void toLoadData(QString filename)
    {
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly))
        {
            return;
        }
        int SetSize=0;
        GetBlob.clear();
        QDataStream out(&file);
        out >> Xscal>>yscal>>OutTypeDefine>>GetImInfo>>SetSize;
        QByteArray temByteData;
        YtBlobDefine temsetdata;
        for(int i=0;i<SetSize;i++)
        {
            out>>temByteData;
            memcpy(&temsetdata,temByteData.data(),temByteData.size());
            GetBlob.append(temsetdata);
        }
        file.close();
    }

};
#endif // YTBLOBDEFINE_H
