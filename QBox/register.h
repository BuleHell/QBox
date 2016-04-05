#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include"tools.h"
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT
    
public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    QString getName() const;
    void setName(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getEamil() const;
    void setEamil(const QString &value);

    QString getPhone() const;
    void setPhone(const QString &value);

protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btnClose_clicked();

    void on_lineEditUserName_editingFinished();

    void on_lineEditPassword_editingFinished();

    void on_lineEditConfirm_editingFinished();

    void on_lineEditMail_editingFinished();

    void on_lineEditPhone_editingFinished();
    void on_btnRegister_clicked();

signals:
    //把数据传出去
    void PersonInfo(QString name,QString password,QString eamil,QString phone);
    //注册返回
    void nothingback();
private:
    Ui::Register *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    //注册的帐号信息放在这里
    QString name;
    QString password;
    QString eamil;
    QString phone;
};

#endif // REGISTER_H
