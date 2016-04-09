#include "frienditem.h"
#include"talkwindow.h"
FriendItem::FriendItem(QWidget *parent,int x,int y,QString id, QString name, quint8 status, QString photo, QString info) :
    QWidget(parent)
{

    this->setGeometry(x,y,260,75);
    this->userid=id;
    this->name=name;
    this->status=status;
    this->photo=photo;
    this->info=info;
    init();
    this->installEventFilter(this);
    Avatar->installEventFilter(this);


}

FriendItem::~FriendItem()
{
    delete Avatar;
    delete Status;
    delete Name;
    delete PS;
    delete groupbox;
    delete talk;

}


bool FriendItem::eventFilter(QObject *obj, QEvent *event)
{

    if (obj == this)
    {
        if (event->type() == QEvent::MouseButtonRelease) { //随便判断什么事件都可以了

            qDebug()<<"我被点击了"<<this->name;
            return true;
        }if(event->type()==QEvent::MouseMove)
        {

            qDebug()<<"我被移动"<<this->name;
            return true;

        }if(event->type()==QEvent::MouseButtonDblClick)
        {
            qDebug()<<"我被双击了"<<this->name;
            return true;

        }
        else {
            return false;
        }
    }else if(obj==this->Avatar)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            qDebug()<<"点击了我的图像"<<this->name;
            talk=new TalkWindow();
            talk->init(  userid,
                         name,
                         status,
                         photo,
                         info);

            talk->show();
            return true;
        }else
        {
            return false;
        }


    }

    else {
        return FriendItem::eventFilter(obj, event);
    }
}

void FriendItem::init()
{
    groupbox = new QGroupBox(this);
    groupbox->setStyleSheet("QGroupBox {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E0E0E0, stop: 1 #FFFFFF);border: 2px solid gray;border-radius: 5px;margin-top: 0px; /* leave space at the top for the title */}");
    groupbox->setGeometry(0,0,260,70);
    Avatar = new QLabel(groupbox);
    Status = new QLabel(groupbox);
    Name= new QLabel(groupbox);
    PS= new QLabel(groupbox);
    Avatar->setGeometry(5,5,50,50);

    Name->setGeometry(60,10,80,20);
    Status->setGeometry(210,10,50,20);
    PS->setGeometry(60,40,200,20);
    Name->setFont(QFont("微软雅黑",12,3));
    Name->setText(this->name);
    Name->setStyleSheet("QLabel:hover{color: rgb(255, 0, 0);}");
    Name->setToolTip("我是"+this->name+",你好啊！");

    if( this->status ==0)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,QColor(10,23,90,89));
        Status->setPalette(pa);
    }
    else if(this->status==1)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,QColor(0,212,122,255));
        Status->setPalette(pa);
    }
    else if(this->status==2)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,QColor(10,23,90,89));
        Status->setPalette(pa);
    }
    else if(this->status==3)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,QColor(10,23,90,89));
        Status->setPalette(pa);
    }
    else if(this->status==4)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,QColor(10,23,90,89));
        Status->setPalette(pa);
    }
    else if(this->status==5)
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,QColor(10,23,90,89));
        Status->setPalette(pa);
    }
    Status->setText(QString("%1").arg(this->status));
    Status->setFont(QFont("微软雅黑",15,30));
    Status->setStyleSheet("QLabel:hover{color: rgb(255, 125, 0);}");
    Status->setToolTip("点击我，离线也可一发消息哦！");
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(124,23,90,89));
    PS->setPalette(pa);
    PS->setText(this->info);
    PS->setStyleSheet("QLabel:hover{color: rgb(125,125,10);}");
    PS->setFont(QFont("微软雅黑",8,2));
    avatar_images =QPixmap(this->photo);
    Avatar->setScaledContents(true);
    Avatar->setPixmap(QPixmap(this->photo));
    Avatar->setStyleSheet("QLabel:hover{border-color: rgb(255, 120, 31);}");
    Avatar->setCursor(QCursor(Qt::PointingHandCursor));
    Avatar->setToolTip("我是"+this->name+",单机我，跟我聊天啊！");


}
