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
    ui->labelPhoto->installEventFilter(this);
    //做一个在登录界面上的动画
    ui->Logo->setText(QObject::tr("欢迎你使用QBox"));
    ui->Logo->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //窗体居中显示
    Tools::FormInCenter(this);
    //从setting中读出数据来填上
    mysetting=Setting::getInstance();
    //数据库的东西
    myDB=DBHelp::getInstance();
    //-----------------------
    myDB->LinkDatabase();
    //-------------------
    //XML里的东西
    myXML=GroupSetting::getInstance();
    myXML->createXML();
    //默认的值填上
    this->username=mysetting->getUsername();
    this->userid=mysetting->getUserid();
    this->userphotopath=mysetting->getUserphotopath();
    this->isremeber=mysetting->getIsremeber();
    this->pwd=mysetting->getPwd();
    this->status=mysetting->getStatus();
    //    qDebug()<<this->status;
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
    this->Status_init();
    this->photo_init();

}


//在线状态初始化
void Login::Status_init()
{
    QMenu * menu =ui->btnStatus->getmenu();
    //            ui->Status_pushButton->getmenu();
    QActionGroup *actionGroup = new QActionGroup(this);
    menu->setStyleSheet("QMenu {color: white;background-color:#E78261; border: 1px solid black;width:70px;}"
                        "QMenu::item {background-color: transparent; }"
                        "QMenu::item:selected { background-color: #FF781F;}");
    //:/resource/image/login/resource/image/login/svg/status-away-1.svg
    action[0] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imonline.png"), tr("在线"), this);
    action[1] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imhidden.png"), tr("隐身"), this);
    action[2] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imbusy.png"), tr("忙碌"), this);
    action[3] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imaway.png"), tr("离开"), this);
    action[4] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imcallme.png"), tr("求扰"), this);
    action[5] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imsilent.png"), tr("勿扰"), this);
    //:/resource/image/login/resource/image/login/svg/status-busy-1.svg
    //    :/resource/image/login/resource/image/login/status/imaway.png
    ImagesIcon[0] = ":/resource/image/login/resource/image/login/svg/status-online-1.svg";//初始化状态
    ImagesIcon[1] = ":/resource/image/login/resource/image/login/svg/status-hidden-1.svg";
    ImagesIcon[2] = ":/resource/image/login/resource/image/login/svg/status-busy-1.svg";
    ImagesIcon[3] = ":/resource/image/login/resource/image/login/svg/status-away-1.svg";
    ImagesIcon[4] = ":/resource/image/login/resource/image/login/svg/status-callme-1.svg";
    ImagesIcon[5] = ":/resource/image/login/resource/image/login/svg/status-silent-1.svg";
    for(int i =0;i<6;i++)
    {

        menu->addAction(actionGroup->addAction(action[i]));
        action[i]->setCheckable(true);
        //把状态的变化发射到槽上，让槽来处理
        connect(action[i], SIGNAL(triggered()), this, SLOT(Status_Changed()));
    }
    //这里使用设置来设置显示那个
    for(int i=0;i<6;i++)
    {
        if(action[i]->text()==mysetting->getStatus())
        {
            qDebug()<<"-----------------------------------";
            action[i]->setChecked(true);
            ui->btnStatus->setIcon(QIcon(ImagesIcon[i]));//被点击后，把Menu的图片换成相应的图片
            qDebug()<<action[i]->text();
            this->setStatus(action[i]->text());
        }

    }





}

void Login::photo_init()
{
    QFile file(this->userphotopath);
    if(file.exists())
    {
        //先暂存起来
        ui->labelPhoto->setPixmap(QPixmap(getUserphotopath()));

    }else
    {

        QMessageBox::information(this,tr("没有图片"),tr("请点击头像位置上传图片哦！"),QMessageBox::Ok);
    }

}

//状态变化的槽处理函数
void Login::Status_Changed()
{
    for(int i =0;i<6;i++)
    {
        if(action[i]->isChecked())
        {
            ui->btnStatus->setIcon(QIcon(ImagesIcon[i]));//被点击后，把Menu的图片换成相应的图片
            qDebug()<<action[i]->text();
            this->setStatus(action[i]->text());
            qDebug()<<"现在是槽在处理";
            mysetting->setStatus(action[i]->text());
            break;
        }
    }
}



Login::~Login()
{
    qDebug()<<"Lgin析构函数";
    delete mysetting;
    delete myDB;
    delete myXML;
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

    }else if (obj==ui->labelPhoto)
    {
        if(ev->type()==QEvent::MouseButtonPress)
        {
            qDebug()<<"PHOTO";
            QString filename=QFileDialog::getOpenFileName(this,tr("选择头像"),"./",tr("图片文件(*png *jpg)"));
            qDebug()<<"photoPath:"<<filename;
            this->setUserphotopath(filename);
            //先暂存起来
            mysetting->setUserphotopath(filename);
            ui->labelPhoto->setPixmap(QPixmap(filename));
            return true;
        }

    }
    else
    {

        return QWidget::eventFilter(obj,ev);
    }
    return QWidget::eventFilter(obj,ev);
}

void Login::on_btnLogin_clicked()
{
    //网络部分先暂停下
    NetWork * a=NetWork::getInstance();
    a->initSocket("127.0.0.1",8989);
    //写入数据

    //查询出用户ID出来，填在这里

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
    //登录成功后:有一系列的动作的
    //1.保存设置:或者否
    this->saveSetting();
    //2.发送出相应的信息String userid,QString username,QString pthotoPath
    emit LoginSuccessSIGNAL(this->getUserid(),this->getUsername(),this->getUserphotopath(),this->status);
}


//只有在登录成功后才保存设置
void Login::saveSetting()
{
    mysetting->setIsremeber(this->getIsremeber());
    mysetting->setPwd(this->getPwd());
    mysetting->setUserid(this->getUserid());
    mysetting->setUsername(this->getUsername());
    mysetting->setUserphotopath(this->getUserphotopath());
    mysetting->setStatus(this->getStatus());
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
QString Login::getStatus() const
{
    return status;
}

void Login::setStatus(const QString &value)
{
    status = value;
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

