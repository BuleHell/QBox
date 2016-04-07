#include "talkwindow.h"
#include "ui_talkwindow.h"

TalkWindow::TalkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TalkWindow)
{
    ui->setupUi(this);
}

TalkWindow::~TalkWindow()
{
    delete ui;
}
