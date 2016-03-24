#ifndef QBOXPROTOCOL_H
#define QBOXPROTOCOL_H

#include <QObject>
#include<QDataStream>
#include<QtGui>
/*
 *MyQBox协议


//协议头
//----------------------------------
|--数据大小--|：MessageSize   quint16      16个bit    ：消息头的大小
|--数据类型--|：MessageType   quint16      16个bit
|--发送者ID--|：senderID      QString      （任意bit）
|--数据发送时间--|：MsgTimeStamp quint64   64个bit
//----------------------------------


//协议数据
*/

//发送者的消息
enum QBOXMESSAGETYPE
{
    LOGIN=1,//新加入
    MESSAGE,//发送消息
    GETADDRESSANDPORT,//获取通信ip和端口
    FRIENDLIST,//获取好友列表    //其它从这里加入
    LOGOUT//离开
};

//发送者的消息的大小（只包含消息的内容，因为其它的这些都是固定的大小）
typedef  quint16  MessageSize; /* 16 bit unsigned */ //16bit

class QBoxProtocol : public QObject
{
    Q_OBJECT

public:
    explicit QBoxProtocol(QObject *parent = 0);
    //-------------------------------------------------
    //制作协议头（true：消息头正确了 false：大小字段没填）
    void makeHead(QBOXMESSAGETYPE type, MessageSize size, QString ID, QDateTime time);
    //制作协议主体
    void makeBody(QBOXMESSAGETYPE type,QByteArray content);
    //--------------------------------------------------
    //打开协议头
    void openHead(QByteArray *block, quint16 &size,  quint16 &type, QString &ID, QDateTime &time);
    //打开协议主体
    void openBody();




public:
    //流的操作
    QByteArray *getBlock();
    void setBlock(QByteArray *b);
signals:
   //所有的协议内容解析完之后使用信号的方式发送出去

public slots:

private:
    QByteArray *block;
};

#endif // QBOXPROTOCOL_H
