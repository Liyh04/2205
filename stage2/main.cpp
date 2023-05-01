#include "widget.h"
#include"mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

//enum{WHITE=2;BLACK=1;EMPTY=0;}

int main(int argc, char *argv[])
{
    //Widget::do_timer_timeout();
    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "timer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Widget w;
    MainWindow ww;

    ww.show();
    w.show();
    return a.exec();
}
