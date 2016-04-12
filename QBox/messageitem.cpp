#include "messageitem.h"
#include "ui_messageitem.h"

MessageItem::MessageItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageItem)
{
    ui->setupUi(this);
}

MessageItem::MessageItem(QWidget *parent, int x, int y):
    QWidget(parent),
    ui(new Ui::MessageItem)
{
    ui->setupUi(this);
    this->setGeometry(x,y,260,75);
    this->installEventFilter(this);
//    this->installEventFilter();

//    this->init();
}

MessageItem::~MessageItem()
{
    delete ui;
}
