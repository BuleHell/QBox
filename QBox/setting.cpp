#include "setting.h"

//设置文件名
const QString Setting::FILENAME = "settings.ini";
Setting * Setting::setting=NULL;

//析构之前，先保存
Setting::~Setting()
{
    qDebug()<<"setting析构函数";
    Save();

}
//构造之前，先加载
Setting::Setting():
    loaded(false),username(""),lastlogin(QDateTime::currentDateTime()),userid(""),userphotopath(""),isremeber(false),pwd(""),status("")
{
    Load();
}
//加载函数
void Setting::Load()
{
    if (loaded) {
        return;
    }

    //    QFile portableSettings(FILENAME);
    //    if (portableSettings.exists())
    //        makeToxPortable=true;

    QString filePath = getSettingsDirPath() + '/' + FILENAME;

    //如果文件不存在，就使用默认的配置
    QFile file(filePath);
    if (!file.exists()) {
        qDebug() <<QObject::tr("配置文件不存在，使用默认的配置");
        qDebug()<<QObject::tr("------------默认配置--------------");
        return;
    }

    QSettings s(filePath, QSettings::IniFormat);
    //保存组1-------------------------------------------------
    s.beginGroup("user");
  //  qDebug() <<filePath;
    this->username=s.value("username").toString();
    this->userid=s.value("userid").toString();
    this->lastlogin=s.value("LastLogin").toDateTime();
    this->isremeber=s.value("isremeber").toBool();
    this->userphotopath=s.value("userphotopath").toString();
    this->pwd=s.value("pwd").toString();
    this->status=s.value("status").toString();
//    qDebug() <<QObject::tr("Load完毕");
    s.endGroup();
    //    //保存组2-------------------------------------------------
    //    s.beginGroup("General");

    //    s.endGroup();
    //    //保存组3-------------------------------------------------
    //    s.beginGroup("Widgets");

    //    s.endGroup();
    //    //保存组4-------------------------------------------------
    //    s.beginGroup("GUI");

    //    s.endGroup();
    //    //保存组5-------------------------------------------------
    //    s.beginGroup("Privacy");
    //    s.endGroup();
    //-------------------------------------------------
    loaded = true;
}
//保存函数1
void Setting::Save()
{
    qDebug()<<"SAVE";
    QString filePath = getSettingsDirPath() + '/' + FILENAME;
    Save(filePath);
}
//保存函数2
void Setting::Save(QString path)
{
    QSettings s(path, QSettings::IniFormat);
  //  qDebug()<<QObject::tr("保存在：")<<path;
    s.clear();

    //保存组1-------------------------------------------------
    s.beginGroup("user");
    s.setValue("username", this->username);
    s.setValue("userid",this->userid);
    s.setValue("LastLogin",this->lastlogin);
    s.setValue("isremeber",this->isremeber);
    s.setValue("userphotopath",this->userphotopath);
    s.setValue("pwd",this->pwd);
    s.setValue("status",this->status);
    s.endGroup();
    //    //保存组2-------------------------------------------------
    //    s.beginGroup("General");

    //    s.endGroup();
    //    //保存组3-------------------------------------------------
    //    s.beginGroup("Widgets");

    //    s.endGroup();
    //    //保存组4-------------------------------------------------
    //    s.beginGroup("GUI");

    //    s.endGroup();
    //    //保存组5-------------------------------------------------
    //    s.beginGroup("Privacy");
    //    s.endGroup();
    //-------------------------------------------------
}
//获得保存的目录
QString Setting::getSettingsDirPath()
{
    if (true)
        return ".";
    //多系统平台
    //#ifdef Q_OS_WIN
    //    return QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    //#else
    //    return QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + '/' + "QBox" + '/';
    //#endif
}
QString Setting::getStatus() const
{
    return status;
}

void Setting::setStatus(const QString &value)
{
    status = value;
}

QString Setting::getPwd() const
{
    return pwd;
}

void Setting::setPwd(const QString &value)
{
    pwd = value;
}

QString Setting::getUserphotopath() const
{
    return userphotopath;
}

void Setting::setUserphotopath(const QString &value)
{
    userphotopath = value;
}

QString Setting::getUserid() const
{
    return userid;
}

void Setting::setUserid(const QString &value)
{
    userid = value;
}

bool Setting::getIsremeber() const
{
    return isremeber;
}

void Setting::setIsremeber(bool value)
{
    isremeber = value;
}

QDateTime Setting::getLastlogin() const
{
    return lastlogin;
}

void Setting::setLastlogin(const QDateTime &value)
{
    lastlogin = value;
}

QString Setting::getUsername() const
{
    return username;
}

void Setting::setUsername(const QString &value)
{
    username = value;
}


