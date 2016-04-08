#ifndef QBOXCLIENT_H
#define QBOXCLIENT_H

#include <QObject>
//#include "mainwindow.h"    //主界面
#include"friendwindow.h"
#include "login.h"         //登录界面
#include"network.h"        //网络模块
#include"qboxprotocol.h"   //协议
#include"dbhelp.h"         //数据库操作
#include"groupsetting.h"   //群组设置xml
#include"setting.h"        //用户设置ini
class MainWindow;
class Login;

class QBoxClient : public QObject
{
    Q_OBJECT
public:
    explicit QBoxClient(QObject *parent = 0);
    ~QBoxClient();
signals:
   void SLOT_LoginMessage(QString userid, QString username, QString pthotoPath,QString status);
public slots:
    void showLogin();
    void showFriendWindow(QString userid, QString username, QString pthotoPath, QString status);
private:
    //所有可以操作的对象都在这里；
    Login *login;
    FriendWindow *friendwindow;

};

#endif // QBOXCLIENT_H
