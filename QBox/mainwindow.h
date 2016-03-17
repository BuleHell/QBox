#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    //这两个函数用来保证可以移动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btnClose_clicked();

    void on_btnMin_clicked();

    void on_btnClock_clicked();

    void on_btnSend_clicked();

    void on_toolBtn_clicked();

    void on_toolBtn2_clicked();

    void on_toolBtn3_clicked();

    void on_toolBtn4_clicked();

    void on_toolBtn5_clicked();

    void on_btnChange_clicked();

    void on_btnAdd_clicked();

    void on_btnGroup_clicked();

    void on_btnSeting_clicked();

    void on_btnFTP_clicked();

private:
    Ui::MainWindow *ui;
    //这三个点：记录移动的事件
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};

#endif // MAINWINDOW_H
