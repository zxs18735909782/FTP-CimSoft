#ifndef YTCIMPARAMSET_H
#define YTCIMPARAMSET_H

#include <QDialog>


#include "ytftpsetting.h"
#include "ytsharefoldersetting.h"
#include "ytsqlsetting.h"
#include "DataStruct.h"

#include "ytcimscriptui.h"
#include "YtNetWorkDo.h"
#include "plccom.h"


namespace Ui {
class YtCimParamSet;
}

class YtCimParamSet : public QDialog
{
    Q_OBJECT

public:
    explicit YtCimParamSet(QWidget *parent = nullptr);
    ~YtCimParamSet();

    void toInit();

    //flag: 0-FTP   1-ShardFolder  2-Sql
    YtNetWorkDo* toGetObject(int flag = 0);

    void toSetRecrdTime(QString tTime);

public:
    YTFtpSetting                    m_YTFtpSetting;
    YtShareFolderSetting            m_YtShareFolderSetting;
    YtSqlSetting                    m_YtSqlSetting;
    YtCimScriptUI                   m_YtCimScriptUI;
    PlcCom                          m_PlcCom;

    QVector<int>                    m_vectorType;

    QStringList                     m_FtpList;
    QStringList                     m_ShareFolderList;
    QStringList                     m_SqlList;
    QStringList                     m_BasicList;
    QStringList                     m_PLCList;

    QString                         m_Type;


public slots:
    void on_Next_clicked();

    void on_Back_clicked();

    void on_Add_clicked();

    void on_RunOnce_clicked();

    void on_ChoseFunction_currentTextChanged(const QString &arg1);

    void on_Type_currentTextChanged(const QString &arg1);

    void on_ExecCycle_clicked();

    void on_SaveScript_clicked();

    void on_Stop_clicked();

private:
    Ui::YtCimParamSet *ui;
};

#endif // YTCIMPARAMSET_H
