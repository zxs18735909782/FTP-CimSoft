#ifndef YtSuperDisPlay_H
#define YtSuperDisPlay_H
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QMap>
namespace Ui {
class YtSuperDisPlay;
}
class QDESIGNER_WIDGET_EXPORT YtSuperDisPlay : public QWidget
{
    Q_OBJECT

public:
    explicit YtSuperDisPlay(QWidget *parent = 0);
    ~YtSuperDisPlay();
    enum RotaeShape
    {
        ROTAE0,//旋转角度
        ROTAE90,
        ROTAE180,
        RORAE270,
    };
private:
    //ROI的list存储
     typedef QMap<QString,  void*> ItemMap;
     //视图绘制指针
     ItemMap m_OverPlayItemMap;//存储map
public:
    void toSetBackgroundColor(QColor ucolor=QColor(128,128,128));//设置背景色
    void toSetReset();//重置显示
    void toSetQImage(QImage Inim,int type=RotaeShape::ROTAE0);//显示图像
    void toViewPoint(int x=100, int y=100, double dscal=1.0);//固定比例查看
    void toResetPos(int type=RotaeShape::ROTAE0,bool xTran=false,bool yTran=false);
public:
     //绘制 体系
     void addOverPlayPtr(void* tpart,QString key="test");
     void removeOverPlayPtr(QString key="test");
     void ClearAllOverPlayPtr();
     void toUpdateShow();//刷新显示
public:
     void toLoadFileImage(QString filename, int type=RotaeShape::ROTAE0);
private:
    Ui::YtSuperDisPlay *ui;

};

#endif // YtSuperDisPlay_H
