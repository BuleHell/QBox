#include <QApplication>
#include"window.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //全部使用UTF-8编码
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    //------------------------------------------------------------------
    Window win;
    win.show();
    
    return a.exec();
}
