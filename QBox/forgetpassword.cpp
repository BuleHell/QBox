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
    //            //居中显示 static QDesktopWidget *desktop();

//    move ((screen.width() - this->width())/2,(screen.height() - this->height())/2);
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
    this->destroy();
}
