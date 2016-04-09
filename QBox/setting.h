#ifndef SETTING_H
#define SETTING_H

#include<QObject>
#include<QSettings>
#include<QDateTime>
#include<QFile>
#include<QDebug>
/*
// *Setting *a=Setting::getInstance();
////a->setLastlogin(QDateTime::currentDateTime());
////a->setUsername(QString("Lex"));
////a->setIsremeber(false);
//qDebug()<<a->getUsername();
//delete a;
 *
 *使用时一定要注意：必须delete，否则会造成无法保存文件的现象
 *
 */

class Setting : public QObject
{
    Q_OBJECT
public:
    static Setting* setting;
    static Setting* getInstance()
    {
        if(Setting::setting == NULL)  //判断是否第一次调用
            Setting::setting = new Setting();
        return Setting::setting;
    }
    ~Setting();
private:
    Setting();
    //功能函数------------------------------------------------
    void Load();//把配置加载到内存里
    void Save();//保存
    void Save(QString path);//保存到指定的路径去
    static QString getSettingsDirPath();//设置保存配置的路径名
signals:
    
public slots:


private:
    //加载控制数据数据
    static const QString FILENAME;//加载的名字
    bool loaded;//是否被加载

    //加载的数据/////////////////////////////////////////////////////
    QString username;//用户的名字
    QString userid;//用户的ID
    QDateTime lastlogin;//上次登录时间
    QString userphotopath;// 用户的图片
    bool isremeber;//是否记住密码
    QString pwd;//密码
    QString status;//状态
    //////////////////////////////////////////////////////////////
    //相应的设置加载的函数
public:
    //所有变量的set和get函数
    QString getUsername() const;
    void setUsername(const QString &value);
    QDateTime getLastlogin() const;
    void setLastlogin(const QDateTime &value);
    bool getIsremeber() const;
    void setIsremeber(bool value);
    QString getUserid() const;
    void setUserid(const QString &value);
    QString getUserphotopath() const;
    void setUserphotopath(const QString &value);
    QString getPwd() const;
    void setPwd(const QString &value);
    QString getStatus() const;
    void setStatus(const QString &value);
};

#endif // SETTING_H
