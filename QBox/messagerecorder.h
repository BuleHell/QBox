#ifndef MESSAGERECORDER_H
#define MESSAGERECORDER_H
#include <QObject>
/**
 * @brief The MessageRecorder class
 *本类是一个单例，而且必须显式的delete，否则会造成不能写入的情况
 *尽量把它做成一个工具类
 */
class MessageRecorder : public QObject
{    
    Q_OBJECT
public:
    //  explicit MessageRecorder(QObject *parent = 0);
    //加载文件


    //解析文件（给键得值）

    //加入文件（主要是添加append）



    //添加


    //创建新的文件（每一天一个文件）

    
public:
//    QDomDocument doc;//文件的
signals:
    
public slots:
    
};   
#endif // MESSAGERECORDER_H
