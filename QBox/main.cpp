#include <QApplication>
#include<QtGui>
#include<QDebug>
 #include <QThread>

//-----------------------------
#include"qboxclient.h"
#include"qboxprotocol.h"
//---------------------------------



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //全部使用UTF-8编码
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    //------------------------------------------------------------------

    //我的客户端
//    QBoxClient *myQBox=new QBoxClient();
//    //登录界面分支结束
//     myQBox->showLogin();
//    //主界面分支结束
//     myQBox->showMainWindow();
    QBoxProtocol pp;
    QString id="12345678912";
    QString MyID;
    QDateTime TT;
    QDateTime t=QDateTime::currentDateTime();
    enum QBOXMESSAGETYPE type=LOGIN;
    quint16 bbb;
    pp.makeHead(type,0,id,t);

    quint16 size;

    pp.openHead(pp.getBlock(),size,bbb,MyID,TT);

    qDebug()<<size<<bbb<<MyID<<TT;



    return a.exec();
}
