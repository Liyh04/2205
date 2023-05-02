/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
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
    QPushButton *showClientButton;
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
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 50, 451, 286));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        serverGet = new QLineEdit(layoutWidget);
        serverGet->setObjectName("serverGet");

        gridLayout->addWidget(serverGet, 3, 2, 1, 2);

        clientGetEdit = new QLineEdit(layoutWidget);
        clientGetEdit->setObjectName("clientGetEdit");

        gridLayout->addWidget(clientGetEdit, 2, 0, 1, 1);

        lastOneLabel = new QLabel(layoutWidget);
        lastOneLabel->setObjectName("lastOneLabel");
        lastOneLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lastOneLabel, 1, 2, 1, 2);

        clientSendEdit = new QLineEdit(layoutWidget);
        clientSendEdit->setObjectName("clientSendEdit");

        gridLayout->addWidget(clientSendEdit, 4, 0, 1, 1);

        serverSendButton = new QPushButton(layoutWidget);
        serverSendButton->setObjectName("serverSendButton");

        gridLayout->addWidget(serverSendButton, 4, 4, 1, 1);

        SGG_OP = new QPushButton(layoutWidget);
        SGG_OP->setObjectName("SGG_OP");

        gridLayout->addWidget(SGG_OP, 10, 4, 1, 1);

        serverSendEdit = new QLineEdit(layoutWidget);
        serverSendEdit->setObjectName("serverSendEdit");

        gridLayout->addWidget(serverSendEdit, 4, 2, 1, 2);

        reSetButton = new QPushButton(layoutWidget);
        reSetButton->setObjectName("reSetButton");

        gridLayout->addWidget(reSetButton, 0, 3, 1, 1);

        SREJECT_OP = new QPushButton(layoutWidget);
        SREJECT_OP->setObjectName("SREJECT_OP");

        gridLayout->addWidget(SREJECT_OP, 7, 4, 1, 1);

        serverSend = new QLineEdit(layoutWidget);
        serverSend->setObjectName("serverSend");

        gridLayout->addWidget(serverSend, 5, 2, 1, 2);

        serverGetEdit = new QLineEdit(layoutWidget);
        serverGetEdit->setObjectName("serverGetEdit");

        gridLayout->addWidget(serverGetEdit, 2, 2, 1, 2);

        clientGet = new QLineEdit(layoutWidget);
        clientGet->setObjectName("clientGet");

        gridLayout->addWidget(clientGet, 3, 0, 1, 1);

        PORTEdit = new QLineEdit(layoutWidget);
        PORTEdit->setObjectName("PORTEdit");
        PORTEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PORTEdit, 0, 1, 1, 2);

        CREADY_OP = new QPushButton(layoutWidget);
        CREADY_OP->setObjectName("CREADY_OP");

        gridLayout->addWidget(CREADY_OP, 6, 1, 1, 1);

        SMOVE_OP = new QPushButton(layoutWidget);
        SMOVE_OP->setObjectName("SMOVE_OP");

        gridLayout->addWidget(SMOVE_OP, 9, 4, 1, 1);

        CREJECT_OP = new QPushButton(layoutWidget);
        CREJECT_OP->setObjectName("CREJECT_OP");

        gridLayout->addWidget(CREJECT_OP, 7, 1, 1, 1);

        showClientButton = new QPushButton(layoutWidget);
        showClientButton->setObjectName("showClientButton");

        gridLayout->addWidget(showClientButton, 0, 4, 1, 1);

        clientSendButton = new QPushButton(layoutWidget);
        clientSendButton->setObjectName("clientSendButton");

        gridLayout->addWidget(clientSendButton, 4, 1, 1, 1);

        reConnectButton = new QPushButton(layoutWidget);
        reConnectButton->setObjectName("reConnectButton");

        gridLayout->addWidget(reConnectButton, 1, 1, 1, 1);

        getButton_1 = new QPushButton(layoutWidget);
        getButton_1->setObjectName("getButton_1");

        gridLayout->addWidget(getButton_1, 2, 1, 1, 1);

        CGG_OP = new QPushButton(layoutWidget);
        CGG_OP->setObjectName("CGG_OP");

        gridLayout->addWidget(CGG_OP, 10, 1, 1, 1);

        SREADY_OP = new QPushButton(layoutWidget);
        SREADY_OP->setObjectName("SREADY_OP");

        gridLayout->addWidget(SREADY_OP, 6, 4, 1, 1);

        CLEAVE_OP = new QPushButton(layoutWidget);
        CLEAVE_OP->setObjectName("CLEAVE_OP");

        gridLayout->addWidget(CLEAVE_OP, 8, 1, 1, 1);

        reStartButton = new QPushButton(layoutWidget);
        reStartButton->setObjectName("reStartButton");

        gridLayout->addWidget(reStartButton, 1, 4, 1, 1);

        clientSend = new QLineEdit(layoutWidget);
        clientSend->setObjectName("clientSend");

        gridLayout->addWidget(clientSend, 5, 0, 1, 1);

        getButton_2 = new QPushButton(layoutWidget);
        getButton_2->setObjectName("getButton_2");

        gridLayout->addWidget(getButton_2, 2, 4, 1, 1);

        SLEAVE_OP = new QPushButton(layoutWidget);
        SLEAVE_OP->setObjectName("SLEAVE_OP");

        gridLayout->addWidget(SLEAVE_OP, 8, 4, 1, 1);

        CMOVE_OP = new QPushButton(layoutWidget);
        CMOVE_OP->setObjectName("CMOVE_OP");

        gridLayout->addWidget(CMOVE_OP, 9, 1, 1, 1);

        IPEdit = new QLineEdit(layoutWidget);
        IPEdit->setObjectName("IPEdit");
        IPEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(IPEdit, 0, 0, 1, 1);

        connectLabel = new QLabel(layoutWidget);
        connectLabel->setObjectName("connectLabel");
        connectLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(connectLabel, 1, 0, 1, 1);

        CilentGiveup = new QPushButton(layoutWidget);
        CilentGiveup->setObjectName("CilentGiveup");

        gridLayout->addWidget(CilentGiveup, 11, 1, 1, 1);

        ServerGiveup_2 = new QPushButton(layoutWidget);
        ServerGiveup_2->setObjectName("ServerGiveup_2");

        gridLayout->addWidget(ServerGiveup_2, 11, 4, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
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
        showClientButton->setText(QCoreApplication::translate("Widget", "ShowClients", nullptr));
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
