#ifndef YTDISPLAYDOW_H
#define YTDISPLAYDOW_H
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QMap>
namespace Ui {
class YtDisplayDoW;
}
class QDESIGNER_WIDGET_EXPORT YtDisplayDoW : public QWidget
{
    Q_OBJECT

public:
    explicit YtDisplayDoW(QWidget *parent = 0);
    ~YtDisplayDoW();
    enum ROIShape {
        circleROI = 0,      //圆形ROI
        ellipseROI = 1,     //椭圆ROI
        rectangleROI = 2,   //矩形ROI
        rotaterectangleROI = 3,//旋转矩形ROI
        lineROI = 4,        //直线ROI
        arcROI = 5,         //弧形ROI
        ringROI = 6,        //圆环ROI
        polygonROI = 7,     //多边形ROI
        waistROI = 8,       //腰形ROI
        pieROI = 9,          //扇形ROI
        pointROI = 10 ,       //点ROI
        polygonROIE = 11     //多边ROI,非循环点集
    };
private:
    //ROI的list存储
     typedef QMap<QString,  void*> ItemMap;
     ItemMap m_ListItemMap;//存储map
     typedef QMap<QString,  int> ItemMapType;
     ItemMapType m_ListItemMapType;//存储map type
     //视图绘制指针
     ItemMap m_OverPlayItemMap;//存储map
public:
    void toSetBackgroundColor(QColor ucolor=QColor(128,128,128));//设置背景色
    void toSetReset();//重置显示
    void toSetQImage(QImage Inim);//显示图像
    void toViewPoint(int x=100, int y=100, double dscal=1.0);//固定比例查看
public:
    //ROI 体系
     void addROI(ROIShape shape, QVector<double> Val, QString key="Test");//增加ROI
     QVector<double> getROI(QString key="Test");//获取ROI
public:
     //绘制 体系
     void addOverPlayPtr(void* tpart,QString key="test");
     void removeOverPlayPtr(QString key="test");
     void ClearAllOverPlayPtr();
     void toUpdateShow();//刷新显示


private:
    Ui::YtDisplayDoW *ui;
signals:
    void ROIChange(QVector<double> tdata,QString &key,int type);

private slots:
    void SigROIChange(QVector<double> tdata,QString &key,int type);
public:
    void toRemoveRoiByKey(QString key="Test");//斜矩形，圆弧
    void toRemoveAllRoi();//清除所有的ROI
};

#endif // YTDISPLAYDOW_H
