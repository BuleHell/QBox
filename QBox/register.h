#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT
    
public:
    explicit Register(QWidget *parent = 0);
    ~Register();
protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btnClose_clicked();

private:
    Ui::Register *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // REGISTER_H
