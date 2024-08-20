#ifndef YTBASEDEFINE_H
#define YTBASEDEFINE_H
#define YtSAPI __declspec (dllexport)
#include "math.h"
#include <QVector>
#include <QColor>
//ͼ����Ӿ��㷨���õĵ����ȸ��������ݿɺ��Խ�Сֵ����ֵ
#define  MV_FEPS   1.0e-6F
//ͼ����Ӿ��㷨���õ�˫���ȸ��������ݿɺ��Խ�Сֵ����ֵ
#define  MV_DEPS   1.0e-9
//2pi ��ֵ
#define  MV_2_PI  6.283185307179586476925286766559
//pi ��ֵ
#define  MV_PI   3.1415926535897932384626433832795
//pi/2 ��ֵ
#define  MV_PI_2   1.5707963267948966192313216916398
//�Ƕ�ת����
#define M_PI_180 0.01745329
/////////////
//�㶨��
struct CMvPoint
{
    CMvPoint()
    {
        x=0.0;//���x�����꣬Ĭ��ֵΪ0.0
        y=0.0;//���y�����꣬Ĭ��ֵΪ0.0
    }
    CMvPoint(double tx,double ty)
    {
        x=tx;//���x�����꣬Ĭ��ֵΪ0.0
        y=ty;//���y�����꣬Ĭ��ֵΪ0.0
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<x<<y;
    }
    void GetData(QVector<double> data)
    {
        x=data.at(0);
        y=data.at(1);
    }
   double x=0.0;//���x�����꣬Ĭ��ֵΪ0.0
   double y=0.0;//���y�����꣬Ĭ��ֵΪ0.0
};
//��ά�㶨��
struct CMvPoint3d
{
    double  x=0.0; //���x�����꣬Ĭ��ֵΪ0.0
    double  y=0.0;//���y�����꣬Ĭ��ֵΪ0.0
    double  z =0.0;//���z�����꣬Ĭ��ֵΪ0.0
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<x<<y<<z;
    }
    void GetData(QVector<double> data)
    {
        x=data.at(0);
        y=data.at(1);
        z=data.at(2);
    }
};
//ֱ�߶���
struct CMvLine
{
    CMvPoint CenterP;//���ϵ�һ����
    double angle=0.0;//�Ƕ�
    CMvLine()
    {

    }
    CMvLine(double tx,double ty,double tang)
    {
        CenterP.x=tx;
        CenterP.y=ty;
        angle=tang;
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<CenterP.x<<CenterP.y<<angle;
    }
    void GetData(QVector<double> data)
    {
        CenterP.x=data.at(0);
        CenterP.y=data.at(1);
        angle=data.at(2);
    }
};
//�߶ζ���
struct CMvLineSeg
{
    CMvPoint  st ;//�߶���ʼ�㣬Ĭ��ֵΪ(0.0, 0.0)
    CMvPoint  ed; //�߶���ֹ�㣬Ĭ��ֵΪ(0.0, 0.0)
    double width;//���ÿɲ��õ�һ������
    CMvLineSeg()
    {
        st.x=0;
        st.y=0;
        ed.x=0;
        ed.y=0;
        width=0;
    }
    CMvLineSeg(double sx, double sy,double ex,double ey)
    {
       st.x=sx;
       st.y=sy;
       ed.x=ex;
       ed.y=ey;
    }
    CMvLineSeg(double sx, double sy,double ex,double ey,double twidth)
    {
       st.x=sx;
       st.y=sy;
       ed.x=ex;
       ed.y=ey;
       width=twidth;
    }
    double CenterX()
    {
        return (st.x+ed.x)/2;
    }
    double CenterY()
    {
        return (st.y+ed.y)/2;
    }
    double Length()
    {
        return sqrt((st.x-ed.x)*(st.x-ed.x)+(st.y-ed.y)*(st.y-ed.y));
    }
    double Deg()
    {

        return (180*atan((ed.y-st.y)/(ed.x-st.x))/3.1415926);
    }
    double Rad()
    {

        return atan((ed.y-st.y)/(ed.x-st.x));
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<st.x<<st.y<<ed.x<<ed.y<<width;
    }
    void GetData(QVector<double> data)
    {
        st.x=data.at(0);
        st.y=data.at(1);
        ed.x=data.at(2);
        ed.y=data.at(3);
        width=data.at(4);
    }
};
//Բ����
struct CMvCircle
{
    CMvCircle()
    {
        center.x=0;
        center.y=0;
        radius=0;
    }
    CMvCircle(double tx,double ty,double tradius)
    {
        center.x=tx;
        center.y=ty;
        radius=tradius;
    }
    CMvPoint  center;//Բ��λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double  radius=0.0 ;//�뾶���ȣ�Ĭ��ֵΪ0.0
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<center.x<<center.y<<radius;
    }
    void GetData(QVector<double> data)
    {
        center.x=data.at(0);
        center.y=data.at(1);
        radius=data.at(2);
    }
};
//Բ������
struct CMvArc
{
    CMvPoint  center ;//Բ��λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double  radius ;//Բ���뾶���ȣ�Ĭ��ֵΪ0.0
    double  stAngle ;//Բ����ʼ�Ƕȣ����ȣ���Ĭ��ֵΪ0.0
    double  edAngle ;//Բ�������Ƕȣ����ȣ���Ĭ��ֵΪ0.0
    CMvArc()
    {

    }
    CMvArc(double centerx,double centery,double tradius,double tstAngl,double tedAngle)
    {
        center.x=centerx;
        center.y=centery;
        radius=tradius;
        stAngle=tstAngl;
        edAngle=tedAngle;
    }
    double stAngleRad()
    {
        return (M_PI_180*stAngle);
    }
    double edAngleRad()
    {
        return (M_PI_180*edAngle);
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<center.x<<center.y<<radius<<stAngle<<edAngle;
    }
    void GetData(QVector<double> data)
    {
        center.x=data.at(0);
        center.y=data.at(1);
        radius=data.at(2);
        stAngle=data.at(3);
        edAngle=data.at(4);
    }

};
//����ϵ����
struct CMvCoord
{
    CMvPoint  origin;//����ԭ�㣬Ĭ��ֵΪ(0.0, 0.0)
    double  angle;//x��������ĽǶȣ�Ĭ��ֵΪ0.0
    double Rad()
    {
        return (M_PI_180*angle);
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<origin.x<<origin.y<<angle;
    }
    void GetData(QVector<double> data)
    {
        origin.x=data.at(0);
        origin.y=data.at(1);
        angle=data.at(2);
    }
};
//��Բ����
struct CMvEllipse
{
    CMvPoint  Center;//Բ��λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double  axisX ;//x���᳤�ȣ�Ĭ��ֵΪ0.0
    double  axisY;//y���᳤�ȣ�Ĭ��ֵΪ0.0
    double  angle;//x��������ĽǶȣ�Ĭ��ֵΪ0.0
    CMvEllipse()
    {

    }
    CMvEllipse(double centx,double centy,double tcx,double tcy,double tangle)
    {
        Center.x=centx;
        Center.y=centy;
        axisX=tcx;
        axisY=tcy;
        angle=tangle;
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<Center.x<<Center.y<<axisX<<axisY<<angle;
    }
    void GetData(QVector<double> data)
    {
        Center.x=data.at(0);
        Center.y=data.at(1);
        axisX=data.at(2);
        axisY=data.at(3);
        angle=data.at(4);
    }
    double Rad()
    {
        return (M_PI_180*angle);
    }
};
//��С����
struct CMvSize
{
    double  cx=0.0 ;//x�᷽���ȣ�Ĭ��ֵΪ0.0
    double  cy=0.0 ;//y�᷽���ȣ�Ĭ��ֵΪ0.0
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<cx<<cy;
    }
    void GetData(QVector<double> data)
    {
        cx=data.at(0);
        cy=data.at(1);
    }
};

//�����ζ���
struct CMvRect
{
   CMvPoint  LeftTop;//���ϵ�λ�ã�Ĭ��ֵΪ(0.0, 0.0)
   double  cx=0.0 ;//x�᷽���ȣ�Ĭ��ֵΪ0.0
   double  cy=0.0 ;//y�᷽���ȣ�Ĭ��ֵΪ0.0
   CMvRect()
   {

   }
   CMvRect(double lefttopx,double lefttopy,double tcx,double tcy)
   {
       LeftTop.x=lefttopx;
       LeftTop.y=lefttopy;
       cx=tcx;
       cy=tcy;
   }
   QVector<double> Data()
   {
       QVector<double> data;
       return data<<LeftTop.x<<LeftTop.y<<cx<<cy;
   }
   void GetData(QVector<double> data)
   {
       LeftTop.x=data.at(0);
       LeftTop.y=data.at(1);
       cx=data.at(2);
       cy=data.at(3);

   }
};
//��ת���ζ���
struct CMvRotatedRect
{
    CMvPoint  Center;//���ĵ�λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double  cx=0.0 ;//x�᷽���ȣ�Ĭ��ֵΪ0.0
    double  cy=0.0 ;//y�᷽���ȣ�Ĭ��ֵΪ0.0
    double angle=0.0;//��ת�Ƕȣ�����
    CMvRotatedRect()
    {

    }
    CMvRotatedRect(double centx,double centy,double tcx,double tcy,double tangle)
    {
        Center.x=centx;
        Center.y=centy;
        cx=tcx;
        cy=tcy;
        angle=tangle;
    }
    double Rad()
    {
        return (M_PI_180*angle);
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<Center.x<<Center.y<<cx<<cy<<angle;
    }
    void GetData(QVector<double> data)
    {
        Center.x=data.at(0);
        Center.y=data.at(1);
        cx=data.at(2);
        cy=data.at(3);
        angle=data.at(4);
    }
    void toGetPoint(CMvPoint (&GetPoints)[4])
    {
        double fAngle = -M_PI_180*angle;
        double a = sin(fAngle) * 0.5;
        double b = cos(fAngle) * 0.5;
        double tcx=Center.x;
        double tcy=Center.y;
        double h=this->cy*2;
        double w=this->cx*2;
        GetPoints[0].x=(tcx + a * h - b * w);
        GetPoints[0].y=(tcy - b * h - a * w);
        GetPoints[2].x=(2 * tcx - GetPoints[0].x);
        GetPoints[2].y=(2 * tcy - GetPoints[0].y);

        GetPoints[3].x=(tcx - a * h - b * w);
        GetPoints[3].y=(tcy + b * h - a * w);
        GetPoints[1].x=(2 * tcx - GetPoints[3].x);
        GetPoints[1].y=(2 * tcy - GetPoints[3].y);
    }
};
//��Բ����
struct CMvWaistRound
{
    CMvPoint  Center;//���ĵ�λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double  cx=0.0 ;//x�᷽���ȣ�Ĭ��ֵΪ0.0,�ٻ��ư뾶����
    double  cy=0.0 ;//y�᷽���ȣ�Ĭ��ֵΪ0.0
    double angle=0.0;//��ת�Ƕȣ�����
    CMvWaistRound()
    {

    }
    CMvWaistRound(double centx,double centy,double tcx,double tcy,double tangle)
    {
        Center.x=centx;
        Center.y=centy;
        cx=tcx;
        cy=tcy;
        angle=tangle;
    }
    double Rad()
    {
        return (M_PI_180*angle);
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<Center.x<<Center.y<<cx<<cy<<angle;
    }
    void GetData(QVector<double> data)
    {
        Center.x=data.at(0);
        Center.y=data.at(1);
        cx=data.at(2);
        cy=data.at(3);
        angle=data.at(4);
    }
};
//Բ������
struct CMvRingCircle
{
    CMvPoint  Center;//���ĵ�λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double RadisMin=10;//Բ���ڰ뾶
    double RadisMax=20;//Բ����뾶
    CMvRingCircle()
    {

    }
    CMvRingCircle(double centx,double centy,double tmin,double tmax)
    {
        Center.x=centx;
        Center.y=centy;
        RadisMax=tmax;
        RadisMin=tmin;
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<Center.x<<Center.y<<RadisMin<<RadisMax;
    }
    void GetData(QVector<double> data)
    {
        Center.x=data.at(0);
        Center.y=data.at(1);
        RadisMin=data.at(2);
        RadisMax=data.at(3);
    }
};
//����ζ���
struct CMvPolygon
{
    QVector<CMvPoint> points;//�㼯��
    CMvPolygon()
    {

    }
    CMvPolygon( QVector<CMvPoint> tpoints)
    {
        points=tpoints;
    }
    QVector<double> Data()
    {
        QVector<double> data;
        for(int i=0;i<points.size();i++)
        {

            data<<points.at(i).x<<points.at(i).y;
        }
        return data;

    }
    void GetData(QVector<double> data)
    {
        points.clear();
        for(int i=0;i<data.size()/2;i++)
        {
            CMvPoint tp;
            tp.x=data.at(2*i);
            tp.y=data.at(2*i+1);
            points.push_back(tp);
        }
    }
};
//���ζ���
struct CMvPie
{
    CMvPoint  center ;//���ĵ�λ�ã�Ĭ��ֵΪ(0.0, 0.0)
    double RadisMin=10;//Բ���ڰ뾶
    double RadisMax=20;//Բ����뾶
    double stAngle ;//Բ����ʼ�Ƕȣ����ȣ���Ĭ��ֵΪ0.0
    double edAngle ;//Բ�������Ƕȣ����ȣ���Ĭ��ֵΪ0.0
    CMvPie()
    {

    }
    CMvPie(double centx,double centy,double tmin,double tmax,double tstang,double tedAngel)
    {
        center.x=centx;
        center.y=centy;
        RadisMax=tmax;
        RadisMin=tmin;
        stAngle=tstang;
        edAngle=tedAngel;
    }
    QVector<double> Data()
    {
        QVector<double> data;
        return data<<center.x<<center.y<<RadisMin<<RadisMax<<stAngle<<edAngle;
    }
    void GetData(QVector<double> data)
    {
        center.x=data.at(0);
        center.y=data.at(1);
        RadisMin=data.at(2);
        RadisMax=data.at(3);
        stAngle=data.at(4);
        edAngle=data.at(5);
    }
};









#endif // YTBASEDEFINE_H
