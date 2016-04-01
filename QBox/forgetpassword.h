#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QWidget>

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
signals:
    //把数据传出去
    //    void

private:
    Ui::ForgetPassword *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // FORGETPASSWORD_H
