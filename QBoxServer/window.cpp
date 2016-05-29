#include "window.h"
#include "ui_window.h"
Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window),countLink(0),countOnline(0),port(0),isWork(false)
{

    ui->setupUi(this);
    net=new myTcpServer(this);
    //链接一些东西
    //链接客户端来链接的信号
    connect(net,SIGNAL(ClientConnect(int,QString,int)),this,SLOT(ClientConnect(int,QString,int)));
    //链接客户端
    connect(net,SIGNAL(ClientDisConnect(int,QString,int)),this,SLOT(ClientDisConnect(int,QString,int)));
    //读取客户来的消息
    connect(net,SIGNAL(ClientReadData(int,QString,int,QByteArray)),this,SLOT(ClientReadData(int,QString,int,QByteArray)));
    myDB=DBHelp::getInstance();
    myDB->LinkDatabase();
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    //安装协议解析器
    myprot=QBoxProtocol::getInstance();
    //安装登录协议
    connect(myprot,SIGNAL(TO_Login_SLOT(QString,QString,QString,QDateTime)),this,SLOT(Login_Process(QString,QString,QString,QDateTime)));
    //     connect(net,SIGNAL(ClientReadData(int,QString,int,QByteArray)),this,SLOT(ClientReadData(int,QString,int,QByteArray)));


    init();
}

Window::~Window()
{
    delete ui;
    delete net;
}

void Window::init()
{
    // 一开始隐藏输入的面板
    ui->lineEdit_Port->setText(QString("8989"));
    ui->lineEdit_Port->setEnabled(false);
    ui->cbBind->setChecked(true);
    this->port=ui->lineEdit_Port->text().toInt();
    ui->LabelNotice->setText(tr("请点击左侧的监听按钮，启动服务器"));
    ui->EditPanel->hide();
    //聊天按钮无法打开
    ui->btnTalk->setEnabled(false);

    //定时器
    // 开启一个1秒定时器，返回其ID
    this->timerID1 = startTimer(2000);//2秒
    this->timerID2 = startTimer(3000);//3秒

    // 创建一个新的定时器
    QTimer *timer = new QTimer(this);
    // 关联定时器的溢出信号到我们的槽函数上
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    //设置溢出时间为1秒，并启动定时器
    timer->start(1000);
    //------------------------------------------------------------
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

void Window::updateUserSend()
{
    if(!AllLinks.isEmpty())
    {
        ui->cbSendToID->clear();//先全部清除
        ui->cbSendToID->addItem(QString("全体人员"));
        for(int i=0;i<AllLinks.size();i++)
        {
            ui->cbSendToID->addItem(QString("%1").arg(AllLinks.at(i).clientID));
        }
    }
    else
    {
        ui->cbSendToID->clear();//先全部清除
        ui->cbSendToID->addItem(QString("全体人员"));
    }
}

void Window::updataNoUserID()
{
    if(!AllLinks.isEmpty())
    {
        ui->cbNogister->clear();
        for(int i=0;i<AllLinks.size();i++)
        {
            if(AllLinks.at(i).userID==tr("未知"))
            {
                ui->cbNogister->addItem(QString("%1").arg(AllLinks.at(i).clientID));

            }
            //            ui->cbSendToID->addItem(QString("%1").arg(AllLinks.at(i).clientID));
        }
    }
    else
    {
        ui->cbNogister->clear();
    }
}

void Window::timerEvent(QTimerEvent *event)
{
    // 判断是哪个定时器
    if(event->timerId() == timerID1){
        //        qDebug() << "这个是2S的定时器";
        timeUpdate2s();
    }
    else if(event->timerId() == timerID2){
        //        qDebug() << "这个是3S的定时器";
        timeUpdate3s();
    }
    else{
        //        qDebug() << "这个是4S的定时器";
        timeUpdate4s();
    }
}

void Window::timerUpdate()
{
    //    qDebug() << "这个是1S的定时器";

}

void Window::timeUpdate2s()
{
    //      qDebug() << "这个是2S的定时器";
}

void Window::timeUpdate3s()
{
    //     qDebug() << "这个是3S的定时器";

}

void Window::timeUpdate4s()
{
    //     qDebug() << "这个是4S的定时器";
    //刷新一下Notic
    ui->LabelNotice->setText(tr("这里是公告栏"));
}

void Window::ClientConnect(int clientID, QString IP, int Port)
{
    ui->LabelNotice->setText(QString("客户端:[clientID:%1 IP:%2 Port:%3]建立链接").arg(clientID).arg(IP).arg(Port));
    qDebug()<<"来链接时的客户端是："<<clientID;
    UserInfo a;
    a.clientID=clientID;
    a.IP=IP;
    a.Port=Port;
    a.userName=QString("未知:");
    a.userID=QString("未知");
    //现在存入
    AllLinks<<a;
    qDebug()<<"AllLinks.size:"<<AllLinks.size();
    this->countLink++;
    updateStatus();
    updateUserSend();
    updataNoUserID();
}

void Window::ClientDisConnect(int clientID, QString IP, int Port)
{
    ui->LabelNotice->setText(tr("客户端:[clientID:%1 IP:%2 Port:%3]端开了链接")
                             .arg(clientID).arg(IP).arg(Port));
    if(AllLinks.isEmpty())return;
    //移除
    for(int i=0;i<AllLinks.size();i++)
    {
        if(AllLinks.at(i).clientID==clientID)
        {
            UserInfo temp=AllLinks.takeAt(i);
            //            qDebug()<<"移除了:"<<temp.clientID;
        }

    }
    this->countLink--;
    qDebug()<<AllLinks.size();
    updateStatus();
    updateUserSend();
    updataNoUserID();
}

void Window::ClientReadData(int clientID, QString IP, int Port, QByteArray data)
{
    qDebug()<<"读入的消息：";
    qDebug()<<clientID<<IP<<Port<<data;
    //------------------------------------------
    //当场解开：
    qDebug()<<"当场解开";
    //建造一个输出流
    QDataStream in(&data, QIODevice::ReadOnly);
    //设定一个版本
    in.setVersion(QDataStream::Qt_4_8);
    //开始解析
    if(data.isEmpty()){
        qDebug()<<"Empty";
    }
    //先把头拿出来
    quint16 _size;
    quint16 _type;
    QBOXMESSAGETYPE TYPE;
    QString _ID;
    QDateTime _time;
    in>>_size;
    in>>_type;
    in>>_ID;
    in>>_time;
    TYPE=(QBOXMESSAGETYPE)_type;
    if(TYPE==LOGIN)
    {
        //|-用户名-|-密码-|
        QString name;
        QString pswd;
        in>>name;
        in>>pswd;
        qDebug()<<"name:"<<name<<"password"<<pswd<<"ID:"<<_ID<<"time:"<<_time;
        //填入AllLink中
        for(int i=0;i<this->AllLinks.size();i++)
        {
            qDebug()<<AllLinks.at(i).clientID;
            if(AllLinks.at(i).clientID==clientID)
            {
                if(!name.isEmpty())
                {
                    AllLinks[i].userName=name;
                    //把ID给赋值进去
                    if(this->myDB->FindID(name)!="")
                    {
                        AllLinks[i].userID=this->myDB->FindID(name);
                    }

                    qDebug()<<"查出ID："<<AllLinks[i].userID;

                }
                if(!_ID.isEmpty())
                {
                    AllLinks[i].userID=_ID;
                }

            }

        }

    }

    //触发登录的处理程序
    this->myprot->Open(&data);
    //------------------------------------------

}

void Window::Login_Process(QString username, QString password, QString ID, QDateTime time)
{
    //处理登录
    for(int i=0;i<this->AllLinks.size();i++)
    {
        qDebug()<<"--------------------------";
        qDebug()<<"clientID:"<<AllLinks.at(i).clientID;
        qDebug()<<"IP:"<<AllLinks.at(i).IP;
        qDebug()<<"Port:"<<AllLinks.at(i).Port;
        qDebug()<<"username:"<<AllLinks.at(i).userName;
        qDebug()<<"userID:"<<AllLinks.at(i).userID;
        qDebug()<<"--------------------------";
    }
    qDebug()<<username<<password<<ID<<time;

    //是否允许登录
    bool isCanLogin=true;
    //查询密码是否正确
    isCanLogin=this->myDB->pwdisRight(username,password);

    if(isCanLogin) //允许登录
    {
        qDebug()<<"密码正确";
        //数据初始化
        //在这里发送消息
        myprot->BackLogin(QString("system"),SUCCESS);
        //-----------------
        int clientid;
        QString ip;
        int port;
        Find_IP_Port(ID,username,clientid,port,ip);
        net->SendData(clientid,ip,port,*(myprot->getBlock()));
    }
    else         //不允许登录
    {
        qDebug()<<"密码错误";
        //数据初始化
        //在这里发送消息
        myprot->BackLogin(QString("system"),ERRORPWD);
        //-----------------
        int clientid;
        QString ip;
        int port;
        Find_IP_Port(ID,username,clientid,port,ip);
        net->SendData(clientid,ip,port,*(myprot->getBlock()));
    }

}

void Window::on_btnClose_clicked()
{
    this->close();
}

void Window::on_btnListen_clicked()
{
    if(ui->btnListen->text()==tr("监听"))
    {
        if(port==0){
            ui->LabelNotice->setText(tr("请设置端口号"));
        }
        //        qDebug()<<"port:"<<ui->lineEdit_Port->text();
        //        qDebug()<<port;
        bool ok=net->listen(QHostAddress::Any,port);
        if (ok)
        {
            //监听成功后该做的事--------------------------
            ui->btnListen->setText("停止");
            this->isWork=true;
            ui->MessageView->append("监听成功");
            ui->lineEdit_Port->setEnabled(false);
            ui->btnTalk->setEnabled(true);
            ui->LabelNotice->setText("恭喜,服务器启动监听成功.....");
            this->timerID3 = startTimer(4000);//4秒
        }
        else
        {
            ui->LabelNotice->setText("悲剧了,服务器启动监听失败.....");

        }
    }
    else
    {
        net->close();
        //        qDebug()<<"停止监听";
        ui->LabelNotice->setText("您停止了服务器的监听哦");
        ui->MessageView->append("停止监听");
        ui->btnListen->setText("监听");
        this->isWork=false;
        ui->lineEdit_Port->setEnabled(true);
        ui->btnSend->setEnabled(false);
        ui->btnClear->setEnabled(false);
    }
}

void Window::on_btnTalk_toggled(bool checked)
{
    ui->EditPanel->setVisible(checked);
    if(checked)
    {

        ui->btnTalk->setText(tr("静"));
    }
    else
    {
        ui->btnTalk->setText(tr("聊"));
    }
}

void Window::updateStatus()
{
    this->ui->label_Link->setText(QString("<html><head/><body><p><span style='font-size:11pt; font-weight:600; color:#55ff00;'>当前链接人数：%1人</span></p></body></html>").arg(countLink));
    this->ui->label_online->setText(QString("<html><head/><body><p><span style='font-size:12pt; font-weight:600; color:#830000;'>在线人数:%1人</span></p></body></html>").arg(countOnline));
}
int Window::getCountOnline() const
{
    return countOnline;
}

void Window::setCountOnline(int value)
{
    countOnline = value;
}

int Window::getCountLink() const
{
    return countLink;
}

void Window::setCountLink(int value)
{
    countLink = value;
}


void Window::on_cbBind_clicked()
{
    if(ui->cbBind->isChecked())
    {

        port=ui->lineEdit_Port->text().toInt();
        ui->lineEdit_Port->setEnabled(false);
    }
    else
    {

        ui->lineEdit_Port->setEnabled(true);

    }

    if(isWork)
    {

        ui->lineEdit_Port->setEnabled(false);
    }

}

void Window::on_btnRegister_clicked()
{
    //这里注册：并且相应的允许
}

void Window::on_btnSend_clicked()
{
    this->messagenow= this->ui->textEditMessage->toHtml();
    this->ui->textEditMessage->clear();
    messageList<<messagenow;
    qDebug()<<ui->cbSendToID->currentText();
    if(ui->cbSendToID->currentText()=="全体人员")
    {


    }
    else
    {
        int clientid;
        int port;
        QString ip;
        for(int i=0;i<this->AllLinks.size();i++)
        {
            qDebug()<<AllLinks.at(i).clientID;
            if(QString("%1").arg(AllLinks.at(i).clientID)==this->ui->cbSendToID->currentText())
            {
                port=AllLinks.at(i).Port;
                ip=AllLinks.at(i).IP;
                clientid=this->ui->cbSendToID->currentText().toInt();
                qDebug()<<"clientID:"<<clientid;
                qDebug()<<"ip:"<<clientid;
                qDebug()<<"port:"<<clientid;
                //在这里发送消息
                myprot->To_Message(QString("81121115"),QString("9243314"),messagenow);
                net->SendData(clientid,ip,port,*(myprot->getBlock()));
            }

        }
    }
}

void Window::on_btnClear_clicked()
{
    this->ui->textEditMessage->clear();
}

void Window::Find_IP_Port(QString userID,QString userName,int &clientid,int &port,QString &ip)
{
    qDebug()<<userID;
    qDebug()<<userName;

    if(userID==QString("未知")||userName==QString("未知"))
    {
        qDebug()<<"两个未知，玩个屁";
        return;
    }
    
    for(int i=0;i<this->AllLinks.size();i++)
    {
        qDebug()<<AllLinks.at(i).clientID;
        if(AllLinks.at(i).userID==userID||AllLinks.at(i) .userName==userName)
        {
            port=AllLinks.at(i).Port;
            ip=AllLinks.at(i).IP;
            clientid=AllLinks.at(i).clientID;
            qDebug()<<"clientID:"<<clientid;
            qDebug()<<"ip:"<<ip;
            qDebug()<<"port:"<<port;

        }

    }
}
