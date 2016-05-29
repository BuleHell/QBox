#include "dbhelp.h"
DBHelp * DBHelp::Mydb=NULL;

DBHelp::~DBHelp()
{
    qDebug()<<QObject::tr("析构函数被执行");
    db.close();
    qDebug()<<QObject::tr("数据库关闭");

}

DBHelp::DBHelp()
{
    qDebug()<<QObject::tr("构造函数被执行");
    qDebug()<<QObject::tr("请链接并打开数据库");
}

bool DBHelp::LinkDatabase()
{
    QFile file("QBOX.db");
    //文件存在，不必在创建，直接返回就好了
    if(file.exists())
    {
        qDebug()<<QObject::tr("数据库存在不必创建");
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("QBox");
        db.setDatabaseName("QBOX.db");
        db.setUserName("xjt");
        db.setPassword("123456");
        return true;
    }

    //创建数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("QBox");
    db.setDatabaseName("QBOX.db");
    db.setUserName("xjt");
    db.setPassword("123456");
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //创建一个表
    QSqlQuery query;
    //创建用户列表：userList
    //用户好友列表userList：database
    //     userID (*)             ：用户的ID
    //     userName               ：用户的名字
    //     userstatus             ：用户的状态
    //     userPhoto              ：用户的照片
    //     userInfo               ：用户的信息
    //     isFriend               ：是否是朋友
    query.exec("CREATE TABLE IF NOT EXISTS UserList (userID VARCHAR(12) PRIMARY KEY,userName VARCHAR(10), userstatus INTEGER,userPhoto VARCHAR(30),userInfo TEXT,isFriend INTEGER)");
    //创建用户消息表：OwnMessage
    //用户聊天记录OwnMessage:database
    //    ownMessageID
    //    datatime:时间
    //    peer：接受者
    //    message：消息
    // ON DELETE CASCADE ON UPDATE NO ACTION
    query.exec("CREATE TABLE IF NOT EXISTS OwnMessage (ownMessageID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, DataTime TIMESTAMP NOT NULL  DEFAULT (datetime('now','localtime')),message TEXT,peer VARCHAR(12)  REFERENCES userList (userID))");
    //创建群组消息表：groupMessage
    //groupMessageid:
    //groupid:组的ID
    //datatime:时间
    //sender:发送者
    //message：消息
    query.exec("CREATE TABLE IF NOT EXISTS GroupMessage (GroupMessageID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, GroupID VARCHAR(12),DataTime TIMESTAMP NOT NULL DEFAULT (datetime('now','localtime')),message TEXT,sender VARCHAR(12)  REFERENCES userList (userID))");
    return true;
}

bool DBHelp::insert_userList(QString id, QString name, quint8 status, QString photo, QString info, quint8 isfriend)
{

    if (!db.open())
    {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO UserList (userID, userName, userstatus,userPhoto,userInfo,isFriend) VALUES ('%1','%2',%3,'%4','%5',%6)").arg(id).arg(name).arg(status).arg(photo).arg(info).arg(isfriend));
    if( !query.exec() )
    {
        qDebug() <<QObject::tr("用户列表UserList插入失败:")<<query.lastError();
        return false;
    }
    else
    {
        qDebug()<<QObject::tr("用户列表UserList数据插入成功");
        return true;
    }
}

void DBHelp::showUserList()
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return;
    }
    //查询
    QSqlQuery query;
    query.prepare("select * from UserList ");
    if( !query.exec() )
    {
        qDebug() <<QObject::tr("查询UserList失败:")<< query.lastError();
        return;
    }
    else
    {
        qDebug()<<QObject::tr("查询成功");
        while(query.next())
        {
            //            qDebug() <<query.value(0).toString()
            //                    <<query.value(1).toString()
            //            <<query.value(2).toInt()
            //            <<query.value(3).toString()
            //            <<query.value(4).toString()
            //            <<query.value(5).toInt();
            emit SLOT_showUserList(query.value(0).toString(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt());
        }
        return ;
    }


}

void DBHelp::showOwnMessage()
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return ;
    }
    //插入
    QSqlQuery query;
    query.prepare("select * from OwnMessage ");
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("查询失败");
        return ;
    }

    else
    {
        qDebug()<<QObject::tr("查询成功");
        while(query.next())
        {
            //            qDebug()
            //                    <<query.value(1).toDateTime()
            //                   <<query.value(2).toString()
            //                  <<query.value(3).toString();
            emit SLOT_showOwnMessage(query.value(1).toDateTime(),query.value(2).toString(),query.value(3).toString());
        }

        return ;
    }




}

void DBHelp::showGroupMessage()
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return ;
    }
    //插入
    QSqlQuery query;
    query.prepare("select * from GroupMessage");
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("查询失败");
        return ;
    }

    else
    {
        qDebug()<<QObject::tr("查询成功");
        while(query.next())
        {
            //            qDebug()
            //                                       <<query.value(2).toDateTime()
            //                    <<query.value(1).toString()
            //<<query.value(4).toString()
            //                  <<query.value(3).toString()
            //            ;
            emit SLOT_showGroupMessage(query.value(2).toDateTime(),query.value(1).toString(),query.value(4).toString(),query.value(3).toString());
        }

        return ;
    }


}

QString DBHelp::getNamefromID(QString id)
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return "错误";
    }
    QSqlQuery query;
    query.prepare(QString("select userName from UserList where userID='%1'").arg(id));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("查询失败");
        return "错误";
    }

    else
    {
        qDebug()<<QObject::tr("查询成功");
        query.next();
        return query.value(0).toString();
    }
}

bool DBHelp::insert_ownMessage(QString message, QString peer)
{

    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO OwnMessage (message, peer) VALUES ('%1','%2')").arg(message).arg(peer));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("插入成功");
        return true;
    }
}

bool DBHelp::insert_GroupMessage(QString groupid, QString sender, QString message)
{


    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO GroupMessage (GroupID, message,sender) VALUES ('%1','%2','%3')").arg(groupid).arg(message).arg(sender));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("插入成功");
        return true;
    }
}
