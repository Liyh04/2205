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
    QLineEdit *lineEdit_2;
    QLCDNumber *lcd_row;
    QLCDNumber *lcd_coloum;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(998, 600);
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
        layoutWidget->setGeometry(QRect(790, 140, 93, 245));
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

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);

        verticalLayout_2->addWidget(lineEdit_2);

        lcd_row = new QLCDNumber(Widget);
        lcd_row->setObjectName(QString::fromUtf8("lcd_row"));
        lcd_row->setGeometry(QRect(790, 400, 51, 61));
        lcd_row->setDigitCount(1);
        lcd_coloum = new QLCDNumber(Widget);
        lcd_coloum->setObjectName(QString::fromUtf8("lcd_coloum"));
        lcd_coloum->setGeometry(QRect(840, 400, 51, 61));
        lcd_coloum->setDigitCount(1);
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(800, 490, 71, 41));
        lcdNumber->setDigitCount(2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "GIVE UP", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\216\251\345\256\266\344\270\200", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\216\251\345\256\266\344\272\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
