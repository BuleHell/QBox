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
    //从setting中读出数据来填上
    mysetting=Setting::getInstance();
    //默认的值填上
    this->username=mysetting->getUsername();
    this->userid=mysetting->getUserid();
    this->userphotopath=mysetting->getUserphotopath();
    this->isremeber=mysetting->getIsremeber();
    this->pwd=mysetting->getPwd();
    //显示在Ui上
    this->ui->lineEditUser->setText(username);
    if(isremeber)
    {
        //勾选
        this->ui->cbkAuto->setCheckState(Qt::Checked);
        //如果上次登录是7天前，则密码为空
        if(this->lastlogin.date().addDays(7)<=QDateTime::currentDateTime().date())
        {
            this->ui->lineEditPassword->setText(pwd);
        }
        else
        {

            this->ui->lineEditPassword->setText(QString(""));
        }

    }
}

Login::~Login()
{
    qDebug()<<"Lgin析构函数";
    delete mysetting;
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
    //网络部分先暂停下
    //    NetWork * a=NetWork::getInstance();
    //    a->initSocket();
    //写入数据
    //    a->writeData(QString("1232").toAscii());



    qDebug()<<"你点击了登录按钮";
    //qDebug()<<a->ReadData();
    //保存设置记录:先保存在本类的记录上，如果正确的话，就存入ini文件中
    //假设登录成功
    this->LoginSuccess();


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
//密码找回方式
void Login::getMyLostPWD(int way)
{
    qDebug()<<"你要找回密码的方式是"<<way;
    //窗体居中显示
    Tools::FormInCenter(this);
    this->show();
}

//注册
void Login::registeredInfo(QString name, QString password, QString eamil, QString phone)
{
    //窗体居中显示
    Tools::FormInCenter(this);
    this->show();
    qDebug()<<"-----------注册的消息-------------";
    qDebug()<<"name:"<<name
            <<"password:"<<password
            <<"eamil:"<<eamil
            <<"phone:"<<phone;
}

void Login::registeredBack()
{
    qDebug()<<"什么注册信息都没有使用";
    //窗体居中显示
    Tools::FormInCenter(this);
    this->show();
}

void Login::LoginSuccess()
{
    this->setUsername(ui->lineEditUser->text());
    this->setUserid("待定");
    this->setIsremeber(Qt::Checked==ui->cbkAuto->checkState());
    if(Qt::Checked==ui->cbkAuto->checkState())
    {
        this->setPwd(ui->lineEditPassword->text());
    }
    else
    {
        this->setPwd("");
    }
    this->setUserphotopath("没有照片");


    //登录成功后:有一系列的动作的
    //保存设置:或者否
    this->saveSetting();
}

void Login::saveSetting()
{
    mysetting->setIsremeber(this->getIsremeber());
    mysetting->setPwd(this->getPwd());
    mysetting->setUserid(this->getUserid());
    mysetting->setUsername(this->getUsername());
    mysetting->setUserphotopath(this->getUserphotopath());
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
    this->close();
    registerView->setWindowModality(Qt::ApplicationModal);
    //窗体居中显示
    Tools::FormInCenter(registerView);
    registerView->show();
}
QString Login::getPwd() const
{
    return pwd;
}

void Login::setPwd(const QString &value)
{
    pwd = value;
}

bool Login::getIsremeber() const
{
    return isremeber;
}

void Login::setIsremeber(bool value)
{
    isremeber = value;
}

QString Login::getUserphotopath() const
{
    return userphotopath;
}

void Login::setUserphotopath(const QString &value)
{
    userphotopath = value;
}

QDateTime Login::getLastlogin() const
{
    return lastlogin;
}

void Login::setLastlogin(const QDateTime &value)
{
    lastlogin = value;
}

QString Login::getUserid() const
{
    return userid;
}

void Login::setUserid(const QString &value)
{
    userid = value;
}

QString Login::getUsername() const
{
    return username;
}

void Login::setUsername(const QString &value)
{
    username = value;
}

