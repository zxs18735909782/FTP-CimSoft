/********************************************************************************
** Form generated from reading UI file 'ytsharefoldersetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YTSHAREFOLDERSETTING_H
#define UI_YTSHAREFOLDERSETTING_H

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

class Ui_YtShareFolderSetting
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *filePath;
    QPushButton *pushButton;
    QLabel *Status;
    QPushButton *Test_Connect;
    QPushButton *Save_Param;
    QComboBox *comboBox;
    QLineEdit *User;
    QLineEdit *PassWord;

    void setupUi(QDialog *YtShareFolderSetting)
    {
        if (YtShareFolderSetting->objectName().isEmpty())
            YtShareFolderSetting->setObjectName(QString::fromUtf8("YtShareFolderSetting"));
        YtShareFolderSetting->resize(581, 141);
        gridLayout = new QGridLayout(YtShareFolderSetting);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(YtShareFolderSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        filePath = new QLineEdit(groupBox);
        filePath->setObjectName(QString::fromUtf8("filePath"));

        gridLayout_2->addWidget(filePath, 3, 1, 1, 2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 3, 3, 1, 1);

        Status = new QLabel(groupBox);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setMinimumSize(QSize(100, 20));
        Status->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));

        gridLayout_2->addWidget(Status, 4, 1, 1, 1);

        Test_Connect = new QPushButton(groupBox);
        Test_Connect->setObjectName(QString::fromUtf8("Test_Connect"));

        gridLayout_2->addWidget(Test_Connect, 4, 2, 1, 1);

        Save_Param = new QPushButton(groupBox);
        Save_Param->setObjectName(QString::fromUtf8("Save_Param"));

        gridLayout_2->addWidget(Save_Param, 4, 3, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 3);

        User = new QLineEdit(groupBox);
        User->setObjectName(QString::fromUtf8("User"));

        gridLayout_2->addWidget(User, 1, 1, 1, 3);

        PassWord = new QLineEdit(groupBox);
        PassWord->setObjectName(QString::fromUtf8("PassWord"));

        gridLayout_2->addWidget(PassWord, 2, 1, 1, 3);

        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);

        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(YtShareFolderSetting);

        QMetaObject::connectSlotsByName(YtShareFolderSetting);
    } // setupUi

    void retranslateUi(QDialog *YtShareFolderSetting)
    {
        YtShareFolderSetting->setWindowTitle(QCoreApplication::translate("YtShareFolderSetting", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("YtShareFolderSetting", "\345\205\261\344\272\253\346\226\207\344\273\266\345\244\271\345\217\202\346\225\260\351\205\215\347\275\256\347\225\214\351\235\242", nullptr));
        label_4->setText(QCoreApplication::translate("YtShareFolderSetting", "\345\212\240\350\275\275Dll:", nullptr));
        label_2->setText(QCoreApplication::translate("YtShareFolderSetting", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_3->setText(QCoreApplication::translate("YtShareFolderSetting", "\345\257\206\347\240\201:", nullptr));
        label->setText(QCoreApplication::translate("YtShareFolderSetting", "\345\205\261\344\272\253\350\267\257\345\276\204", nullptr));
        pushButton->setText(QCoreApplication::translate("YtShareFolderSetting", "...", nullptr));
        Status->setText(QString());
        Test_Connect->setText(QCoreApplication::translate("YtShareFolderSetting", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        Save_Param->setText(QCoreApplication::translate("YtShareFolderSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YtShareFolderSetting: public Ui_YtShareFolderSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YTSHAREFOLDERSETTING_H
