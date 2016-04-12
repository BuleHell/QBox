#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QWidget>
#include<QtGui>
#include"setting.h"
#include"dbhelp.h"
#include"groupsetting.h"
#include"frienditem.h"
#include"messageitem.h"
#include"groupitem.h"
namespace Ui {
class FriendWindow;
}

class FriendWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit FriendWindow(QWidget *parent = 0);
    ~FriendWindow();
private:
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

private slots:
    void insertFriendItem(QString id,QString name,quint8 status,QString photo,QString info,quint8 isfriend);
    //初始化消息列表
    void updateMessagePanel(QDateTime, QString, QString peer);
    void insertMessageItem(QMap<QString, QString> &messagelist);


    //初始化群组列表
    void updateGroupPanel(QString groupID, QString name,QString info,QString admin,QMap<QString,QString> userList);
    void insertGroupItem();
    void on_btnClose_clicked();
    void initSatus(QString userid, QString username, QString pthotoPath,QString status);
    void Status_Changed();
    void on_btnAdd_clicked();

    void on_btnGroup_clicked();

    void on_btnSeting_clicked();

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

    //好友列表
    QWidget *FriendListPanel;
    QGridLayout *gridlayout_FriendList;
    QScrollArea *FriendListscrollArea;
    QVector <FriendItem*> FriendItemList;
//    QLink<

    //消息列表
    QWidget *MessageListPanel;
    QGridLayout *gridlayout_MessageList;
    QScrollArea *MessageListscrollArea;
    QMap<QString,QString>messageList;
    QVector <MessageItem*> MessageItemList;

    //群组列表
    QWidget *GroupListPanel;
    QGridLayout *gridlayout_GroupList;
    QScrollArea *GroupListscrollArea;
    QMap<QString,QString>GroupList;
    QVector <GroupItem*> GroupItemList;


};

#endif // FRIENDWINDOW_H
