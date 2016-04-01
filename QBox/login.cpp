#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    this->ui->lineEditUser->setFocus(); //将光标转到用户名输入框
    //安装事件监听器
    ui->labelForget->installEventFilter(this);
    ui->labelRegist->installEventFilter(this);
    //做一个在登录界面上的动画

}

Login::~Login()
{
    delete ui;
    delete registerView;
    delete forgetpwdView;
}
//鼠标移动事件
void Login::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}
//鼠标点击时间
void Login::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

bool Login::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj==ui->labelForget)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            this->showForgetPwdView();
            return true;
        }

    }
    else if (obj==ui->labelRegist)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {

            this->showRegisterView();
            return true;
        }

    }else
    {

        return QWidget::eventFilter(obj,ev);
    }
    return QWidget::eventFilter(obj,ev);
}

void Login::on_btnLogin_clicked()
{
    qDebug()<<"你点击了登录按钮";
}

void Login::on_btnMin_clicked()
{
    //最小化
    qDebug()<<"窗口最小化暂时没有实现";
}

void Login::on_btnClose_clicked()
{
    //关闭
    qDebug()<<"你点击了关闭按钮";
    this->close();
}

void Login::showForgetPwdView()
{
    qDebug()<<"你点击了忘记密码的按钮";
    forgetpwdView=new ForgetPassword();
    this->hide();
    forgetpwdView->show();
    //    //居中显示
    //    move ((QApplication::desktop()->width() - registerView->width())/2,(QApplication::desktop()->height() - registerView->height())/2);
}

void Login::showRegisterView()
{
    qDebug()<<"你点击了注册的按钮";
    registerView=new Register();
    this->hide();
    registerView->show();
}
