#include <QApplication>
#include<QtGui>
#include<QDebug>
#include <QThread>
#include"qboxclient.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //全部使用UTF-8编码
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    //----------------------------------------------------------------
    //我的客户端
    QBoxClient myQBox;
    //登录界面:一切都从登录开始
    myQBox.showLogin();

    return a.exec();
}
