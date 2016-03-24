#ifndef QBOXPROTOCOL_H
#define QBOXPROTOCOL_H

#include <QObject>
#include<QDataStream>
#include<QtGui>
//MyQBox协议
////协议头
////----------------------------------
//|--数据大小--|：MessageSize   quint16      16个bit    ：消息头的大小
//|--数据类型--|：MessageType   quint16      16个bit
//|--发送者ID--|：senderID      QString      （任意bit）
//|--数据发送时间--|：MsgTimeStamp quint64   64个bit
////----------------------------------
//客户端
//to:登录：
//|-内容大小-|--用户名--|--用户密码--|
//to:心跳：
//|-用户ID-|
//to:消息传送
//|-发送者-|-接受者-|-消息类型-|-消息内容-|
//to：文件传送
//|-发送者-|-接受者-|-文件大小|-文件名-|-文件内容-|
////协议数据


//发送者的消息
enum QBOXMESSAGETYPE
{
    LOGIN=1,   //登录
    BACK_LOGIN,//登录返回
    //--------------------
    BEAT,       //心跳
    BACK_BEAT,  //心跳返回
    //------------------------
    MESSAGE,//发送消息
    GETADDRESSANDPORT,//获取通信ip和端口
    FRIENDLIST,//获取好友列表    //其它从这里加入
    LOGOUT//离开
};
//我的状态
enum MYSTATUS
{
    ONLINE=1,//在线

    OFFLINE//离线
};

//发送者的消息的大小（只包含消息的内容，因为其它的这些都是固定的大小）
typedef  quint16  MessageSize; /* 16 bit unsigned */ //16bit

class QBoxProtocol : public QObject
{
    Q_OBJECT

public:
    explicit QBoxProtocol(QObject *parent = 0);
    //------------制作协议----------------------
    //登录协议
    void  TO_Login(QString username,QString password,QString ID,QBOXMESSAGETYPE type=LOGIN, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //BACK:|-登录返回-|

    //心跳协议
    void To_beat(QString ID,MYSTATUS status,QBOXMESSAGETYPE type=BEAT, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //
    //发送消息(私聊消息)
    void To_Message(QString ID,QString receiver,QString Message,QBOXMESSAGETYPE type=MESSAGE, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //BACK:|-登录返回-|

    void Open(QByteArray *block);//主要的解析函数
public:
    //流的操作
    QByteArray *getBlock();
    void setBlock(QByteArray *b);
signals:
    //所有的协议内容解析完之后使用信号的方式发送出去
    //解析完登录
    void TO_Login_SLOT(QString username,QString password,QString ID, QDateTime time);
    //解析玩心跳
    void To_beat_SLOT(QString ID,MYSTATUS status, QDateTime time);
    //解析完消息
    void To_Message_SLOT(QString ID,QString receiver,QString Message, QDateTime time);
public slots:

private:
    QByteArray *block;
};

#endif // QBOXPROTOCOL_H
