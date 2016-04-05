#include "register.h"
#include "ui_register.h"
#include<QtGui>
#include <QMouseEvent>
#include <QPoint>
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->lineEditUserName->setFocus();
    //窗体居中显示
    Tools::FormInCenter(this);
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
    emit nothingback();
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    this->destroy();
}

void Register::on_lineEditUserName_editingFinished()
{
    qDebug()<<QObject::tr("你输入的名字是：")<<ui->lineEditUserName->text();
    this->setName(ui->lineEditUserName->text());
}

void Register::on_lineEditPassword_editingFinished()
{
    qDebug()<<QObject::tr("你输入的密码是：")<<ui->lineEditPassword->text();
}


void Register::on_lineEditConfirm_editingFinished()
{
    qDebug()<<QObject::tr("你输入再次确实的密码是：")<<ui->lineEditConfirm->text();
    this->setPassword(ui->lineEditConfirm->text());
}

void Register::on_lineEditMail_editingFinished()
{
    qDebug()<<QObject::tr("你输入的邮箱是：")<<ui->lineEditMail->text();
    this->setEamil(ui->lineEditMail->text());
}

void Register::on_lineEditPhone_editingFinished()
{
    qDebug()<<QObject::tr("你输入的电话是：")<<ui->lineEditPhone->text();
    this->setPhone(ui->lineEditPhone->text());
}
QString Register::getPhone() const
{
    return phone;
}

void Register::setPhone(const QString &value)
{
    phone = value;
}

QString Register::getEamil() const
{
    return eamil;
}

void Register::setEamil(const QString &value)
{
    eamil = value;
}

QString Register::getPassword() const
{
    return password;
}

void Register::setPassword(const QString &value)
{
    password = value;
}

QString Register::getName() const
{
    return name;
}

void Register::setName(const QString &value)
{
    name = value;
}


void Register::on_btnRegister_clicked()
{
    emit this->PersonInfo(this->getName(),this->getPassword(),this->getEamil(),this->getPhone());
    qDebug()<<"这里还应该有个注册成功返回的界面";
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
//    this->destroy();
}
