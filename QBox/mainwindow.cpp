#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void MainWindow::on_btnClose_clicked()
{
    qDebug()<<QObject::tr("点击了关闭按钮");
    this->close();
}

void MainWindow::on_btnMin_clicked()
{
    qDebug()<<QObject::tr("点击了最小化按钮");
}

void MainWindow::on_btnClock_clicked()
{
    qDebug()<<QObject::tr("点击了锁定按钮");
}

void MainWindow::on_btnSend_clicked()
{
    qDebug()<<QObject::tr("点击了发送的按钮");
}

void MainWindow::on_toolBtn_clicked()
{
    qDebug()<<QObject::tr("点击了工具1的按钮");
}

void MainWindow::on_toolBtn2_clicked()
{
    qDebug()<<QObject::tr("点击了工具2的按钮");
}

void MainWindow::on_toolBtn3_clicked()
{
    qDebug()<<QObject::tr("点击了工具3的按钮");
}

void MainWindow::on_toolBtn4_clicked()
{
    qDebug()<<QObject::tr("点击了工具4的按钮");
}

void MainWindow::on_toolBtn5_clicked()
{
    qDebug()<<QObject::tr("点击了工具5的按钮");
}

void MainWindow::on_btnChange_clicked()
{
    qDebug()<<QObject::tr("点击了改变状态的按钮：离开或者在线");
}

void MainWindow::on_btnAdd_clicked()
{
    qDebug()<<QObject::tr("点击自己工具栏下的添加按钮");
    QLabel *a=new QLabel(QObject::tr("添加"),ui->MessageView);
    a->show();
}

void MainWindow::on_btnGroup_clicked()
{
    qDebug()<<QObject::tr("点击自己工具栏下的群组按钮");
    QLabel *a=new QLabel(QObject::tr("群组"),ui->MessageView);
    a->show();
}

void MainWindow::on_btnSeting_clicked()
{
    qDebug()<<QObject::tr("点击自己工具栏下的设置按钮");
    QLabel *a=new QLabel(QObject::tr("设置"),ui->MessageView);
    a->show();
}

void MainWindow::on_btnFTP_clicked()
{
    qDebug()<<QObject::tr("点击自己工具栏下的FTP按钮");
    QLabel *a=new QLabel(QObject::tr("FTP"),ui->MessageView);
    a->show();
}
