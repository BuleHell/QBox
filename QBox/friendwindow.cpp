#include "friendwindow.h"
#include"tools.h"
#include "ui_friendwindow.h"
FriendWindow * FriendWindow::MyFriendPanel=NULL;
FriendWindow::FriendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendWindow),
    userid(""),username(""),pthotoPath(""),status(""),job("")
{
    ui->setupUi(this);
    Tools::FormInCenter(this);
    Tools::FormNotResize(this);

    setWindowFlags(Qt::FramelessWindowHint);
    this->resize(279,600);
    //调用初始化函数
    init();
    //初始化在线状态
    Status_init();
    //初始化主体面板
    UpdatePanel();
    //初始化朋友选项卡
    initFriend_Tab();
    //消息列表初始化
    initMessage_Tab();
    //群组选项卡初始化
    initGroup_Tab();
}
FriendWindow::~FriendWindow()
{

    delete ui;
}

QString FriendWindow::getNameFromID(QString id)
{
    //这里查找下
   return myDB->getNamefromID(id);
}

void FriendWindow::init()
{
    //初始化数据源
    myDB=DBHelp::getInstance();
    myDB->LinkDatabase();
    myXML=GroupSetting::getInstance();
    //链接信号
    connect(myDB,SIGNAL(SLOT_showUserList(QString,QString,quint8,QString,QString,quint8)),this,SLOT(updateFriendList(QString,QString,quint8,QString,QString,quint8)));
    connect(myDB,SIGNAL(SLOT_showOwnMessage(QDateTime,QString,QString)),this,SLOT(updateMessageList(QDateTime,QString,QString)));
    connect(myXML,SIGNAL(SLOT_GroupInfo(QString,QString,QString,QString,QMap<QString,QString>)),this,SLOT(updateGroupList(QString,QString,QString,QString,QMap<QString,QString>)));
    //安装协议解析器
    myproct=QBoxProtocol::getInstance();
    //链接信号











}

void FriendWindow::UpdatePanel()
{
    ui->labelName->setText(QString("<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#ff0000; '>%1</span></p></body></html>").arg(this->username));
    ui->labelstatus->setText(this->status);
    //设置头像
    if(this->pthotoPath!="")
    {
        ui->labelPic->setPixmap(QPixmap(this->pthotoPath));
    }
    //这里使用设置来设置显示那个
    for(int i=0;i<6;i++)
    {
        if(action[i]->text()==this->status)
        {
            action[i]->setChecked(true);
            ui->btnChange->setIcon(QIcon(ImagesIcon[i]));//被点击后，把Menu的图片换成相应的图片
            qDebug()<<action[i]->text();
        }

    }

}
//槽来初始化数据
void FriendWindow::initSatus(QString userid, QString username, QString pthotoPath, QString status)
{
    this->userid=userid;
    this->username=username;
    this->pthotoPath=pthotoPath;
    this->status=status;
    this->UpdatePanel();
}

//在线状态初始化
void FriendWindow::Status_init()
{
    QMenu * menu =ui->btnChange->getmenu();
    QActionGroup *actionGroup = new QActionGroup(this);
    menu->setStyleSheet("QMenu {color: white;background-color:#E78261; border: 1px solid black;width:70px;}"
                        "QMenu::item {background-color: transparent; }"
                        "QMenu::item:selected { background-color: #FF781F;}");
    action[0] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imonline.png"), tr("在线"), this);
    action[1] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imhidden.png"), tr("隐身"), this);
    action[2] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imbusy.png"), tr("忙碌"), this);
    action[3] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imaway.png"), tr("离开"), this);
    action[4] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imcallme.png"), tr("求扰"), this);
    action[5] = new QAction(QIcon(":/resource/image/login/resource/image/login/status/imsilent.png"), tr("勿扰"), this);
    ImagesIcon[0] = ":/resource/image/login/resource/image/login/svg/status-online-1.svg";
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
        if(action[i]->text()==this->status)
        {
            action[i]->setChecked(true);
            //被点击后，把Menu的图片换成相应的图片
            ui->btnChange->setIcon(QIcon(ImagesIcon[i]));
            qDebug()<<action[i]->text();
        }

    }
}

void FriendWindow::Status_Changed()
{
    for(int i =0;i<6;i++)
    {
        if(action[i]->isChecked())
        {
            //被点击后，把Menu的图片换成相应的图片
            ui->btnChange->setIcon(QIcon(ImagesIcon[i]));
            qDebug()<<action[i]->text();
            this->status=action[i]->text();
            Setting::getInstance()->setStatus(action[i]->text());
            this->UpdatePanel();
            break;
        }
    }
}

void FriendWindow::initFriend_Tab()
{
    //好友的列表里设置当前的组和列表
    FriendListPanel=new QWidget();
    gridlayout_FriendList = new QGridLayout(ui->Friends_tab);
    FriendListscrollArea=new QScrollArea(ui->Friends_tab);
    FriendListscrollArea->setWidget(FriendListPanel);
    gridlayout_FriendList->addWidget(FriendListscrollArea);
    gridlayout_FriendList->setSpacing(0);
    gridlayout_FriendList->setContentsMargins(0,0,0,0);
    //从数据表里查询出来，填上
    myDB->showUserList();
    //刷新一下面板
    this->updateFriendPanel();
    //    qDebug()<<FriendList.size();
}

void FriendWindow::initMessage_Tab()
{
    //初始化消息列表里的东西
    MessageListPanel=new QWidget();
    gridlayout_MessageList = new QGridLayout(ui->Message_tab);
    MessageListscrollArea=new QScrollArea(ui->Message_tab);
    MessageListscrollArea->setWidget(MessageListPanel);
    gridlayout_MessageList->addWidget(MessageListscrollArea);
    gridlayout_MessageList->setSpacing(0);
    gridlayout_MessageList->setContentsMargins(0,0,0,0);
    //从数据表里查询出来，填上(这里不能多次来，因为，它是消息，具有可重复性)
    myDB->showOwnMessage();
    updateMessagePanel();
}

void FriendWindow::initGroup_Tab()
{
    //初始化群组列表里的东西
    //群组列表
    GroupListPanel=new QWidget();
    gridlayout_GroupList = new QGridLayout(ui->Groups_tab);
    GroupListscrollArea=new QScrollArea(ui->Groups_tab);
    GroupListscrollArea->setWidget(GroupListPanel);
    gridlayout_GroupList->addWidget(GroupListscrollArea);
    gridlayout_GroupList->setSpacing(0);
    gridlayout_GroupList->setContentsMargins(0,0,0,0);
    myXML->showGroupList();
    updateGroupPanel();
}

void FriendWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void FriendWindow::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

//这里还可以设置一个动画：自动缩回去和弹出来的动画
void FriendWindow::MovetoRight()
{
    QDesktopWidget desktop;
    int screenX=desktop/*.availableGeometry()*/.width();
    int screenY=desktop/*.availableGeometry()*/.height();
    int wndX=this->width();
    int wndY=this->height();
    QPoint movePoint(screenX-wndX,0);
    this->move(movePoint);
}

//-------------------------------------------------------------
void FriendWindow::updateFriendList(QString id, QString name, quint8 status, QString photo, QString info, quint8 isfriend)
{
    Friend *tmp=new Friend();
    tmp->id=id;
    tmp->name=name;
    tmp->status=status;
    tmp->photo=photo;
    tmp->info=info;
    tmp->isfriend=isfriend;

    if(FriendList.isEmpty())
    {
        //空的话，直接加入即可
        FriendList.append(tmp);
    }
    else
    {
        //去除掉重复项
        bool isHave=false;
        for(int i=0;i<FriendList.size();i++)
        {
            if(FriendList[i]->id==id)
            {
                isHave=true;
            }

        }
        //没有就加入
        if(!isHave){
            FriendList.append(tmp);
        }
    }
}

void FriendWindow::updateFriendPanel()
{
    //先清理一下面板
    for(int j=0;j<this->FriendItemList.size();j++)
    {
        delete FriendItemList[j];
    }
    this->FriendListPanel->setFixedSize(0,0);
    for(int i=0;i<FriendList.size();i++)
    {
        this->insertFriendItem(FriendList[i]->id,
                               FriendList[i]->name,
                               FriendList[i]->status,
                               FriendList[i]->photo,
                               FriendList[i]->info,
                               FriendList[i]->isfriend
                               );
    }

}

void FriendWindow::insertFriendItem(QString id, QString name, quint8 status, QString photo, QString info, quint8 isfriend)
{
    static int j=0;
    int w,h;
    if(isfriend==1)//1是朋友 0不是朋友
    {
        FriendItem *frienditem = new FriendItem(this->FriendListPanel,0,j*75,id,name,status,photo,info);
        j++;
        w=frienditem->width();
        h=frienditem->height();
        //加入面板
        this->FriendItemList.append(frienditem);
    }
    this->FriendListPanel->setFixedSize(w,(j)*75);
}
//-------------------------------------------------------------
void FriendWindow::updateMessageList(QDateTime time, QString message, QString peer)
{
    Message *tmp=new Message();
    tmp->message=message;
    tmp->time=time;
    if(messageList.isEmpty())
    {
        QList<Message*> *list=new QList<Message*>();
        list->append(tmp);
        messageList[peer]=list;
    }
    else
    {
        //是否含有某个键
        bool  isHave;
        isHave=messageList.contains(peer);
        if(isHave)
        {
            messageList[peer]->append(tmp);
        }
        else
        {
            QList<Message*> *list=new QList<Message*>();
            list->append(tmp);
            messageList[peer]=list;
        }
    }
}

void FriendWindow::updateMessagePanel()
{
    //先清理一下面板
    for(int j=0;j<this->MessageItemList.size();j++)
    {
        delete MessageItemList[j];
    }
    this->MessageListPanel->setFixedSize(0,0);

    //插入相应的条目
    QMap<QString,QList<Message*>*>::iterator it; //遍历map
    for ( it = messageList.begin(); it != messageList.end(); ++it )
    {
        QString UserID=it.key();
        QString firstmessage=it.value()->at(0)->message;
        QString firsttime=it.value()->at(0)->time.time().toString();
        insertMessageItem(UserID,firstmessage,firsttime);
    }

}

void FriendWindow::insertMessageItem(QString userID,QString Firtmessage,QString time)
{
    static int j=0;
    QString photo;
    QString name;
    for(int i=0;i<FriendList.size();i++)
    {
        if(FriendList[i]->id==userID)
        {
            photo=FriendList[i]->photo;
            name=FriendList[i]->name;
        }
    }
    MessageItem *messageitem=new MessageItem(this->MessageListPanel,0,j*75,photo,name,time,Firtmessage);
    this->MessageItemList.append(messageitem);
    j++;
    this->MessageListPanel->setFixedSize(260,j*75);
}
//-------------------------------------------------------------
void FriendWindow::updateGroupList(QString groupID, QString name, QString info, QString admin, QMap<QString, QString> userList)
{

    qDebug()<<groupID<<name<<info<<admin<<userList;
    Group *tmp=new Group();
    tmp->groupID=groupID;
    tmp->name=name;
    tmp->info=info;
    tmp->admin=getNameFromID(admin);
    tmp->userList=userList;

    if(GroupList.isEmpty())
    {
        //空的话，直接加入即可
        GroupList.append(tmp);
    }
    else
    {
        //去除掉重复项
        bool isHave=false;
        for(int i=0;i<GroupList.size();i++)
        {
            if(GroupList[i]->groupID==groupID)
            {
                isHave=true;
                GroupList.removeAt(i);
            }

        }
        //没有就加入
        if(!isHave){
            GroupList.append(tmp);
        }
        else//有的话就更新
        {
            GroupList.append(tmp);
        }
    }
    //    qDebug()<<groupID<<name<<info<<admin<<userList;

}
void FriendWindow::updateGroupPanel()
{
    //    先清理一下面板
    for(int j=0;j<this->GroupItemList.size();j++)
    {
        delete GroupItemList[j];
    }
    this->GroupListPanel->setFixedSize(0,0);
    for(int i=0;i<GroupList.size();i++)
    {
        QString groupID=GroupList[i]->groupID;
        QString name=GroupList[i]->name;
        QString info=GroupList[i]->info;
        QString admin=GroupList[i]->admin;
        QMap<QString,QString> userList=GroupList[i]->userList;
        int count=userList.count();
        insertGroupItem(groupID,name,info,admin,userList,count);
    }
}

void FriendWindow::insertGroupItem(QString groupID,QString name,QString info,QString admin,QMap<QString,QString> userList,int count)
{
    static int j=0;
    GroupItem *groupItem=new GroupItem(this->GroupListPanel,0,j*73,groupID,name,info,admin,userList,count);
    this->GroupItemList.append(groupItem);
    j++;
    this->GroupListPanel->setFixedSize(260,j*73);
}


//--------------------------------------------------------------
void FriendWindow::on_btnClose_clicked()
{
    TalkWindow::getInstance()->close();
    this->close();

}

//--------------------------------------------------------------
void FriendWindow::on_btnAdd_clicked()
{
    qDebug()<<"你点击了添加朋友的按钮！";
}

void FriendWindow::on_btnGroup_clicked()
{
    qDebug()<<"你点击了添加群组的按钮！";
}

void FriendWindow::on_btnSeting_clicked()
{
    qDebug()<<"你点击了设置的按钮！";

}

void FriendWindow::on_btnFTP_clicked()
{
    qDebug()<<"你点击了上传下载的按钮！";

}
