#include "qboxprotocol.h"

QBoxProtocol::QBoxProtocol(QObject *parent) :
    QObject(parent)
{
    //要制作的数据流
    this->block=new QByteArray();
}

void QBoxProtocol::makeHead(QBOXMESSAGETYPE type, MessageSize size, QString ID, QDateTime time)
{
    qDebug()<<"----------------PACK----------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);

    //输入消息内容的大小
    qDebug()<<"Messagesize:";
    qDebug()<<(quint16)size;
    out<<(quint16)size;

    //输入消息类型
    qDebug()<<"type:";
    qDebug()<<(quint16)type;
    out << (quint16)type;

    //输入发送的ID
    qDebug()<<"MessageID:";
    qDebug()<<ID;
    out<<ID;

    //输入发送的时间戳
    qDebug()<<"MessageTIME:";
    qDebug()<<time;
    out<<time;

    //查看输入流和大小
    qDebug()<<QObject::tr("大小：")<<this->block->size();
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();

}

void QBoxProtocol::openHead(QByteArray *block, quint16 &size, quint16 &type, QString &ID, QDateTime &time)
{
    qDebug()<<"----------------OPEN----------------";
    //建造一个输出流
    QDataStream in(block, QIODevice::ReadOnly);
    //设定一个版本
    in.setVersion(QDataStream::Qt_4_8);

//输入消息内容的大小
//    quint16 size;
    in>>size;
    qDebug()<<"Messagesize:";
    qDebug()<<size;


    //输入消息类型
  //  quint16 type;
    in>>type;
    qDebug()<<"type:";
    qDebug()<<type;

    //输入发送的ID
//    QString ID;
    in>>ID;
    qDebug()<<"MessageID:";
    qDebug()<<ID;

    //输入发送的时间戳
//    qint64 stamp;
    in>>time;
    qDebug()<<"MessageTIME:";
    qDebug()<<time;
}

QByteArray *QBoxProtocol::getBlock()
{
    return this->block;
}

void QBoxProtocol::setBlock(QByteArray *b)
{
    this->block=b;
}

void QBoxProtocol::makeBody(QBOXMESSAGETYPE type, QByteArray content)
{
    switch (type)
    {
    case LOGIN://登录消息
    {

        break;
    }
    case MESSAGE://
    {
        break;

    }
    default:
    {
        qDebug()<<"ERROR";
    }

    }


}



