#include "talkwindow.h"
#include "ui_talkwindow.h"
TalkWindow*  TalkWindow::myTalkWindow=NULL;
TalkWindow::TalkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TalkWindow)
{
    ui->setupUi(this);
    ui->textEditMessage->setFocus();
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
}

void TalkWindow::init(QString userid, QString name, quint8 status, QString photo, QString info)
{
    //设置单聊属性
    this->type=1;

    //先把它进行数据的复制
    this->userid=userid;
    this->name=name;
    this->status=status;
    this->photo=photo;
    this->info=info;
    //将这些东西显示在界面上
    ui->label_name->setText(QString("<html><head/><body><p><span style='font-size:20pt ;font-weight:600; color:#55ff00;'>%1</span></p></body></html>").arg(name));
    ui->label_PeopleStatus->setText(QString("状态：%1").arg(Tools::getStatus(status)));
    ui->UserPS_label->setText(info);
    QFile pic(photo);
    if(pic.exists())
    {
        ui->labelPic->setPixmap(QPixmap(photo));
    }


    qDebug()<<userid<<name<<status<<photo<<info;
}

void TalkWindow::init_Group(QString groupID, QString name, QString info, QString admin, QMap<QString, QString> *userList)
{

    //设置群聊属性
    this->type=2;
    //先把它进行数据的复制
    this->groupID=groupID;
    this->Groupname=name;
    this->Groupinfo=info;
    this->admin=admin;
    this->userList=userList;
    //将这些东西显示在界面上
    ui->label_name->setText(QString("<html><head/><body><p><span style='font-size:20pt ;font-weight:600; color:#55ff00;'>群组：%1</span></p></body></html>").arg(name));
    ui->label_PeopleStatus->setText(QString("群主：%1").arg(admin));
    ui->UserPS_label->setText(info);

    QString photo=":/resource/image/talkwindow/resource/image/talkwindow/group.png";
    QFile pic(photo);
      qDebug()/*<<photo*/<<admin;
//      qDebug()<<*userList;

    if(pic.exists())
    {
        qDebug()<<photo;
        ui->labelPic->setPixmap(QPixmap(photo));
    }
}

TalkWindow::~TalkWindow()
{
    delete ui;
    qDebug()<<QObject::tr("析构函数被执行");
}

void TalkWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void TalkWindow::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void TalkWindow::on_btnClose_clicked()
{
    qDebug()<<"关闭！";
    this->hide();
//    this->close();
}

void TalkWindow::on_btnClear_clicked()
{
    ui->textEditMessage->clear();
}

void TalkWindow::on_btnSend_clicked()
{
    static bool i=false;
    message=ui->textEditMessage->toHtml();
    i!=i;
    qDebug()<<message;

    //    if(i==true)
    //    {
    //        ui->MessageBrowser->setAlignment(Qt::AlignRight);
    //    }
    //    else
    //    {
    //        ui->MessageBrowser->setAlignment(Qt::AlignLeft);

    //    }
    ui->MessageBrowser->append(message);
    ui->textEditMessage->clear();
}
