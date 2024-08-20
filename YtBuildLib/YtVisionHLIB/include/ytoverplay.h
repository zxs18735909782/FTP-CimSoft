#ifndef YTOVERPLAY_H
#define YTOVERPLAY_H
#include <QImage>
# include "ytbasedefine.h"
struct TxtInfo
{
    CMvPoint ltp;
    QString data;
};
struct YtStOverPlayObj
{
    //������ͼ�񶯵�ͼ�����
    QVector<CMvPoint> m_ShowPointslist;//��ʾ�㼯���̶���С��x
    QVector<CMvLine>  m_ShowLinelist;//ֱ��
    QVector<CMvLineSeg> m_ShowLineSeglist;//�߶�
    QVector<CMvRect>   m_ShowRectlist;//������
    QVector<CMvRotatedRect> m_RotateRectlist;//��ת����
    QVector<TxtInfo> m_TxtInfolist;//����
    QVector<CMvPolygon> m_Polygonlist;//ѭ���㼯
    QVector<QVector<CMvPoint>> m_PolygonElist;//��ѭ���㼯
    QVector<CMvCircle>  m_CircleList;//Բ�б�
    QVector<CMvEllipse>  m_EllipseList;//��Բ�б�
    QVector<CMvLine>  m_XShowLinelist;//����
    QVector<CMvLineSeg> m_XShowLineSeglist;//�����߶�
    QVector<double> m_ResultDoble;//���������
    QVector<int>   m_Resultint;//�������
    QVector<bool>  m_ResultBool;//���������
    QVector<QString> m_ResultQString;//qstring

    void toSetBlobIM(QImage &im)
    {
        m_BlobIm=im;
        m_isshowBlobim=true;
    }
    void toClearBlobIm()
    {
        m_BlobIm=QImage();
        m_isshowBlobim=false;
    }
    void ClearAll()
    {
        m_ShowPointslist.clear();
        m_ShowLinelist.clear();
        m_ShowLineSeglist.clear();
        m_ShowRectlist.clear();
        m_RotateRectlist.clear();
        m_TxtInfolist.clear();
        m_Polygonlist.clear();
        m_PolygonElist.clear();
        m_CircleList.clear();
        m_EllipseList.clear();
        m_XShowLinelist.clear();
        m_XShowLineSeglist.clear();
        m_ResultDoble.clear();
        m_Resultint.clear();
        m_ResultBool.clear();
        m_ResultQString.clear();

    }
    int ResultCount()
    {
        //�������ݽ������
        int tNumber=0;
        tNumber+=m_ShowPointslist.size();
        tNumber+=m_ShowLinelist.size();
        tNumber+=m_ShowLineSeglist.size();
        tNumber+=m_ShowRectlist.size();
        tNumber+=m_RotateRectlist.size();
        tNumber+=m_TxtInfolist.size();
        tNumber+=m_Polygonlist.size();
        tNumber+=m_PolygonElist.size();
        tNumber+=m_CircleList.size();
        tNumber+=m_EllipseList.size();
        tNumber+=m_XShowLinelist.size();
        tNumber+=m_XShowLineSeglist.size();
        tNumber+=m_ResultDoble.size();
        tNumber+=m_Resultint.size();
        tNumber+=m_ResultQString.size();
        tNumber+=m_ResultBool.size();
        return tNumber;
    }
    void SetShowPar(QColor tShowColor,int tfontsize,int tfontwidth,int tLineWidth)
    {
        ShowColor=tShowColor;
        fontsize=tfontsize;//�����С
        fontwidth=tfontwidth;//������
        LineWidth=tLineWidth;//�߿�
    }
    QColor ShowColor;
    int fontsize;//�����С
    int fontwidth;//������
    int LineWidth;//�߿�
    bool m_isshowBlobim=false;
    QImage m_BlobIm;
};









#endif // YTOVERPLAY_H
