#ifndef QBOXCLIENT_H
#define QBOXCLIENT_H

#include <QObject>
#include "mainwindow.h"
#include "login.h"

class MainWindow;
class Login;

class QBoxClient : public QObject
{
    Q_OBJECT
public:
    explicit QBoxClient(QObject *parent = 0);
    ~QBoxClient();
    void showLogin();
    void showMainWindow();
signals:
    
public slots:
    
private:
    Login *login;
    MainWindow *mainwindow;

};

#endif // QBOXCLIENT_H
