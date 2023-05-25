/********************************************************************************
** Form generated from reading UI file 'replay.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replay
{
public:

    void setupUi(QWidget *replay)
    {
        if (replay->objectName().isEmpty())
            replay->setObjectName("replay");
        replay->resize(1316, 732);

        retranslateUi(replay);

        QMetaObject::connectSlotsByName(replay);
    } // setupUi

    void retranslateUi(QWidget *replay)
    {
        replay->setWindowTitle(QCoreApplication::translate("replay", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class replay: public Ui_replay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H
