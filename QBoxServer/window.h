#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include<QtGui>
#include"network.h"
#include"mytcpserver.h"
#include"dbhelp.h"
namespace Ui {
class Window;
}
//我的暂存的数据
struct UserInfo{
   int clientID;
   QString IP;
   int Port;
   QString userID;
   QString userName;
};
class Window : public QWidget
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    int getCountLink() const;
    void setCountLink(int value);

    int getCountOnline() const;
    void setCountOnline(int value);

private:
    void init();
protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void updateUserSend();
    void updataNoUserID();
protected:
    void timerEvent(QTimerEvent *event);
private slots:
    void timerUpdate();
private:
    void timeUpdate2s();
    void timeUpdate3s();
    void timeUpdate4s();
private slots:
    //客户端来的链接槽
    void ClientConnect( int clientID,QString IP,int Port);
    //客户端断开的处理槽
    void ClientDisConnect(int clientID,QString IP,int Port);
    //读取客户端信息
    void ClientReadData(int clientID,QString IP,int Port,QByteArray data);

    //关闭按钮
    void on_btnClose_clicked();

    void on_btnListen_clicked();

    void on_btnTalk_toggled(bool checked);

    void on_cbBind_clicked();

    void on_btnRegister_clicked();

    void on_btnSend_clicked();

    void on_btnClear_clicked();

private:
    Ui::Window *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

    //网络的客户端监听
    myTcpServer *net;
    int port;
    bool isWork;

    //我的数据库
    DBHelp *myDB;


    QList<UserInfo> AllLinks;


    //当前链接的人数
    int countLink;
    //当前在线的人数
    int countOnline;
    //定时器
    int timerID1;
    int timerID2;
    int timerID3;
    //我的消息
    QString messagenow;
    QStringList messageList;

private:
    void updateStatus();

};

#endif // WINDOW_H
