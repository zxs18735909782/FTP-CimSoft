QT       += core gui script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Plc/plccom.cpp \
    ShareFolder/ytsharefoldersetting.cpp \
    Sql/ytsqlsetting.cpp \
    main.cpp \
    ytcimparamset.cpp \
    ytcimscript.cpp \
    ytcimscriptthread.cpp \
    ytcimscriptui.cpp \
    ytcimsysmain.cpp \
    FTP/ytftpsetting.cpp

HEADERS += \
    DataStruct.h \
    Plc/plccom.h \
    ShareFolder/ytsharefoldersetting.h \
    Sql/ytsqlsetting.h \
    ytcimparamset.h \
    ytcimscript.h \
    ytcimscriptthread.h \
    ytcimscriptui.h \
    ytcimsysmain.h \
    FTP/ytftpsetting.h

FORMS += \
    Plc/plccom.ui \
    ShareFolder/ytsharefoldersetting.ui \
    Sql/ytsqlsetting.ui \
    ytcimparamset.ui \
    ytcimscriptui.ui \
    ytcimsysmain.ui \
    FTP/ytftpsetting.ui


INCLUDEPATH +=  ../YTBuildLib/YtBaseProLib/include \
                ../YTBuildLib/ShowPlginLib/include  \
                ../YTBuildLib/YtVisionHLIB/include  \
                FTP \
                ShareFolder \
                Sql \
                Plc \
                ../YtDriveProject/YtNetWorkPro/YtNetWorkDo/include \
                ../YtPlcDo

LIBS += ../YTBuildLib/YtBaseProLib/lib/YtLogProLib.lib \
        ../YtDriveProject/YtNetWorkPro/YtNetWorkDo/lib/YtNetWorkDo.lib \
        ../YTBuildLib/ShowPlginLib/lib/ytedittoolplugin.lib \
        ../YTBuildLib/YtVisionHLIB/lib/YtBaseObject.lib \
        ../bin/YtPlcDo.lib


DESTDIR = ../bin

RESOURCES += \
    operationImage.qrc

RC_ICONS = ./image/dataChange.ico


