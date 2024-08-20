#include "ytsharefoldersetting.h"
#include "ui_ytsharefoldersetting.h"
#include "ytlogprolib.h"

#include <QFileDialog>
#include <QDebug>


YtShareFolderSetting::YtShareFolderSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YtShareFolderSetting)
{
    ui->setupUi(this);
    Init();
}

YtShareFolderSetting::~YtShareFolderSetting()
{
    m_YtNetWorkDo.closeCommunication();
    delete ui;
}

void YtShareFolderSetting::Init()
{
    QStringList Dll_List;
    QStringList fileter;
    fileter << QString("*.dll");
    QDir dir("./NetWorkDevice");

    Dll_List = dir.entryList(fileter);
    Dll_List.insert(0, "");
    ui->comboBox->addItems(Dll_List);
    toLoadParam();
    toSetUi(m_share_folder_param);
    ui->Status->setStyleSheet(QString("background: gray; border:1px solid gray;"));
}

void YtShareFolderSetting::toLoadParam()
{
    QString FilePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/SHARE_FOLDER";
    QDir dir(FilePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(FilePath + "/SHARE_FOLDER.dat");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream out(&file);
        out >> m_share_folder_param.DLL_NAME >> m_share_folder_param.SHARE_USER >> m_share_folder_param.SHARE_PASS
                >> m_share_folder_param.SHARE_FOLDER;
    }
    file.close();
}

void YtShareFolderSetting::toSaveParam()
{
    QString filePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/SHARE_FOLDER";
    QDir dir(filePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    toGetUi(m_share_folder_param);

    QFile file(filePath + "/SHARE_FOLDER.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream in(&file);
        in << m_share_folder_param.DLL_NAME << m_share_folder_param.SHARE_USER << m_share_folder_param.SHARE_PASS
           << m_share_folder_param.SHARE_FOLDER;
    }
    file.close();
}

void YtShareFolderSetting::toGetUi(SHARE_FOLDER_PARAM &share_folder_param)
{
    share_folder_param.DLL_NAME = ui->comboBox->currentText();
    share_folder_param.SHARE_USER = ui->User->text();
    share_folder_param.SHARE_PASS = ui->PassWord->text();
    share_folder_param.SHARE_FOLDER = ui->filePath->text();

}

void YtShareFolderSetting::toSetUi(SHARE_FOLDER_PARAM share_folder_param)
{
    if(share_folder_param.DLL_NAME.isEmpty())
    {
       toSetLineEditEnable();
       return ;
    }

    ui->comboBox->setCurrentText(share_folder_param.DLL_NAME);
    ui->User->setText(share_folder_param.SHARE_USER);
    ui->PassWord->setText(share_folder_param.SHARE_PASS);
    ui->filePath->setText(share_folder_param.SHARE_FOLDER);
}

YtNetWorkDo *YtShareFolderSetting::toGetObject()
{
    on_Test_Connect_clicked();
    if(&m_YtNetWorkDo == nullptr)
    {
        return nullptr;
    }
    return &m_YtNetWorkDo;
}

void YtShareFolderSetting::toSetLineEditEnable(bool isEna)
{
    ui->filePath->setEnabled(isEna);
    ui->User->setEnabled(isEna);
    ui->PassWord->setEnabled(isEna);
    ui->Status->setEnabled(isEna);
    ui->Test_Connect->setEnabled(isEna);
    ui->Save_Param->setEnabled(isEna);
}

void YtShareFolderSetting::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory();
    ui->filePath->setText(filePath);

}

void YtShareFolderSetting::on_Test_Connect_clicked()
{
    toGetUi(m_share_folder_param);

    if(m_share_folder_param.DLL_NAME.isEmpty())
    {
        return;
    }

    toPrintLog(u8"CIM_SHARE_FOLDER:----------准备映射共享文件夹----------", Qt::green);
    if(m_YtNetWorkDo.toLoadNetWork(QDir::currentPath()+"/NetWorkDevice/" + ui->comboBox->currentText()))
    {
        toPrintLog(u8"CIM_SHARE_FOLDER:----------共享文件夹DLL构造成功----------", Qt::green);

        QStringList ShareFolderList;
        ShareFolderList << m_share_folder_param.SHARE_FOLDER << m_share_folder_param.SHARE_USER
                        << m_share_folder_param.SHARE_PASS;

        if(m_YtNetWorkDo.openCommunication(ShareFolderList))
        {
            toPrintLog(u8"CIM_SHARE_FOLDER:-----共享文件夹映射成功-----------路径:" + m_share_folder_param.SHARE_FOLDER +
                       u8"\t\t用户名:" + m_share_folder_param.SHARE_USER + u8"\t\t密码:" + m_share_folder_param.SHARE_PASS, Qt::green);
            ui->Status->setStyleSheet(QString("background: green;"));
        }
        else
        {
            toPrintLog(u8"CIM_SHARE_FOLDER:------共享文件夹映射失败-----------路径:" + m_share_folder_param.SHARE_FOLDER +
                       u8"\t\t用户名:" + m_share_folder_param.SHARE_USER + u8"\t\t密码:" + m_share_folder_param.SHARE_PASS, Qt::red);
            ui->Status->setStyleSheet(QString("background: red;"));
            return ;

        }
    }
    else
    {
        toPrintLog(u8"CIM_SHARE_FOLDER:----------共享文件夹映射失败----------", Qt::red);
        return ;
    }

}

void YtShareFolderSetting::on_Save_Param_clicked()
{
    toSaveParam();
}

void YtShareFolderSetting::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << u8"CIM_ShareFolder:----------comBox当前内容---------" << arg1;
    if(arg1.isEmpty())
    {
        toSetLineEditEnable();
        return ;
    }

    toSetLineEditEnable(true);
}
