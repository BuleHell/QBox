#include <QApplication>
#include<QtGui>
#include<QDebug>
#include"qboxclient.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //全部使用UTF-8编码
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    //------------------------------------------------------------------

    //
    QBoxClient *myQBox=new QBoxClient();
    myQBox->showLogin();

    return a.exec();
}
