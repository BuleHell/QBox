#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include<QByteArray>
//这个是网络模块的主调用类
//这个类主要是处理协议和网络逻辑的调用者
//服务器端的网络协议
class NetWork : public QObject
{
    Q_OBJECT
public:
    explicit NetWork(QObject *parent = 0);
    
signals:
    
public slots:

private:

};

#endif // NETWORK_H
