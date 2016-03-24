#include "qboxprotocol.h"

QBoxProtocol::QBoxProtocol(QObject *parent) :
    QObject(parent)
{
    //要制作的数据流
    this->block=new QByteArray();
}


void QBoxProtocol::ToLogin(QString username, QString password, QString ID, QBOXMESSAGETYPE type, QDateTime time, MessageSize size)
{
    //|--数据大小--|--数据类型--|--发送者ID--|--数据发送时间--|-用户名-|-密码-|
    //    qDebug()<<"----------------PACK--TOLogin--------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);
    //设置协议头
    //    qDebug()<<"----------------PACK--Header---------------";
    //输入消息内容的大小
    //    qDebug()<<"Messagesize:"<<(quint16)size;
    out<<(quint16)size;
    //输入消息类型
    //    qDebug()<<"type:"<<(quint16)type;
    out << (quint16)type;
    //输入发送的ID
    //    qDebug()<<"MessageID:"<<ID;
    out<<ID;
    //输入发送的时间戳
    //    qDebug()<<"MessageTIME:"<<time;
    out<<time;
    //    qDebug()<<"----------------OVER--Header---------------";
    //------------------------------------------------------
    //    qDebug()<<"----------------body---------------";
    //用户名
    out<<username;
    //密码
    out<<password;
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();
    //查看输入流和大小
    //    qDebug()<<QObject::tr("大小：")<<this->block->size();
    //    qDebug()<<"----------------body--over-------------";
}

void QBoxProtocol::BackLogin(QString ID, CANLOGIN iscan, QBOXMESSAGETYPE type, QDateTime time, MessageSize size)
{
    //|--数据大小--|--数据类型--|--发送者ID--|--数据发送时间--|-登录指示-|
    //    qDebug()<<"----------------PACK--TOLogin--------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);
    //设置协议头
    //    qDebug()<<"----------------PACK--Header---------------";
    //输入消息内容的大小
    //    qDebug()<<"Messagesize:"<<(quint16)size;
    out<<(quint16)size;
    //输入消息类型
    //    qDebug()<<"type:"<<(quint16)type;
    out << (quint16)type;
    //输入发送的ID
    //    qDebug()<<"MessageID:"<<ID;
    out<<ID;
    //输入发送的时间戳
    //    qDebug()<<"MessageTIME:"<<time;
    out<<time;
    //    qDebug()<<"----------------OVER--Header---------------";
    //------------------------------------------------------
    //    qDebug()<<"----------------body---------------";
    out<<(quint8)iscan;
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();
    //查看输入流和大小
    //    qDebug()<<QObject::tr("大小：")<<this->block->size();
    //    qDebug()<<"----------------body--over-------------";
}

void QBoxProtocol::To_beat(QString ID, MYSTATUS status, QBOXMESSAGETYPE type, QDateTime time, MessageSize size)
{
    //|--数据大小--|--数据类型--|--发送者ID--|--数据发送时间--|-状态-|
    //       qDebug()<<"----------------PACK--TOLogin--------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);
    //设置协议头
    //        qDebug()<<"----------------PACK--Header---------------";
    //输入消息内容的大小
    //        qDebug()<<"Messagesize:"<<(quint16)size;
    out<<(quint16)size;
    //        输入消息类型
    //        qDebug()<<"type:"<<(quint16)type;
    out << (quint16)type;
    //输入发送的ID
    //        qDebug()<<"MessageID:"<<ID;
    out<<ID;
    //输入发送的时间戳
    //        qDebug()<<"MessageTIME:"<<time;
    out<<time;
    //        qDebug()<<"----------------OVER--Header---------------";
    //------------------------------------------------------
    //        qDebug()<<"----------------body---------------";
    //状态
    out<<(quint16)status;
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();
    //查看输入流和大小
    //        qDebug()<<QObject::tr("大小：")<<this->block->size();
    //        qDebug()<<"----------------body--over-------------";
}

void QBoxProtocol::Back_beat(QMap<QString, quint8> friendlistStatus, QString ID, QBOXMESSAGETYPE type, QDateTime time, MessageSize size)
{
    //|--数据大小--|--数据类型--|--发送者ID--|--数据发送时间--|-整个map-|
    //       qDebug()<<"----------------PACK--TOLogin--------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);
    //设置协议头
    //        qDebug()<<"----------------PACK--Header---------------";
    //输入消息内容的大小
    //        qDebug()<<"Messagesize:"<<(quint16)size;
    out<<(quint16)size;
    //        输入消息类型
    //        qDebug()<<"type:"<<(quint16)type;
    out << (quint16)type;
    //输入发送的ID
    //        qDebug()<<"MessageID:"<<ID;
    out<<ID;
    //输入发送的时间戳
    //        qDebug()<<"MessageTIME:"<<time;
    out<<time;
    //        qDebug()<<"----------------OVER--Header---------------";
    //------------------------------------------------------
    //        qDebug()<<"----------------body---------------";
    //
    out<<friendlistStatus;
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();
    //查看输入流和大小
    //        qDebug()<<QObject::tr("大小：")<<this->block->size();
    //        qDebug()<<"----------------body--over-------------";
}

void QBoxProtocol::To_Message(QString ID, QString receiver, QString Message, QBOXMESSAGETYPE type, QDateTime time, MessageSize size)
{
    //|--数据大小--|--数据类型--|--发送者ID--|--数据发送时间--|-接受者ID-|-内容-|
    //  qDebug()<<"----------------PACK--TOLogin--------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);
    //设置协议头
    //    qDebug()<<"----------------PACK--Header---------------";
    //输入消息内容的大小
    //    qDebug()<<"Messagesize:"<<(quint16)size;
    out<<(quint16)size;
    //输入消息类型
    //    qDebug()<<"type:"<<(quint16)type;
    out << (quint16)type;
    //输入发送的ID
    //    qDebug()<<"MessageID:"<<ID;
    out<<ID;
    //输入发送的时间戳
    //    qDebug()<<"MessageTIME:"<<time;
    out<<time;
    //    qDebug()<<"----------------OVER--Header---------------";
    //    ------------------------------------------------------
    //    qDebug()<<"----------------body---------------";
    //接受者ID
    out<<receiver;
    //消息内容
    out<<Message;
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();
    //查看输入流和大小
    //    qDebug()<<QObject::tr("大小：")<<this->block->size();
    //    qDebug()<<"----------------body--over-------------";



}

void QBoxProtocol::back_Message(QString ID, MESSAGESTSTUS msg_type, QBOXMESSAGETYPE type, QDateTime time, MessageSize size)
{
    //|--数据大小--|--数据类型--|--发送者ID--|--数据发送时间--|-接受者ID-|-内容-|
    //  qDebug()<<"----------------PACK--TOLogin--------------";
    //建造一个输入流
    QDataStream out(this->block, QIODevice::WriteOnly);
    //设定一个版本
    out.setVersion(QDataStream::Qt_4_8);
    //设置协议头
    //    qDebug()<<"----------------PACK--Header---------------";
    //输入消息内容的大小
    //    qDebug()<<"Messagesize:"<<(quint16)size;
    out<<(quint16)size;
    //输入消息类型
    //    qDebug()<<"type:"<<(quint16)type;
    out << (quint16)type;
    //输入发送的ID
    //    qDebug()<<"MessageID:"<<ID;
    out<<ID;
    //输入发送的时间戳
    //    qDebug()<<"MessageTIME:"<<time;
    out<<time;
    //    qDebug()<<"----------------OVER--Header---------------";
    //    ------------------------------------------------------
    //    qDebug()<<"----------------body---------------";

    //消息状态
    out<<(quint8)msg_type;
    //重新填入大小
    out.device()->seek(0);
    out<<(quint16)this->block->size();
    //查看输入流和大小
    //    qDebug()<<QObject::tr("大小：")<<this->block->size();
    //    qDebug()<<"----------------body--over-------------";
}

void QBoxProtocol::Open(QByteArray *block)
{
    qDebug()<<tr("----------------开始解析----------------");
    //建造一个输出流
    QDataStream in(block, QIODevice::ReadOnly);
    //设定一个版本
    in.setVersion(QDataStream::Qt_4_8);
    //开始解析
    if(block->isEmpty()){
        qDebug()<<"Empty";
    }
    //先把头拿出来
    quint16 _size;
    quint16 _type;
    QBOXMESSAGETYPE TYPE;
    QString _ID;
    QDateTime _time;
    in>>_size;
    in>>_type;
    in>>_ID;
    in>>_time;
    TYPE=(QBOXMESSAGETYPE)_type;
    switch (TYPE) {
    case LOGIN:
    {
        qDebug("Login");
        //|-用户名-|-密码-|
        QString name;
        QString pswd;
        in>>name;
        in>>pswd;
        qDebug()<<"name:"<<name<<"password"<<pswd<<"ID:"<<_ID<<"time:"<<_time;
        //把解析的内容发出去
        emit TO_Login_SLOT(name,pswd,_ID, _time);
        break;
    }
    case BACK_LOGIN:
    {
        qDebug("Login back");
        //|-登录状态-|
        qint8 _stat;
        in>>_stat;
        CANLOGIN _s=(CANLOGIN)_stat;
        qDebug()<<"status:"<<_s<<"ID:"<<_ID<<"time:"<<_time;
        emit back_Login_SLOT(_ID,_s, _time);
        break;
    }
    case BEAT:
    {
        qDebug("BEAT");
        //|-状态-|
        MYSTATUS status;
        quint16 ss;
        in>>ss;
        status=(MYSTATUS)ss;
        qDebug()<<"ID:"<<_ID<<"Status"<<status<<"time:"<<_time;
        //把解析的内容发出去
        emit  To_beat_SLOT(_ID,status,_time);
        break;
    }
    case BACK_BEAT:
    {
        qDebug("BACK_BEAT");
        //|-好友列表-|
        QMap<QString,quint8>liststatus;
        in>>liststatus;
        qDebug()<<"ID:"<<_ID<<"liststatus"<<liststatus<<"time:"<<_time;
        //把解析的内容发出去
        emit  back_beat_SLOT(liststatus,_ID,_time);
        break;
    }
    case MESSAGE:
    {
        //|-接受者ID-|-内容-|
        QString receiver;
        QString message;
        in>>receiver;
        in>>message;
        qDebug()<<"ID:"<<_ID<<"receiver"<<receiver<<"message"<<message<<"time:"<<_time;
        emit  To_Message_SLOT(_ID,receiver,message,_time);
        break;
    }
    case BACK_MESSAGE:
    {
        //|-消息状态-|
        quint8 sts;
        in>>sts;
        MESSAGESTSTUS msg_s=(MESSAGESTSTUS)sts;
        qDebug()<<"ID:"<<_ID<<"MESSAGESTSTUS"<<msg_s<<"time:"<<_time;
        emit back_Message_SLOT(_ID,msg_s,_time);
        break;
    }

    default:
    {
        qDebug()<<QObject::tr("没有该种消息，或者消息结构体被损坏");
        break;
    }

    }



}


QByteArray *QBoxProtocol::getBlock()
{
    return this->block;
}

void QBoxProtocol::setBlock(QByteArray *b)
{
    this->block=b;
}





