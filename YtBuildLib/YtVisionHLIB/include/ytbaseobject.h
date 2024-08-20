#ifndef YTBASEOBJECT_H
#define YTBASEOBJECT_H
#include <QImage>
#include <QPointF>
#include <QRectF>
#include "ytbasedefine.h"
#include "ytblobdefine.h"
///////////////////////////
//对QImage进行拓展,使得能够支持内存挂载方便中途传输
//使用Qimage的浅拷贝就可以实现内存共享
class YtSAPI YtInterIm
{
    //此对象用于构建算法执行dll的中间承载
    //存储中间共享内存的变量，方便传输使用
private:
    uchar * data;
    int width;
    int height;
    int bytesPerLine;
    int format;//记录中间承载，
    QImage mIM;//内部承载
public:
    YtInterIm(uchar * data=nullptr, int width=400, int height=400, int bytesPerLine=400, int format=QImage::Format_Grayscale8);
    void toSetQimamage(QImage im);//承载图像，浅拷贝
    void toSetCloenImage(QImage im);//承载图像，深拷贝
    QImage toGetIm();//拿出对象
    void toSetData(uchar * data=nullptr, int width=400, int height=400, int bytesPerLine=400, int format=QImage::Format_Grayscale8);
public:
    //基础调用方法
    bool LoadFile(QString filename);
    bool SaveFile(const QString &fileName, const char *format = Q_NULLPTR, int quality=-1);
    //获取图像指针
    unsigned char * GetImageData(unsigned int nX = 0, unsigned int nY = 0);
    //按照单通道读取灰度值
    int GetGrayVal(unsigned int nX = 0, unsigned int nY = 0);
    //获取图像宽度
    int GetImageWidth();
    //获取图像高度
    int GetImageHight();
    //获取图像类型
    int GetImageType();
};
//增加一些基本数据类型的构造,与Qt的数据类型相互转换
QPointF  YtSAPI YtMVPointToQpoint(CMvPoint tempoint);
CMvPoint YtSAPI YtQpointToMvPoint(QPointF tempoint);
//线段转换
CMvLineSeg YtSAPI YtQlineToMvLine(QLineF temline);//直线构造转换
double YtSAPI YtMvLineSegAng(CMvLineSeg temline);//直线角度计算
double YtSAPI YtMvLineSegLenth(CMvLineSeg temline);//直线长度计算
CMvPoint YtSAPI YtMvLineSegCenter(CMvLineSeg temline);//获取直线的中点
//正矩形
CMvRect YtSAPI YtQRectToMvRect(QRectF temrect);
double YtSAPI YtMvRectWidth(CMvRect temrect);//获取宽度
double YtSAPI YtMvRectHeight(CMvRect temrect);//获取高度
CMvPoint YtSAPI YtMvRectCenter(CMvRect temrect);//正矩形的中心
//旋转矩形的相关配置
CMvRotatedRect YtSAPI YtCreateRoTatedRect(double cx = 0, double cy = 0, double w = 0, double h = 0, double angle = 0);//构建旋转矩形
CMvRotatedRect YtSAPI YtCreateRoTatedRect( QPointF center,QSizeF size, double angle);//构建旋转矩形
//  pts[0] ------------ pts[1]
//         |          |
//         |          |
//         |    -->   O  箭头方向为正方向. 角度是逆时针为正(与Qt/Halcon方向一致, 与OpenCv方向相反)
//         |          |
//         |          |
//  pts[3] ------------ pts[2]
int YtSAPI YtRotatedRectPoints(CMvRotatedRect &inrect,QPointF (&GetPoints)[4]);
int YtSAPI YtRotatedRectPoints(CMvRotatedRect &inrect,CMvPoint (&GetPoints)[4]);
//获取旋转矩形外接正矩形
QRectF YtSAPI YtGetRotatedRectMaxRect(CMvRotatedRect &inrect);
CMvRect YtSAPI YtGetRotatedRectMaxMRect(CMvRotatedRect &inrect);
//增加一些基础接口
//对qimage进行读写
//读取图像接口
bool YtSAPI toLoadQImage(QImage &OutIm,QString FileName);
//写入图像接口
bool YtSAPI toSaveQImage(QImage &InIm, QString FileNmae, int Perset=80);
//内存图像压缩转内存图像
int YtSAPI YtHCodeJpgeN(unsigned char* im, int imwidth, int imheight, int changle, unsigned char *OutData,int &OutSize, int perset = 80);
//从内存读入jpge图像
int YtSAPI YtHDecodeJpegN(QImage &Inim, unsigned char* imdata,int size);
int YtSAPI YtHDecodeJpegN(YtInterIm &Inim, unsigned char* imdata,int size);
//保存jpg图像
int YtSAPI YtHDoImageToJpg(QImage &Inim, QString filename, int perset = 80);
int YtSAPI YtHDoImageToJpg(YtInterIm &Inim, QString filename, int perset = 80);
//读取jpg图像
int YtSAPI YtHDoReadJpgN(QImage & Inim, QString filename);
int YtSAPI YtHDoReadJpgN(YtInterIm & Inim, QString filename);
//自定义图像格式
int YtSAPI YtSaveYtImage(QImage &Inim,YtAllBlob &BlobData,QString FileNmae, int Perset=80);
int YtSAPI YtLoadYtImage(QImage &OutIm, YtAllBlob &BlobData, QString FileName);
//高速自定义图像格式
int YtSAPI YtSaveYtImageH(QImage InIm, YtAllBlob &BlobData, QString FileNmae, int Perset=80);
int YtSAPI YtLoadYtImageH(QImage &OutIm, YtAllBlob &BlobData, QString FileName);


#endif // YTBASEOBJECT_H
