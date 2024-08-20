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
        circleROI = 0,      //Բ��ROI
        ellipseROI = 1,     //��ԲROI
        rectangleROI = 2,   //����ROI
        rotaterectangleROI = 3,//��ת����ROI
        lineROI = 4,        //ֱ��ROI
        arcROI = 5,         //����ROI
        ringROI = 6,        //Բ��ROI
        polygonROI = 7,     //�����ROI
        waistROI = 8,       //����ROI
        pieROI = 9,          //����ROI
        pointROI = 10 ,       //��ROI
        polygonROIE = 11     //���ROI,��ѭ���㼯
    };
private:
    //ROI��list�洢
     typedef QMap<QString,  void*> ItemMap;
     ItemMap m_ListItemMap;//�洢map
     typedef QMap<QString,  int> ItemMapType;
     ItemMapType m_ListItemMapType;//�洢map type
     //��ͼ����ָ��
     ItemMap m_OverPlayItemMap;//�洢map
public:
    void toSetBackgroundColor(QColor ucolor=QColor(128,128,128));//���ñ���ɫ
    void toSetReset();//������ʾ
    void toSetQImage(QImage Inim);//��ʾͼ��
    void toViewPoint(int x=100, int y=100, double dscal=1.0);//�̶������鿴
public:
    //ROI ��ϵ
     void addROI(ROIShape shape, QVector<double> Val, QString key="Test");//����ROI
     QVector<double> getROI(QString key="Test");//��ȡROI
public:
     //���� ��ϵ
     void addOverPlayPtr(void* tpart,QString key="test");
     void removeOverPlayPtr(QString key="test");
     void ClearAllOverPlayPtr();
     void toUpdateShow();//ˢ����ʾ


private:
    Ui::YtDisplayDoW *ui;
signals:
    void ROIChange(QVector<double> tdata,QString &key,int type);

private slots:
    void SigROIChange(QVector<double> tdata,QString &key,int type);
public:
    void toRemoveRoiByKey(QString key="Test");//б���Σ�Բ��
    void toRemoveAllRoi();//������е�ROI
};

#endif // YTDISPLAYDOW_H
