#include "qboxprotocol.h"

QBoxProtocol::QBoxProtocol(QObject *parent) :
    QObject(parent)
{
    //要制作的数据流
    this->block=new QByteArray();

}
