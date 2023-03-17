/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
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
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *Btnstart;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(998, 600);
        lcd_sec = new QLCDNumber(Widget);
        lcd_sec->setObjectName("lcd_sec");
        lcd_sec->setGeometry(QRect(840, 30, 81, 71));
        lcd_sec->setDigitCount(2);
        lcd_sec->setProperty("intValue", QVariant(0));
        lcd_min = new QLCDNumber(Widget);
        lcd_min->setObjectName("lcd_min");
        lcd_min->setGeometry(QRect(760, 30, 81, 71));
        lcd_min->setDigitCount(2);
        lcd_min->setProperty("intValue", QVariant(0));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setEnabled(true);
        widget->setGeometry(QRect(790, 140, 93, 176));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Btnstart = new QPushButton(widget);
        Btnstart->setObjectName("Btnstart");
        Btnstart->setEnabled(true);

        verticalLayout->addWidget(Btnstart);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);

        verticalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setEnabled(true);

        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);

        verticalLayout_2->addWidget(lineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);

        verticalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEnabled(true);

        verticalLayout_2->addWidget(lineEdit_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Btnstart->setText(QCoreApplication::translate("Widget", "start", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "surrender", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\216\251\345\256\266\344\270\200", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\216\251\345\256\266\344\272\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
