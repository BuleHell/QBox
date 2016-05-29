#include "messageitem.h"
#include "ui_messageitem.h"

MessageItem::MessageItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageItem)
{
    ui->setupUi(this);
}

MessageItem::MessageItem(QWidget *parent,int x,int y,QString photo,QString name,QString time,QString message):
    QWidget(parent),
    ui(new Ui::MessageItem)
{
    ui->setupUi(this);
    this->setGeometry(x,y,260,72);
    QFile f(photo);
    if(f.exists())
    {
        ui->label_Photo->setPixmap(QPixmap(photo));
    }
    ui->label_name->setText(QString("<html><head/><body><p><span style=' font-weight:600;'>%1</span></p></body></html>").arg(name));
    ui->label_time->setText(QString("<html><head/><body><p><span style='font-size:10pt; font-weight:600; color:#b0021c;'>%1</span></p></body></html>").arg(time));
    ui->label_message->setText(message);
    this->installEventFilter(this);
    ui->label_Photo->installEventFilter(this);
}

MessageItem::~MessageItem()
{
    delete ui;
}

bool MessageItem::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==this)
    {
        if (event->type() == QEvent::MouseButtonRelease) { //随便判断什么事件都可以了

//            qDebug()<<"11"<<this->name;

            return true;
        }if(event->type()==QEvent::MouseMove)
        {

//            qDebug()<<"我被移动"<<this->name;
            return true;

        }if(event->type()==QEvent::MouseButtonDblClick)
        {
//            qDebug()<<"我被双击了"<<this->name;
            return true;

        }
        else {
            return false;
        }


    }else if(obj==this->ui->label_Photo)
    {

        if (event->type() == QEvent::MouseButtonRelease) { //随便判断什么事件都可以了
            talk=TalkWindow::getInstance();
//            talk->init_Group(this->groupID,this->name,this->info,this->admin,this->userList);
            talk->show();
//            qDebug()<<"我被点击了"<<this->name;
            return true;
        }if(event->type()==QEvent::MouseMove)
        {

//            qDebug()<<"我被移动"<<this->name;
            return true;

        }if(event->type()==QEvent::MouseButtonDblClick)
        {
//            qDebug()<<"我被双击了"<<this->name;
            return true;

        }
        else {
            return false;
        }

    }else
    {
        return MessageItem::eventFilter(obj,event);
    }
}
