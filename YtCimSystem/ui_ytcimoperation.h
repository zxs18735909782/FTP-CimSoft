/********************************************************************************
** Form generated from reading UI file 'ytcimoperation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YTCIMOPERATION_H
#define UI_YTCIMOPERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YtCimOperation
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *ChoseFunction;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QWidget *page_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLineEdit *DownLoadPath;
    QLabel *label_8;
    QLineEdit *SavePath;
    QLabel *label_7;
    QComboBox *FileStype;
    QWidget *page_4;
    QWidget *page_5;
    QPushButton *OK;
    QPushButton *Cancel;

    void setupUi(QDialog *YtCimOperation)
    {
        if (YtCimOperation->objectName().isEmpty())
            YtCimOperation->setObjectName(QString::fromUtf8("YtCimOperation"));
        YtCimOperation->resize(514, 276);
        gridLayout = new QGridLayout(YtCimOperation);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        label = new QLabel(YtCimOperation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(YtCimOperation);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(YtCimOperation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        ChoseFunction = new QComboBox(YtCimOperation);
        ChoseFunction->setObjectName(QString::fromUtf8("ChoseFunction"));

        gridLayout->addWidget(ChoseFunction, 0, 3, 1, 2);

        stackedWidget = new QStackedWidget(YtCimOperation);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        lineEdit_3 = new QLineEdit(page_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 20, 71, 21));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 81, 21));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 20, 91, 21));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        DownLoadPath = new QLineEdit(page_3);
        DownLoadPath->setObjectName(QString::fromUtf8("DownLoadPath"));

        gridLayout_3->addWidget(DownLoadPath, 0, 1, 1, 1);

        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        SavePath = new QLineEdit(page_3);
        SavePath->setObjectName(QString::fromUtf8("SavePath"));

        gridLayout_3->addWidget(SavePath, 1, 1, 1, 1);

        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        FileStype = new QComboBox(page_3);
        FileStype->addItem(QString());
        FileStype->addItem(QString());
        FileStype->addItem(QString());
        FileStype->setObjectName(QString::fromUtf8("FileStype"));

        gridLayout_3->addWidget(FileStype, 2, 1, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 5);

        OK = new QPushButton(YtCimOperation);
        OK->setObjectName(QString::fromUtf8("OK"));

        gridLayout->addWidget(OK, 2, 3, 1, 1);

        Cancel = new QPushButton(YtCimOperation);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 2, 4, 1, 1);


        retranslateUi(YtCimOperation);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(YtCimOperation);
    } // setupUi

    void retranslateUi(QDialog *YtCimOperation)
    {
        YtCimOperation->setWindowTitle(QCoreApplication::translate("YtCimOperation", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("YtCimOperation", "\351\200\211\346\213\251\350\204\232\346\234\254\347\261\273\345\236\213:", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("YtCimOperation", "FTP\345\215\217\350\256\256", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("YtCimOperation", "\345\205\261\344\272\253\346\226\207\344\273\266\345\244\271", nullptr));

        label_2->setText(QCoreApplication::translate("YtCimOperation", "\344\270\212\344\274\240\345\207\275\346\225\260:", nullptr));
        label_3->setText(QCoreApplication::translate("YtCimOperation", "\344\270\212\344\274\240\346\240\207\351\242\230:", nullptr));
        label_4->setText(QCoreApplication::translate("YtCimOperation", "\346\240\207\351\242\230\345\210\206\351\232\224\347\254\246:", nullptr));
        label_5->setText(QCoreApplication::translate("YtCimOperation", "\345\256\236\351\231\205\344\270\212\344\274\240\344\270\252\346\225\260:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("YtCimOperation", "\347\241\256\345\256\232", nullptr));
        label_6->setText(QCoreApplication::translate("YtCimOperation", "\346\226\207\344\273\266\344\270\213\350\275\275\350\267\257\345\276\204", nullptr));
        label_8->setText(QCoreApplication::translate("YtCimOperation", "\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        label_7->setText(QCoreApplication::translate("YtCimOperation", "\346\226\207\344\273\266\346\240\274\345\274\217", nullptr));
        FileStype->setItemText(0, QCoreApplication::translate("YtCimOperation", "txt", nullptr));
        FileStype->setItemText(1, QCoreApplication::translate("YtCimOperation", "csv", nullptr));
        FileStype->setItemText(2, QCoreApplication::translate("YtCimOperation", "dat", nullptr));

        OK->setText(QCoreApplication::translate("YtCimOperation", "\347\241\256\350\256\244", nullptr));
        Cancel->setText(QCoreApplication::translate("YtCimOperation", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YtCimOperation: public Ui_YtCimOperation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YTCIMOPERATION_H
