/********************************************************************************
** Form generated from reading UI file 'ytftpsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YTFTPSETTING_H
#define UI_YTFTPSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_YTFtpSetting
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_6;
    QPushButton *TestPub;
    QPushButton *SaveParam;
    QLabel *Status;
    QLineEdit *PassWord;
    QLineEdit *User;
    QLineEdit *Port;
    QLineEdit *IPAddress;
    QComboBox *comboBox;

    void setupUi(QDialog *YTFtpSetting)
    {
        if (YTFtpSetting->objectName().isEmpty())
            YTFtpSetting->setObjectName(QString::fromUtf8("YTFtpSetting"));
        YTFtpSetting->resize(366, 166);
        gridLayout = new QGridLayout(YTFtpSetting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(YTFtpSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        TestPub = new QPushButton(groupBox);
        TestPub->setObjectName(QString::fromUtf8("TestPub"));

        gridLayout_2->addWidget(TestPub, 5, 2, 1, 1);

        SaveParam = new QPushButton(groupBox);
        SaveParam->setObjectName(QString::fromUtf8("SaveParam"));

        gridLayout_2->addWidget(SaveParam, 5, 3, 1, 1);

        Status = new QLabel(groupBox);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setMinimumSize(QSize(100, 20));
        Status->setStyleSheet(QString::fromUtf8("border:2px solid gray;"));

        gridLayout_2->addWidget(Status, 5, 1, 1, 1);

        PassWord = new QLineEdit(groupBox);
        PassWord->setObjectName(QString::fromUtf8("PassWord"));

        gridLayout_2->addWidget(PassWord, 4, 1, 1, 3);

        User = new QLineEdit(groupBox);
        User->setObjectName(QString::fromUtf8("User"));

        gridLayout_2->addWidget(User, 3, 1, 1, 3);

        Port = new QLineEdit(groupBox);
        Port->setObjectName(QString::fromUtf8("Port"));

        gridLayout_2->addWidget(Port, 2, 1, 1, 3);

        IPAddress = new QLineEdit(groupBox);
        IPAddress->setObjectName(QString::fromUtf8("IPAddress"));

        gridLayout_2->addWidget(IPAddress, 1, 1, 1, 3);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 3);

        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(YTFtpSetting);

        QMetaObject::connectSlotsByName(YTFtpSetting);
    } // setupUi

    void retranslateUi(QDialog *YTFtpSetting)
    {
        YTFtpSetting->setWindowTitle(QCoreApplication::translate("YTFtpSetting", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("YTFtpSetting", "FTP\345\217\202\346\225\260\351\205\215\347\275\256\347\225\214\351\235\242", nullptr));
        label_8->setText(QCoreApplication::translate("YTFtpSetting", "DLL\351\200\211\346\213\251:", nullptr));
        label->setText(QCoreApplication::translate("YTFtpSetting", "IP\345\234\260\345\235\200:", nullptr));
        label_2->setText(QCoreApplication::translate("YTFtpSetting", "\347\253\257\345\217\243\345\217\267:", nullptr));
        label_7->setText(QCoreApplication::translate("YTFtpSetting", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_6->setText(QCoreApplication::translate("YTFtpSetting", "\345\257\206\347\240\201:", nullptr));
        TestPub->setText(QCoreApplication::translate("YTFtpSetting", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        SaveParam->setText(QCoreApplication::translate("YTFtpSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        Status->setText(QString());
        PassWord->setText(QCoreApplication::translate("YTFtpSetting", "ytvision", nullptr));
        User->setText(QCoreApplication::translate("YTFtpSetting", "ytvision", nullptr));
        Port->setText(QCoreApplication::translate("YTFtpSetting", "21", nullptr));
        IPAddress->setText(QCoreApplication::translate("YTFtpSetting", "192.168.0.80", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YTFtpSetting: public Ui_YTFtpSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YTFTPSETTING_H
