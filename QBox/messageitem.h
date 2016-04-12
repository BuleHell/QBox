#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H

#include <QWidget>

namespace Ui {
class MessageItem;
}

class MessageItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit MessageItem(QWidget *parent = 0);
    MessageItem(QWidget *parent,int x,int y);
    //把所有的东西全在init里进行初始化
    void init();
    ~MessageItem();
    
private:
    Ui::MessageItem *ui;
private:
    //传入的数据
};

#endif // MESSAGEITEM_H
