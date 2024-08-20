/********************************************************************************
** Form generated from reading UI file 'plccom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLCCOM_H
#define UI_PLCCOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PlcCom
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_4;
    QLineEdit *PLC_IP;
    QLabel *label_5;
    QLineEdit *PLC_PORT;
    QLabel *label_6;
    QLineEdit *LOCAL_PORT;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *SaveParam;

    void setupUi(QDialog *PlcCom)
    {
        if (PlcCom->objectName().isEmpty())
            PlcCom->setObjectName(QString::fromUtf8("PlcCom"));
        PlcCom->resize(557, 191);
        gridLayout = new QGridLayout(PlcCom);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(PlcCom);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_3->addWidget(comboBox, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        PLC_IP = new QLineEdit(groupBox);
        PLC_IP->setObjectName(QString::fromUtf8("PLC_IP"));

        gridLayout_3->addWidget(PLC_IP, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        PLC_PORT = new QLineEdit(groupBox);
        PLC_PORT->setObjectName(QString::fromUtf8("PLC_PORT"));

        gridLayout_3->addWidget(PLC_PORT, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_6, 3, 0, 1, 1);

        LOCAL_PORT = new QLineEdit(groupBox);
        LOCAL_PORT->setObjectName(QString::fromUtf8("LOCAL_PORT"));

        gridLayout_3->addWidget(LOCAL_PORT, 3, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        SaveParam = new QPushButton(groupBox);
        SaveParam->setObjectName(QString::fromUtf8("SaveParam"));

        gridLayout_2->addWidget(SaveParam, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 4, 0, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(PlcCom);

        QMetaObject::connectSlotsByName(PlcCom);
    } // setupUi

    void retranslateUi(QDialog *PlcCom)
    {
        PlcCom->setWindowTitle(QCoreApplication::translate("PlcCom", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PlcCom", "PLC\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("PlcCom", "\345\212\240\350\275\275dll:", nullptr));
        label_4->setText(QCoreApplication::translate("PlcCom", "PLC IP:", nullptr));
        PLC_IP->setText(QCoreApplication::translate("PlcCom", "192.168.10.100", nullptr));
        label_5->setText(QCoreApplication::translate("PlcCom", "\347\253\257\345\217\243:", nullptr));
        PLC_PORT->setText(QCoreApplication::translate("PlcCom", "5000", nullptr));
        label_6->setText(QCoreApplication::translate("PlcCom", "\346\234\254\345\234\260\347\253\257\345\217\243:", nullptr));
        LOCAL_PORT->setText(QCoreApplication::translate("PlcCom", "0", nullptr));
        SaveParam->setText(QCoreApplication::translate("PlcCom", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlcCom: public Ui_PlcCom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLCCOM_H
