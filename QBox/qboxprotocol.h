#ifndef QBOXPROTOCOL_H
#define QBOXPROTOCOL_H

#include <QObject>
//发送者的消息
enum MessageType
{
    LOGIN,//新加入
    MESSAGE,//发送消息
    GETADDRESSANDPORT,//获取通信ip和端口
    FRIENDLIST,//获取好友列表
    //其它从这里加入
    LOGOUT//离开
};
/* 16 bit unsigned */
typedef  quint16  MessageSize; /* 16 bit unsigned */
typedef  quint16  SendID; /* 16 bit unsigned */
class QBoxProtocol : public QObject
{
    Q_OBJECT
public:
    explicit QBoxProtocol(QObject *parent = 0);
    //制作协议头（true：消息头正确了 false：大小字段没填）
    bool makeHead(MessageType type,MessageSize size,SendID ID,stamp);
    //制作协议主体
    void makeBody(MessageType type,QByteArray content);
    //总的主体
    void make();
signals:
    
public slots:

private:
    QByteArray *block;

};

#endif // QBOXPROTOCOL_H
