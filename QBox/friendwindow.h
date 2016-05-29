#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QWidget>
#include<QtGui>
#include"talkwindow.h"
#include"setting.h"
#include"dbhelp.h"
#include"groupsetting.h"
#include"frienditem.h"
#include"messageitem.h"
#include"qboxprotocol.h"
#include"groupitem.h"
namespace Ui {
class FriendWindow;
}


class FriendWindow : public QWidget
{
    Q_OBJECT

    //我的暂存的数据
    struct UserInfo{
        QString userID;    //用户的ID
        QString userName;  //用户的名字
        QString IP;        //用户的IP
        int Port;          //用户的端口
        int status;        //用户的状态
    };

    //朋友列表中的数据
    struct Friend{
        QString id;
        QString name;
        quint8 status;
        QString photo;
        QString info;
        quint8 isfriend;
    };

    //消息列表中的数据
    struct Message{
        QDateTime time;
        QString message;
    };

    //群组的数据
    struct Group{
        QString groupID;
        QString name;
        QString info;
        QString admin;
        QMap<QString,QString> userList;
    };

public:
    static FriendWindow *MyFriendPanel;
    static FriendWindow *getInstance()
    {
        if(FriendWindow::MyFriendPanel==NULL)
        {
            FriendWindow::MyFriendPanel=new FriendWindow();

        }
        return FriendWindow::MyFriendPanel;


    }



public:
    explicit FriendWindow(QWidget *parent = 0);
    ~FriendWindow();
    //用ID得出名字
    QString getNameFromID(QString id);

private:
    //初始化
    void init();
    //初始化面板
    void UpdatePanel();
    //在线状态初始化
    void Status_init();
    //好友列表初始化
    void initFriend_Tab();
    //消息列表初始化
    void initMessage_Tab();
    //群组列表初始化
    void initGroup_Tab();


protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    //窗口移动到最右侧
    void MovetoRight();

private slots:
    //初始化面板状态
    void initSatus(QString userid, QString username, QString pthotoPath,QString status);

    //初始化好友列表
    void updateFriendList(QString id,QString name,quint8 status,QString photo,QString info,quint8 isfriend);
    void updateFriendPanel();
    void insertFriendItem(QString id,QString name,quint8 status,QString photo,QString info,quint8 isfriend);

    //初始化消息列表
    void updateMessageList(QDateTime time, QString message, QString peer);
    void updateMessagePanel();
    void insertMessageItem(QString userID,QString Firtmessage,QString time);


    //初始化群组列表
    void updateGroupList(QString groupID, QString name,QString info,QString admin,QMap<QString,QString> userList);
    void updateGroupPanel();
    void insertGroupItem(QString groupID, QString name, QString info, QString admin, QMap<QString,QString> userList, int count);


    //关闭按钮
    void on_btnClose_clicked();
    //状态改变
    void Status_Changed();
    //添加好友功能
    void on_btnAdd_clicked();
    //添加群组功能
    void on_btnGroup_clicked();
    //设置功能
    void on_btnSeting_clicked();
    //FTP功能
    void on_btnFTP_clicked();


private:
    Ui::FriendWindow *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    //用户的状态
    QString userid;
    QString username;
    QString pthotoPath;
    QString status;
    QString job;
    //设置用户状态
    QAction *action[6];
    QString ImagesIcon[6];
    //设置我的数据源
    DBHelp *myDB;
    GroupSetting *myXML;

    //我的解析器
    QBoxProtocol *myproct;

    //好友列表-------------------------------------------
    QWidget *FriendListPanel;
    QGridLayout *gridlayout_FriendList;
    QScrollArea *FriendListscrollArea;
    //实时的动态数据
    QList<Friend*> FriendList; //实时数据列表
    QVector <FriendItem*> FriendItemList;//插入的控件列表

    //消息列表-------------------------------------------
    QWidget *MessageListPanel;
    QGridLayout *gridlayout_MessageList;
    QScrollArea *MessageListscrollArea;
    //实时的动态数据
    QMap<QString,QList<Message*>*>messageList;//实时数据列表【id】->message
    QVector <MessageItem*> MessageItemList;//插入的控件列表


    //群组列表-------------------------------------------
    QWidget *GroupListPanel;
    QGridLayout *gridlayout_GroupList;
    QScrollArea *GroupListscrollArea;
    //实时的动态数据
    QList<Group*>GroupList;
    QVector <GroupItem*> GroupItemList;


};

#endif // FRIENDWINDOW_H
