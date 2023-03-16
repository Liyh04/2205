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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *Btnstart;
    QLCDNumber *lcd_sec;
    QLCDNumber *lcd_min;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Btnstart = new QPushButton(Widget);
        Btnstart->setObjectName("Btnstart");
        Btnstart->setGeometry(QRect(590, 310, 92, 29));
        lcd_sec = new QLCDNumber(Widget);
        lcd_sec->setObjectName("lcd_sec");
        lcd_sec->setGeometry(QRect(640, 200, 81, 71));
        lcd_sec->setDigitCount(2);
        lcd_sec->setProperty("intValue", QVariant(0));
        lcd_min = new QLCDNumber(Widget);
        lcd_min->setObjectName("lcd_min");
        lcd_min->setGeometry(QRect(560, 200, 81, 71));
        lcd_min->setDigitCount(2);
        lcd_min->setProperty("intValue", QVariant(0));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Btnstart->setText(QCoreApplication::translate("Widget", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
