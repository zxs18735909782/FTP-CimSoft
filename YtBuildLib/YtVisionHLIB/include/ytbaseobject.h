#ifndef YTBASEOBJECT_H
#define YTBASEOBJECT_H
#include <QImage>
#include <QPointF>
#include <QRectF>
#include "ytbasedefine.h"
#include "ytblobdefine.h"
///////////////////////////
//��QImage������չ,ʹ���ܹ�֧���ڴ���ط�����;����
//ʹ��Qimage��ǳ�����Ϳ���ʵ���ڴ湲��
class YtSAPI YtInterIm
{
    //�˶������ڹ����㷨ִ��dll���м����
    //�洢�м乲���ڴ�ı��������㴫��ʹ��
private:
    uchar * data;
    int width;
    int height;
    int bytesPerLine;
    int format;//��¼�м���أ�
    QImage mIM;//�ڲ�����
public:
    YtInterIm(uchar * data=nullptr, int width=400, int height=400, int bytesPerLine=400, int format=QImage::Format_Grayscale8);
    void toSetQimamage(QImage im);//����ͼ��ǳ����
    void toSetCloenImage(QImage im);//����ͼ�����
    QImage toGetIm();//�ó�����
    void toSetData(uchar * data=nullptr, int width=400, int height=400, int bytesPerLine=400, int format=QImage::Format_Grayscale8);
public:
    //�������÷���
    bool LoadFile(QString filename);
    bool SaveFile(const QString &fileName, const char *format = Q_NULLPTR, int quality=-1);
    //��ȡͼ��ָ��
    unsigned char * GetImageData(unsigned int nX = 0, unsigned int nY = 0);
    //���յ�ͨ����ȡ�Ҷ�ֵ
    int GetGrayVal(unsigned int nX = 0, unsigned int nY = 0);
    //��ȡͼ����
    int GetImageWidth();
    //��ȡͼ��߶�
    int GetImageHight();
    //��ȡͼ������
    int GetImageType();
};
//����һЩ�����������͵Ĺ���,��Qt�����������໥ת��
QPointF  YtSAPI YtMVPointToQpoint(CMvPoint tempoint);
CMvPoint YtSAPI YtQpointToMvPoint(QPointF tempoint);
//�߶�ת��
CMvLineSeg YtSAPI YtQlineToMvLine(QLineF temline);//ֱ�߹���ת��
double YtSAPI YtMvLineSegAng(CMvLineSeg temline);//ֱ�߽Ƕȼ���
double YtSAPI YtMvLineSegLenth(CMvLineSeg temline);//ֱ�߳��ȼ���
CMvPoint YtSAPI YtMvLineSegCenter(CMvLineSeg temline);//��ȡֱ�ߵ��е�
//������
CMvRect YtSAPI YtQRectToMvRect(QRectF temrect);
double YtSAPI YtMvRectWidth(CMvRect temrect);//��ȡ���
double YtSAPI YtMvRectHeight(CMvRect temrect);//��ȡ�߶�
CMvPoint YtSAPI YtMvRectCenter(CMvRect temrect);//�����ε�����
//��ת���ε��������
CMvRotatedRect YtSAPI YtCreateRoTatedRect(double cx = 0, double cy = 0, double w = 0, double h = 0, double angle = 0);//������ת����
CMvRotatedRect YtSAPI YtCreateRoTatedRect( QPointF center,QSizeF size, double angle);//������ת����
//  pts[0] ------------ pts[1]
//         |          |
//         |          |
//         |    -->   O  ��ͷ����Ϊ������. �Ƕ�����ʱ��Ϊ��(��Qt/Halcon����һ��, ��OpenCv�����෴)
//         |          |
//         |          |
//  pts[3] ------------ pts[2]
int YtSAPI YtRotatedRectPoints(CMvRotatedRect &inrect,QPointF (&GetPoints)[4]);
int YtSAPI YtRotatedRectPoints(CMvRotatedRect &inrect,CMvPoint (&GetPoints)[4]);
//��ȡ��ת�������������
QRectF YtSAPI YtGetRotatedRectMaxRect(CMvRotatedRect &inrect);
CMvRect YtSAPI YtGetRotatedRectMaxMRect(CMvRotatedRect &inrect);
//����һЩ�����ӿ�
//��qimage���ж�д
//��ȡͼ��ӿ�
bool YtSAPI toLoadQImage(QImage &OutIm,QString FileName);
//д��ͼ��ӿ�
bool YtSAPI toSaveQImage(QImage &InIm, QString FileNmae, int Perset=80);
//�ڴ�ͼ��ѹ��ת�ڴ�ͼ��
int YtSAPI YtHCodeJpgeN(unsigned char* im, int imwidth, int imheight, int changle, unsigned char *OutData,int &OutSize, int perset = 80);
//���ڴ����jpgeͼ��
int YtSAPI YtHDecodeJpegN(QImage &Inim, unsigned char* imdata,int size);
int YtSAPI YtHDecodeJpegN(YtInterIm &Inim, unsigned char* imdata,int size);
//����jpgͼ��
int YtSAPI YtHDoImageToJpg(QImage &Inim, QString filename, int perset = 80);
int YtSAPI YtHDoImageToJpg(YtInterIm &Inim, QString filename, int perset = 80);
//��ȡjpgͼ��
int YtSAPI YtHDoReadJpgN(QImage & Inim, QString filename);
int YtSAPI YtHDoReadJpgN(YtInterIm & Inim, QString filename);
//�Զ���ͼ���ʽ
int YtSAPI YtSaveYtImage(QImage &Inim,YtAllBlob &BlobData,QString FileNmae, int Perset=80);
int YtSAPI YtLoadYtImage(QImage &OutIm, YtAllBlob &BlobData, QString FileName);
//�����Զ���ͼ���ʽ
int YtSAPI YtSaveYtImageH(QImage InIm, YtAllBlob &BlobData, QString FileNmae, int Perset=80);
int YtSAPI YtLoadYtImageH(QImage &OutIm, YtAllBlob &BlobData, QString FileName);


#endif // YTBASEOBJECT_H
