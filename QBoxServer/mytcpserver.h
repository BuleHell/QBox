#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QHostAddress>
#include"myclientsocket.h"
class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit myTcpServer(QObject *parent = 0);
public:
    //发送数据客户ID，ip,port,data
    void SendData(int clientID,QString IP,int Port,QByteArray data);
private:
    //链接的链表
    QList<myClientSocket *> ClientSocketList;
    //链接的ID号
    QList<int> ClientSocketID;
protected:
    void incomingConnection(int handle);

signals:
    void ClientReadData(int clientID,QString IP,int Port,QByteArray data);
    void ClientConnect(int clientID,QString IP,int Port);
    void ClientDisConnect(int clientID,QString IP,int Port);
private slots:
    void ReadData(int clientID,QString IP,int Port,QByteArray data);
    void DisConnect(int clientID,QString IP,int Port);
public slots:
};

#endif // MYTCPSERVER_H
