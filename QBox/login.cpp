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
    ui->Logo->setText(QObject::tr("欢迎你使用QBox"));
    ui->Logo->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //窗体居中显示
    Tools::FormInCenter(this);

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
    ui->Logo->setText(QObject::tr("正在登录中，请稍等"));
    ui->btnLogin->setEnabled(false);
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

void Login::getMyLostPWD(int way)
{
    qDebug()<<"你要找回密码的方式是"<<way;
    //窗体居中显示
    Tools::FormInCenter(this);
    this->show();
}

void Login::registeredInfo(QString name, QString password, QString eamil, QString phone)
{
    //窗体居中显示
    Tools::FormInCenter(this);
    this->show();
}

void Login::registeredBack()
{
    qDebug()<<"什么注册信息都没有使用";
    //窗体居中显示
    Tools::FormInCenter(this);
    this->show();
}

void Login::showForgetPwdView()
{
    qDebug()<<"你点击了忘记密码的按钮";
    forgetpwdView=new ForgetPassword();
    //链接忘记密码的监视器
    connect(forgetpwdView,SIGNAL(way(int)),this,SLOT(getMyLostPWD(int)));
//    this->hide();
   this->close();
    forgetpwdView->setWindowModality(Qt::ApplicationModal);
    //窗体居中显示
    Tools::FormInCenter(forgetpwdView);
    forgetpwdView->show();

}

void Login::showRegisterView()
{
    qDebug()<<"你点击了注册的按钮";
    registerView=new Register();
    //链接注册的监视器
    connect(registerView,SIGNAL(PersonInfo(QString,QString,QString,QString)),this,SLOT(registeredInfo(QString,QString,QString,QString)));
    connect(registerView,SIGNAL(nothingback()),this,SLOT(registeredBack()));
//    this->hide();
    this->close();
    registerView->setWindowModality(Qt::ApplicationModal);
    //窗体居中显示
    Tools::FormInCenter(registerView);
    registerView->show();
}
