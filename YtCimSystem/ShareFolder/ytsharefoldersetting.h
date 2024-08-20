#ifndef YTSHAREFOLDERSETTING_H
#define YTSHAREFOLDERSETTING_H

#include <QDialog>

#include "YtNetWorkDo.h"
#include "DataStruct.h"

namespace Ui {
class YtShareFolderSetting;
}

class YtShareFolderSetting : public QDialog
{
    Q_OBJECT

public:
    explicit YtShareFolderSetting(QWidget *parent = nullptr);
    ~YtShareFolderSetting();

    void Init();

    void toLoadParam();

    void toSaveParam();

    void toGetUi(SHARE_FOLDER_PARAM &share_folder_param);

    void toSetUi(SHARE_FOLDER_PARAM share_folder_param);

    YtNetWorkDo* toGetObject();

    void toSetLineEditEnable(bool isEna = false);

public:
    SHARE_FOLDER_PARAM  m_share_folder_param;
    YtNetWorkDo         m_YtNetWorkDo;

private slots:
    void on_pushButton_clicked();

    void on_Test_Connect_clicked();

    void on_Save_Param_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::YtShareFolderSetting *ui;
};

#endif // YTSHAREFOLDERSETTING_H
