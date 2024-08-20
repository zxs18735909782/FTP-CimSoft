#ifndef YTEDITTOOL_H
#define YTEDITTOOL_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
class CodeForm;
class QDESIGNER_WIDGET_EXPORT YtEditTool : public QWidget
{
    Q_OBJECT

public:
    YtEditTool(QWidget *parent = 0);
    ~YtEditTool();
    void resizeEvent(QResizeEvent *event);
private:
     CodeForm *m_CodeForm=nullptr;
public:
     void toSetData(QString CodeData);
     void toGetData(QString &OutData);
     void toAppendData(QString Codedata);
};

#endif // YTEDITTOOL_H
