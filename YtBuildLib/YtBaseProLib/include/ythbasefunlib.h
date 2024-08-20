#ifndef YTHBASEFUNLIB_H
#define YTHBASEFUNLIB_H
#include "ytvisionobject.h"
#include <halconcpp/HalconCpp.h>
#include <halconcpp/HDevThread.h>
using namespace HalconCpp;
struct MBlobDefine
{
    HObject Region;
    QVector<QString> BlobName;
};
//ͨ������HobjectIm �����Խ�ͼ���ڴ�󶨣�ֻ���c18uͼ��
//���������µ�ͼ�������ٽ�������
int Q_DECL_EXPORT toShareMQimage(HObject &Inim,YtInterIm &OutIm);
//�����ڴ����
int Q_DECL_EXPORT toCreateSizeHQImage(HObject &Inim,YtInterIm &OutImage,int width,int hight);
//�ɼ��ڴ�ת�� Qimage to Himage
int Q_DECL_EXPORT toCopyQToHImage(YtInterIm &InQim,HObject &OutImag);
//�����������������ѻ������ӽ��а�װ��������ڶԽ������ĸ���
//��ȡxld ����regin�� ��Ե�㷽�����
int Q_DECL_EXPORT toGetXldPointS(HObject &Txld, QVector<CMvPolygon> &toutPoint);
//��ȡregon�ı�Ե�㣬���л���
int Q_DECL_EXPORT toGetRegionPointS(HObject &tReg,QVector<CMvPolygon> &toutPoint);
/////////////////////
//���һ�����߹�������ķ���
bool Q_DECL_EXPORT YtGetPointByTwoLine(CMvLineSeg inline1,CMvLineSeg inline2,CMvPoint &outPoint);
//����㵽�ߵľ���,��¼����
bool Q_DECL_EXPORT YTGetLentByPointToLine(CMvPoint inPoint,CMvPoint inline1,CMvPoint &OutP,double &OutLenth);
//����㵽��ľ���
bool Q_DECL_EXPORT YtGetLenByPointToPoint(CMvPoint inPoint1,CMvPoint inPoint2,double &OutLenth);
////////////////////
//����һ������ϵͳת�����࣬����ת��ͼ������xld���Լ���
class Q_DECL_EXPORT YtHomtAxis
{
    //����ϵͳһ��
public:
    YtHomtAxis();
    ~YtHomtAxis();
private:
    //��Ϊֻ��һ�������࣬���ԾͲ�����ģ���������
    HTuple m_HomMat2D;//ת������,����ת��
    HTuple m_HomMat2DD;//����ת���������ͼ��������
public:
    //����ĽǶ�Ϊ����
    void toGenHomMat2D(CMvPoint InP,double InAng,CMvPoint GetP,double GetAng);
    //����ת��,�Ƿ����򴫲�
    bool toGetOutReg(HObject &treg,HObject &toutreg,bool isTran=true);
    //ͼ��ת��
    bool toGetOutImage(HObject &tInim,HObject &tOutIm,bool isTran=true);
    //��ת��
    bool toGetOutPontF(CMvPoint &tInPoint,CMvPoint &tOutPoint,bool isTran=true);
    //��ת���α任
    bool toGetOutRotaRect(CMvRotatedRect &tInRect,CMvRotatedRect &tOutRect,bool isTran=true);
    //��ת��
    bool toGetOutLineF(CMvLineSeg &tInLine,CMvLineSeg &tOutLine,bool isTran=true);
    //��תƫ�Ƶ㼯
    bool toGetOutPointS(QVector<CMvPoint> &tInpoints,QVector<CMvPoint> &tOutpoints,bool isTran=true);

    bool toGetOutCircleArc(CMvArc &inArc, CMvArc &outArc, bool isTran);
};

//regionת����ɫ����
int Q_DECL_EXPORT YtHRegionToColorImage(HObject &Inreg, QImage &OutShowim, QVector<QRgb> &sColorTable, int imagewidth, int imagehight,bool isfill=true);
///////
//��ȡͼ��ӿ�
bool Q_DECL_EXPORT toZLoadQImage(QImage &OutIm,QString FileName);
//д��ͼ��ӿ�
bool Q_DECL_EXPORT toZSaveQImage(QImage &InIm, QString FileNmae, int Perset=80);
//�ڴ�ͼ��ѹ��ת�ڴ�ͼ��
int Q_DECL_EXPORT YtZHCodeJpgeN(unsigned char* im, int imwidth, int imheight, int changle, unsigned char *OutData,int &OutSize, int perset = 80);
//���ڴ����jpgeͼ��
int Q_DECL_EXPORT YtZHDecodeJpegN(QImage &Inim, unsigned char* imdata,int size);
int Q_DECL_EXPORT YtZHDecodeJpegN(YtInterIm &Inim, unsigned char* imdata,int size);
//����jpgͼ��
int Q_DECL_EXPORT YtZHDoImageToJpg(QImage &Inim, QString filename, int perset = 80);
int Q_DECL_EXPORT YtZHDoImageToJpg(YtInterIm &Inim, QString filename, int perset = 80);
//��ȡjpgͼ��
int Q_DECL_EXPORT YtZHDoReadJpgN(QImage & Inim, QString filename);
int Q_DECL_EXPORT YtZHDoReadJpgN(YtInterIm & Inim, QString filename);


#endif // YTHBASEFUNLIB_H
