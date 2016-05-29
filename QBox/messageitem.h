#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H
#include<QtGui>
#include"talkwindow.h"
namespace Ui {
class MessageItem;
}

class MessageItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit MessageItem(QWidget *parent = 0);
    MessageItem(QWidget *parent,int x,int y,QString photo,QString name,QString time,QString message);
    ~MessageItem();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::MessageItem *ui;
private:
    //传入的数据
    TalkWindow *talk;
};

#endif // MESSAGEITEM_H
