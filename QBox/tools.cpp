#include "tools.h"

Tools::Tools(QObject *parent) :
    QObject(parent)
{
}

void Tools::FormInCenter(QWidget *frm)
{
    //窗体居中显示
    QDesktopWidget desktop;
    int screenX=desktop/*.availableGeometry()*/.width();
    int screenY=desktop/*.availableGeometry()*/.height();
    int wndX=frm->width();
    int wndY=frm->height();
    QPoint movePoint(screenX/2-wndX/2,screenY/2-wndY/2);
    frm->move(movePoint);
}

void Tools::FormNotResize(QWidget *frm)
{
    frm->setFixedSize(frm->width(),frm->height());
}

QString Tools::getStatus(int i)
{
    switch(i)
    {
    case 0:
    {
        return "在线";

    }
    case 1:
    {
        return "隐身";

    }
    case 2:
    {
        return "忙碌";

    }
    case 3:
    {
        return "离开";

    }
    case 4:
    {
        return "求扰";

    }
    case 5:
    {
        return "勿扰";

    }
    default:
    {
        return "错误";
    }
    }
}
//这个函数必须在show之后使用
QString Tools::movetoRight(QWidget *frm)
{
    QDesktopWidget desktop;
    int screenX=desktop/*.availableGeometry()*/.width();
    int screenY=desktop/*.availableGeometry()*/.height();
    int wndX=frm->width();
    int wndY=frm->height();
    QPoint movePoint(screenX-wndX,screenY/2-wndY/2);
    frm->move(movePoint);




//    QDesktopWidget desktop;
//    int screenX=desktop.availableGeometry().width();
//    int screenY=desktop.availableGeometry().height();
//    int wndX=frm->/*frameGeometry().*/width();
//    int wndY=frm->/*frameGeometry().*/height();
//    //距离
//    QPoint movePoint(screenX/2-wndX/2,screenY/2-wndY/2);
//    frm->move(movePoint);

//    frm->move(screenX-wndX,screenY/2-wndY/2);
}
