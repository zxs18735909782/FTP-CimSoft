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
    m_FtpList << u8"FTP�ϴ��ļ�" << u8"FTP�����ļ�";
    m_ShareFolderList << u8"�ϴ��ļ�" << u8"��ȡ����";
    m_BasicList << u8"������־" << u8"������ʱ"  << u8"��ȡ��ƷID" << u8"���ɿ�����" << u8"����ָ������"
                << u8"��ȡ�ͻ���ȱ����Ϣ" << u8"��ȡ��ͼȱ����Ϣ" << u8"��ȡʱ���" << u8"��ȡ�ļ�����"
                << u8"�ϴ��������ļ�" << u8"��ȡ�ļ���Ϣ�б�" << u8"��ȡ�ļ����б�";

    m_SqlList  << u8"��ѯ����" << u8"��ȡ��������" << u8"������������";
    m_PLCList  << u8"д���ַ���" << u8"��ȡ�ַ���";

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
    if(ui->Next->text() == u8"ȷ��")
    {
        this->close();
    }
    else
    {
        ui->Next->setText(u8"ȷ��");
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void YtCimParamSet::on_Back_clicked()
{
    ui->Next->setText(u8"��һҳ");
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

    if(arg1 == u8"FTPЭ��")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_FtpList);
    }
    else if(arg1 == u8"�����ļ���")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_ShareFolderList);
    }
    else if(arg1 == u8"���ݿ����")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_SqlList);
    }
    else if(arg1 == u8"��������")
    {
        ui->ChoseFunction->setEnabled(true);
        ui->ChoseFunction->clear();
        ui->ChoseFunction->addItems(m_BasicList);
    }
    else if(arg1 == u8"PLC����")
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