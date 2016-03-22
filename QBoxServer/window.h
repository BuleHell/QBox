#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include<QtGui>
namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btnPrivate_toggled(bool checked);

    void on_btnPublic_toggled(bool checked);

    void on_btnPressure_toggled(bool checked);

    void on_btnWatch_toggled(bool checked);

    void on_btnQuit_clicked();

private:
    Ui::Window *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // WINDOW_H
