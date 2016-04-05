#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QWidget>
#include"tools.h"

namespace Ui {
class ForgetPassword;
}

class ForgetPassword : public QWidget
{
    Q_OBJECT
    
public:
    explicit ForgetPassword(QWidget *parent = 0);
    ~ForgetPassword();

protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_btnClose_clicked();
    void on_btnPhone_clicked();

    void on_btnMail_clicked();

signals:
    //把数据传出去
    void way(int i);
private:
    Ui::ForgetPassword *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // FORGETPASSWORD_H
