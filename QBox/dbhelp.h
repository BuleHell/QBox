#ifndef DBHELP_H
#define DBHELP_H

#include <QObject>
#include <QtSql>
#include <QDebug>
#include<QDateTime>
//这个类最主要是进行一些相应的数据库操作的东西
//直接就可以调用语句
class DBHelp : public QObject
{
    Q_OBJECT
public:
    static DBHelp* Mydb;
    static DBHelp* getInstance()
    {
        if(DBHelp::Mydb == NULL)  //判断是否第一次调用
            DBHelp::Mydb = new DBHelp();
        return DBHelp::Mydb;
    }
    ~DBHelp();

private:
    DBHelp();

public:
    //创建数据库并链接数据库（必须执行）
    bool LinkDatabase();

signals:
    //发送查询的数据
    void SLOT_showUserList(QString id, QString name, quint8 status, QString photo, QString info, quint8 isfriend);
    void SLOT_showOwnMessage(QDateTime time, QString message,QString peer);
    void SLOT_showGroupMessage(QDateTime time,QString groupid,QString sender, QString message);
    
public slots:
    //插入一条用户列表的数据
    bool  insert_userList(QString id,QString name,quint8 status,QString photo,QString info,quint8 isfriend);
    //插入一条我自己的消息记录
    bool  insert_ownMessage(QString message,QString peer);
    //插入一条群消息记录
    bool  insert_GroupMessage(QString groupid,QString sender,QString message);
    // 查询数据-->查询结果用信号返回
    void showUserList();
    void showOwnMessage();
    void showGroupMessage();
    //更新用户列表

    //删除用户列表

private:
    QSqlDatabase db;

};

#endif // DBHELP_H
