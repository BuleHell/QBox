#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
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
signals:
    
public slots:
    
};

#endif // TOOLS_H
