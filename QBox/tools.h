#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include<QtGui>
#include <QDesktopWidget>

class Tools : public QObject
{
    Q_OBJECT
public:
    explicit Tools(QObject *parent = 0);
    //使显示的窗口居中
    static void FormInCenter(QWidget *frm);
    //大小固定
    static void FormNotResize(QWidget *frm);
    //由数字获得状态
    static QString getStatus(int i);
    //缓慢移动到右侧
    static QString movetoRight(QWidget *frm);



signals:
    
public slots:
    
};

#endif // TOOLS_H
