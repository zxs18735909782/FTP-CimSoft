#ifndef YTCIMSCRIPT_H
#define YTCIMSCRIPT_H

#include <QObject>
#include <QTime>

#include "ytlogprolib.h"
#include "YtNetWorkDo.h"
#include "ytbasedefine.h"
#include "ytblobdefine.h"
#include "ytbaseobject.h"
#include "ytplcdo.h"


class YtCimScript : public QObject
{
    Q_OBJECT
public:
    explicit YtCimScript(QObject *parent = nullptr);
    ~YtCimScript();

public:
    bool            m_RunState = false;
    bool            m_flag = false;             //表示是否是第一次运行

    YtNetWorkDo*    m_YtFTPNetWorkDo = nullptr;
    YtNetWorkDo*    m_YtShareFolderNetWorkDo = nullptr;
    YtNetWorkDo*    m_YtSQLNetWork = nullptr;
    YtPlcDo*        m_YtPlcDo       = nullptr;

    QStringList     m_PanelIDList;
    QStringList     m_BlobFileList;

    QStringList     m_SigelInfo;            //解析数据库的信息

    QDateTime       m_dateTime = QDateTime::currentDateTime();
    QString         m_recordTime;

public:
    Q_INVOKABLE void toPrintlog(QString logContent, QString color);

    //读取产品ID
    Q_INVOKABLE QString toGetPanelID();

    //延时
    Q_INVOKABLE void toSleep(int msec);

    //获取Blob信息  参数1:产品ID  参数2:工厂名称   参数3:图片命名填充  参数4:时间字符串 参数5:玻璃短边比例尺 参数6:玻璃长边比例尺
    Q_INVOKABLE QStringList toGetDefectInfo(QString PanelID, QString Factory, QString fillContent,QString time,int face_num = 2, double scale_x = 0.025,double scale_y = 0.025);

    //获取服务器的大图blob缺陷信息
    Q_INVOKABLE QStringList toGetBigImDefectInfo(QString PanelID, QString Factory, QString fillContent, QString time,int face_num = 2, double scale_x = 0.025, double scale_y = 0.025);

    //参数1:FTP上传标题 参数2:上传标题的分割符号  参数3:上传内容的填充字符  参数4:上传内容的分隔符号
    Q_INVOKABLE QString toCombinaFtpContent(QString titleContent, QString splitSig1, QString FillSig, QString splitSig2);

    //组装特定的内容   参数1:需要更新的字符串 参数2:参数1的分隔符  参数3:填充字符串 参数4:参数3的分隔符  参数5:参数4的分隔符
    Q_INVOKABLE QString toFillSpecialSig(QString FillContent, QString splitSig1, QString fillSig, QString splitSig2, QString splitSig3);

    //获取时间戳  参数1:获取的长度
    Q_INVOKABLE QString toGetTimepoint(int length);

    //获取文件内容
    Q_INVOKABLE QString toGetTextContent(QString PanelID, QString filePath, QString fileType, QString MatchContent, bool isDel);

    //直接解析上传文件  参数1:本地文件路径  参数2：文件类型  参数3:FTP固定路径  参数4:FTP活动路径
    Q_INVOKABLE bool toParseFileAndPut(QString filePath, QString fileType, QString FtpFilePath, QString unControlPath);

    Q_INVOKABLE QStringList toGetFileList(QString filePath,QString FileType);

    /************************************FTP上传文件*******************************************/
    //下载文件
    Q_INVOKABLE bool toDownLoadFile(QString Panel_ID, QString FtpFilePath, QString SavePath, QString FileType);

    //上传文件 参数1:产品id 参数2:ID是否大写 参数3:ftp固定的路径  参数4:id的长度截断 参数5:变化的路径 参数6:上传的内容  参数7:文件后缀
    Q_INVOKABLE bool toUploadFile(QString PanelID, bool isUpper, QString FtpFilePath, QString FileName, QString unControlPath,QString UploadContent, QString FileLastName, QString FileType);

    /************************************数据库文件操作*******************************************/
    //查询指定的信息
    Q_INVOKABLE bool QueryProductInfo(QString QueryContent, QString QueryTable, int queryTime);

    //返回单条信息
    Q_INVOKABLE QString ParseSigleInfo();

    //解析单条信息
    Q_INVOKABLE QStringList ParseProductDefectInfo(QString QueryContent, QString sigleInfo,double scale_x = 0.025,double scale_y = 0.025);


    /************************************搜索第三方文件*******************************************/
    Q_INVOKABLE QStringList getOtherFile(QString filePath, int Sec);

    /************************************PLC交互*******************************************/
    Q_INVOKABLE void toWriteQString(QString WritAdr, QString val);
    Q_INVOKABLE QString toReadQString(QString ReadAdr, int len); //读取字符串

    /************************************ini文件交互*******************************************/
    Q_INVOKABLE QString toReadIni(QString filePath, QString productName);

private:
    void toLoadSmallBlobIm(QVector<QImage> &OutImList, QString filename);

    bool YTLoadBlobFile(YtAllBlob &blobfile, QString filename);

signals:
    void onSignalSendIndexOut(int index, QString content);

public slots:
    void getSignalOut(int index, QString content);



};

#endif // YTCIMSCRIPT_H
