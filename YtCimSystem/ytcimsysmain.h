#ifndef YTCIMSYSMAIN_H
#define YTCIMSYSMAIN_H

#include <QWidget>
#include "ytcimparamset.h"
#include "YtNetWorkDo.h"

#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QCloseEvent>
#include <QTimer>

namespace Ui {
class YtCimSysMain;
}

class YtCimSysMain : public QWidget
{
    Q_OBJECT

public:
    explicit YtCimSysMain(QWidget *parent = nullptr);
    ~YtCimSysMain();

    void closeEvent(QCloseEvent *event);

private slots:
    void on_ParamSet_clicked();

    void on_Start_CIM_clicked();

    void on_ChoseFilePath_clicked();

    void on_SavePath_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_reFreash_clicked();

public:
    void toSaveParam();
    void toLoadParam();
    void toRefreshFileList();

    void toGetFileTree(YtNetWorkDo *tYtNetWorkDo, QTreeWidgetItem *treeRoot, QString infoSavePath, QString SearchPath);

    //获取FTP文件的信息
    void toGetFileInfo(QTreeWidgetItem *item, QStringList &filePathList);


signals:
    void onSignalSend(QString filePath);

public slots:
    bool toGetFileInfoList();
    void toCollectFile();
    void toShowFile(QString filePath);

public:
    YtCimParamSet   *m_YtCimParamSet = nullptr;
    QStringList     m_filePathList;
    QTimer          m_timer;

private:
    Ui::YtCimSysMain *ui;
};

#endif // YTCIMSYSMAIN_H
