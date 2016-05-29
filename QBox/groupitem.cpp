#include "groupitem.h"
#include "ui_groupitem.h"

GroupItem::GroupItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupItem)
{
    ui->setupUi(this);
}

GroupItem::GroupItem(QWidget *parent,int x,int y,QString GroupID,QString name,QString info,QString admin,QMap<QString,QString> userList,int count):QWidget(parent),
    ui(new Ui::GroupItem)
{
    ui->setupUi(this);
    this->setGeometry(x,y,260,75);
    this->groupID=GroupID;
    this->name=name;
    this->info=info;
    this->admin=admin;
    this->userList=new  QMap<QString,QString>(userList);

    this->count=count;
    //-------------------------------------
    ui->label_name->setText(QString("<html><head/><body><p><span style='font-size:16pt; font-weight:600;'>%1</span></p></body></html>").arg(name));
    ui->label_info->setText(QString("<html><head/><body><p><span style=' font-weight:600; color:#80129f;'>群的宗旨：%1</span></p></body></html>").arg(info));
    ui->label_num->setText(QString("群人数：%1人").arg(count));

    this->installEventFilter(this);
    ui->label_pic->installEventFilter(this);
//    qDebug()<<"****uuu****"<<admin;
}

GroupItem::~GroupItem()
{
    delete ui;
}

bool GroupItem::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==this)
    {
        if (event->type() == QEvent::MouseButtonRelease) { //随便判断什么事件都可以了

            qDebug()<<"11"<<this->name;

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


    }else if(obj==this->ui->label_pic)
    {

        if (event->type() == QEvent::MouseButtonRelease) { //随便判断什么事件都可以了
            talk=TalkWindow::getInstance();
            talk->init_Group(this->groupID,this->name,this->info,this->admin,this->userList);
            talk->show();
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

    }else
    {
        return GroupItem::eventFilter(obj,event);
    }
}
