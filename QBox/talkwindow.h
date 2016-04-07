#ifndef TALKWINDOW_H
#define TALKWINDOW_H

#include <QWidget>

namespace Ui {
class TalkWindow;
}

class TalkWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit TalkWindow(QWidget *parent = 0);
    ~TalkWindow();
    
private:
    Ui::TalkWindow *ui;
};

#endif // TALKWINDOW_H
