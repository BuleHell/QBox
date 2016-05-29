#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include<QtGui>
#include"qboxprotocol.h"
//#include <QFile>
//#include <QTime>
//#include<QByteArray>
//#include<QByteArray>
//这个是网络模块的主调用类
//这个类主要是处理协议和网络逻辑的调用者
//客户端的网络协议
class NetWork : public QObject
{
    Q_OBJECT
public:
    NetWork(QObject *parent = 0);
    static NetWork* Mynet;
    static NetWork* getInstance()
    {
        if(NetWork::Mynet == NULL)  //判断是否第一次调用
            NetWork::Mynet = new NetWork();
        return NetWork::Mynet;
    }
    ~NetWork();


    void initSocket(QString ip, int port);//初始化套接字
    
signals:
    //--------------------------------------------------
    void SLOT_login();
public slots:
    //链接服务器失败的错误消息槽:输出错误信息
    void ReadError(QAbstractSocket::SocketError);
    //读取数据的槽
    void ReadData();
public:
    //写入数据
    void writeData(QByteArray data);
    //set和get--------------------------------------------
    QHostAddress getHostAddress() const;
    void setHostAddress(const QHostAddress &value);

    qint16 getTcpPort() const;
    void setTcpPort(const qint16 &value);

    quint16 getBlockSize() const;
    void setBlockSize(const quint16 &value);
    QString getTcpIP() const;
    void setTcpIP(const QString &value);
    //----------------------------------------------------


private:
    //连接
    bool TCPToHost(QHostAddress hostAddress,qint16 tcpPort);
    //断开链接
    bool TCPoffHost();
    //--------------------------------------------------
private:
    QBoxProtocol *myProt;

    //----------------------------------
    QTcpSocket *tcpClient; //TCP客户端
    //----------------------------------
    QHostAddress hostAddress;
    QString tcpIP;
    qint16 tcpPort;
    quint16 blockSize;
};

#endif // NETWORK_H
