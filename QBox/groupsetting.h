#ifndef GROUPSETTING_H
#define GROUPSETTING_H

#include <QObject>
#include <QtXml>
/**
 * @brief The GroupSetting class 不用显式delete，只需要用即可，因为本文件是用时打开，不用就马上关闭的
 *一个文件
 */
class GroupSetting : public QObject
{
    Q_OBJECT
public:
    static GroupSetting* MyXML;
    static GroupSetting* getInstance()
    {
        if(GroupSetting::MyXML == NULL)  //判断是否第一次调用
            GroupSetting::MyXML = new GroupSetting();
        return GroupSetting::MyXML;
    }
    ~GroupSetting();
private:
    GroupSetting();
public:
    bool createXML();
signals:
    void SLOT_GroupInfo(QString groupID, QString name,QString info,QString admin,QMap<QString,QString> userList);
public slots:
    //读XML文件
    bool docRead();
    //写XML文档
    bool docWrite();
    //读取全部信息
    void showGroupList();
    //读取对应的信息
    void showGroup(QString groupID);
    //加入一个信息
    //    groupID  info  admin userlist
    //在Updata里，只要有userList的成员只有他自己，即userList就是admin的时候就删掉
    bool update(QString groupID, QString name, QString info,  QString admin, QMap<QString, QString> userList);
    //删除一个信息
    bool del(QString groupID);
private:
    //创造一个节点出来
    QDomElement createNODE(QString groupID, QString name, QString info,  QString admin, QMap<QString, QString> userList);
private:
    QDomDocument doc;//读取的成员
};

#endif // GROUPSETTING_H
