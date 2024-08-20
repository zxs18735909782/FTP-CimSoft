#ifndef YTFTPSETTING_H
#define YTFTPSETTING_H

#include <QDialog>

#include "DataStruct.h"
#include "YtNetWorkDo.h"

namespace Ui {
class YTFtpSetting;
}

class YTFtpSetting : public QDialog
{
    Q_OBJECT

public:
    explicit YTFtpSetting(QWidget *parent = nullptr);
    ~YTFtpSetting();

    void Init();

    void toLoadParam();

    void toSaveParam();

    void toGetUi(FTP_PARAM &ftp_param);

    void toSetUi(FTP_PARAM ftp_param);

    YtNetWorkDo* toGetObject();

    void toSetLineEditEnable(bool isEna = false);

public:
    FTP_PARAM    m_ftp_param;
    YtNetWorkDo  m_YtNetWorkDo;

private slots:
    void on_TestPub_clicked();

    void on_SaveParam_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::YTFtpSetting *ui;
};

#endif // YTFTPSETTING_H
