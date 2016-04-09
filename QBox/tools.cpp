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
        return "";

    }
    case 1:
    {
        return "在线";

    }
    case 2:
    {
        return "";

    }
    case 3:
    {
        return "";

    }
    case 4:
    {
        return "";

    }
    case 5:
    {
        return "";

    }
    default:
        return "ERROR";

    }
}
