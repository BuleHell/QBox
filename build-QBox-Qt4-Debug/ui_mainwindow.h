/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *titleBar;
    QPushButton *btnClose;
    QPushButton *btnMin;
    QLabel *labelLogo;
    QPushButton *btnClock;
    QWidget *centrePanel;
    QWidget *widgetLeft;
    QWidget *widgetMystatus;
    QLabel *labelPic;
    QLabel *labelName;
    QLabel *labelstatus;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widgetTool;
    QPushButton *btnAdd;
    QPushButton *btnGroup;
    QPushButton *btnSeting;
    QPushButton *btnFTP;
    QWidget *widgetTalk;
    QTextBrowser *textBrowser;
    QWidget *widgetYou;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widgetSend;
    QToolButton *toolButton;
    QTextEdit *textEdit;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QPushButton *pushButton_3;
    QToolButton *toolButton_5;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(639, 450);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("/*\345\205\250\345\261\200\350\256\276\347\275\256*/\n"
"* {	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; font-size: 15px;}\n"
"\n"
"/*\346\234\200\344\270\212\350\276\271\347\232\204Logo\345\233\276\346\240\207*/\n"
"QLabel#labelLogo {\n"
"	background: #569082;\n"
"	outline:none;\n"
"	color:#333;\n"
"}\n"
"\n"
"/*\351\224\201\345\256\232\346\214\211\351\222\256*/\n"
"QPushButton#btnClock {\n"
"	background: transparent;\n"
"	border: none;\n"
"	color: #ffffff;\n"
"	font-size: 18px;\n"
"}\n"
"QPushButton#btnClock:hover {\n"
"	background: #569000;\n"
"}\n"
"QPushButton#btnClock:pressed {\n"
"	background: #569040;\n"
"}\n"
"\n"
"/*\345\205\263\351\227\255\346\214\211\351\222\256*/\n"
"QPushButton#btnClose {\n"
"	background: transparent;\n"
"	border: none;\n"
"	color: #ffffff;\n"
"	font-size: 18px;\n"
"}\n"
"QPushButton#btnClose:hover {\n"
"	background: red;\n"
"}\n"
"\n"
"/*\346\234\200\345\260\217\345\214\226\346\214\211\351\222\256*/\n"
"QPushButton#btnMin {\n"
"	background: transparent;\n"
""
                        "	border: none;\n"
"	color: #ffffff;\n"
"	font-size: 18px;\n"
"}\n"
"QPushButton#btnMin:hover {\n"
"	background: #569000;\n"
"}\n"
"QPushButton#btnMin:pressed {\n"
"	background: #569040;\n"
"}\n"
"\n"
"/*\345\206\205\345\256\271*/\n"
"QWidget#centrePanel{\n"
"	border: 2px solid ;\n"
"	background:rgb(0, 74, 80);\n"
"}\n"
"\n"
"/*\346\210\221\347\232\204\347\212\266\346\200\201\346\240\217*/\n"
"QWidget#widgetMystatus{\n"
"	border: 2px solid ;\n"
"	background:rgb(74, 74, 80);\n"
"}\n"
"\n"
"/*\345\210\227\350\241\250\346\240\217\347\233\256*/\n"
"\n"
"\n"
"/*\345\267\246\344\270\213\347\232\204\345\267\245\345\205\267\346\240\217*/\n"
"QWidget#widgetTool{\n"
"\n"
"	border: 2px solid ;\n"
"	background:rgb(74, 60, 80);\n"
"\n"
"}\n"
"\n"
"\n"
"/*\346\211\213\350\204\232\346\236\266*/\n"
"QWidget#centralWidget{\n"
"	border: 2px solid ;\n"
"}\n"
"QWidget#centrePanel{\n"
"	border: 2px solid ;\n"
"}\n"
"QWidget#widgetMystatus{\n"
"	border: 2px solid ;\n"
"}\n"
""));
        titleBar = new QWidget(centralWidget);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        titleBar->setGeometry(QRect(0, 0, 640, 25));
        btnClose = new QPushButton(titleBar);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(620, 0, 21, 21));
        btnMin = new QPushButton(titleBar);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setGeometry(QRect(600, 0, 21, 21));
        labelLogo = new QLabel(titleBar);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setGeometry(QRect(0, 0, 640, 21));
        labelLogo->setAlignment(Qt::AlignCenter);
        btnClock = new QPushButton(titleBar);
        btnClock->setObjectName(QString::fromUtf8("btnClock"));
        btnClock->setGeometry(QRect(0, 0, 21, 21));
        labelLogo->raise();
        btnClock->raise();
        btnClose->raise();
        btnMin->raise();
        centrePanel = new QWidget(centralWidget);
        centrePanel->setObjectName(QString::fromUtf8("centrePanel"));
        centrePanel->setGeometry(QRect(0, 20, 641, 451));
        widgetLeft = new QWidget(centrePanel);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        widgetLeft->setGeometry(QRect(0, 2, 241, 431));
        widgetMystatus = new QWidget(widgetLeft);
        widgetMystatus->setObjectName(QString::fromUtf8("widgetMystatus"));
        widgetMystatus->setGeometry(QRect(-9, -6, 251, 71));
        labelPic = new QLabel(widgetMystatus);
        labelPic->setObjectName(QString::fromUtf8("labelPic"));
        labelPic->setGeometry(QRect(16, 16, 31, 41));
        labelPic->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/mianwindows/ui/resource/image/mainwindow/ui/contact.png")));
        labelName = new QLabel(widgetMystatus);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(68, 14, 101, 21));
        labelName->setAlignment(Qt::AlignCenter);
        labelstatus = new QLabel(widgetMystatus);
        labelstatus->setObjectName(QString::fromUtf8("labelstatus"));
        labelstatus->setGeometry(QRect(70, 40, 81, 16));
        pushButton = new QPushButton(widgetMystatus);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(193, 20, 41, 31));
        scrollArea = new QScrollArea(widgetLeft);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 60, 241, 321));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 239, 319));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        widgetTool = new QWidget(widgetLeft);
        widgetTool->setObjectName(QString::fromUtf8("widgetTool"));
        widgetTool->setGeometry(QRect(-1, 379, 241, 51));
        btnAdd = new QPushButton(widgetTool);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(4, 3, 41, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/image/mianwindows/ui/resource/image/mainwindow/ui/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);
        btnGroup = new QPushButton(widgetTool);
        btnGroup->setObjectName(QString::fromUtf8("btnGroup"));
        btnGroup->setGeometry(QRect(53, 4, 51, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/image/mianwindows/ui/resource/image/mainwindow/ui/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGroup->setIcon(icon1);
        btnSeting = new QPushButton(widgetTool);
        btnSeting->setObjectName(QString::fromUtf8("btnSeting"));
        btnSeting->setGeometry(QRect(110, 5, 61, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/image/mianwindows/ui/resource/image/mainwindow/ui/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSeting->setIcon(icon2);
        btnFTP = new QPushButton(widgetTool);
        btnFTP->setObjectName(QString::fromUtf8("btnFTP"));
        btnFTP->setGeometry(QRect(174, 5, 61, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resource/image/mianwindows/ui/resource/image/mainwindow/ui/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFTP->setIcon(icon3);
        widgetTalk = new QWidget(centrePanel);
        widgetTalk->setObjectName(QString::fromUtf8("widgetTalk"));
        widgetTalk->setGeometry(QRect(249, 59, 381, 281));
        textBrowser = new QTextBrowser(widgetTalk);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(5, 1, 371, 281));
        widgetYou = new QWidget(centrePanel);
        widgetYou->setObjectName(QString::fromUtf8("widgetYou"));
        widgetYou->setGeometry(QRect(250, 6, 381, 51));
        label = new QLabel(widgetYou);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 81, 41));
        label_2 = new QLabel(widgetYou);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 10, 81, 31));
        label_3 = new QLabel(widgetYou);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 10, 81, 31));
        widgetSend = new QWidget(centrePanel);
        widgetSend->setObjectName(QString::fromUtf8("widgetSend"));
        widgetSend->setGeometry(QRect(240, 350, 401, 81));
        toolButton = new QToolButton(widgetSend);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(190, -2, 31, 18));
        textEdit = new QTextEdit(widgetSend);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 341, 61));
        toolButton_2 = new QToolButton(widgetSend);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(220, -2, 31, 18));
        toolButton_3 = new QToolButton(widgetSend);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(250, -2, 31, 18));
        toolButton_4 = new QToolButton(widgetSend);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(280, -4, 31, 21));
        pushButton_3 = new QPushButton(widgetSend);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 20, 61, 61));
        toolButton_5 = new QToolButton(widgetSend);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(314, -4, 31, 21));
        fontComboBox = new QFontComboBox(widgetSend);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(6, -3, 111, 22));
        comboBox = new QComboBox(widgetSend);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(116, -3, 71, 22));
        MainWindow->setCentralWidget(centralWidget);
        titleBar->raise();
        centrePanel->raise();
        labelLogo->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        btnMin->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelLogo->setText(QApplication::translate("MainWindow", "QBOX", 0, QApplication::UnicodeUTF8));
        btnClock->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        labelPic->setText(QString());
        labelName->setText(QApplication::translate("MainWindow", "\347\223\234\344\270\215\347\224\234", 0, QApplication::UnicodeUTF8));
        labelstatus->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232\345\234\250\347\272\277", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\347\246\273\345\274\200", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QString());
        btnGroup->setText(QString());
        btnSeting->setText(QString());
        btnFTP->setText(QString());
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
