#include "mytcpserver.h"



myTcpServer::myTcpServer(QObject *parent) :
    QTcpServer(parent)
{
}
//到来的链接
void myTcpServer::incomingConnection(int handle)
{
    //对到来的客户端链接，设置一个描述符ID
    myClientSocket *client=new myClientSocket(this,handle);
    client->setSocketDescriptor(handle);

    connect(client,SIGNAL(ClientReadData(int,QString,int,QByteArray)),this,SLOT(ReadData(int,QString,int,QByteArray)));
    connect(client,SIGNAL(ClientDisConnect(int,QString,int)),this,SLOT(DisConnect(int,QString,int)));

    emit ClientConnect(handle, client->peerAddress().toString(),client->peerPort());

    ClientSocketList.append(client);//将新的连接添加到列表
    ClientSocketID.append(handle);//每个链接的ID添加到列表
}

void myTcpServer::ReadData(int clientID,QString IP,int Port,QByteArray data)
{
    emit ClientReadData(clientID,IP,Port,data);
}

void myTcpServer::DisConnect(int clientID,QString IP,int Port)
{
    for (int i=0;i<ClientSocketID.count();i++)
    {
        if (ClientSocketID[i]==clientID)
        {
            ClientSocketList.removeAt(i);//从列表中移除该连接
            emit ClientDisConnect(clientID,IP,Port);
            break;
        }
    }
}

//指定客户端连接发消息
void myTcpServer::SendData(int clientID,QString IP,int Port,QByteArray data)
{
    for (int i=0;i<ClientSocketID.count();i++)
    {
        if (ClientSocketID[i]==clientID)
        {
            ClientSocketList[i]->write(data);
            break;
        }
    }
}
