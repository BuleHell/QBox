#include "qboxclient.h"
#include <QMouseEvent>
#include <QPoint>
QBoxClient::QBoxClient(QObject *parent):
    QObject(parent)
{
    friendwindow=FriendWindow::getInstance();
    login=new Login();
    myPrcot=QBoxProtocol::getInstance();
    myNet=NetWork::getInstance();
    //链接登录成功的
    connect(login,SIGNAL(LoginSuccessSIGNAL(QString,QString,QString,QString)),this,SLOT(showFriendWindow(QString,QString,QString,QString)));
    //链接登录消息的
    connect(this,SIGNAL(SLOT_LoginMessage(QString,QString,QString,QString)),friendwindow,SLOT(initSatus(QString,QString,QString,QString))); 
}

QBoxClient::~QBoxClient()
{
    delete login;
    delete friendwindow;
}

void QBoxClient::showLogin()
{
    login->show();
}

void QBoxClient::showFriendWindow(QString userid, QString username, QString pthotoPath,QString status)
{
    login->close();
//    qDebug()<<"userid"<<userid
//            <<"username"<<username
//            <<"status"<<status
//            <<"pthotoPath"<<pthotoPath;
    friendwindow->show();
    friendwindow->MovetoRight();
    emit SLOT_LoginMessage(userid,username,pthotoPath,status);
}
FriendWindow *QBoxClient::getFriendwindow() const
{
    return friendwindow;
}

void QBoxClient::setFriendwindow(FriendWindow *value)
{
    friendwindow = value;
}

