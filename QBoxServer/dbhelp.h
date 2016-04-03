#ifndef DBHELP_H
#define DBHELP_H

#include <QObject>
#include <QDebug>
#include<QDateTime>
#include <QtSql>
//这个类最主要是进行一些相应的数据库操作的东西
//直接就可以调用语句：请delete掉相关的语句
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
    bool insertUser(QString id, QString name, quint8 age, QString sex, QString pwd, QString phone, QString email);
    //插入一个新的部门
    bool  insertDepartment(QString id, QString name, QString job, QString charge, QString info);
    //插入一个群组建立的消息
    bool  insertGroupInfo(QString id, QString admin, QString name,QString info,int num);
    //插入一个群组的加入用户消息
    bool  insertChatGroup(QString groupid,QString userid);
    //插入一条日志
    bool insretLOG(QString userid,int status);
    //插入一条聊天监控
    bool insertWatch(QString userid,QString receiverid,QString message);
    //插入一条裙聊天监控
    bool insertwatchGroup(QString senderid, QString groupid, QString message);
    // 查询数据-->查询结果用信号返回
    //查询所有的用户
    void showUserList();
    //查询某个用户
    void showUser(QString id,QString name);
    //查询所有的部门
    void showDepartment();
    //更新用户列表

    //删除用户列表

private:
    QSqlDatabase db;

};

#endif // DBHELP_H
