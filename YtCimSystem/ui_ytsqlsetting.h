/********************************************************************************
** Form generated from reading UI file 'ytsqlsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YTSQLSETTING_H
#define UI_YTSQLSETTING_H

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

class Ui_YtSqlSetting
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QLabel *label_4;
    QLineEdit *DB_USER;
    QLabel *label_3;
    QPushButton *SaveParam;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *DB_PORT;
    QLabel *label_6;
    QLabel *Status;
    QPushButton *TestConnect;
    QLineEdit *DB_IP;
    QLineEdit *DB_PASSWORD;
    QLineEdit *DB_NAME;

    void setupUi(QDialog *YtSqlSetting)
    {
        if (YtSqlSetting->objectName().isEmpty())
            YtSqlSetting->setObjectName(QString::fromUtf8("YtSqlSetting"));
        YtSqlSetting->resize(627, 191);
        gridLayout = new QGridLayout(YtSqlSetting);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(YtSqlSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        DB_USER = new QLineEdit(groupBox);
        DB_USER->setObjectName(QString::fromUtf8("DB_USER"));

        gridLayout_2->addWidget(DB_USER, 5, 1, 1, 3);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 6, 0, 1, 1);

        SaveParam = new QPushButton(groupBox);
        SaveParam->setObjectName(QString::fromUtf8("SaveParam"));

        gridLayout_2->addWidget(SaveParam, 7, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 5, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        DB_PORT = new QLineEdit(groupBox);
        DB_PORT->setObjectName(QString::fromUtf8("DB_PORT"));

        gridLayout_2->addWidget(DB_PORT, 2, 1, 1, 3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        Status = new QLabel(groupBox);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));

        gridLayout_2->addWidget(Status, 7, 1, 1, 1);

        TestConnect = new QPushButton(groupBox);
        TestConnect->setObjectName(QString::fromUtf8("TestConnect"));

        gridLayout_2->addWidget(TestConnect, 7, 2, 1, 1);

        DB_IP = new QLineEdit(groupBox);
        DB_IP->setObjectName(QString::fromUtf8("DB_IP"));

        gridLayout_2->addWidget(DB_IP, 1, 1, 1, 3);

        DB_PASSWORD = new QLineEdit(groupBox);
        DB_PASSWORD->setObjectName(QString::fromUtf8("DB_PASSWORD"));

        gridLayout_2->addWidget(DB_PASSWORD, 6, 1, 1, 3);

        DB_NAME = new QLineEdit(groupBox);
        DB_NAME->setObjectName(QString::fromUtf8("DB_NAME"));

        gridLayout_2->addWidget(DB_NAME, 4, 1, 1, 3);

        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(YtSqlSetting);

        QMetaObject::connectSlotsByName(YtSqlSetting);
    } // setupUi

    void retranslateUi(QDialog *YtSqlSetting)
    {
        YtSqlSetting->setWindowTitle(QCoreApplication::translate("YtSqlSetting", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("YtSqlSetting", "\346\225\260\346\215\256\345\272\223\345\217\202\346\225\260\351\205\215\347\275\256\347\225\214\351\235\242", nullptr));
        label_4->setText(QCoreApplication::translate("YtSqlSetting", "\346\225\260\346\215\256\345\272\223IP:", nullptr));
        label_3->setText(QCoreApplication::translate("YtSqlSetting", "\345\257\206\347\240\201:", nullptr));
        SaveParam->setText(QCoreApplication::translate("YtSqlSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("YtSqlSetting", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_5->setText(QCoreApplication::translate("YtSqlSetting", "\347\253\257\345\217\243:", nullptr));
        label->setText(QCoreApplication::translate("YtSqlSetting", "\345\212\240\350\275\275dll:", nullptr));
        label_6->setText(QCoreApplication::translate("YtSqlSetting", "\346\225\260\346\215\256\345\272\223\345\220\215:", nullptr));
        Status->setText(QString());
        TestConnect->setText(QCoreApplication::translate("YtSqlSetting", "\346\265\213\350\257\225\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YtSqlSetting: public Ui_YtSqlSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YTSQLSETTING_H
