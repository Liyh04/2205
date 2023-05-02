/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcd_sec;
    QLCDNumber *lcd_min;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit1;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLineEdit *serverGet;
    QLineEdit *clientGetEdit;
    QLabel *lastOneLabel;
    QLineEdit *clientSendEdit;
    QPushButton *serverSendButton;
    QPushButton *SGG_OP;
    QLineEdit *serverSendEdit;
    QPushButton *reSetButton;
    QPushButton *SREJECT_OP;
    QLineEdit *serverSend;
    QLineEdit *serverGetEdit;
    QLineEdit *clientGet;
    QLineEdit *PORTEdit;
    QPushButton *CREADY_OP;
    QPushButton *SMOVE_OP;
    QPushButton *CREJECT_OP;
    QPushButton *pushButton_2;
    QPushButton *clientSendButton;
    QPushButton *reConnectButton;
    QPushButton *getButton_1;
    QPushButton *CGG_OP;
    QPushButton *SREADY_OP;
    QPushButton *CLEAVE_OP;
    QPushButton *reStartButton;
    QLineEdit *clientSend;
    QPushButton *getButton_2;
    QPushButton *SLEAVE_OP;
    QPushButton *CMOVE_OP;
    QLineEdit *IPEdit;
    QLabel *connectLabel;
    QPushButton *CilentGiveup;
    QPushButton *ServerGiveup_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1295, 600);
        lcd_sec = new QLCDNumber(Widget);
        lcd_sec->setObjectName(QString::fromUtf8("lcd_sec"));
        lcd_sec->setGeometry(QRect(840, 30, 81, 71));
        lcd_sec->setDigitCount(2);
        lcd_sec->setProperty("intValue", QVariant(0));
        lcd_min = new QLCDNumber(Widget);
        lcd_min->setObjectName(QString::fromUtf8("lcd_min"));
        lcd_min->setGeometry(QRect(760, 30, 81, 71));
        lcd_min->setDigitCount(2);
        lcd_min->setProperty("intValue", QVariant(0));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setEnabled(true);
        layoutWidget->setGeometry(QRect(790, 140, 114, 245));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);

        verticalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);

        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);

        verticalLayout_2->addWidget(lineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);

        verticalLayout_2->addWidget(label_2);

        lineEdit1 = new QLineEdit(layoutWidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        lineEdit1->setEnabled(true);

        verticalLayout_2->addWidget(lineEdit1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(795, 110, 111, 23));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 italic 22pt \"Cascadia Mono SemiBold\";"));
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(930, 10, 451, 423));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        serverGet = new QLineEdit(layoutWidget1);
        serverGet->setObjectName(QString::fromUtf8("serverGet"));

        gridLayout->addWidget(serverGet, 3, 2, 1, 2);

        clientGetEdit = new QLineEdit(layoutWidget1);
        clientGetEdit->setObjectName(QString::fromUtf8("clientGetEdit"));

        gridLayout->addWidget(clientGetEdit, 2, 0, 1, 1);

        lastOneLabel = new QLabel(layoutWidget1);
        lastOneLabel->setObjectName(QString::fromUtf8("lastOneLabel"));
        lastOneLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lastOneLabel, 1, 2, 1, 2);

        clientSendEdit = new QLineEdit(layoutWidget1);
        clientSendEdit->setObjectName(QString::fromUtf8("clientSendEdit"));

        gridLayout->addWidget(clientSendEdit, 4, 0, 1, 1);

        serverSendButton = new QPushButton(layoutWidget1);
        serverSendButton->setObjectName(QString::fromUtf8("serverSendButton"));

        gridLayout->addWidget(serverSendButton, 4, 4, 1, 1);

        SGG_OP = new QPushButton(layoutWidget1);
        SGG_OP->setObjectName(QString::fromUtf8("SGG_OP"));

        gridLayout->addWidget(SGG_OP, 10, 4, 1, 1);

        serverSendEdit = new QLineEdit(layoutWidget1);
        serverSendEdit->setObjectName(QString::fromUtf8("serverSendEdit"));

        gridLayout->addWidget(serverSendEdit, 4, 2, 1, 2);

        reSetButton = new QPushButton(layoutWidget1);
        reSetButton->setObjectName(QString::fromUtf8("reSetButton"));

        gridLayout->addWidget(reSetButton, 0, 3, 1, 1);

        SREJECT_OP = new QPushButton(layoutWidget1);
        SREJECT_OP->setObjectName(QString::fromUtf8("SREJECT_OP"));

        gridLayout->addWidget(SREJECT_OP, 7, 4, 1, 1);

        serverSend = new QLineEdit(layoutWidget1);
        serverSend->setObjectName(QString::fromUtf8("serverSend"));

        gridLayout->addWidget(serverSend, 5, 2, 1, 2);

        serverGetEdit = new QLineEdit(layoutWidget1);
        serverGetEdit->setObjectName(QString::fromUtf8("serverGetEdit"));

        gridLayout->addWidget(serverGetEdit, 2, 2, 1, 2);

        clientGet = new QLineEdit(layoutWidget1);
        clientGet->setObjectName(QString::fromUtf8("clientGet"));

        gridLayout->addWidget(clientGet, 3, 0, 1, 1);

        PORTEdit = new QLineEdit(layoutWidget1);
        PORTEdit->setObjectName(QString::fromUtf8("PORTEdit"));
        PORTEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PORTEdit, 0, 1, 1, 2);

        CREADY_OP = new QPushButton(layoutWidget1);
        CREADY_OP->setObjectName(QString::fromUtf8("CREADY_OP"));

        gridLayout->addWidget(CREADY_OP, 6, 1, 1, 1);

        SMOVE_OP = new QPushButton(layoutWidget1);
        SMOVE_OP->setObjectName(QString::fromUtf8("SMOVE_OP"));

        gridLayout->addWidget(SMOVE_OP, 9, 4, 1, 1);

        CREJECT_OP = new QPushButton(layoutWidget1);
        CREJECT_OP->setObjectName(QString::fromUtf8("CREJECT_OP"));

        gridLayout->addWidget(CREJECT_OP, 7, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 4, 1, 1);

        clientSendButton = new QPushButton(layoutWidget1);
        clientSendButton->setObjectName(QString::fromUtf8("clientSendButton"));

        gridLayout->addWidget(clientSendButton, 4, 1, 1, 1);

        reConnectButton = new QPushButton(layoutWidget1);
        reConnectButton->setObjectName(QString::fromUtf8("reConnectButton"));

        gridLayout->addWidget(reConnectButton, 1, 1, 1, 1);

        getButton_1 = new QPushButton(layoutWidget1);
        getButton_1->setObjectName(QString::fromUtf8("getButton_1"));

        gridLayout->addWidget(getButton_1, 2, 1, 1, 1);

        CGG_OP = new QPushButton(layoutWidget1);
        CGG_OP->setObjectName(QString::fromUtf8("CGG_OP"));

        gridLayout->addWidget(CGG_OP, 10, 1, 1, 1);

        SREADY_OP = new QPushButton(layoutWidget1);
        SREADY_OP->setObjectName(QString::fromUtf8("SREADY_OP"));

        gridLayout->addWidget(SREADY_OP, 6, 4, 1, 1);

        CLEAVE_OP = new QPushButton(layoutWidget1);
        CLEAVE_OP->setObjectName(QString::fromUtf8("CLEAVE_OP"));

        gridLayout->addWidget(CLEAVE_OP, 8, 1, 1, 1);

        reStartButton = new QPushButton(layoutWidget1);
        reStartButton->setObjectName(QString::fromUtf8("reStartButton"));

        gridLayout->addWidget(reStartButton, 1, 4, 1, 1);

        clientSend = new QLineEdit(layoutWidget1);
        clientSend->setObjectName(QString::fromUtf8("clientSend"));

        gridLayout->addWidget(clientSend, 5, 0, 1, 1);

        getButton_2 = new QPushButton(layoutWidget1);
        getButton_2->setObjectName(QString::fromUtf8("getButton_2"));

        gridLayout->addWidget(getButton_2, 2, 4, 1, 1);

        SLEAVE_OP = new QPushButton(layoutWidget1);
        SLEAVE_OP->setObjectName(QString::fromUtf8("SLEAVE_OP"));

        gridLayout->addWidget(SLEAVE_OP, 8, 4, 1, 1);

        CMOVE_OP = new QPushButton(layoutWidget1);
        CMOVE_OP->setObjectName(QString::fromUtf8("CMOVE_OP"));

        gridLayout->addWidget(CMOVE_OP, 9, 1, 1, 1);

        IPEdit = new QLineEdit(layoutWidget1);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));
        IPEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(IPEdit, 0, 0, 1, 1);

        connectLabel = new QLabel(layoutWidget1);
        connectLabel->setObjectName(QString::fromUtf8("connectLabel"));
        connectLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(connectLabel, 1, 0, 1, 1);

        CilentGiveup = new QPushButton(layoutWidget1);
        CilentGiveup->setObjectName(QString::fromUtf8("CilentGiveup"));

        gridLayout->addWidget(CilentGiveup, 11, 1, 1, 1);

        ServerGiveup_2 = new QPushButton(layoutWidget1);
        ServerGiveup_2->setObjectName(QString::fromUtf8("ServerGiveup_2"));

        gridLayout->addWidget(ServerGiveup_2, 11, 4, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "GIVE UP", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Player 1(Black)", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Player 2(White)", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "BLACK", nullptr));
        serverGet->setText(QCoreApplication::translate("Widget", "data2:", nullptr));
        clientGetEdit->setText(QCoreApplication::translate("Widget", "data1:", nullptr));
        lastOneLabel->setText(QCoreApplication::translate("Widget", "LastOne: ", nullptr));
        clientSendEdit->setText(QCoreApplication::translate("Widget", "data1:", nullptr));
        serverSendButton->setText(QCoreApplication::translate("Widget", "ServerSend", nullptr));
        SGG_OP->setText(QCoreApplication::translate("Widget", "GG_OP", nullptr));
        serverSendEdit->setText(QCoreApplication::translate("Widget", "data1:", nullptr));
        reSetButton->setText(QCoreApplication::translate("Widget", "ReSet", nullptr));
        SREJECT_OP->setText(QCoreApplication::translate("Widget", "REJECT_OP", nullptr));
        serverSend->setText(QCoreApplication::translate("Widget", "data2:", nullptr));
        serverGetEdit->setText(QCoreApplication::translate("Widget", "data1:", nullptr));
        clientGet->setText(QCoreApplication::translate("Widget", "data2:", nullptr));
        PORTEdit->setText(QCoreApplication::translate("Widget", "16667", nullptr));
        CREADY_OP->setText(QCoreApplication::translate("Widget", "READY_OP", nullptr));
        SMOVE_OP->setText(QCoreApplication::translate("Widget", "MOVE_OP", nullptr));
        CREJECT_OP->setText(QCoreApplication::translate("Widget", "REJECT_OP", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "ShowClients", nullptr));
        clientSendButton->setText(QCoreApplication::translate("Widget", "ClientSend", nullptr));
        reConnectButton->setText(QCoreApplication::translate("Widget", "Reconnect", nullptr));
        getButton_1->setText(QCoreApplication::translate("Widget", "CilentGet", nullptr));
        CGG_OP->setText(QCoreApplication::translate("Widget", "GG_OP", nullptr));
        SREADY_OP->setText(QCoreApplication::translate("Widget", "READY_OP", nullptr));
        CLEAVE_OP->setText(QCoreApplication::translate("Widget", "LEAVE_OP", nullptr));
        reStartButton->setText(QCoreApplication::translate("Widget", "RestartServer", nullptr));
        clientSend->setText(QCoreApplication::translate("Widget", "data2:", nullptr));
        getButton_2->setText(QCoreApplication::translate("Widget", "ServerGet", nullptr));
        SLEAVE_OP->setText(QCoreApplication::translate("Widget", "LEAVE_OP", nullptr));
        CMOVE_OP->setText(QCoreApplication::translate("Widget", "MOVE_OP", nullptr));
        IPEdit->setText(QCoreApplication::translate("Widget", "10.47.145.75", nullptr));
        connectLabel->setText(QCoreApplication::translate("Widget", "Connection fail", nullptr));
        CilentGiveup->setText(QCoreApplication::translate("Widget", "GiveUp", nullptr));
        ServerGiveup_2->setText(QCoreApplication::translate("Widget", "GiveUp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
