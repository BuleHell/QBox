#include "friendwindow.h"
#include"tools.h"
#include "ui_friendwindow.h"

FriendWindow::FriendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendWindow),
    userid(""),username(""),pthotoPath(""),status(""),job("")
{
    ui->setupUi(this);
//    this->resize(279,600);
    Tools::FormInCenter(this);
    Tools::FormNotResize(this);
    setWindowFlags(Qt::FramelessWindowHint);
    myDB=DBHelp::getInstance();
    myDB->LinkDatabase();
    myXML=GroupSetting::getInstance();
    connect(myDB,SIGNAL(SLOT_showUserList(QString,QString,quint8,QString,QString,quint8)),this,SLOT(insertFriendItem(QString,QString,quint8,QString,QString,quint8)));

    //setAttribute(Qt::WA_TranslucentBackground);//透明底部
    //初始化在线状态
    Status_init();
    //初始化面板
    UpdatePanel();
    //初始化，建立一个单例模式，聊天面板

    //好友的列表里设置当前的组和列表
    FriendListPanel=new QWidget();
    gridlayout_FriendList = new QGridLayout(ui->Friends_tab);
    FriendListscrollArea=new QScrollArea(ui->Friends_tab);

    myDB->showUserList();
    //   FriendListPanel->show();
    initFriend_Tab();
 //   FriendListscrollArea->setBackgroundRole(QPalette::Dark);
    FriendListscrollArea->setWidget(FriendListPanel);
    gridlayout_FriendList->addWidget(FriendListscrollArea);
    gridlayout_FriendList->setSpacing(0);
    gridlayout_FriendList->setContentsMargins(0,0,0,0);
}
//在好友tab里设置一些

FriendWindow::~FriendWindow()
{
    delete ui;
}

void FriendWindow::UpdatePanel()
{

    ui->labelName->setText(    QString("<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#ff0000; '>%1</span></p></body></html>").arg(this->username)
                               );
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
            qDebug()<<"-----------------------------------";
            action[i]->setChecked(true);
            ui->btnChange->setIcon(QIcon(ImagesIcon[i]));//被点击后，把Menu的图片换成相应的图片
            qDebug()<<action[i]->text();
        }

    }

}

//在线状态初始化
void FriendWindow::Status_init()
{
    QMenu * menu =ui->btnChange->getmenu();
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
        if(action[i]->text()==this->status)
        {
            qDebug()<<"-----------------------------------";
            action[i]->setChecked(true);
            ui->btnChange->setIcon(QIcon(ImagesIcon[i]));//被点击后，把Menu的图片换成相应的图片
            qDebug()<<action[i]->text();
        }

    }





}

void FriendWindow::initFriend_Tab()
{

    //    FriendListscrollArea->setBackgroundRole(QPalette::Dark);
    //    FriendListscrollArea->setWidget(FriendListPanel);

    //    FriendListPanel->show();
    //    FriendListscrollArea->show();

    //在好友tab里新建了一个QToolBox实现好友列表
    //    friends_box = new QToolBox();
    //    friends_box->setGeometry(10,10,260,250);
    //    friends_box->setStyleSheet("QToolBox::tab {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);border-radius: 5px;color: darkgray; }QToolBox::tab:selected { /* italicize selected tabs */font: italic; color: white;}");
    //新建一个布局管理器
    //    scrollArea = new QScrollArea(ui->Friends_tab);
    //    scrollArea->setBackgroundRole(QPalette::Dark);
    //    scrollArea->setWidget(friends_box);
    //     friends_box->show();
    //     scrollArea->show();
    myDB->showUserList();
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

void FriendWindow::insertFriendItem(QString id, QString name, quint8 status, QString photo, QString info, quint8 isfriend)
{
    static int j=0;
    int w,h;
    if(isfriend==1)//是朋友
    {

        FriendItem *frienditem = new FriendItem(this->FriendListPanel,0,j*70+2,id,name,status,photo,info);
        j++;
        w=frienditem->width();
        h=frienditem->height();
        this->FriendItemList.append(frienditem);
    }
   this->FriendListPanel->setFixedSize(w,(j)*h);
}

void FriendWindow::on_btnClose_clicked()
{
    this->close();
}
//槽来初始化数据
void FriendWindow::initSatus(QString userid, QString username, QString pthotoPath, QString status)
{
    qDebug()<<"+++++++++++++++++++++++++++";
    qDebug()<<"userid"<<userid
           <<"username"<<username
          <<"status"<<status
         <<"pthotoPath"<<pthotoPath;
    this->userid=userid;
    this->username=username;
    this->pthotoPath=pthotoPath;
    this->status=status;
    this->UpdatePanel();
}

void FriendWindow::Status_Changed()
{
    for(int i =0;i<6;i++)
    {
        if(action[i]->isChecked())
        {
            ui->btnChange->setIcon(QIcon(ImagesIcon[i]));//被点击后，把Menu的图片换成相应的图片
            qDebug()<<action[i]->text();
            //            this->setStatus(action[i]->text());
            this->status=action[i]->text();
            qDebug()<<"现在是槽在处理";
            Setting::getInstance()->setStatus(action[i]->text());
            this->UpdatePanel();
            break;
        }
    }
}
