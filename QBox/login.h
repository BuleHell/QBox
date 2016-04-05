#ifndef LOGIN_H
#define LOGIN_H

#include <QtGui>
#include <QMouseEvent>
#include <QPoint>
#include"tools.h"
#include"register.h"
#include"forgetpassword.h"
/*
 *这个文件的作用是处理登陆的逻辑
 *登录的界面在ui中设置，使用完全的MVC模式进行编码
 */
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
    
public:
    //得到类的对象
    explicit Login(QWidget *parent = 0);
    ~Login();
protected:    
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //使用事件监听器
    bool eventFilter(QObject *obj, QEvent *ev);
private slots:

    void on_btnLogin_clicked();

    void on_btnMin_clicked();

    void on_btnClose_clicked();

    //设置找回密码方式
    void getMyLostPWD(int way);
    //设置注册的信息
    void registeredInfo(QString name,QString password,QString eamil,QString phone);
    void registeredBack();
private:

    Ui::Login *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

    //注册页面
    Register *registerView;
    //忘记密码页面
    ForgetPassword *forgetpwdView;
    int forget_way;

public:
    void showForgetPwdView();
    void showRegisterView();


};



#endif // LOGIN_H
