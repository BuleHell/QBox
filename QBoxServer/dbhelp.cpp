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
    QFile file("QBOXServer.db");
    //文件存在，不必在创建，直接返回就好了
    if(file.exists())
    {
        qDebug()<<QObject::tr("数据库存在不必创建");
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("QBox");
        db.setDatabaseName("QBOXServer.db");
        db.setUserName("xjt");
        db.setPassword("123456");
        return true;
    }

    //创建数据库
    qDebug()<<QObject::tr("数据库开始创建");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("QBox");
    db.setDatabaseName("QBOXServer.db");
    db.setUserName("xjt");
    db.setPassword("123456");
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //创建一个表
    QSqlQuery query;
    //    用户表 userList
    //           user_ID(*):用户的ID
    //           user_name:用户的名字
    //           user_age:用户的年龄
    //           user_sex:用户的性别
    //           user_pwd:用户的密码
    //           user_phone:用户的电话
    //           user_email:用户的电子邮箱
    //           user_job:工作的职责                ""
    //           user_departmentID:用户所在部门的ID号""
    //           user_join:用户加入的时间
    //           user_photo:用户的图片              ""
    //           user_signature: 用户的签名         ""
    //           user_satus: 用户的现在状态          ""
    //           userInfo:备注                      ""
    //           user_lastloginID:上次操作登录的时间      ""
    query.exec("CREATE TABLE IF NOT EXISTS UserList (userID VARCHAR(12) PRIMARY KEY,userName VARCHAR(10),userAge INTEGER,userSex VARCHAR(2),userPwd VARCHAR(12),userPhone VARCHAR(12),userEmail VARCHAR(80),userJob VARCHAR(15) NOT NULL DEFAULT '',userdepartmentID VARCHAR(12) NOT NULL DEFAULT '',userJoin TIMESTAMP NOT NULL DEFAULT (datetime('now','localtime')),userPhoto VARCHAR(12) NOT NULL DEFAULT '',userSignature TEXT NOT NULL DEFAULT '',userStatus INTEGER NOT NULL DEFAULT '0',userInfo TEXT NOT NULL DEFAULT '',userLastLoginID INTEGER NOT NULL DEFAULT '' REFERENCES LOG(logID))");
    //--------------------------------------------------------
    //    公司部门 department
    //            departemnt_ID(*)   :     部门的ID
    //            departemnt_name :     部门的名字
    //            departemnt_job  ：    部门的职责
    //            departemnt_charge：   部门负责人的ID
    //            departemnt_info：     部门的详细描述
    //            departemnt_create:    部门成立
    query.exec("CREATE TABLE IF NOT EXISTS Department (departemntID VARCHAR(20) NOT NULL PRIMARY KEY,departemntName VARCHAR(20),departemntJob TEXT,departemntCharge VARCHAR(12) REFERENCES UserList (userID),departemntInfo TEXT,departemntCreate DataTime TIMESTAMP NOT NULL DEFAULT (datetime('now','localtime')))");
    //--------------------------------------------------------
    //    聊天群组详细表：chatgroupinfo
    //                   chatgroup_ID(*):聊天群组的ID
    //                   chatgroup_Admin:群主（发起人）
    //                   chatgroup_name:群组名字
    //                   chatgroup_info:群组的备注
    //                   chatgroup_num:群组的人员数量
    query.exec("CREATE TABLE IF NOT EXISTS ChatGroupInfo (chatgroupID VARCHAR(12) NOT NULL PRIMARY KEY,chatgroupAdmin VARCHAR(12) NOT NULL REFERENCES UserList(userID),chatgroupName VARCHAR(50) NOT NULL,chatgroupInfo TEXT,chatgroupNum INTEGER  NOT NULL)");
    //--------------------------------------------------------
    //    聊天群组表：chatgroup
    //                chatgroup_ID(#)
    //                user_ID    (#)
    query.exec("CREATE TABLE IF NOT EXISTS ChatGroup (chatgroupID VARCHAR(12) NOT NULL REFERENCES ChatGroupInfo (chatgroupID),userID VARCHAR(12) NOT NULL REFERENCES UserList(userID))");
    //--------------------------------------------------------
    //    日志表  Log
    //            Log_ID
    //            user_ID
    //            user_status
    //            time
    query.exec("CREATE TABLE IF NOT EXISTS LOG(logID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,userID VARCHAR(12) NOT NULL REFERENCES UserList(userID),userStatus INTEGER NOT NULL REFERENCES UserList(userStatus),DataTime TIMESTAMP NOT NULL DEFAULT (datetime('now','localtime')))");
    //--------------------------------------------------------
    //消息监控表 Watch
    //            Watch_id
    //            sender_id
    //            receiver_id
    //            time
    //            msg
    query.exec("CREATE TABLE IF NOT EXISTS Watch(watchID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,senderID VARCHAR(12) NOT NULL REFERENCES UserList(userID),receiverID VARCHAR(12) NOT NULL REFERENCES UserList(userID),DataTime TIMESTAMP NOT NULL  DEFAULT (datetime('now','localtime')),message TEXT)");
    //--------------------------------------------------------
    //群组监控表 watchGroup
    //            watchgroup_id
    //            sender_id
    //            group_id
    //            time
    //            msg
    query.exec("CREATE TABLE IF NOT EXISTS WatchGroup(watchgroupID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,senderID VARCHAR(12) NOT NULL REFERENCES UserList(userID),groupID VARCHAR(12) NOT NULL REFERENCES ChatGroupInfo(chatgroupID),DataTime TIMESTAMP NOT NULL  DEFAULT (datetime('now','localtime')),message TEXT)");
    qDebug()<<QObject::tr("数据库和表创建完毕");
    return true;
}
//插入一个新的用户
bool DBHelp::insertUser(QString id, QString name, quint8 age, QString sex, QString pwd, QString phone, QString email)
{
    if (!db.open())
    {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO UserList (userID ,userName,userAge ,userSex ,userPwd,userPhone,userEmail) VALUES ('%1','%2',%3,'%4','%5','%6','%7')")
                  .arg(id)
                  .arg(name)
                  .arg(age)
                  .arg(sex)
                  .arg(pwd)
                  .arg(phone)
                  .arg(email));
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
                /*emit SLOT_showUserList(query.value(0).toString(),query.value(1).toString(),query.value(2).toInt(),query.value(3).toString(),query.value(4).toString(),query.value(5).toInt());*/
            }
            return ;
        }


}

QString DBHelp::FindID(QString name)
{
    QString ID;
    if (!db.open())
    {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return "DB ERROR";
    }
    //查询
    QSqlQuery query;
    query.prepare(QString("select UserID from UserList where UserName='%1'").arg(name));
    if( !query.exec() )
    {
        qDebug() <<QObject::tr("查询UserList失败:")<< query.lastError();
        return "query ERROR";
    }
    else
    {
        qDebug()<<QObject::tr("查询成功");
        query.next();
        ID=query.value(0).toString();
        qDebug() <<ID;
        return ID;
    }

}

bool DBHelp::pwdisRight(QString name, QString passwd)
{
     QString pwd;
    if (!db.open())
    {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return "DB ERROR";
    }
    //查询
    QSqlQuery query;
    query.prepare(QString("select userPwd from UserList where UserName='%1'").arg(name));
    if( !query.exec() )
    {
        qDebug() <<QObject::tr("查询UserList失败:")<< query.lastError();
        return "query ERROR";
    }
    else
    {
        qDebug()<<QObject::tr("查询成功");
        query.next();
        pwd=query.value(0).toString();
        qDebug() <<pwd;
        return pwd==passwd;
    }
}

void DBHelp::showUser(QString id, QString name)
{

}

void DBHelp::showDepartment()
{

}

//void DBHelp::showOwnMessage()
//{
//    if (!db.open()) {
//        //提示出错
//        qDebug()<<QObject::tr("数据库无法打开!");
//        return ;
//    }
//    //插入
//    QSqlQuery query;
//    query.prepare("select * from OwnMessage ");
//    if( !query.exec() )
//    {
//        qDebug() << query.lastError();
//        qDebug()<<QObject::tr("查询失败");
//        return ;
//    }

//    else
//    {
//        qDebug()<<QObject::tr("查询成功");
//        while(query.next())
//        {
//            //            qDebug()
//            //                    <<query.value(1).toDateTime()
//            //                   <<query.value(2).toString()
//            //                  <<query.value(3).toString();
//            emit SLOT_showOwnMessage(query.value(1).toDateTime(),query.value(2).toString(),query.value(3).toString());
//        }

//        return ;
//    }




//}

//void DBHelp::showGroupMessage()
//{
//    if (!db.open()) {
//        //提示出错
//        qDebug()<<QObject::tr("数据库无法打开!");
//        return ;
//    }
//    //插入
//    QSqlQuery query;
//    query.prepare("select * from GroupMessage");
//    if( !query.exec() )
//    {
//        qDebug() << query.lastError();
//        qDebug()<<QObject::tr("查询失败");
//        return ;
//    }

//    else
//    {
//        qDebug()<<QObject::tr("查询成功");
//        while(query.next())
//        {
//            //            qDebug()
//            //                                       <<query.value(2).toDateTime()
//            //                    <<query.value(1).toString()
//            //<<query.value(4).toString()
//            //                  <<query.value(3).toString()
//            //            ;
//            emit SLOT_showGroupMessage(query.value(2).toDateTime(),query.value(1).toString(),query.value(4).toString(),query.value(3).toString());
//        }

//        return ;
//    }


//}

bool DBHelp::insertDepartment(QString id, QString name,QString job,QString charge,QString info)
{

    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO Department (departemntID,departemntName ,departemntJob,departemntCharge,departemntInfo) VALUES ('%1','%2','%3','%4','%5')")
                  .arg(id)
                  .arg(name)
                  .arg(job)
                  .arg(charge)
                  .arg(info));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("Department插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("Department插入成功");
        return true;
    }
}

bool DBHelp::insertGroupInfo(QString id, QString admin, QString name,QString info,int num)
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO ChatGroupInfo (chatgroupID,chatgroupAdmin,chatgroupName,chatgroupInfo,chatgroupNum) VALUES ('%1','%2','%3','%4',%5)")
                  .arg(id)
                  .arg(admin)
                  .arg(name)
                  .arg(info)
                  .arg(num));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("ChatGroupInfo插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("ChatGroupInfo插入成功");
        return true;
    }
}

bool DBHelp::insertChatGroup(QString groupid, QString userid)
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO ChatGroup (chatgroupID,userID) VALUES ('%1','%2')")
                  .arg(groupid)
                  .arg(userid));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("ChatGroup插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("ChatGroup插入成功");
        return true;
    }
}

bool DBHelp::insretLOG(QString userid, int status)
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }
    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO LOG (userID, userStatus) VALUES ('%1',%2)")
                  .arg(userid)
                  .arg(status));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("LOG插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("LOG插入成功");
        return true;
    }
}

bool DBHelp::insertWatch(QString userid, QString receiverid, QString message)
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }

    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO Watch(senderID,receiverID ,message) VALUES ('%1','%2','%3')")
                  .arg(userid)
                  .arg(receiverid)
                  .arg(message));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("Watch插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("Watch插入成功");
        return true;
    }
}

bool DBHelp::insertwatchGroup(QString senderid, QString groupid, QString message)
{
    if (!db.open()) {
        //提示出错
        qDebug()<<QObject::tr("数据库无法打开!");
        return false;
    }

    //插入
    QSqlQuery query;
    query.prepare(QString("INSERT INTO WatchGroup(senderID,groupID,message) VALUES ('%1','%2','%3')")
                  .arg(senderid)
                  .arg(groupid)
                  .arg(message));
    if( !query.exec() )
    {
        qDebug() << query.lastError();
        qDebug()<<QObject::tr("watchGroup插入失败");
        return false;
    }

    else
    {
        qDebug()<<QObject::tr("watchGroup插入成功");
        return true;
    }
}
