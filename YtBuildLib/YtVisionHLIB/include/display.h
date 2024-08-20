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
    //�̶���ͼ����ָ��
    typedef QMap<QString,  void*> ItemMap;
    ItemMap m_StdOverPlayItemMap;//�洢�̶���ͼmap
    //ͼ����ͼ����ָ��
    ItemMap m_OverPlayItemMap;//�洢map
    //

signals:    
    void toGetPixInfo(QPoint Pos, QRgb rgb,int type);//��ȡ�Ҷ�ֵ��Ӧ
    void toLeftDoubleOut(QString key);
    void toRightClick(QString key);
public:
    void toSetBGColor(QColor color);//���ñ���ɫ
    void toSetImage(QImage showim);//
    void toSetImageData(unsigned char *imagedata,int imwidth,int imhieht,int chanle=1);//�Ƿ�Ϊ��פ�ڴ棬�ǵĻ������ڴ�࿪
    void toUpdateShow(bool iszoom=false);//ˢ����ʾ
    /////////////////
    void toLoadFileImage(QString &filename);//�ļ�������ͼ��
    void toViewPoint( double centerx=0, double centery=0,double scale=1.0);//�������ű�������ʾ����������
public:
     //�̶����� ��ϵ
     void addStdOverPlayPtr(void* tpart,QString key="test");
     void removeStdOverPlayPtr(QString key="test");
     void ClearAllStdOverPlayPtr();
     //ͼ����ͼ����
     void addOverPlayPtr(void* tpart,QString key="test");
     void removeOverPlayPtr(QString key="test");
     void ClearAllOverPlayPtr();
public:
     void toSetLeftDoubleMode(int t=0,QString key="1");//0 Ϊ����ģʽ��

};

#endif // DISPLAY_H
