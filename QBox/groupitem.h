#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QWidget>

namespace Ui {
class GroupItem;
}

class GroupItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit GroupItem(QWidget *parent = 0);
    GroupItem(QWidget *parent,int x,int y);
    //把所有的东西全在init里进行初始化
    void init();
    ~GroupItem();

private:
    Ui::GroupItem *ui;
};

#endif // GROUPITEM_H
