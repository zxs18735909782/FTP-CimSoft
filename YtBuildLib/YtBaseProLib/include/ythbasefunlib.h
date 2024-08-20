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
//通过构建HobjectIm 共享到自建图像内存绑定，只针对c18u图像
//后面碰到新的图像类型再进行完善
int Q_DECL_EXPORT toShareMQimage(HObject &Inim,YtInterIm &OutIm);
//构建内存组对
int Q_DECL_EXPORT toCreateSizeHQImage(HObject &Inim,YtInterIm &OutImage,int width,int hight);
//采集内存转移 Qimage to Himage
int Q_DECL_EXPORT toCopyQToHImage(YtInterIm &InQim,HObject &OutImag);
//构建基础处理函数，把基本算子进行包装，方便后期对界面代码的复用
//获取xld 或者regin的 边缘点方便绘制
int Q_DECL_EXPORT toGetXldPointS(HObject &Txld, QVector<CMvPolygon> &toutPoint);
//获取regon的边缘点，进行绘制
int Q_DECL_EXPORT toGetRegionPointS(HObject &tReg,QVector<CMvPolygon> &toutPoint);
/////////////////////
//设计一个线线构建交点的方法
bool Q_DECL_EXPORT YtGetPointByTwoLine(CMvLineSeg inline1,CMvLineSeg inline2,CMvPoint &outPoint);
//计算点到线的距离,记录垂足
bool Q_DECL_EXPORT YTGetLentByPointToLine(CMvPoint inPoint,CMvPoint inline1,CMvPoint &OutP,double &OutLenth);
//计算点到点的距离
bool Q_DECL_EXPORT YtGetLenByPointToPoint(CMvPoint inPoint1,CMvPoint inPoint2,double &OutLenth);
////////////////////
//构建一个坐标系统转换的类，可以转换图像，区域，xld，以及点
class Q_DECL_EXPORT YtHomtAxis
{
    //坐标系统一类
public:
    YtHomtAxis();
    ~YtHomtAxis();
private:
    //因为只是一个处理类，所以就不存在模板这个概念
    HTuple m_HomMat2D;//转换对象,正向转换
    HTuple m_HomMat2DD;//反向转化，比如把图像反向修正
public:
    //这里的角度为弧度
    void toGenHomMat2D(CMvPoint InP,double InAng,CMvPoint GetP,double GetAng);
    //区域转换,是否正向传播
    bool toGetOutReg(HObject &treg,HObject &toutreg,bool isTran=true);
    //图像转换
    bool toGetOutImage(HObject &tInim,HObject &tOutIm,bool isTran=true);
    //点转换
    bool toGetOutPontF(CMvPoint &tInPoint,CMvPoint &tOutPoint,bool isTran=true);
    //旋转矩形变换
    bool toGetOutRotaRect(CMvRotatedRect &tInRect,CMvRotatedRect &tOutRect,bool isTran=true);
    //旋转线
    bool toGetOutLineF(CMvLineSeg &tInLine,CMvLineSeg &tOutLine,bool isTran=true);
    //旋转偏移点集
    bool toGetOutPointS(QVector<CMvPoint> &tInpoints,QVector<CMvPoint> &tOutpoints,bool isTran=true);

    bool toGetOutCircleArc(CMvArc &inArc, CMvArc &outArc, bool isTran);
};

//region转换颜色绘制
int Q_DECL_EXPORT YtHRegionToColorImage(HObject &Inreg, QImage &OutShowim, QVector<QRgb> &sColorTable, int imagewidth, int imagehight,bool isfill=true);
///////
//读取图像接口
bool Q_DECL_EXPORT toZLoadQImage(QImage &OutIm,QString FileName);
//写入图像接口
bool Q_DECL_EXPORT toZSaveQImage(QImage &InIm, QString FileNmae, int Perset=80);
//内存图像压缩转内存图像
int Q_DECL_EXPORT YtZHCodeJpgeN(unsigned char* im, int imwidth, int imheight, int changle, unsigned char *OutData,int &OutSize, int perset = 80);
//从内存读入jpge图像
int Q_DECL_EXPORT YtZHDecodeJpegN(QImage &Inim, unsigned char* imdata,int size);
int Q_DECL_EXPORT YtZHDecodeJpegN(YtInterIm &Inim, unsigned char* imdata,int size);
//保存jpg图像
int Q_DECL_EXPORT YtZHDoImageToJpg(QImage &Inim, QString filename, int perset = 80);
int Q_DECL_EXPORT YtZHDoImageToJpg(YtInterIm &Inim, QString filename, int perset = 80);
//读取jpg图像
int Q_DECL_EXPORT YtZHDoReadJpgN(QImage & Inim, QString filename);
int Q_DECL_EXPORT YtZHDoReadJpgN(YtInterIm & Inim, QString filename);


#endif // YTHBASEFUNLIB_H
