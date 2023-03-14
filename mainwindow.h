#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTimer>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLineEdit *usernameEdit;
private:
    QTimer *mytimer;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void do_timer_timeout();
    void do_timer_shot();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
