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
    bool            m_flag = false;             //��ʾ�Ƿ��ǵ�һ������

    YtNetWorkDo*    m_YtFTPNetWorkDo = nullptr;
    YtNetWorkDo*    m_YtShareFolderNetWorkDo = nullptr;
    YtNetWorkDo*    m_YtSQLNetWork = nullptr;
    YtPlcDo*        m_YtPlcDo       = nullptr;

    QStringList     m_PanelIDList;
    QStringList     m_BlobFileList;

    QStringList     m_SigelInfo;            //�������ݿ����Ϣ

    QDateTime       m_dateTime = QDateTime::currentDateTime();
    QString         m_recordTime;

public:
    Q_INVOKABLE void toPrintlog(QString logContent, QString color);

    //��ȡ��ƷID
    Q_INVOKABLE QString toGetPanelID();

    //��ʱ
    Q_INVOKABLE void toSleep(int msec);

    //��ȡBlob��Ϣ  ����1:��ƷID  ����2:��������   ����3:ͼƬ�������  ����4:ʱ���ַ��� ����5:�����̱߱����� ����6:�������߱�����
    Q_INVOKABLE QStringList toGetDefectInfo(QString PanelID, QString Factory, QString fillContent,QString time,int face_num = 2, double scale_x = 0.025,double scale_y = 0.025);

    //��ȡ�������Ĵ�ͼblobȱ����Ϣ
    Q_INVOKABLE QStringList toGetBigImDefectInfo(QString PanelID, QString Factory, QString fillContent, QString time,int face_num = 2, double scale_x = 0.025, double scale_y = 0.025);

    //����1:FTP�ϴ����� ����2:�ϴ�����ķָ����  ����3:�ϴ����ݵ�����ַ�  ����4:�ϴ����ݵķָ�����
    Q_INVOKABLE QString toCombinaFtpContent(QString titleContent, QString splitSig1, QString FillSig, QString splitSig2);

    //��װ�ض�������   ����1:��Ҫ���µ��ַ��� ����2:����1�ķָ���  ����3:����ַ��� ����4:����3�ķָ���  ����5:����4�ķָ���
    Q_INVOKABLE QString toFillSpecialSig(QString FillContent, QString splitSig1, QString fillSig, QString splitSig2, QString splitSig3);

    //��ȡʱ���  ����1:��ȡ�ĳ���
    Q_INVOKABLE QString toGetTimepoint(int length);

    //��ȡ�ļ�����
    Q_INVOKABLE QString toGetTextContent(QString PanelID, QString filePath, QString fileType, QString MatchContent, bool isDel);

    //ֱ�ӽ����ϴ��ļ�  ����1:�����ļ�·��  ����2���ļ�����  ����3:FTP�̶�·��  ����4:FTP�·��
    Q_INVOKABLE bool toParseFileAndPut(QString filePath, QString fileType, QString FtpFilePath, QString unControlPath);

    Q_INVOKABLE QStringList toGetFileList(QString filePath,QString FileType);

    /************************************FTP�ϴ��ļ�*******************************************/
    //�����ļ�
    Q_INVOKABLE bool toDownLoadFile(QString Panel_ID, QString FtpFilePath, QString SavePath, QString FileType);

    //�ϴ��ļ� ����1:��Ʒid ����2:ID�Ƿ��д ����3:ftp�̶���·��  ����4:id�ĳ��Ƚض� ����5:�仯��·�� ����6:�ϴ�������  ����7:�ļ���׺
    Q_INVOKABLE bool toUploadFile(QString PanelID, bool isUpper, QString FtpFilePath, QString FileName, QString unControlPath,QString UploadContent, QString FileLastName, QString FileType);

    /************************************���ݿ��ļ�����*******************************************/
    //��ѯָ������Ϣ
    Q_INVOKABLE bool QueryProductInfo(QString QueryContent, QString QueryTable, int queryTime);

    //���ص�����Ϣ
    Q_INVOKABLE QString ParseSigleInfo();

    //����������Ϣ
    Q_INVOKABLE QStringList ParseProductDefectInfo(QString QueryContent, QString sigleInfo,double scale_x = 0.025,double scale_y = 0.025);


    /************************************�����������ļ�*******************************************/
    Q_INVOKABLE QStringList getOtherFile(QString filePath, int Sec);

    /************************************PLC����*******************************************/
    Q_INVOKABLE void toWriteQString(QString WritAdr, QString val);
    Q_INVOKABLE QString toReadQString(QString ReadAdr, int len); //��ȡ�ַ���

private:
    void toLoadSmallBlobIm(QVector<QImage> &OutImList, QString filename);

    bool YTLoadBlobFile(YtAllBlob &blobfile, QString filename);

signals:
    void onSignalSendIndexOut(int index, QString content);

public slots:
    void getSignalOut(int index, QString content);



};

#endif // YTCIMSCRIPT_H