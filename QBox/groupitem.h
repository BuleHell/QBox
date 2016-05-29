#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QWidget>
#include"talkwindow.h"
namespace Ui {
class GroupItem;
}

class GroupItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit GroupItem(QWidget *parent = 0);
    GroupItem(QWidget *parent,int x,int y,QString GroupID,QString name,QString info,QString admin,QMap<QString,QString> userList,int count);
    ~GroupItem();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::GroupItem *ui;
    QString groupID;
    QString name;
    QString info;
    QString admin;
    QMap<QString,QString> *userList;
    int count;

    //聊天面板
    TalkWindow *talk;

};

#endif // GROUPITEM_H
