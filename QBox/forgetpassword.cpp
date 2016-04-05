#include "forgetpassword.h"
#include "ui_forgetpassword.h"
#include <QMouseEvent>
#include <QPoint>
#include<QApplication>
ForgetPassword::ForgetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgetPassword)
{
    ui->setupUi(this);
    //    第一个参数是设置无边框。第二个参数是允许最小化与还原。
    //    嗯，这样舒服多了。
    this->setWindowFlags(Qt::FramelessWindowHint);
    Tools::FormInCenter(this);
}

ForgetPassword::~ForgetPassword()
{
    delete ui;
}

void ForgetPassword::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void ForgetPassword::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void ForgetPassword::on_btnClose_clicked()
{
    emit way(0);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

void ForgetPassword::on_btnPhone_clicked()
{
    //1是短信通知
    emit way(1);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

void ForgetPassword::on_btnMail_clicked()
{
    //    2是邮件通知
    emit way(2);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}
