#ifndef YTCIMSCRIPTUI_H
#define YTCIMSCRIPTUI_H

#include <QDialog>
#include <QThread>
#include <QtScript>

#include "ytcimscriptthread.h"
#include "YtNetWorkDo.h"
#include "ytplcdo.h"

namespace Ui {
class YtCimScriptUI;
}


class YtCimScriptUI : public QDialog
{
    Q_OBJECT

public:
    explicit YtCimScriptUI(QWidget *parent = nullptr);
    ~YtCimScriptUI();

    void toInsertScript(QString str);

    void toStart(bool isOnce = false);

    void toSetObject(YtNetWorkDo *tYtNetWork = nullptr, int flag = 0);

    void toInitPlc();

    void toStop();

    void toSaveScript();

    void toSetTime(QString tTime);

public:
    YtCimScriptThread *m_YtCimScriptThread = nullptr;

private:
    Ui::YtCimScriptUI *ui;
};


#endif // YTCIMSCRIPTUI_H
