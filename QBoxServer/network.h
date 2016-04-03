#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include<QByteArray>
#include<QByteArray>
//这个是网络模块的主调用类
//这个类主要是处理协议和网络逻辑的调用者

class NetWork : public QObject
{
    Q_OBJECT
public:
    explicit NetWork(QObject *parent = 0);
    
signals:
    
public slots:

private:
    // 读入流
    QByteArray *blockin;
    //读出流
    QByteArray *blockout;
};

#endif // NETWORK_H
