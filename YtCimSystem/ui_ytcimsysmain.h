/********************************************************************************
** Form generated from reading UI file 'ytcimsysmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YTCIMSYSMAIN_H
#define UI_YTCIMSYSMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YtCimSysMain
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *Start_CIM;
    QPushButton *ParamSet;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGridLayout *log;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *FTP_Refresh_Path;
    QPushButton *reFreash;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;
    QTextBrowser *showFileInfo;
    QWidget *tab;
    QPushButton *ChoseFilePath;
    QLabel *label;
    QLineEdit *filePath;
    QPushButton *SavePath;
    QTableView *tableView;

    void setupUi(QWidget *YtCimSysMain)
    {
        if (YtCimSysMain->objectName().isEmpty())
            YtCimSysMain->setObjectName(QString::fromUtf8("YtCimSysMain"));
        YtCimSysMain->resize(955, 795);
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/dataChange.ico"), QSize(), QIcon::Normal, QIcon::Off);
        YtCimSysMain->setWindowIcon(icon);
        gridLayout = new QGridLayout(YtCimSysMain);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Start_CIM = new QPushButton(YtCimSysMain);
        Start_CIM->setObjectName(QString::fromUtf8("Start_CIM"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Start_CIM->sizePolicy().hasHeightForWidth());
        Start_CIM->setSizePolicy(sizePolicy);
        Start_CIM->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(Start_CIM);

        ParamSet = new QPushButton(YtCimSysMain);
        ParamSet->setObjectName(QString::fromUtf8("ParamSet"));
        sizePolicy.setHeightForWidth(ParamSet->sizePolicy().hasHeightForWidth());
        ParamSet->setSizePolicy(sizePolicy);
        ParamSet->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(ParamSet);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(YtCimSysMain);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        log = new QGridLayout();
        log->setObjectName(QString::fromUtf8("log"));

        gridLayout_4->addLayout(log, 0, 0, 1, 1);

        tabWidget->addTab(widget, QString());
        widget_2 = new QWidget();
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        FTP_Refresh_Path = new QLineEdit(widget_2);
        FTP_Refresh_Path->setObjectName(QString::fromUtf8("FTP_Refresh_Path"));

        horizontalLayout->addWidget(FTP_Refresh_Path);

        reFreash = new QPushButton(widget_2);
        reFreash->setObjectName(QString::fromUtf8("reFreash"));

        horizontalLayout->addWidget(reFreash);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 2);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 2);

        treeWidget = new QTreeWidget(widget_2);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        treeWidget->setAutoScroll(true);
        treeWidget->header()->setCascadingSectionResizes(true);
        treeWidget->header()->setMinimumSectionSize(21);
        treeWidget->header()->setHighlightSections(true);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_2->addWidget(treeWidget, 1, 0, 1, 1);

        showFileInfo = new QTextBrowser(widget_2);
        showFileInfo->setObjectName(QString::fromUtf8("showFileInfo"));

        gridLayout_2->addWidget(showFileInfo, 1, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 3);
        tabWidget->addTab(widget_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ChoseFilePath = new QPushButton(tab);
        ChoseFilePath->setObjectName(QString::fromUtf8("ChoseFilePath"));
        ChoseFilePath->setGeometry(QRect(380, 10, 80, 20));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 16));
        filePath = new QLineEdit(tab);
        filePath->setObjectName(QString::fromUtf8("filePath"));
        filePath->setGeometry(QRect(100, 10, 271, 20));
        SavePath = new QPushButton(tab);
        SavePath->setObjectName(QString::fromUtf8("SavePath"));
        SavePath->setGeometry(QRect(470, 10, 80, 20));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(-60, 40, 911, 711));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        retranslateUi(YtCimSysMain);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(YtCimSysMain);
    } // setupUi

    void retranslateUi(QWidget *YtCimSysMain)
    {
        YtCimSysMain->setWindowTitle(QCoreApplication::translate("YtCimSysMain", "YtCIM", nullptr));
        Start_CIM->setText(QCoreApplication::translate("YtCimSysMain", "\345\220\257\345\212\250CIM", nullptr));
        ParamSet->setText(QCoreApplication::translate("YtCimSysMain", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("YtCimSysMain", "\346\227\245\345\277\227\346\230\276\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("YtCimSysMain", "\345\210\267\346\226\260\350\267\257\345\276\204", nullptr));
        reFreash->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("YtCimSysMain", "FTP\346\226\207\344\273\266\346\240\221", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget_2), QCoreApplication::translate("YtCimSysMain", "\346\226\207\344\273\266\346\230\276\347\244\272", nullptr));
        ChoseFilePath->setText(QCoreApplication::translate("YtCimSysMain", "...", nullptr));
        label->setText(QCoreApplication::translate("YtCimSysMain", "\345\233\276\345\203\217\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        SavePath->setText(QCoreApplication::translate("YtCimSysMain", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("YtCimSysMain", "\344\270\212\344\274\240\344\277\241\346\201\257\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YtCimSysMain: public Ui_YtCimSysMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YTCIMSYSMAIN_H
