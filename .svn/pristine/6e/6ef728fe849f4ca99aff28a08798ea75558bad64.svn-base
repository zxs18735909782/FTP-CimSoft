#ifndef DISPLAY_H
#define DISPLAY_H
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QMap>
namespace Ui {
class Display;
}
class QDESIGNER_WIDGET_EXPORT Display : public QWidget
{
    Q_OBJECT
public:
    explicit Display(QWidget *parent = 0);
    ~Display();

private:
    Ui::Display *ui;
    //固定视图绘制指针
    typedef QMap<QString,  void*> ItemMap;
    ItemMap m_StdOverPlayItemMap;//存储固定视图map
    //图像视图绘制指针
    ItemMap m_OverPlayItemMap;//存储map
    //

signals:    
    void toGetPixInfo(QPoint Pos, QRgb rgb,int type);//获取灰度值响应
    void toLeftDoubleOut(QString key);
    void toRightClick(QString key);
public:
    void toSetBGColor(QColor color);//设置背景色
    void toSetImage(QImage showim);//
    void toSetImageData(unsigned char *imagedata,int imwidth,int imhieht,int chanle=1);//是否为常驻内存，是的话避免内存多开
    void toUpdateShow(bool iszoom=false);//刷新显示
    /////////////////
    void toLoadFileImage(QString &filename);//文件名载入图像
    void toViewPoint( double centerx=0, double centery=0,double scale=1.0);//按照缩放倍数把显示点拉到中心
public:
     //固定绘制 体系
     void addStdOverPlayPtr(void* tpart,QString key="test");
     void removeStdOverPlayPtr(QString key="test");
     void ClearAllStdOverPlayPtr();
     //图像视图绘制
     void addOverPlayPtr(void* tpart,QString key="test");
     void removeOverPlayPtr(QString key="test");
     void ClearAllOverPlayPtr();
public:
     void toSetLeftDoubleMode(int t=0,QString key="1");//0 为正常模式，

};

#endif // DISPLAY_H
