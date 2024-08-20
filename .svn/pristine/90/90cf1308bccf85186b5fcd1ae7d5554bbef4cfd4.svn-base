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
    //不随着图像动的图层绘制
    QVector<CMvPoint> m_ShowPointslist;//显示点集，固定大小的x
    QVector<CMvLine>  m_ShowLinelist;//直线
    QVector<CMvLineSeg> m_ShowLineSeglist;//线段
    QVector<CMvRect>   m_ShowRectlist;//正矩形
    QVector<CMvRotatedRect> m_RotateRectlist;//旋转矩形
    QVector<TxtInfo> m_TxtInfolist;//文字
    QVector<CMvPolygon> m_Polygonlist;//循环点集
    QVector<QVector<CMvPoint>> m_PolygonElist;//非循环点集
    QVector<CMvCircle>  m_CircleList;//圆列表
    QVector<CMvEllipse>  m_EllipseList;//椭圆列表
    QVector<CMvLine>  m_XShowLinelist;//虚线
    QVector<CMvLineSeg> m_XShowLineSeglist;//虚线线段
    QVector<double> m_ResultDoble;//结果浮点数
    QVector<int>   m_Resultint;//结果整形
    QVector<bool>  m_ResultBool;//结果浮点型
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
        //返回数据结果数量
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
        fontsize=tfontsize;//字体大小
        fontwidth=tfontwidth;//字体宽度
        LineWidth=tLineWidth;//线宽
    }
    QColor ShowColor;
    int fontsize;//字体大小
    int fontwidth;//字体宽度
    int LineWidth;//线宽
    bool m_isshowBlobim=false;
    QImage m_BlobIm;
};









#endif // YTOVERPLAY_H
