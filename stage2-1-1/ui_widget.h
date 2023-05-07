/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcd_sec;
    QLCDNumber *lcd_min;
    QLabel *label_3;
    QLabel *lastOneLabel;
    QLineEdit *IPEdit;
    QPushButton *reConnectButton;
    QPushButton *SREJECT_OP;
    QLineEdit *serverGetEdit;
    QPushButton *SLEAVE_OP;
    QPushButton *getButton_1;
    QPushButton *SMOVE_OP;
    QLineEdit *serverSendEdit;
    QLineEdit *clientSend;
    QPushButton *reSetButton;
    QLabel *connectLabel;
    QPushButton *CREJECT_OP;
    QPushButton *showClientButton;
    QPushButton *CLEAVE_OP;
    QPushButton *getButton_2;
    QPushButton *reStartButton;
    QPushButton *CGG_OP;
    QLineEdit *serverSend;
    QLineEdit *PORTEdit;
    QLineEdit *clientSendEdit;
    QLineEdit *serverGet;
    QPushButton *CilentGiveup;
    QPushButton *SREADY_OP;
    QPushButton *SGG_OP;
    QPushButton *serverSendButton;
    QPushButton *CREADY_OP;
    QPushButton *ServerGiveup_2;
    QLineEdit *clientGet;
    QPushButton *CMOVE_OP;
    QPushButton *clientSendButton;
    QLineEdit *clientGetEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1100, 600);
        lcd_sec = new QLCDNumber(Widget);
        lcd_sec->setObjectName("lcd_sec");
        lcd_sec->setGeometry(QRect(845, 20, 81, 71));
        lcd_sec->setDigitCount(2);
        lcd_sec->setProperty("intValue", QVariant(0));
        lcd_min = new QLCDNumber(Widget);
        lcd_min->setObjectName("lcd_min");
        lcd_min->setGeometry(QRect(765, 20, 81, 71));
        lcd_min->setDigitCount(2);
        lcd_min->setProperty("intValue", QVariant(0));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(800, 100, 111, 23));
        label_3->setStyleSheet(QString::fromUtf8("font: 600 italic 22pt \"Cascadia Mono SemiBold\";"));
        lastOneLabel = new QLabel(Widget);
        lastOneLabel->setObjectName("lastOneLabel");
        lastOneLabel->setGeometry(QRect(845, 175, 113, 28));
        lastOneLabel->setAlignment(Qt::AlignCenter);
        IPEdit = new QLineEdit(Widget);
        IPEdit->setObjectName("IPEdit");
        IPEdit->setGeometry(QRect(630, 140, 113, 27));
        IPEdit->setAlignment(Qt::AlignCenter);
        reConnectButton = new QPushButton(Widget);
        reConnectButton->setObjectName("reConnectButton");
        reConnectButton->setGeometry(QRect(750, 175, 88, 28));
        SREJECT_OP = new QPushButton(Widget);
        SREJECT_OP->setObjectName("SREJECT_OP");
        SREJECT_OP->setGeometry(QRect(965, 383, 108, 28));
        serverGetEdit = new QLineEdit(Widget);
        serverGetEdit->setObjectName("serverGetEdit");
        serverGetEdit->setGeometry(QRect(845, 210, 113, 27));
        SLEAVE_OP = new QPushButton(Widget);
        SLEAVE_OP->setObjectName("SLEAVE_OP");
        SLEAVE_OP->setGeometry(QRect(965, 418, 108, 28));
        getButton_1 = new QPushButton(Widget);
        getButton_1->setObjectName("getButton_1");
        getButton_1->setGeometry(QRect(750, 210, 88, 28));
        SMOVE_OP = new QPushButton(Widget);
        SMOVE_OP->setObjectName("SMOVE_OP");
        SMOVE_OP->setGeometry(QRect(965, 453, 108, 28));
        serverSendEdit = new QLineEdit(Widget);
        serverSendEdit->setObjectName("serverSendEdit");
        serverSendEdit->setGeometry(QRect(845, 279, 113, 27));
        clientSend = new QLineEdit(Widget);
        clientSend->setObjectName("clientSend");
        clientSend->setGeometry(QRect(630, 314, 113, 27));
        reSetButton = new QPushButton(Widget);
        reSetButton->setObjectName("reSetButton");
        reSetButton->setGeometry(QRect(878, 139, 80, 29));
        connectLabel = new QLabel(Widget);
        connectLabel->setObjectName("connectLabel");
        connectLabel->setGeometry(QRect(630, 175, 113, 28));
        connectLabel->setAlignment(Qt::AlignCenter);
        CREJECT_OP = new QPushButton(Widget);
        CREJECT_OP->setObjectName("CREJECT_OP");
        CREJECT_OP->setGeometry(QRect(750, 383, 88, 28));
        showClientButton = new QPushButton(Widget);
        showClientButton->setObjectName("showClientButton");
        showClientButton->setGeometry(QRect(965, 139, 108, 29));
        CLEAVE_OP = new QPushButton(Widget);
        CLEAVE_OP->setObjectName("CLEAVE_OP");
        CLEAVE_OP->setGeometry(QRect(750, 418, 88, 28));
        getButton_2 = new QPushButton(Widget);
        getButton_2->setObjectName("getButton_2");
        getButton_2->setGeometry(QRect(965, 210, 108, 28));
        reStartButton = new QPushButton(Widget);
        reStartButton->setObjectName("reStartButton");
        reStartButton->setGeometry(QRect(965, 175, 108, 28));
        CGG_OP = new QPushButton(Widget);
        CGG_OP->setObjectName("CGG_OP");
        CGG_OP->setGeometry(QRect(750, 488, 88, 29));
        serverSend = new QLineEdit(Widget);
        serverSend->setObjectName("serverSend");
        serverSend->setGeometry(QRect(845, 314, 113, 27));
        PORTEdit = new QLineEdit(Widget);
        PORTEdit->setObjectName("PORTEdit");
        PORTEdit->setGeometry(QRect(750, 140, 121, 27));
        PORTEdit->setAlignment(Qt::AlignCenter);
        clientSendEdit = new QLineEdit(Widget);
        clientSendEdit->setObjectName("clientSendEdit");
        clientSendEdit->setGeometry(QRect(630, 279, 113, 27));
        serverGet = new QLineEdit(Widget);
        serverGet->setObjectName("serverGet");
        serverGet->setGeometry(QRect(845, 245, 113, 27));
        CilentGiveup = new QPushButton(Widget);
        CilentGiveup->setObjectName("CilentGiveup");
        CilentGiveup->setGeometry(QRect(750, 524, 88, 28));
        SREADY_OP = new QPushButton(Widget);
        SREADY_OP->setObjectName("SREADY_OP");
        SREADY_OP->setGeometry(QRect(965, 348, 108, 28));
        SGG_OP = new QPushButton(Widget);
        SGG_OP->setObjectName("SGG_OP");
        SGG_OP->setGeometry(QRect(965, 488, 108, 29));
        serverSendButton = new QPushButton(Widget);
        serverSendButton->setObjectName("serverSendButton");
        serverSendButton->setGeometry(QRect(965, 279, 108, 28));
        serverSendButton->setMouseTracking(true);
        serverSendButton->setTabletTracking(true);
        CREADY_OP = new QPushButton(Widget);
        CREADY_OP->setObjectName("CREADY_OP");
        CREADY_OP->setGeometry(QRect(750, 348, 88, 28));
        ServerGiveup_2 = new QPushButton(Widget);
        ServerGiveup_2->setObjectName("ServerGiveup_2");
        ServerGiveup_2->setGeometry(QRect(965, 524, 108, 28));
        clientGet = new QLineEdit(Widget);
        clientGet->setObjectName("clientGet");
        clientGet->setGeometry(QRect(630, 245, 113, 27));
        CMOVE_OP = new QPushButton(Widget);
        CMOVE_OP->setObjectName("CMOVE_OP");
        CMOVE_OP->setGeometry(QRect(750, 453, 88, 28));
        clientSendButton = new QPushButton(Widget);
        clientSendButton->setObjectName("clientSendButton");
        clientSendButton->setGeometry(QRect(750, 279, 88, 28));
        clientGetEdit = new QLineEdit(Widget);
        clientGetEdit->setObjectName("clientGetEdit");
        clientGetEdit->setGeometry(QRect(630, 210, 113, 27));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "BLACK", nullptr));
        lastOneLabel->setText(QCoreApplication::translate("Widget", "LastOne: ", nullptr));
        IPEdit->setText(QCoreApplication::translate("Widget", "10.47.145.75", nullptr));
        reConnectButton->setText(QCoreApplication::translate("Widget", "Reconnect", nullptr));
        SREJECT_OP->setText(QCoreApplication::translate("Widget", "REJECT_OP", nullptr));
        serverGetEdit->setText(QString());
        SLEAVE_OP->setText(QCoreApplication::translate("Widget", "LEAVE_OP", nullptr));
        getButton_1->setText(QCoreApplication::translate("Widget", "CilentGet", nullptr));
        SMOVE_OP->setText(QCoreApplication::translate("Widget", "MOVE_OP", nullptr));
        serverSendEdit->setText(QString());
        clientSend->setText(QString());
        reSetButton->setText(QCoreApplication::translate("Widget", "ReSet", nullptr));
        connectLabel->setText(QCoreApplication::translate("Widget", "Connection fail", nullptr));
        CREJECT_OP->setText(QCoreApplication::translate("Widget", "REJECT_OP", nullptr));
        showClientButton->setText(QCoreApplication::translate("Widget", "ShowClients", nullptr));
        CLEAVE_OP->setText(QCoreApplication::translate("Widget", "LEAVE_OP", nullptr));
        getButton_2->setText(QCoreApplication::translate("Widget", "ServerGet", nullptr));
        reStartButton->setText(QCoreApplication::translate("Widget", "RestartServer", nullptr));
        CGG_OP->setText(QCoreApplication::translate("Widget", "GG_OP", nullptr));
        serverSend->setText(QString());
        PORTEdit->setText(QCoreApplication::translate("Widget", "16667", nullptr));
        clientSendEdit->setText(QString());
        serverGet->setText(QString());
        CilentGiveup->setText(QCoreApplication::translate("Widget", "GiveUp", nullptr));
        SREADY_OP->setText(QCoreApplication::translate("Widget", "READY_OP", nullptr));
        SGG_OP->setText(QCoreApplication::translate("Widget", "GG_OP", nullptr));
        serverSendButton->setText(QCoreApplication::translate("Widget", "ServerSend", nullptr));
        CREADY_OP->setText(QCoreApplication::translate("Widget", "READY_OP", nullptr));
        ServerGiveup_2->setText(QCoreApplication::translate("Widget", "GiveUp", nullptr));
        clientGet->setText(QString());
        CMOVE_OP->setText(QCoreApplication::translate("Widget", "MOVE_OP", nullptr));
        clientSendButton->setText(QCoreApplication::translate("Widget", "ClientSend", nullptr));
        clientGetEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
