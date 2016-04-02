#include "groupsetting.h"
GroupSetting * GroupSetting::MyXML=NULL;
GroupSetting::~GroupSetting()
{
    qDebug()<<QObject::tr("析构函数被执行");
}

GroupSetting::GroupSetting()
{
    qDebug()<<QObject::tr("构造函数被执行");
}

bool GroupSetting::createXML()
{
    QFile file("group.xml");
    //文件存在，不必在创建，直接返回就好了
    if(file.exists())
    {
        qDebug()<<QObject::tr("xml存在不必创建");
        return true;
    }
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;
    //       QDomDocument doc;
    //加个文件的头
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(QString("groupconfig"));
    doc.appendChild(root);
    //    QDomText text=doc.createTextNode("");
    //    root.appendChild(text);
    QTextStream out(&file);
    doc.save(out,4);
    qDebug()<<QObject::tr("xml创建成功");
    file.close();
    return true;
}

bool GroupSetting::docRead()
{
    QFile file("group.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<QObject::tr("文件打开失败");
        return false;
    }
    qDebug()<<QObject::tr("文件打开");
    if(!doc.setContent(&file))
    {
        qDebug()<<QObject::tr("无法得到内容，错误返回");
        file.close();
        return false;
    }
    file.close();
    qDebug()<<QObject::tr("得到内容，正确返回");
    return true;
}

bool GroupSetting::docWrite()
{
    QFile file("group.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug()<<QObject::tr("文件打开失败");
        return false;
    }

    QTextStream out(&file);
    doc.save(out,4);
    file.close();
    qDebug()<<QObject::tr("文件关闭");
    return true;
}

void GroupSetting::showGroupList()
{
    if (docRead())
    {
        QDomElement root = doc.documentElement();
        if(root.isNull())
        {
            qDebug()<<QObject::tr("空表");
        }
        QDomNodeList group = doc.elementsByTagName("group");
        for(int i=0;i<group.size();i++)
        {
            QDomElement ele = group.at(i).toElement();
            //------------------------------------------------------------------------
          //  qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
            QString _groupID;
            QString _name;
            QString _info;
            QString _admin;
            QMap<QString,QString> _userList;
            //---------------------------------------
            //获得值并赋值给上诉的值，然后发射出去
         //   qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
            _groupID=ele.attribute("id");
            //获得值并赋值给上诉的值，然后发射出去
            QDomNode node=ele.firstChild();
            while(!node.isNull())
            {
                if (node.toElement().tagName() == "name") //匹配note节点
                {

                    _name=node.toElement().firstChild().toText().data();
                }else if(node.toElement().tagName() == "info")
                {
                    _info=node.toElement().firstChild().toText().data();
                }else if(node.toElement().tagName() == "admin")
                {
                    _admin=node.toElement().firstChild().toText().data();

                }else if(node.toElement().tagName() == "user")
                {
                    QString key=node.toElement().attribute("id");
                    QString value=node.toElement().firstChild().toText().data();
                    _userList[key]=value;
                }
                node = node.nextSibling(); //读取下一个子节点
            }
            qDebug()<<"groupID"<<_groupID<<"name:"<<_name<<"info"<<_info<<"admin"<<_admin<<"userlist"<<_userList;


            //----------------------------------------
            emit SLOT_GroupInfo(_groupID,_name,_info,_admin,_userList);
            //----------------------------------------

        }
        //写入文件
        docWrite();
    }
}
//查找到群主号为 groupID的那个群
void GroupSetting::showGroup(QString groupID)
{
    if (docRead())
    {
        QDomElement root = doc.documentElement();
        if(root.isNull())
        {
            qDebug()<<QObject::tr("空表");
        }
        QDomNodeList group = doc.elementsByTagName("group");
        for(int i=0;i<group.size();i++)
        {
            QDomElement ele = group.at(i).toElement();
            //  qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
            if(ele.attribute("id")==groupID)
            {
            //    qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
                QString _groupID=groupID;
                QString _name;
                QString _info;
                QString _admin;
                QMap<QString,QString> _userList;
                //---------------------------------------
                //获得值并赋值给上诉的值，然后发射出去
                QDomNode node=ele.firstChild();
                while(!node.isNull())
                {
                    if (node.toElement().tagName() == "name") //匹配note节点
                    {

                        _name=node.toElement().firstChild().toText().data();
                    }else if(node.toElement().tagName() == "info")
                    {
                        _info=node.toElement().firstChild().toText().data();
                    }else if(node.toElement().tagName() == "admin")
                    {
                        _admin=node.toElement().firstChild().toText().data();

                    }else if(node.toElement().tagName() == "user")
                    {
                        QString key=node.toElement().attribute("id");
                        QString value=node.toElement().firstChild().toText().data();
                        _userList[key]=value;
                    }
                    node = node.nextSibling(); //读取下一个子节点
                }
                qDebug()<<"groupID"<<_groupID<<"name:"<<_name<<"info"<<_info<<"admin"<<_admin<<"userlist"<<_userList;

                //----------------------------------------
                emit SLOT_GroupInfo(_groupID,_name,_info,_admin,_userList);
                break;
            }
        }
        //写入文件
        docWrite();
    }

}

//更新数据
bool GroupSetting::update(QString groupID,QString name, QString info, QString admin, QMap<QString,QString>userList)
{
    // 先从文件读取
    if (docRead())
    {
        QDomElement root = doc.documentElement();
        //根节点空:创建一个根节点
        if(root.isNull())
        {
            qDebug()<<"root is null";
            QDomElement root = doc.createElement("groupconfig");
            qDebug()<<qPrintable(root.tagName());
        }
        //--------------------------------------------------------------
        //根节点有没有孩子：直接加入
        if(root.firstChild().isNull())
        {
            qDebug()<<QObject::tr("根节点没有孩子");
            //------------------------------------------------------------------
            root.appendChild(this->createNODE(groupID, name, info, admin,userList));
            //写入文件
            docWrite();
            return true;
        }
        else
        {
            qDebug()<<QObject::tr("根节点有孩子");
            bool isIN=false;
            int atChild=-1;
            QDomNodeList group = doc.elementsByTagName("group");
            for(int i=0;i<group.size();i++)
            {
                QDomElement ele = group.at(i).toElement();
                qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
                if(ele.attribute("id")==groupID)
                {
                    atChild=i;
                    isIN=true;

                    qDebug()<<QObject::tr("移除");
                    qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
                    root.removeChild(group.at(i));
                    break;
                }
            }
            //这个GROUP_ID原本就有：删掉
            //这个GROUP_ID原本没有：加入
            root.appendChild(this->createNODE(groupID, name, info, admin,userList));
            //写入文件
            docWrite();
            return true;
        }
        return false;
    }
}
//删除数据（userList==admin）时自动删除
bool GroupSetting::del(QString groupID)
{

    if (docRead())
    {
        QDomElement root = doc.documentElement();
        if(root.isNull())
        {
            qDebug()<<QObject::tr("根节点没有孩子,无法删除");
        }
        QDomNodeList group = doc.elementsByTagName("group");
        for(int i=0;i<group.size();i++)
        {
            QDomElement ele = group.at(i).toElement();
            //  qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
            if(ele.attribute("id")==groupID)
            {
                qDebug()<<qPrintable(ele.tagName())<<qPrintable(ele.attribute("id"));
                root.removeChild(group.at(i));
                break;
            }
        }
        //写入文件
        docWrite();
    }



}

QDomElement GroupSetting::createNODE(QString groupID, QString name, QString info, QString admin, QMap<QString, QString> userList)
{
    //------------------------------------------------------------------
    //材料元素
    QDomElement ele_root=doc.createElement(QObject::tr("group"));
    QDomAttr attr_id=doc.createAttribute(QObject::tr("id"));
    QDomElement ele_name=doc.createElement(QObject::tr("name"));
    QDomElement ele_info=doc.createElement(QObject::tr("info"));
    QDomAttr admin_attr_id=doc.createAttribute(QObject::tr("id"));
    QDomElement ele_admin=doc.createElement(QObject::tr("admin"));

    //组装
    attr_id.setValue(groupID);
    ele_root.setAttributeNode(attr_id);
    QDomText text;
    text =doc.createTextNode(name);
    ele_name.appendChild(text);
    ele_root.appendChild(ele_name);
    //----------------------------
    text =doc.createTextNode(info);
    ele_info.appendChild(text);
    ele_root.appendChild(ele_info);
    //----------------------------
    text.clear();
    //----------------------------
    admin_attr_id.setValue(admin);
    ele_admin.setAttributeNode(admin_attr_id);
    ele_root.appendChild(ele_admin);


    //----------------------------------------
    QMapIterator<QString, QString> i(userList);
    while (i.hasNext()) {
        i.next();
        QDomAttr id=doc.createAttribute(QObject::tr("id"));
        QDomText name;
        QDomElement ele_user=doc.createElement(QObject::tr("user"));
        name =doc.createTextNode(i.value());
        id.setValue(i.key());
        ele_user.setAttributeNode(id);
        ele_user.appendChild(name);
        ele_root.appendChild(ele_user);
    }
    return ele_root;
}
