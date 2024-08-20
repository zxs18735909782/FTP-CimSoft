#ifndef YTHANDQALGO_H
#define YTHANDQALGO_H
#include "ytbaseobject.h"
#include "ytoverplay.h"
#include <halconcpp/HalconCpp.h>
#include <halconcpp/HDevThread.h>
using namespace HalconCpp;
//通过构建HobjectIm 共享到自建图像内存绑定，只针对c18u图像
//后面碰到新的图像类型再进行完善
int YtSAPI toShareMQimage(HObject &Inim,YtInterIm &OutIm);
//构建内存组对
int YtSAPI toCreateSizeHQImage(HObject &Inim,YtInterIm &OutImage,int width,int hight);
//采集内存转移 Qimage to Himage
int YtSAPI toCopyQToHImage(YtInterIm &InQim,HObject &OutImag);
//构建基础处理函数，把基本算子进行包装，方便后期对界面代码的复用
//获取xld 或者regin的 边缘点方便绘制
int YtSAPI toGetXldPointS(HObject &Txld, QVector<QVector<CMvPoint> > &toutPoint);
//获取regon的边缘点，进行绘制
int YtSAPI toGetRegionPointS(HObject &tReg,QVector<QVector<CMvPoint> > &toutPoint);

//设计一个找边的class导出类
class YtSAPI YtHFindLineDo
{
public:
    YtHFindLineDo();
    ~YtHFindLineDo();
private:
    //////////
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值
    //////////////
    QVector<CMvPoint> m_GetPoints;
    QVector<CMvRotatedRect> m_OutRectc;

public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
        Strangest,//最强点
    };
public:
    //给一张图像输出线
    bool toGetLineRestul(HObject &inim, CMvLineSeg &OutLine, CMvLineSeg inSegLine);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<CMvRotatedRect> &OutP);
    //设置测量值,NumM 把线段分割 NumM 个像素的 方格
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int NumM=7,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval,int &tMtran,int &tMSel,int &NumM,double &Sigma,double &score);
};
//////////////////////
//设计一个找圆的的算子
class YtSAPI YtHFindCircleDo
{
public:
    YtHFindCircleDo();
    ~YtHFindCircleDo();
private:
    HTuple MetrologyHandle;//测量句柄
    HTuple mRow,mColumn;//找到的边缘点
    HObject mContours;//查找轮廓
    //////////
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值
public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
    };
public:
    //给一张图像输出线，len1 len2 必须为整数
    bool toGetCircleRestul(HObject &inim, CMvCircle &OutCircle, CMvCircle inCircle, double len1=15, double len2=5);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<QVector<CMvPoint> > &OutP);
    //设置测量值
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int NumM=7,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval,int &tMtran,int &tMSel,int &NumM,double &Sigma,double &score);
};
////////////////////////
//设计一个找圆弧的的算子
class YtSAPI YtHFindCircArcleDo
{
public:
    YtHFindCircArcleDo();
    ~YtHFindCircArcleDo();
private:
    HTuple MetrologyHandle;//测量句柄
    HTuple mRow,mColumn;//找到的边缘点
    HObject mContours;//查找轮廓
    //////////
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值
public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
    };
public:

    //给一张图像输出线
    bool toGetCircleArcRestul(HObject &inim,CMvCircle &OutCircleArc,CMvArc inCircle, double len1=100, double len2=100);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<QVector<CMvPoint> > &OutP);
    //设置测量值
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int nCalipNum=5,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval, int &tMtran, int &tMSel, int &NumM,double &Sigma, double &score);
};

//设计一个找椭圆的的算子
class YtSAPI YtHFindEllipseDo
{
public:
    YtHFindEllipseDo();
    ~YtHFindEllipseDo();
private:
    HTuple MetrologyHandle;//测量句柄
    HTuple mRow,mColumn;//找到的边缘点
    HObject mContours;//查找轮廓
    //////////
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值
public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
    };
public:
    //给一张图像输出线
    bool toGetYtHFindEllipseDoRestul(HObject &inim,CMvEllipse &OutRotatedRect,CMvEllipse RotatedRect, double len1=100, double len2=100);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<QVector<CMvPoint> > &OutP);
    //设置测量值
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int nCalipNum=5,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval, int &tMtran, int &tMSel, int &NumM,double &Sigma, double &score);
};

//设计一个找距形的的算子
class YtSAPI YtHFindRectDo
{
public:
    YtHFindRectDo();
    ~YtHFindRectDo();
private:
    HTuple MetrologyHandle;//测量句柄
    HTuple mRow,mColumn;//找到的边缘点
    HObject mContours;//查找轮廓
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值
public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
    };
public:
    //给一张图像输出线
    bool toGetRectRestul(HObject &inim,CMvRect &OutRect,CMvRect Rect, double len1=100, double len2=100);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<QVector<CMvPoint> > &OutP);
    //设置测量值
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int nCalipNum=5,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval, int &tMtran, int &tMSel, int &NumM,double &Sigma, double &score);
};

//设计一个找斜距形的的算子
class YtSAPI YtHFindRotateRect2Do
{
public:
    YtHFindRotateRect2Do();
    ~YtHFindRotateRect2Do();
private:
    HTuple MetrologyHandle;//测量句柄
    HTuple mRow,mColumn;//找到的边缘点
    HObject mContours;//查找轮廓
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值
public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
    };
public:
    //给一张图像输出线
    bool toGetRotatedRectRestul(HObject &inim,CMvRotatedRect &OutRotatedRect,CMvRotatedRect RotatedRect, double len1=100, double len2=100);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<QVector<CMvPoint> > &OutP);
    //设置测量值
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int nCalipNum=5,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval, int &tMtran, int &tMSel, int &NumM,double &Sigma, double &score);
};

/////////////////////
//设计一个线线构建交点的方法
bool YtSAPI YtGetPointByTwoLine(CMvLineSeg inline1,CMvLineSeg inline2,CMvPoint &outPoint);
//计算点到线的距离,记录垂足
bool YtSAPI YTGetLentByPointToLine(CMvPoint inPoint,CMvPoint inline1,CMvPoint &OutP,double &OutLenth);
//计算点到点的距离
bool YtSAPI YtGetLenByPointToPoint(CMvPoint inPoint1,CMvPoint inPoint2,double &OutLenth);
//构建一个坐标系统转换的类，可以转换图像，区域，xld，以及点
class YtSAPI YtHomtAxis
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
//构建一个ncc模板匹配的计算类
class YtSAPI YtFindNccModel
{
public:
    YtFindNccModel();
    ~YtFindNccModel();
private:
    HTuple m_ModelID;//模型句柄

public:
    //创建模板用户需要提供，建模图像，此建模图像直接裁切出去的小图
    bool toCreateNccMode(HObject &inim,double AngStart,double AngEnd,double AngStep,int NUmLevel);
    //根据输入图像查找
    bool toFindNccMode(HObject &inim, double AngStart, double AngEnd, double minScor, double MaxOvePla, CMvPoint &OutPoint, double &OutAng);
    //保存NCC模板,提供一个路径即可
    bool toSaveNccMode(QString Path);
    //读取NCC模板，提供一个路径即可
    bool toLoadNccMode(QString Path);
};
//构建一个查找shape 匹配的
class YtSAPI YtFindShapeModel
{
public:
    YtFindShapeModel();
    ~YtFindShapeModel();
private:
    HTuple m_ModelID;//模型句柄
    //double m_AngStart,m_AngEnd;
    //int m_Constrc;//梯度阈值
public:
    //创建形状目标，根据图像起始角度，金字塔层数，边缘提取
    bool toCreateShapeMode(HObject &inim, double AngStart,double AngEnd,double AngStep,int NUmLevel,int Contrast);
    //得到计算特征点
    bool toGetShapePoints(HObject &inm, HObject &Roi, QVector<QVector<CMvPoint> > &toutPoint, int Contrast = 0);
    //根据输入图像查找
    bool toFindShapeMode(HObject &inim, double AngStart, double AngEnd, double minScor,double MaxOvePla,CMvPoint &OutPoint,double &OutAng);
    //保存NCC模板,提供一个路径即可
    bool toSaveShapeMode(QString Path);
    //读取NCC模板，提供一个路径即可
    bool toLoadShapeMode(QString Path);

};
//构建一个自动标定计算生成算子
bool YtSAPI toHomat2DSetModeImage(HObject &Inim, YtStOverPlayObj &OutPut,int thval);
//映射坐标生成变换阵,返回msa 均方差
double YtSAPI toGenHomat2DMultiPoint(HTuple &tHomMat2D, YtStOverPlayObj &OutPut, double x, double y, double tscalx, double tscaly);
//region转换颜色绘制
int YtSAPI YtHRegionToColorImage(HObject &Inreg, QImage &OutShowim, QVector<QRgb> &sColorTable, int imagewidth, int imagehight,bool isfill=true);

//构建一个查找ansio shape 匹配的
//class YtSAPI YtFindAnisoShapeModel
//{
//public:
//    YtFindAnisoShapeModel();
//    ~YtFindAnisoShapeModel();
//private:
//    HTuple m_ModelID;//模型句柄
//    //double m_AngStart,m_AngEnd;
//    //int m_Constrc;//梯度阈值
//public:
//    //创建形状目标，根据图像起始角度，金字塔层数，边缘提取
//    bool toCreateShapeMode(HObject &inim, double AngStart,double AngEnd,double AngStep,int NUmLevel,int Contrast);
//    //得到计算特征点
//    bool toGetShapePoints(HObject &inm, HObject &Roi, QVector<QVector<CMvPoint> > &toutPoint, int Contrast = 0);
//    //根据输入图像查找
//    bool toFindShapeMode(HObject &inim, double AngStart, double AngEnd, double minScor,double MaxOvePla,CMvPoint &OutPoint,double &OutAng);
//    //保存NCC模板,提供一个路径即可
//    bool toSaveShapeMode(QString Path);
//    //读取NCC模板，提供一个路径即可
//    bool toLoadShapeMode(QString Path);

//};
//设计一个找边的class导出类
class YtSAPI YtMHFindLineDo
{
public:
    YtMHFindLineDo();
    ~YtMHFindLineDo();
private:
    HTuple MetrologyHandle;//测量句柄
    HTuple mRow,mColumn;//找到的边缘点
    HObject mContours;//查找轮廓
    //////////
    QString mMTran,mMSel;//传输计算以及点选择
    int mThVal;//阈值分割
    double mScore;//最小得分
    int mNumM;//卡尺个数
    double mSigma;//平滑阈值

public:
    enum MTran
    {
       //点计算模式
      WToB,//白到黑
      BToW,//黑到白
      TALL,//所有
      UniF,//统一
    };
    enum MSel
    {
        First,//第一个点
        End,//终点
        SALL,//所有
    };
public:
    //给一张图像输出线
    bool toGetLineRestul(HObject &inim, CMvLineSeg &OutLine, CMvLineSeg inSegLine);
    //获取找到的边缘点
    void toGetRestPoints(QVector<CMvPoint> &OutP);
    //绘制查找线宽
    void toGetXldPoindS(QVector<QVector<CMvPoint> > &OutP);
    //设置测量值,NumM 把线段分割 NumM 个像素的 方格
    void toSetMeasurVal(int thval=30,MTran tMtran=MTran::WToB,MSel tMSel=MSel::First,int NumM=7,double Sigma=1.0,double score=0.7);
    //获取测量参数值
    void toGetMeasurVal(int &thval,int &tMtran,int &tMSel,int &NumM,double &Sigma,double &score);
};




















#endif // YTHANDQALGO_H
