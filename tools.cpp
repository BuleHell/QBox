#include "tools.h"

Tools::Tools(QObject *parent) :
    QObject(parent)
{
}

void Tools::FormInCenter(QWidget *frm)
{
    QDesktopWidget desktop;
    int screenX=desktop.availableGeometry().width();
    int screenY=desktop.availableGeometry().height();
    int wndX=frm->width();
    int wndY=frm->height();
    QPoint movePoint(screenX/2-wndX/2,screenY/2-wndY/2);
    frm->move(movePoint);
}

void Tools::FormNotResize(QWidget *frm)
{
    frm->setFixedSize(frm->width(),frm->height());
}
