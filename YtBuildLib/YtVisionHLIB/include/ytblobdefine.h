#ifndef YTBLOBDEFINE_H
#define YTBLOBDEFINE_H
#include "ytoverplay.h"
#include <QFile>
#include <QDataStream>
struct YtBlobDefine
{
    char Type[32];      // ����32���ַ���ʾ
    CMvRotatedRect Pos; // blobλ����Ϣ
    CMvRect  RectPos;   // ������λ��
    double Len1;        // ʵ�ʳ��᳤
    double Len2;        // ʵ�ʶ��᳤
    double Area;        // ȱ�����
    double Compact;     // ��ʵ��
    double Reserve[4];  // ��������
};
struct YtAllBlob
{
    double Xscal=1.0;//��¼X���������
    double yscal=1.0;//��¼Y��������Ϣ
    int OutTypeDefine;//������ն���,�п��ܾ���true ��false
    CMvPoint m_GetPos[4];//�ĵ㶨λ�İ���
    QVector<QString>    GetImInfo;//���ͼ����Ϣ
    QVector<YtBlobDefine> GetBlob;//��¼���е�blob��Ϣ
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
    //�����л�blob����
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
