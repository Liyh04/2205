#include "inputdialog.h"
#include <QVBoxLayout>

InputDialog::InputDialog(QWidget *parent):QDialog(parent)
{
    setWindowTitle("请输入save文件");
    m_lineEdit = new QLineEdit(this);

    m_okButton = new QPushButton("OK",this);
    connect(m_okButton,&QPushButton::clicked,this,&InputDialog::onOKButtonClicked);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_lineEdit);
    layout->addWidget(m_okButton);

}

void InputDialog::onOKButtonClicked()
{
    emit inputFinished(m_lineEdit->text());
    close();
}
