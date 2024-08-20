#include "ytftpsetting.h"
#include "ui_ytftpsetting.h"

#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include "ytlogprolib.h"

YTFtpSetting::YTFtpSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YTFtpSetting)
{
    ui->setupUi(this);
    Init();
}

YTFtpSetting::~YTFtpSetting()
{
    m_YtNetWorkDo.closeCommunication();
    delete ui;
}

void YTFtpSetting::Init()
{
    QStringList Dll_List;
    QStringList fileter;
    fileter << QString("*.dll");
    QDir dir("./NetWorkDevice");

    Dll_List = dir.entryList(fileter);
    Dll_List.insert(0, "");
    ui->comboBox->addItems(Dll_List);
    toLoadParam();
    toSetUi(m_ftp_param);
    ui->Status->setStyleSheet(QString("background: gray; border:1px solid gray;"));

}

void YTFtpSetting::toLoadParam()
{
    QString FilePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/FTP";
    QDir dir(FilePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(FilePath + "/FTP.dat");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream out(&file);
        out >> m_ftp_param.DLL_NAME >> m_ftp_param.FTP_IP >> m_ftp_param.FTP_PORT >> m_ftp_param.FTP_USER
                >> m_ftp_param.FTP_PASS >> m_ftp_param.FTP_Path;
    }
    file.close();

}

void YTFtpSetting::toSaveParam()
{
    QString filePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/FTP";
    QDir dir(filePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    toGetUi(m_ftp_param);

    QFile file(filePath + "/FTP.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream in(&file);
        in <<  m_ftp_param.DLL_NAME << m_ftp_param.FTP_IP << m_ftp_param.FTP_PORT << m_ftp_param.FTP_USER
            << m_ftp_param.FTP_PASS << m_ftp_param.FTP_Path;
    }
    file.close();
}

void YTFtpSetting::toGetUi(FTP_PARAM &ftp_param)
{
    ftp_param.DLL_NAME  = ui->comboBox->currentText();
    ftp_param.FTP_IP    = ui->IPAddress->text();
    ftp_param.FTP_PORT  = ui->Port->text();
    ftp_param.FTP_USER  = ui->User->text();
    ftp_param.FTP_PASS  = ui->PassWord->text();
}

void YTFtpSetting::toSetUi(FTP_PARAM ftp_param)
{
    if(ftp_param.DLL_NAME.isEmpty())
    {
       toSetLineEditEnable();
       return ;
    }

    ui->comboBox->setCurrentText(ftp_param.DLL_NAME);
    ui->IPAddress->setText(ftp_param.FTP_IP);
    ui->Port->setText(ftp_param.FTP_PORT);
    ui->User->setText(ftp_param.FTP_USER);
    ui->PassWord->setText(ftp_param.FTP_PASS);

}

YtNetWorkDo *YTFtpSetting::toGetObject()
{
    on_TestPub_clicked();

    if(&m_YtNetWorkDo == nullptr)
    {
        return nullptr;
    }

    return &m_YtNetWorkDo;
}

void YTFtpSetting::toSetLineEditEnable(bool isEna)
{
    ui->IPAddress->setEnabled(isEna);
    ui->Port->setEnabled(isEna);
    ui->User->setEnabled(isEna);
    ui->PassWord->setEnabled(isEna);
    ui->Status->setEnabled(isEna);
    ui->TestPub->setEnabled(isEna);
    ui->SaveParam->setEnabled(isEna);
}

void YTFtpSetting::on_TestPub_clicked()
{
    toGetUi(m_ftp_param);

    if(m_ftp_param.DLL_NAME.isEmpty())
    {
        return ;
    }

    if(m_YtNetWorkDo.IsConnnect())
    {
        return ;
    }

    toPrintLog(u8"CIM_FTP:----------准备连接FTP服务器-----------", Qt::green);
    if(m_YtNetWorkDo.toLoadNetWork(QDir::currentPath() +"/NetWorkDevice/" + ui->comboBox->currentText()))
    {
        toPrintLog(u8"CIM_FTP:----------FTP连接构造成功-----------", Qt::green);
        QStringList FtpInfo;
        FtpInfo << m_ftp_param.FTP_IP << m_ftp_param.FTP_PORT << m_ftp_param.FTP_USER << m_ftp_param.FTP_PASS;
        if(m_YtNetWorkDo.openCommunication(FtpInfo))
        {
            toPrintLog(u8"CIM_FTP:-----FTP服务器连接成功-----------IP:" + m_ftp_param.FTP_IP +
                       "\tPort:" + m_ftp_param.FTP_PORT + u8"\t\t用户名:" + m_ftp_param.FTP_USER
                       + u8"\t\t密码:" + m_ftp_param.FTP_PASS, Qt::green);
            ui->Status->setStyleSheet(QString("background: green;"));
        }
        else
        {
            toPrintLog(u8"CIM_FTP:------FTP服务器连接失败-----------IP:" + m_ftp_param.FTP_IP +
                       "\tPort:" + m_ftp_param.FTP_PORT + "\tUSER:" + m_ftp_param.FTP_USER
                       + "\tPWD:" + m_ftp_param.FTP_PASS, Qt::red);
            ui->Status->setStyleSheet(QString("background: red;"));
            return ;
        }
    }
    else
    {
        toPrintLog(u8"CIM_FTP:----------FTP连接构造失败-----------", Qt::red);
        return ;
    }
}


void YTFtpSetting::on_SaveParam_clicked()
{
    toSaveParam();
}

void YTFtpSetting::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << u8"CIM_FTP:----------comBox当前内容---------" << arg1;
    if(arg1.isEmpty())
    {
        toSetLineEditEnable();
        return ;
    }

    toSetLineEditEnable(true);
}
