#ifndef TALKWINDOW_H
#define TALKWINDOW_H

#include<QtGui>
#include"tools.h"
#include"dbhelp.h"//数据库
#include"groupsetting.h"//群组
namespace Ui {
class TalkWindow;
}

class TalkWindow : public QWidget
{
    Q_OBJECT
    
public:
    static TalkWindow * myTalkWindow;
    static TalkWindow *getInstance()
    {
        if(TalkWindow::myTalkWindow==NULL)
        {
            TalkWindow::myTalkWindow=new TalkWindow();
        }
        return TalkWindow::myTalkWindow;

    }
private:
    explicit TalkWindow(QWidget *parent = 0);
public:
    //单聊的数据
    void init(    QString userid,
                  QString name,
                  quint8 status,
                  QString photo,
                  QString info);
    void init_Group(
            QString groupID,
            QString name,
            QString info,
            QString admin,
            QMap<QString,QString> *userList);
    ~TalkWindow();
protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btnClose_clicked();

    void on_btnClear_clicked();

    void on_btnSend_clicked();

private:
    Ui::TalkWindow *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
private:
    //实际的数据
    int type;//群聊还是单聊 1：单聊  2: 群聊

    //单聊的数据
    QString userid;
    QString name;
    quint8 status;
    QString photo;
    QString info;
    //群聊的数据
    QString groupID;
    QString Groupname;
    QString Groupinfo;
    QString admin;
    QMap<QString,QString> *userList;


    //数据助手
    DBHelp *myDB;
    GroupSetting *myXML;


    //我的消息记录
    QStringList MyMessageList;
    QString message;

};

#endif // TALKWINDOW_H
