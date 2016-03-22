#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->MyEdit->hide();
    ui->showPanel->hide();
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
}

Window::~Window()
{
    delete ui;
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void Window::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void Window::on_btnPrivate_toggled(bool checked)
{
    ui->MyEdit->setVisible(checked);
    if(checked)
    {
        ui->btnPrivate->setText(QObject::tr("结束私聊"));
    }
    else
    {
        ui->btnPrivate->setText(QObject::tr("单独消息"));
    }
}

void Window::on_btnPublic_toggled(bool checked)
{
    ui->MyEdit->setVisible(checked);
    if(checked)
    {
        ui->btnPublic->setText(QObject::tr("结束公告"));
    }
    else
    {
        ui->btnPublic->setText(QObject::tr("发送公告"));
    }
}

void Window::on_btnPressure_toggled(bool checked)
{
    ui->showPanel->setVisible(checked);
    if(checked)
    {
        ui->btnPressure->setText(QObject::tr("隐藏压力"));
    }
    else
    {
        ui->btnPressure->setText(QObject::tr("显示压力"));
    }
}

void Window::on_btnWatch_toggled(bool checked)
{
    ui->listView->setVisible(!checked);
    ui->showPanel->setVisible(checked);
    if(checked)
    {
        ui->btnWatch->setText(QObject::tr("结束监视"));

    }
    else
    {
        ui->btnWatch->setText(QObject::tr("监视聊天"));
    }
}

void Window::on_btnQuit_clicked()
{
    this->close();
}
