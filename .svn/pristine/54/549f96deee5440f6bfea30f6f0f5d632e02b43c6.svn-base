#ifndef YTSQLSETTING_H
#define YTSQLSETTING_H

#include <QDialog>

#include "DataStruct.h"
#include "YtNetWorkDo.h"

namespace Ui {
class YtSqlSetting;
}

class YtSqlSetting : public QDialog
{
    Q_OBJECT

public:
    explicit YtSqlSetting(QWidget *parent = nullptr);
    ~YtSqlSetting();

    void Init();

    void toLoadParam();

    void toSaveParam();

    void toGetUi(DATABASE_PARAM &database_param);

    void toSetUi(DATABASE_PARAM database_param);

    YtNetWorkDo* toGetObject();

    void toSetLineEditEnable(bool isEna = false);

public:
    DATABASE_PARAM m_database_param;
    YtNetWorkDo    m_YtNetWorkDo;

private slots:
    void on_TestConnect_clicked();

    void on_SaveParam_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::YtSqlSetting *ui;
};

#endif // YTSQLSETTING_H
