/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
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
    QLineEdit *ServerSend;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 80, 451, 423));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        serverGet = new QLineEdit(layoutWidget);
        serverGet->setObjectName(QString::fromUtf8("serverGet"));

        gridLayout->addWidget(serverGet, 3, 2, 1, 2);

        clientGetEdit = new QLineEdit(layoutWidget);
        clientGetEdit->setObjectName(QString::fromUtf8("clientGetEdit"));

        gridLayout->addWidget(clientGetEdit, 2, 0, 1, 1);

        lastOneLabel = new QLabel(layoutWidget);
        lastOneLabel->setObjectName(QString::fromUtf8("lastOneLabel"));
        lastOneLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lastOneLabel, 1, 2, 1, 2);

        clientSendEdit = new QLineEdit(layoutWidget);
        clientSendEdit->setObjectName(QString::fromUtf8("clientSendEdit"));

        gridLayout->addWidget(clientSendEdit, 4, 0, 1, 1);

        serverSendButton = new QPushButton(layoutWidget);
        serverSendButton->setObjectName(QString::fromUtf8("serverSendButton"));

        gridLayout->addWidget(serverSendButton, 4, 4, 1, 1);

        SGG_OP = new QPushButton(layoutWidget);
        SGG_OP->setObjectName(QString::fromUtf8("SGG_OP"));

        gridLayout->addWidget(SGG_OP, 10, 4, 1, 1);

        serverSendEdit = new QLineEdit(layoutWidget);
        serverSendEdit->setObjectName(QString::fromUtf8("serverSendEdit"));

        gridLayout->addWidget(serverSendEdit, 4, 2, 1, 2);

        reSetButton = new QPushButton(layoutWidget);
        reSetButton->setObjectName(QString::fromUtf8("reSetButton"));

        gridLayout->addWidget(reSetButton, 0, 3, 1, 1);

        SREJECT_OP = new QPushButton(layoutWidget);
        SREJECT_OP->setObjectName(QString::fromUtf8("SREJECT_OP"));

        gridLayout->addWidget(SREJECT_OP, 7, 4, 1, 1);

        ServerSend = new QLineEdit(layoutWidget);
        ServerSend->setObjectName(QString::fromUtf8("ServerSend"));

        gridLayout->addWidget(ServerSend, 5, 2, 1, 2);

        serverGetEdit = new QLineEdit(layoutWidget);
        serverGetEdit->setObjectName(QString::fromUtf8("serverGetEdit"));

        gridLayout->addWidget(serverGetEdit, 2, 2, 1, 2);

        clientGet = new QLineEdit(layoutWidget);
        clientGet->setObjectName(QString::fromUtf8("clientGet"));

        gridLayout->addWidget(clientGet, 3, 0, 1, 1);

        PORTEdit = new QLineEdit(layoutWidget);
        PORTEdit->setObjectName(QString::fromUtf8("PORTEdit"));
        PORTEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(PORTEdit, 0, 1, 1, 2);

        CREADY_OP = new QPushButton(layoutWidget);
        CREADY_OP->setObjectName(QString::fromUtf8("CREADY_OP"));

        gridLayout->addWidget(CREADY_OP, 6, 1, 1, 1);

        SMOVE_OP = new QPushButton(layoutWidget);
        SMOVE_OP->setObjectName(QString::fromUtf8("SMOVE_OP"));

        gridLayout->addWidget(SMOVE_OP, 9, 4, 1, 1);

        CREJECT_OP = new QPushButton(layoutWidget);
        CREJECT_OP->setObjectName(QString::fromUtf8("CREJECT_OP"));

        gridLayout->addWidget(CREJECT_OP, 7, 1, 1, 1);

        showClientButton = new QPushButton(layoutWidget);
        showClientButton->setObjectName(QString::fromUtf8("showClientButton"));

        gridLayout->addWidget(showClientButton, 0, 4, 1, 1);

        clientSendButton = new QPushButton(layoutWidget);
        clientSendButton->setObjectName(QString::fromUtf8("clientSendButton"));

        gridLayout->addWidget(clientSendButton, 4, 1, 1, 1);

        reConnectButton = new QPushButton(layoutWidget);
        reConnectButton->setObjectName(QString::fromUtf8("reConnectButton"));

        gridLayout->addWidget(reConnectButton, 1, 1, 1, 1);

        getButton_1 = new QPushButton(layoutWidget);
        getButton_1->setObjectName(QString::fromUtf8("getButton_1"));

        gridLayout->addWidget(getButton_1, 2, 1, 1, 1);

        CGG_OP = new QPushButton(layoutWidget);
        CGG_OP->setObjectName(QString::fromUtf8("CGG_OP"));

        gridLayout->addWidget(CGG_OP, 10, 1, 1, 1);

        SREADY_OP = new QPushButton(layoutWidget);
        SREADY_OP->setObjectName(QString::fromUtf8("SREADY_OP"));

        gridLayout->addWidget(SREADY_OP, 6, 4, 1, 1);

        CLEAVE_OP = new QPushButton(layoutWidget);
        CLEAVE_OP->setObjectName(QString::fromUtf8("CLEAVE_OP"));

        gridLayout->addWidget(CLEAVE_OP, 8, 1, 1, 1);

        reStartButton = new QPushButton(layoutWidget);
        reStartButton->setObjectName(QString::fromUtf8("reStartButton"));

        gridLayout->addWidget(reStartButton, 1, 4, 1, 1);

        clientSend = new QLineEdit(layoutWidget);
        clientSend->setObjectName(QString::fromUtf8("clientSend"));

        gridLayout->addWidget(clientSend, 5, 0, 1, 1);

        getButton_2 = new QPushButton(layoutWidget);
        getButton_2->setObjectName(QString::fromUtf8("getButton_2"));

        gridLayout->addWidget(getButton_2, 2, 4, 1, 1);

        SLEAVE_OP = new QPushButton(layoutWidget);
        SLEAVE_OP->setObjectName(QString::fromUtf8("SLEAVE_OP"));

        gridLayout->addWidget(SLEAVE_OP, 8, 4, 1, 1);

        CMOVE_OP = new QPushButton(layoutWidget);
        CMOVE_OP->setObjectName(QString::fromUtf8("CMOVE_OP"));

        gridLayout->addWidget(CMOVE_OP, 9, 1, 1, 1);

        IPEdit = new QLineEdit(layoutWidget);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));
        IPEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(IPEdit, 0, 0, 1, 1);

        connectLabel = new QLabel(layoutWidget);
        connectLabel->setObjectName(QString::fromUtf8("connectLabel"));
        connectLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(connectLabel, 1, 0, 1, 1);

        CilentGiveup = new QPushButton(layoutWidget);
        CilentGiveup->setObjectName(QString::fromUtf8("CilentGiveup"));

        gridLayout->addWidget(CilentGiveup, 11, 1, 1, 1);

        ServerGiveup_2 = new QPushButton(layoutWidget);
        ServerGiveup_2->setObjectName(QString::fromUtf8("ServerGiveup_2"));

        gridLayout->addWidget(ServerGiveup_2, 11, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        serverGet->setText(QCoreApplication::translate("MainWindow", "data2:", nullptr));
        clientGetEdit->setText(QCoreApplication::translate("MainWindow", "data1:", nullptr));
        lastOneLabel->setText(QCoreApplication::translate("MainWindow", "LastOne: ", nullptr));
        clientSendEdit->setText(QCoreApplication::translate("MainWindow", "data1:", nullptr));
        serverSendButton->setText(QCoreApplication::translate("MainWindow", "ServerSend", nullptr));
        SGG_OP->setText(QCoreApplication::translate("MainWindow", "GG_OP", nullptr));
        serverSendEdit->setText(QCoreApplication::translate("MainWindow", "data1:", nullptr));
        reSetButton->setText(QCoreApplication::translate("MainWindow", "ReSet", nullptr));
        SREJECT_OP->setText(QCoreApplication::translate("MainWindow", "REJECT_OP", nullptr));
        ServerSend->setText(QCoreApplication::translate("MainWindow", "data2:", nullptr));
        serverGetEdit->setText(QCoreApplication::translate("MainWindow", "data1:", nullptr));
        clientGet->setText(QCoreApplication::translate("MainWindow", "data2:", nullptr));
        PORTEdit->setText(QCoreApplication::translate("MainWindow", "16667", nullptr));
        CREADY_OP->setText(QCoreApplication::translate("MainWindow", "READY_OP", nullptr));
        SMOVE_OP->setText(QCoreApplication::translate("MainWindow", "MOVE_OP", nullptr));
        CREJECT_OP->setText(QCoreApplication::translate("MainWindow", "REJECT_OP", nullptr));
        showClientButton->setText(QCoreApplication::translate("MainWindow", "ShowClients", nullptr));
        clientSendButton->setText(QCoreApplication::translate("MainWindow", "ClientSend", nullptr));
        reConnectButton->setText(QCoreApplication::translate("MainWindow", "Reconnect", nullptr));
        getButton_1->setText(QCoreApplication::translate("MainWindow", "CilentGet", nullptr));
        CGG_OP->setText(QCoreApplication::translate("MainWindow", "GG_OP", nullptr));
        SREADY_OP->setText(QCoreApplication::translate("MainWindow", "READY_OP", nullptr));
        CLEAVE_OP->setText(QCoreApplication::translate("MainWindow", "LEAVE_OP", nullptr));
        reStartButton->setText(QCoreApplication::translate("MainWindow", "RestartServer", nullptr));
        clientSend->setText(QCoreApplication::translate("MainWindow", "data2:", nullptr));
        getButton_2->setText(QCoreApplication::translate("MainWindow", "ServerGet", nullptr));
        SLEAVE_OP->setText(QCoreApplication::translate("MainWindow", "LEAVE_OP", nullptr));
        CMOVE_OP->setText(QCoreApplication::translate("MainWindow", "MOVE_OP", nullptr));
        IPEdit->setText(QCoreApplication::translate("MainWindow", "10.47.145.75", nullptr));
        connectLabel->setText(QCoreApplication::translate("MainWindow", "Connection fail", nullptr));
        CilentGiveup->setText(QCoreApplication::translate("MainWindow", "GiveUp", nullptr));
        ServerGiveup_2->setText(QCoreApplication::translate("MainWindow", "GiveUp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
