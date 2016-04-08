#ifndef FRIENDITEM_H
#define FRIENDITEM_H
#include<QtGui>
#include"talkwindow.h"

//这个是一个Item，即朋友列表额选项
//需要做到的是：一：生成列表
//该列表可以点击生成聊天的页面

class ChatView;
class FriendItem : public QWidget
{
    Q_OBJECT
public:
    explicit FriendItem(QWidget *parent = 0);
    FriendItem(QWidget *parent,int x,int y,QString id, QString name, quint8 status, QString photo, QString info);
public:
    QLabel *Avatar;
    QLabel *Status;
    QLabel *Name;
    QLabel *PS;
    QGroupBox *groupbox;
    QPixmap avatar_images;
private:
    QString userid;
    QString name;
    quint8 status;
    QString photo;
    QString info;
signals:

public slots:

protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    void init(QString name, quint8 status, QString photo, QString info);
    bool IsChatOpen;
    //    ChatView *w;

};

#endif // FRIENDITEM_H
