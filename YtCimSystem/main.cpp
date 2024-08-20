#include "ytcimsysmain.h"

#include <QApplication>
#include <QSharedMemory>
#include <QMessageBox>
#include <QCoreApplication>


static bool isSignalInstance(QSharedMemory &shareMemory, const QString &strSIgnelKey)
{
    shareMemory.setKey(strSIgnelKey);
    if(shareMemory.attach())
    {
        QMessageBox::warning(nullptr, u8"����", strSIgnelKey + u8"����������");
        return false;
    }

    if(!shareMemory.create(1))
    {
        QMessageBox::critical(nullptr, u8"����", strSIgnelKey + u8"����������");
        return false;
    }

    return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    QApplication a(argc, argv);
    QSharedMemory shareMemory;
    if(!isSignalInstance(shareMemory, u8"YtCIM"))
    {
        QMessageBox::critical(nullptr, u8"����", u8"�����Ѵ�");
        return 0;
    }

    YtCimSysMain w;
    w.show();
    return a.exec();
}
