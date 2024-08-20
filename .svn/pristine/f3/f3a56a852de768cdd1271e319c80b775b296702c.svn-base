#ifndef YTLOGPROLIB_H
#define YTLOGPROLIB_H
#include <QWidget>
#include <QColor>
#include <QtCore/qglobal.h>
#include <QString>
#include <QColor>
#include <QVector>

#define YtLogEndL           "qendl"             // 正常显示并且保存文件
#define YtLogEndL_OnlySave  "qendl_only_save"   // 只保存不显示
#define YtLogEndL_OnlyShow  "qendl_only_show"   // 只显示不保存

//这将是一个所有处理类用的必要类，所以必要的定义做完整
#ifndef _DELETE_POINT_
#define _DELETE_POINT_(ptr)             \
    if((##ptr) != nullptr) {                \
    delete (##ptr);                     \
    (##ptr) = nullptr;                  \
    }
#endif
typedef enum
{
    InfoLog = 0,//基本信息日志
    WaringLog,//警告日志，不影响崩溃，但是出现异常
    FatlLog,//致命错误可能会影响到
}LOG_LEVEL;

// 日志模式
typedef enum
{
    kLogShowAndSave = 0, // 界面显示并且保存文件
    kLogOnlySave,        // 只保存文件
    kLogOnlyShow         // 只界面显示
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
    YtqDebug(QString logename=u8"系统日志",QColor tcor=Qt::red);

    void AddLoginfo(QString data);
    QString GetLoginfo();
    QColor GetColorShow();
    int GetLogType();
    QString GetLogName();
private:
    QString m_LogNmae;//书写日志的名称
    int m_type;//日志的等级
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
void Q_DECL_EXPORT toInitLogoProcDo(int ShoeType=kLogShowAndSave,int SaveTime=1);//初始化日志内核，记录软件的开始时间并且删除
void Q_DECL_EXPORT toCloseLogoProDo();//结束
Q_DECL_EXPORT QWidget *toGetLogoWindow(QColor UiColor=Qt::white, int Showtype=YtLeft);//我们在创建一个日志窗口时，避让有个默认的窗口，这个tab页的显示名称就logowidname，日志区还是只有一个
void Q_DECL_EXPORT toApendWidTab(QString strLogName);//线程所呈现的日志往往只能在加载模板的时候才能打印，所以日志的名字需要从线程开始的时候一层一层向里面传递
void Q_DECL_EXPORT toPrintLog(QString logo,QColor logcore=Qt::green,int logLevel=InfoLog,QString tabname=u8"系统日志");
void Q_DECL_EXPORT toSetCurentTab(QString TabName);//设置当前显示tab
void Q_DECL_EXPORT toReMoveAllTab();
void Q_DECL_EXPORT toReMoveTab(QString TabName);




#endif // YTLOGPROLIB_H
