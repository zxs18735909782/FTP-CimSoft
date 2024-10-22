#include "ytcimparamset.h"
#include "ui_ytcimparamset.h"

#include <QFileDialog>
#include <QDataStream>
#include "ytlogprolib.h"


YtCimParamSet::YtCimParamSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YtCimParamSet)
{
    ui->setupUi(this);
    toInit();
}

YtCimParamSet::~YtCimParamSet()
{
    delete ui;
}

void YtCimParamSet::toInit()
{
    m_Type  =   "";
    m_FtpList << u8"FTP上传文件" << u8"FTP下载文件";
    m_ShareFolderList << u8"上传文件" << u8"读取内容";
    m_BasicList << u8"添加日志" << u8"添加延时"  << u8"获取产品ID" << u8"生成空内容" << u8"设置指定内容"
                << u8"获取客户端缺陷信息" << u8"获取大图缺陷信息" << u8"获取时间戳" << u8"获取文件内容"
                << u8"上传第三方文件" << u8"获取文件信息列表" << u8"获取文件夹列表";

    m_SqlList  << u8"查询数据" << u8"获取单条数据" << u8"解析单条数据";
    m_PLCList  << u8"写入字符串" << u8"读取字符串";

    ui->stackedWidget->setCurrentIndex(0);
    ui->BasicParam->addWidget(&m_YTFtpSetting, 0, 0);
    m_YtCimScriptUI.toSetObject(m_YTFtpSetting.toGetObject(), 0);

    ui->BasicParam->addWidget(&m_YtShareFolderSetting, 1, 0);
    m_YtCimScriptUI.toSetObject(m_YtShareFolderSetting.toGetObject(), 1);

    ui->BasicParam->addWidget(&m_YtSqlSetting, 2, 0);
    m_YtCimScriptUI.toSetObject(m_YtSqlSetting.toGetObject(), 2);

    ui->BasicParam->addWidget(&m_PlcCom, 3, 0);
    m_YtCimScriptUI.toInitPlc();

    ui->gridLayout_2->addWidget(&m_YtCimScriptUI);

    ui->ChoseFunction->setEnabled(false);
}

YtNetWorkDo *YtCimParamSet::toGetObject(int flag)
{
    if(flag == 0)
    {
        return m_YTFtpSetting.toGetObject();
    }

    if(flag == 1)
    {
        return m_YtShareFolderSetting.toGetObject();
    }
}

void YtCimParamSet::toSetRecrdTime(QString tTime)
{
    m_YtCimScriptUI.toSetTime(tTime);
}


void YtCimParamSet::on_Next_clicked()
{
    if(ui->Next->text() == u8"确定")
    {
        this->close();
    }
    else
    {
        ui->Next->setText(u8"确定");
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void YtCimParamSet::on_Back_clicked()
{
    ui->Next->setText(u8"下一页");
    ui->stackedWidget->setCurrentIndex(0);
}


void YtCimParamSet::on_Add_clicked()
{
    m_YtCimScriptUI.toInsertScript(m_Type);
}

void YtCimParamSet::on_RunOnce_clicked()
{
    m_YtCimScriptUI.toStart(true);
}

void YtCimParamSet::on_ChoseFunction_currentTextChanged(const QString &arg1)
{
    m_Type = arg1;
}

void YtCimParamSet::on_Type_currentTextChanged(const QString &arg1)
{
    toPrintLog(arg1, Qt::yellow);

    if(arg1 == u8"FTP协议")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_FtpList);
    }
    else if(arg1 == u8"共享文件夹")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_ShareFolderList);
    }
    else if(arg1 == u8"数据库操作")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_SqlList);
    }
    else if(arg1 == u8"基础函数")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_BasicList);
    }
    else if(arg1 == u8"PLC操作")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_PLCList);
    }
    else
    {
        ui->ChoseFunction->setEnabled(false);
    }
}

void YtCimParamSet::on_ExecCycle_clicked()
{
    m_YtCimScriptUI.toStart();
}

void YtCimParamSet::on_SaveScript_clicked()
{
    m_YtCimScriptUI.toSaveScript();
}

void YtCimParamSet::on_Stop_clicked()
{
    m_YtCimScriptUI.toStop();
}
