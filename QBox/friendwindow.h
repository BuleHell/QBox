﻿#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QWidget>
#include<QtGui>
#include"setting.h"
#include"dbhelp.h"
#include"groupsetting.h"
#include"frienditem.h"
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


protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void insertFriendItem(QString id,QString name,quint8 status,QString photo,QString info,quint8 isfriend);


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


    //好友和好友分组
    QToolBox *friends_box;
    QGroupBox *Groups_box;

    QVector <FriendItem*> FriendItemList;

};

#endif // FRIENDWINDOW_H
