#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *widget = new QWidget();
    QLabel *label = new QLabel("00");
    QPushButton *startButton = new QPushButton("Start");
    QPushButton *stopButton = new QPushButton("Stop");
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    widget->setLayout(layout);
    widget->setWindowTitle("Timer");

    QTimer *timer = new QTimer(widget);
    int seconds = 0;

    QObject::connect(timer, &QTimer::timeout, [&]() {
        seconds++;
        if (seconds == 60) {
            timer->stop();
            QMessageBox::information(nullptr, "Timeout", "60 seconds elapsed.");
            seconds = 0;
        }
        QString timeString = QString("%3").arg(seconds, 2, 10, QChar('0'));
        label->setText(timeString);
    });

    QObject::connect(startButton, &QPushButton::clicked, [&]() {
        timer->start(1000);
    });

    QObject::connect(stopButton, &QPushButton::clicked, [&]() {
        timer->stop();
        seconds = 0;
        label->setText("00");
    });

    widget->show();
    return app.exec();
}
