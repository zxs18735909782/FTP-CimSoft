#ifndef YTLOGPROLIB_H
#define YTLOGPROLIB_H
#include <QWidget>
#include <QColor>
#include <QtCore/qglobal.h>
#include <QString>
#include <QColor>
#include <QVector>

#define YtLogEndL           "qendl"             // ������ʾ���ұ����ļ�
#define YtLogEndL_OnlySave  "qendl_only_save"   // ֻ���治��ʾ
#define YtLogEndL_OnlyShow  "qendl_only_show"   // ֻ��ʾ������

//�⽫��һ�����д������õı�Ҫ�࣬���Ա�Ҫ�Ķ���������
#ifndef _DELETE_POINT_
#define _DELETE_POINT_(ptr)             \
    if((##ptr) != nullptr) {                \
    delete (##ptr);                     \
    (##ptr) = nullptr;                  \
    }
#endif
typedef enum
{
    InfoLog = 0,//������Ϣ��־
    WaringLog,//������־����Ӱ����������ǳ����쳣
    FatlLog,//����������ܻ�Ӱ�쵽
}LOG_LEVEL;

// ��־ģʽ
typedef enum
{
    kLogShowAndSave = 0, // ������ʾ���ұ����ļ�
    kLogOnlySave,        // ֻ�����ļ�
    kLogOnlyShow         // ֻ������ʾ
}ENUM_LOG_TYPE;
typedef enum
{
    YtTop,
    YtBottom,
    YtLeft,
    YtRight,
}ShowTie;
class Q_DECL_EXPORT YtqDebug
{
public:
    YtqDebug(QString logename,int type,QColor tcor= Qt::red);
    YtqDebug(QString logename=u8"ϵͳ��־",QColor tcor=Qt::red);

    void AddLoginfo(QString data);
    QString GetLoginfo();
    QColor GetColorShow();
    int GetLogType();
    QString GetLogName();
private:
    QString m_LogNmae;//��д��־������
    int m_type;//��־�ĵȼ�
    QColor m_Color;
    QString m_SaveStr;
public:
    YtqDebug  &operator<<(QString  c);
    YtqDebug  &operator<<(int  c);
    YtqDebug  &operator<<(double  c);
    YtqDebug  &operator<<(float  c);
    YtqDebug  &operator<<(long  c);
    YtqDebug  &operator<<(QStringList  c);
    template <typename T>
    YtqDebug  &operator<<(QVector<T>  c);
};
void Q_DECL_EXPORT toSetInnerShowType(int ShowType=YtLeft,QColor UiColor=Qt::white);
void Q_DECL_EXPORT toInitLogoProcDo(int ShoeType=kLogShowAndSave,int SaveTime=1);//��ʼ����־�ںˣ���¼����Ŀ�ʼʱ�䲢��ɾ��
void Q_DECL_EXPORT toCloseLogoProDo();//����
Q_DECL_EXPORT QWidget *toGetLogoWindow(QColor UiColor=Qt::white, int Showtype=YtLeft);//�����ڴ���һ����־����ʱ�������и�Ĭ�ϵĴ��ڣ����tabҳ����ʾ���ƾ�logowidname����־������ֻ��һ��
void Q_DECL_EXPORT toApendWidTab(QString strLogName);//�߳������ֵ���־����ֻ���ڼ���ģ���ʱ����ܴ�ӡ��������־��������Ҫ���߳̿�ʼ��ʱ��һ��һ�������洫��
void Q_DECL_EXPORT toPrintLog(QString logo,QColor logcore=Qt::green,int logLevel=InfoLog,QString tabname=u8"ϵͳ��־");
void Q_DECL_EXPORT toSetCurentTab(QString TabName);//���õ�ǰ��ʾtab
void Q_DECL_EXPORT toReMoveAllTab();
void Q_DECL_EXPORT toReMoveTab(QString TabName);




#endif // YTLOGPROLIB_H
