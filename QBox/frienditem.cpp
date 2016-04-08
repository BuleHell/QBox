#include "frienditem.h"
//#include "userdata.h"
//#include "chatview.h"
//#include <QEvent>
//#include <friendslist.h>
FriendItem::FriendItem(QWidget *parent,int x,int y,QString id, QString name, quint8 status, QString photo, QString info) :
    QWidget(parent)
{

    this->setGeometry(x,y,260,75);
    this->userid=id;
    this->name=name;
    this->status=status;
    this->photo=photo;
    this->info=info;
    init(name,status, photo, info);
    this->installEventFilter(this);
    //    w = ChatView::getInstance();

}


bool FriendItem::eventFilter(QObject *obj, QEvent *event)
{

    if (obj == this) {
        if (event->type() == QEvent::MouseButtonRelease) { //随便判断什么事件都可以了

            qDebug()<<"我被点击了"<<this->name;


            //            w->addChat(user);
            //            w->show();
            return true;
        }if(event->type()==QEvent::MouseMove)
        {

            qDebug()<<"我被移动"<<this->name;

        }if(event->type()==QEvent::MouseButtonDblClick)
        {

            qDebug()<<"我被点击了"<<this->name;

        }


        else {
            return false;
        }
    } else {
        return FriendItem::eventFilter(obj, event);
    }
}

void FriendItem::init(QString name, quint8 status, QString photo, QString info)
{
    groupbox = new QGroupBox(this);
    groupbox->setStyleSheet("QGroupBox {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E0E0E0, stop: 1 #FFFFFF);border: 2px solid gray;border-radius: 5px;margin-top: 0px; /* leave space at the top for the title */}");
    groupbox->setGeometry(0,0,260,70);
    Avatar = new QLabel(groupbox);
    Status = new QLabel(groupbox);
    Name= new QLabel(groupbox);
    PS= new QLabel(groupbox);
    Avatar->setGeometry(5,5,50,50);
    Name->setGeometry(60,10,50,20);
    Status->setGeometry(210,10,50,20);
    PS->setGeometry(60,40,200,20);
    Name->setText(this->name);
    Name->setToolTip("我是"+this->name+",双击就可以跟我聊天了！");
    Status->setText(QString("%1").arg(this->status));
    if( this->status ==1)
    {
        Status->setStyleSheet("color:red;");
    }
    PS->setText(this->info);
    avatar_images =QPixmap(this->photo);
    Avatar->setScaledContents(true);
    Avatar->setPixmap(QPixmap(this->photo));


}

//void FriendItem::init(UserData::UserInfo *user)
//{







//    if(user->UserStatus =="1")
//    {
//        Status->setStyleSheet("color:red;");
//    }
//    PS->setText(user->UserPS);
//    avatar_images =QPixmap(UserData::AvatarPath+user->UserAvatar);
//    Avatar->setScaledContents(true);
//    Avatar->setPixmap(QPixmap(UserData::AvatarPath+user->UserAvatar));

//    //    Avatar->show();

//}
