#ifndef TALKWINDOW_H
#define TALKWINDOW_H

#include<QtGui>
#include"tools.h"
#include"dbhelp.h"//数据库
namespace Ui {
class TalkWindow;
}

class TalkWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit TalkWindow(QWidget *parent = 0);
    void init(    QString userid,
                  QString name,
                  quint8 status,
                  QString photo,
                  QString info);
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
    QString userid;
    QString name;
    quint8 status;
    QString photo;
    QString info;

    //数据助手
    DBHelp *myDB;

    //我的消息记录
    QStringList MyMessageList;
    QString message;

};

#endif // TALKWINDOW_H
