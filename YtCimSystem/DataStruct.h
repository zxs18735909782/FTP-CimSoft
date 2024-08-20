#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <QObject>



/******��¼FTP�Ļ�������*******/
struct FTP_PARAM
{
    QString DLL_NAME                = "";
    QString FTP_IP                  = "";
    QString FTP_PORT                = "";
    QString FTP_USER                = "";
    QString FTP_PASS                = "";
    QString FTP_Path                = "";              //FTP�ϴ�·��
};

/********�����ļ��л�������*********/
struct SHARE_FOLDER_PARAM
{
    QString DLL_NAME                = "";
    QString SHARE_FOLDER            = "";
    QString SHARE_USER              = "";
    QString SHARE_PASS              = "";
};

struct DATABASE_PARAM
{
    QString DLL_NAME                = "";
    QString USER                    = "";
    QString PASSWORD                = "";
    QString HOSTADD                 = "";
    QString PORT                    = "";
    QString DB_NAME                 = "";
};

struct PLC_PARAM
{
    QString DLL_NAME                = "";
    QString PLC_IP                  = "";
    QString PLC_PORT                = "";
    QString LOCAL_PORT              = "";

};


#endif // DATASTRUCT_H