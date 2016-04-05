#ifndef MYCLIENTSOCKET_H
#define MYCLIENTSOCKET_H

#include <QTcpSocket>
#include<QtNetwork>
//重载TCP的主要原因是为了增加ID号和相应的信号
class myClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit myClientSocket(QObject *parent = 0,int clientID=0);
    
signals:
    //客户端读取数据
    void ClientReadData(int clientID,QString IP,int Port,QByteArray data);
    //客户端断开链接
    void ClientDisConnect(int clientID,QString IP,int Port);
public slots:

private slots:
    //读取一条数据并发送信号
    void ReadData();
    //断开链接，并发送一条信号
    void DisConnect();
private:
    //客户端的ID号
    int clientID;
};

#endif // MYCLIENTSOCKET_H
