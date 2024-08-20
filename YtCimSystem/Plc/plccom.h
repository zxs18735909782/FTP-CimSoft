#ifndef PLCCOM_H
#define PLCCOM_H

#include <QDialog>
#include "ytplcdo.h"
#include "DataStruct.h"

namespace Ui {
class PlcCom;
}

class PlcCom : public QDialog
{
    Q_OBJECT

public:
    explicit PlcCom(QWidget *parent = nullptr);
    ~PlcCom();

public:
    void Init();

    void toLoadParam();
    void toSaveParam();

    void toGetUi(PLC_PARAM &plc_param);
    void toSetUi(PLC_PARAM plc_param);

//    YtPlcDo* toGetObject();


public:
//    YtPlcDo     m_YtPlcDo;
    PLC_PARAM   m_plc_param;

    bool        m_isConnect = false;


private slots:
    void on_SaveParam_clicked();

//    void on_TestConnect_clicked();

private:
    Ui::PlcCom *ui;
};

#endif // PLCCOM_H
