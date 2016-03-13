#include "register.h"
#include "ui_register.h"
#include <QMouseEvent>
#include <QPoint>
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    //    第一个参数是设置无边框。第二个参数是允许最小化与还原。
    //    嗯，这样舒服多了。
        this->setWindowFlags(Qt::FramelessWindowHint);
}

Register::~Register()
{
    delete ui;
}

void Register::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void Register::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void Register::on_btnClose_clicked()
{
    this->destroy();
}
