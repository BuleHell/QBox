#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H

#include <QWidget>
#include<QtGui>
#include"setting.h"
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

protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btnClose_clicked();
    void initSatus(QString userid, QString username, QString pthotoPath,QString status);
    void Status_Changed();
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

};

#endif // FRIENDWINDOW_H
