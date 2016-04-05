#include "qboxclient.h"
#include <QMouseEvent>
#include <QPoint>
QBoxClient::QBoxClient(QObject *parent):
    QObject(parent)
{
}

QBoxClient::~QBoxClient()
{
    delete login;
    delete mainwindow;
}

void QBoxClient::showLogin()
{
    login=new Login();
    login->show();
}

void QBoxClient::showMainWindow()
{
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->close();
    mainwindow=new MainWindow();
}
