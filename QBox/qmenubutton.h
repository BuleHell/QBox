#ifndef QMENUBUTTON_H
#define QMENUBUTTON_H
//这个类是用来提升相应的对象
#include <QPushButton>
class QMenu;
class QMenuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QMenuButton(QWidget *parent = 0);
    QMenu * getmenu();

signals:

protected:
public slots:
    void popupmenu();
private:
    QMenu * menu;

};

#endif // QMENUBUTTON_H


