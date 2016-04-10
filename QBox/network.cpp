#include "network.h"
NetWork * NetWork::Mynet=NULL;
NetWork::NetWork(QObject *parent) :
    QObject(parent)
{
    qDebug()<<QObject::tr("客户端的Net构造函数被调用");
}

NetWork::~NetWork()
{
    qDebug()<<QObject::tr("客户端的Net析构函数被调用");
}

void NetWork::initSocket(QString ip,int port)
{
    tcpClient=new QTcpSocket(this);//创建一个套接字
    tcpClient->abort();//取消原有连接
    this->TCPToHost(QHostAddress(ip),port);//测试服务器
    //链接读数据
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(ReadData()));
    //链接错误时的数据
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ReadError(QAbstractSocket::SocketError)));
}

//链接服务器失败
void NetWork::ReadError(QAbstractSocket::SocketError)
{
    tcpClient->disconnectFromHost();//从主机断开链接
    qDebug()<<QObject::tr("连接服务器失败");
    qDebug()<<tcpClient->errorString();
}

QByteArray NetWork::ReadData()
{
    qDebug()<<QString(tcpClient->readAll());
    return tcpClient->readAll();

}

void NetWork::writeData(QByteArray data)
{
    tcpClient->write(data);
}
QHostAddress NetWork::getHostAddress() const
{
    return hostAddress;
}

void NetWork::setHostAddress(const QHostAddress &value)
{
    hostAddress = value;
}
qint16 NetWork::getTcpPort() const
{
    return tcpPort;
}

void NetWork::setTcpPort(const qint16 &value)
{
    tcpPort = value;
}
quint16 NetWork::getBlockSize() const
{
    return blockSize;
}

void NetWork::setBlockSize(const quint16 &value)
{
    blockSize = value;
}

bool NetWork::TCPToHost(QHostAddress hostAddress, qint16 tcpPort)
{
    tcpClient->connectToHost(hostAddress,tcpPort);
    if (tcpClient->waitForConnected(1000))
    {
        qDebug()<<QObject::tr("连接服务器成功");
        return true;
    }
    qDebug()<<QObject::tr("连接服务器失败");
    return false;
}

bool NetWork::TCPoffHost()
{
    tcpClient->disconnectFromHost();
    tcpClient->waitForDisconnected(1000);
    if (tcpClient->state() == QAbstractSocket::UnconnectedState || tcpClient->waitForDisconnected(1000))
    {
        qDebug()<<QObject::tr("断开服务器成功");
        return true;
    }
    qDebug()<<QObject::tr("断开服务器失败");
    return false;
}
QString NetWork::getTcpIP() const
{
    return tcpIP;
}

void NetWork::setTcpIP(const QString &value)
{
    tcpIP = value;
}




