#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class InputDialog:public QDialog
{
    Q_OBJECT
public:
    InputDialog(QWidget *parent = nullptr);

signals:
    void inputFinished(const QString& text);

private slots:
    void onOKButtonClicked();

private:
    QLineEdit* m_lineEdit;
    QPushButton* m_okButton;

};

#endif // INPUTDIALOG_H
