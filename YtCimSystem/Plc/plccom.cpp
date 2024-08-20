#include "plccom.h"
#include "ui_plccom.h"
#include <QFile>
#include <QDir>
#include "ytlogprolib.h"
#include <QDebug>

PlcCom::PlcCom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlcCom)
{
    ui->setupUi(this);
    Init();
}

PlcCom::~PlcCom()
{
    delete ui;
}

void PlcCom::Init()
{
    QStringList Dll_List;
    QStringList fileter;
    fileter << QString("*.dll");
    QDir dir("./Plc");

    Dll_List = dir.entryList(fileter);
    Dll_List.insert(0, "");
    ui->comboBox->addItems(Dll_List);

    toLoadParam();
    toSetUi(m_plc_param);
//    ui->Status->setStyleSheet(QString("background: gray; border:1px solid gray;"));
}

void PlcCom::toLoadParam()
{
    QString FilePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/Plc";
    QDir dir(FilePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(FilePath + "/PLC.dat");

    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream out(&file);
        out >> m_plc_param.DLL_NAME >> m_plc_param.PLC_IP >> m_plc_param.PLC_PORT >> m_plc_param.LOCAL_PORT;
    }

    file.close();
}

void PlcCom::toSaveParam()
{

    QString FilePath = QApplication::applicationDirPath() + "/CIM_Manger/PARAM/Plc";
    QDir dir(FilePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    toGetUi(m_plc_param);

    QFile file(FilePath + "/PLC.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream in(&file);
        in << m_plc_param.DLL_NAME << m_plc_param.PLC_IP << m_plc_param.PLC_PORT << m_plc_param.LOCAL_PORT;
    }
    file.close();

}

void PlcCom::toGetUi(PLC_PARAM &plc_param)
{
    plc_param.DLL_NAME      = ui->comboBox->currentText();
    plc_param.PLC_IP        = ui->PLC_IP->text();
    plc_param.PLC_PORT      = ui->PLC_PORT->text();
    plc_param.LOCAL_PORT    = ui->LOCAL_PORT->text();

}

void PlcCom::toSetUi(PLC_PARAM plc_param)
{
    if(plc_param.DLL_NAME.isEmpty())
    {
        return ;
    }

    ui->comboBox->setCurrentText(plc_param.DLL_NAME);
    ui->PLC_IP->setText(plc_param.PLC_IP);
    ui->PLC_PORT->setText(plc_param.PLC_PORT);
    ui->LOCAL_PORT->setText(plc_param.LOCAL_PORT);
}

//YtPlcDo *PlcCom::toGetObject()
//{
////    on_TestConnect_clicked();
//    if(&m_YtPlcDo == nullptr)
//    {
//        return nullptr;
//    }
//    return &m_YtPlcDo;
//}

void PlcCom::on_SaveParam_clicked()
{
    toSaveParam();
}

//void PlcCom::on_TestConnect_clicked()
//{
//    toPrintLog(u8"CIM_PLC:-----------测试加载PLC驱动----------", Qt::green);
//    toGetUi(m_plc_param);
//    if(m_plc_param.DLL_NAME.isEmpty())
//    {
//        return;
//    }

//    toPrintLog(QString(u8"CIM_PLC:-----------驱动加载中----------%1").arg(m_isConnect), Qt::green);
//    if(m_isConnect == true)
//    {
//        return ;
//    }

//    m_isConnect = true;

//    if(!m_YtPlcDo.toLoadPlc("./Plc/" + m_plc_param.DLL_NAME))
//    {
//        toPrintLog(u8"CIM_PLC:-----------加载PLC DLL失败----------", Qt::green);
//        return ;
//    }

//    int val = m_YtPlcDo.ConnectServer(m_plc_param.PLC_IP, m_plc_param.PLC_PORT.toInt(), m_plc_param.LOCAL_PORT.toInt());

//    toPrintLog(QString(u8"CIM_PLC:-----------PLC连接结果----------%1").arg(val), Qt::green);
//    if(val != 0)
//    {
//       ui->Status->setStyleSheet(QString("background: red;"));
//    }
//    else
//    {
//        m_YtPlcDo.ConnectClose();
//        ui->Status->setStyleSheet(QString("background: green;"));
//    }

//}
