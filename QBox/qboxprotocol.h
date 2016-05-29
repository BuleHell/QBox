#ifndef QBOXPROTOCOL_H
#define QBOXPROTOCOL_H

#include <QObject>
#include<QDataStream>
#include<QtGui>
//QMap<int,QString> Status;
//Status[0]="离开";






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
    //-----------------------
    BEAT,       //心跳
    BACK_BEAT,  //心跳返回
    //------------------------
    MESSAGE,//发送消息
    BACK_MESSAGE,//返回消息
    //    RECEIVER_MESSAGE,//接受返回消息

    //------------------------
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
//登录指示
enum CANLOGIN
{
    NONAME,//名字不存在
    ERRORPWD,//密码错误
    FORBIDDEN,//禁止登录
    SUCCESS,//登录成功
    NOLOGIN//未知原因，不能登录


};
//消息状态
enum MESSAGESTSTUS
{
    LOST_msg,//消息丢失
    OFFLINE_msg,//对方离线了（服务器端离线消息）
    SUCESS_msg//消息成功

};

//发送者的消息的大小（只包含消息的内容，因为其它的这些都是固定的大小）
typedef  quint16  MessageSize; /* 16 bit unsigned */ //16bit

class QBoxProtocol : public QObject
{
    Q_OBJECT

public:
    //制作成单例模式
    static QBoxProtocol *myprot;
    static QBoxProtocol*getInstance()
    {
        if(QBoxProtocol::myprot==NULL)
        {

            QBoxProtocol::myprot=new QBoxProtocol();

        }
        return myprot;
    }


    explicit QBoxProtocol(QObject *parent = 0);
    //------------制作协议----------------------
    //登录协议
    void  ToLogin(QString username,QString password,QString ID,QBOXMESSAGETYPE type=LOGIN, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //BACK:|-登录返回-|
    void BackLogin(QString ID,CANLOGIN iscan=NOLOGIN,QBOXMESSAGETYPE type=BACK_LOGIN, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //心跳协议
    void To_beat(QString ID,MYSTATUS status,QBOXMESSAGETYPE type=BEAT, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //心跳协议返回
    void Back_beat(QMap<QString, quint8> friendlistStatus, QString ID, QBOXMESSAGETYPE type=BACK_BEAT, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //发送消息(私聊消息)
    void To_Message(QString ID,QString receiver,QString Message,QBOXMESSAGETYPE type=MESSAGE, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);
    //发送消息（给客户端A发）
    void back_Message(QString ID,MESSAGESTSTUS msg_type,QBOXMESSAGETYPE type=BACK_MESSAGE, QDateTime time=QDateTime::currentDateTime(), MessageSize size=0);

    //------------解析函数------------------------------
    void Open(QByteArray *block);//主要的解析函数
public:
    //流的操作
    QByteArray *getBlock();
    void setBlock(QByteArray *b);
signals:
    //所有的协议内容解析完之后使用信号的方式发送出去
    //解析完登录
    void TO_Login_SLOT(QString username,QString password,QString ID, QDateTime time);
    //解析完登录返回
    void back_Login_SLOT(QString ID,CANLOGIN status, QDateTime time);
    //解析玩心跳
    void To_beat_SLOT(QString ID,MYSTATUS status, QDateTime time);
    //解析心跳返回
    void back_beat_SLOT(QMap<QString, quint8> friendlistStatus,QString ID,QDateTime time);
    //解析完消息
    void To_Message_SLOT(QString ID,QString receiver,QString Message, QDateTime time);
    //解析玩发送消息
    void back_Message_SLOT(QString ID,MESSAGESTSTUS msg_type,QDateTime time);
public slots:

private:
    QByteArray *block;
};

#endif

