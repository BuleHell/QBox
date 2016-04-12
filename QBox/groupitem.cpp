#include "groupitem.h"
#include "ui_groupitem.h"

GroupItem::GroupItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupItem)
{
    ui->setupUi(this);
}

GroupItem::GroupItem(QWidget *parent, int x, int y):QWidget(parent),
    ui(new Ui::GroupItem)
{
    ui->setupUi(this);
    this->setGeometry(x,y,260,75);
//    this->installEventFilter(this);

}

void GroupItem::init()
{

}

GroupItem::~GroupItem()
{
    delete ui;
}
