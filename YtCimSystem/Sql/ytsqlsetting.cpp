#include "ytsqlsetting.h"
#include "ui_ytsqlsetting.h"

#include "ytlogprolib.h"

#include <QDir>
#include <QFile>
#include <QDebug>

YtSqlSetting::YtSqlSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YtSqlSetting)
{
    ui->setupUi(this);
    Init();
}

YtSqlSetting::~YtSqlSetting()
{
    delete ui;
}

void YtSqlSetting::Init()
{
    QStringList Dll_List;
    QStringList fileter;
    fileter << QString("*.dll");
    QDir dir("./NetWorkDevice");

    Dll_List = dir.entryList(fileter);
    Dll_List.insert(0, "");
    ui->comboBox->addItems(Dll_List);

    toLoadParam();
    toSetUi(m_database_param);
    ui->Status->setStyleSheet(QString("background: gray; border:1px solid gray;"));

}

void YtSqlSetting::toLoadParam()
{
    QString FilePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/SQL_DATABASE";
    QDir dir(FilePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(FilePath + "/DATABASE.dat");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream out(&file);
        out >> m_database_param.DLL_NAME >> m_database_param.HOSTADD >> m_database_param.PORT
                >> m_database_param.USER >> m_database_param.PASSWORD;
    }
    file.close();
}

void YtSqlSetting::toSaveParam()
{
    QString filePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/SQL_DATABASE";
    QDir dir(filePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    toGetUi(m_database_param);

    QFile file(filePath + "/DATABASE.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream in(&file);
        in << m_database_param.DLL_NAME << m_database_param.HOSTADD << m_database_param.PORT
           << m_database_param.USER << m_database_param.PASSWORD;
    }
    file.close();
}

void YtSqlSetting::toGetUi(DATABASE_PARAM &database_param)
{
    database_param.DLL_NAME = ui->comboBox->currentText();
    database_param.HOSTADD  = ui->DB_IP->text();
    database_param.PORT     = ui->DB_PORT->text();
    database_param.USER     = ui->DB_USER->text();
    database_param.PASSWORD = ui->DB_PASSWORD->text();
    database_param.DB_NAME  = ui->DB_NAME->text();
}

void YtSqlSetting::toSetUi(DATABASE_PARAM database_param)
{
    if(database_param.DLL_NAME.isEmpty())
    {
       toSetLineEditEnable();
       return ;
    }

    ui->comboBox->setCurrentText(database_param.DLL_NAME);
    ui->DB_IP->setText(database_param.HOSTADD);
    ui->DB_PORT->setText(database_param.PORT);
    ui->DB_USER->setText(database_param.USER);
    ui->DB_PASSWORD->setText(database_param.PASSWORD);
    ui->DB_NAME->setText(database_param.DB_NAME);
}

YtNetWorkDo *YtSqlSetting::toGetObject()
{
    on_TestConnect_clicked();
    if(&m_YtNetWorkDo == nullptr)
    {
        return nullptr;
    }
    return &m_YtNetWorkDo;
}

void YtSqlSetting::toSetLineEditEnable(bool isEna)
{
    ui->DB_IP->setEnabled(isEna);
    ui->DB_PORT->setEnabled(isEna);
    ui->DB_NAME->setEnabled(isEna);
    ui->DB_USER->setEnabled(isEna);
    ui->DB_PASSWORD->setEnabled(isEna);
    ui->Status->setEnabled(isEna);
    ui->TestConnect->setEnabled(isEna);
    ui->SaveParam->setEnabled(isEna);
}

void YtSqlSetting::on_TestConnect_clicked()
{
    toGetUi(m_database_param);
    if(m_database_param.DLL_NAME.isEmpty())
    {
        return;
    }

    if(m_YtNetWorkDo.IsConnnect())
    {
        return ;
    }

    toPrintLog(u8"CIM_SQL:----------准备连接数据库-----------", Qt::green);
    if(m_YtNetWorkDo.toLoadNetWork(QDir::currentPath() + "/NetWorkDevice/" + ui->comboBox->currentText()))
    {
        toPrintLog(u8"CIM_SQL:----------数据库连接构造成功-----------", Qt::green);
        QStringList SqlInfo;
        SqlInfo << m_database_param.HOSTADD << m_database_param.PORT << m_database_param.DB_NAME
                << m_database_param.USER << m_database_param.PASSWORD;
        if(m_YtNetWorkDo.openCommunication(SqlInfo))
        {
            toPrintLog(u8"CIM_SQL:-----数据库连接成功-----------IP:" + m_database_param.HOSTADD +
                       "\tPort:" + m_database_param.PORT + u8"\t\t用户名:" + m_database_param.USER
                       + u8"\t\t密码:" +m_database_param.PASSWORD, Qt::green);
            ui->Status->setStyleSheet(QString("background: green;"));
            return ;
        }
        else
        {
            toPrintLog(u8"CIM_SQL:-----数据库连接成功-----------IP:" + m_database_param.HOSTADD +
                       "\tPort:" + m_database_param.PORT + u8"\t\t用户名:" + m_database_param.USER
                       + u8"\t\t密码:" +m_database_param.PASSWORD, Qt::red);
            ui->Status->setStyleSheet(QString("background: red;"));
            return ;
        }
    }
    else
    {
        toPrintLog(u8"CIM_SQL:----------数据库连接构造失败-----------", Qt::red);
        return ;
    }
}

void YtSqlSetting::on_SaveParam_clicked()
{
    toSaveParam();
}

void YtSqlSetting::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << u8"CIM_SQL:----------comBox当前内容---------" << arg1;
    if(arg1.isEmpty())
    {
        toSetLineEditEnable();
        return ;
    }
    toSetLineEditEnable(true);
}
