#ifndef LOGIN_H
#define LOGIN_H

#include <QtGui>
#include <QMouseEvent>
#include <QPoint>
#include"network.h"
#include"tools.h"
#include"register.h"
#include"forgetpassword.h"
#include"setting.h"
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
private:
    //在线状态初始化
    void Status_init();
    //头像初始化
    void photo_init();

protected:    
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //使用事件监听器
    bool eventFilter(QObject *obj, QEvent *ev);
signals:
    //登录成功的信号
    void LoginSuccessSIGNAL(QString userid,QString username,QString pthotoPath,QString status);

private slots:
    void Status_Changed();
    void on_btnLogin_clicked();

    void on_btnMin_clicked();

    void on_btnClose_clicked();

    //设置找回密码方式
    void getMyLostPWD(int way);
    //设置注册的信息
    void registeredInfo(QString name,QString password,QString eamil,QString phone);
    void registeredBack();

    //登录成功的处理函数
    void LoginSuccess();
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
    int forget_way;//找回密码的方式
    //设置用户状态
    QAction *action[6];
    QString ImagesIcon[6];
private:
    Setting *mysetting;

    void saveSetting();



public:
    void showForgetPwdView();
    void showRegisterView();
    //-------------------------
private:
    QString username;//用户的名字
    QString userid;//用户的ID
    QDateTime lastlogin;//上次登录时间
    QString userphotopath;// 用户的图片
    bool isremeber;//是否记住密码
    QString pwd;//密码
    QString status;//状态
    //-------------------------
public:
    //set和get
    QString getUsername() const;
    void setUsername(const QString &value);
    QString getUserid() const;
    void setUserid(const QString &value);
    QDateTime getLastlogin() const;
    void setLastlogin(const QDateTime &value);
    QString getUserphotopath() const;
    void setUserphotopath(const QString &value);
    bool getIsremeber() const;
    void setIsremeber(bool value);
    QString getPwd() const;
    void setPwd(const QString &value);
    QString getStatus() const;
    void setStatus(const QString &value);
};



#endif // LOGIN_H
