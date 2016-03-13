/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *labelLogo;
    QPushButton *btnClose;
    QPushButton *btnLogin;
    QPushButton *btnMin;
    QLabel *labelRegist;
    QLabel *labelForget;
    QWidget *widgetPassword;
    QLineEdit *lineEditPassword;
    QLabel *label;
    QWidget *widgetUser;
    QLabel *label1;
    QLineEdit *lineEditUser;
    QCheckBox *cbkAuto;
    QLabel *Logo;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(528, 410);
        Login->setStyleSheet(QString::fromUtf8("/*\345\205\250\345\261\200\350\256\276\347\275\256*/\n"
"* {	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; font-size: 15px;}\n"
"\n"
"/*\346\234\200\344\270\212\350\276\271\347\232\204Logo\345\233\276\346\240\207*/\n"
"QLabel#labelLogo {\n"
"	background: #569082;\n"
"	outline:none;\n"
"	color:#333;\n"
"}\n"
"\n"
"/*\346\263\250\345\206\214*/\n"
"QLabel#labelRegist {\n"
"	color: rgb(0, 170, 127);\n"
"}\n"
"QLabel#labelRegist:hover\n"
"{\n"
"    color: rgb(255, 0, 0);\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"}\n"
"\n"
"/*\345\277\230\350\256\260\345\257\206\347\240\201*/\n"
"QLabel#labelForget {\n"
"	color: rgb(0, 170, 127);\n"
"\n"
"}\n"
"QLabel#labelForget:hover\n"
"{\n"
"    color: rgb(255, 0, 0);\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"}\n"
"\n"
"\n"
"/*\346\234\200\345\260\217\345\214\226\346\214\211\351\222\256*/\n"
"QPushButton#btnMin {\n"
"	background: transparent;\n"
"	border: none;\n"
"	color: #fffff"
                        "f;\n"
"	font-size: 18px;\n"
"}\n"
"QPushButton#btnMin:hover {\n"
"\n"
"	background: #569000;\n"
"}\n"
"\n"
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
"\n"
"/*\346\263\250\345\206\214\346\214\211\351\222\256*/\n"
"QPushButton#btnLogin {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"}\n"
"QPushButton#btnLogin:hover {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #ff9032;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"   \n"
"}\n"
"QPushButton#btnLogin:pressed {\n"
"	border:9px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\""
                        ";\n"
"	font-size: 20px;\n"
"   \n"
"}\n"
"\n"
"\n"
"/*\350\256\260\344\275\217\345\257\206\347\240\201\345\244\215\351\200\211\346\241\206*/\n"
"QCheckBox::indicator \n"
"{\n"
"	width: 15px;\n"
" 	height: 15px;\n"
"	margin-right:5px;\n"
"}\n"
"QCheckBox#cbkAuto {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"	color: rgb(46, 44, 45);\n"
"}\n"
"QCheckBox#cbkAuto:hover {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"	\n"
"	color: rgb(0, 206, 0);\n"
"}\n"
"QCheckBox#cbkAuto:checked {\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"	\n"
"	color: rgb(0, 170, 127);\n"
"}\n"
"/*\350\276\223\345\205\245\346\241\206\345\205\250\345\261\200\350\256\276\347\275\256*/\n"
"QLineEdit {\n"
"	border: none;    \n"
"	font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background: transparent;\n"
"}\n"
"/*\350\276\223\345\205\245\347\224\250\346\210\267\345\220"
                        "\215\347\210\266\346\216\247\344\273\266*/\n"
"QWidget#widgetUser {\n"
"	border: 1px solid #c9c9c9;\n"
"\n"
"}\n"
"\n"
"/*\350\276\223\345\205\245\345\257\206\347\240\201\347\210\266\346\216\247\344\273\266*/\n"
"QWidget#widgetPassword {\n"
"	border: 1px solid #c9c9c9;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        labelLogo = new QLabel(Login);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setGeometry(QRect(0, 0, 530, 131));
        labelLogo->setStyleSheet(QString::fromUtf8("QLabel#labelLogo {\n"
"	background: #569082;\n"
"	outline:none;\n"
"	color:#333;\n"
"}"));
        btnClose = new QPushButton(Login);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(500, 0, 31, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy);
        btnLogin = new QPushButton(Login);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(150, 332, 211, 41));
        btnMin = new QPushButton(Login);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setGeometry(QRect(470, 0, 31, 21));
        labelRegist = new QLabel(Login);
        labelRegist->setObjectName(QString::fromUtf8("labelRegist"));
        labelRegist->setGeometry(QRect(390, 186, 61, 21));
        labelForget = new QLabel(Login);
        labelForget->setObjectName(QString::fromUtf8("labelForget"));
        labelForget->setGeometry(QRect(390, 244, 61, 21));
        widgetPassword = new QWidget(Login);
        widgetPassword->setObjectName(QString::fromUtf8("widgetPassword"));
        widgetPassword->setGeometry(QRect(150, 240, 211, 41));
        lineEditPassword = new QLineEdit(widgetPassword);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(40, 0, 171, 41));
        lineEditPassword->setAutoFillBackground(false);
        lineEditPassword->setMaxLength(12);
        lineEditPassword->setEchoMode(QLineEdit::Password);
        label = new QLabel(widgetPassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(3, 5, 31, 31));
        label->setStyleSheet(QString::fromUtf8("label{\n"
"image: url(:/resource/image/login/resource/image/login/passwd.png);\n"
"}\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/passwd.png")));
        widgetUser = new QWidget(Login);
        widgetUser->setObjectName(QString::fromUtf8("widgetUser"));
        widgetUser->setGeometry(QRect(150, 180, 211, 41));
        label1 = new QLabel(widgetUser);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(3, 5, 31, 31));
        label1->setStyleSheet(QString::fromUtf8("label1{\n"
"\n"
"url(:/resource/image/login/resource/image/login/person.png)}"));
        label1->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/person.png")));
        lineEditUser = new QLineEdit(widgetUser);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));
        lineEditUser->setGeometry(QRect(40, 0, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        lineEditUser->setFont(font);
        lineEditUser->setAutoFillBackground(false);
        lineEditUser->setMaxLength(12);
        lineEditUser->setEchoMode(QLineEdit::Normal);
        cbkAuto = new QCheckBox(Login);
        cbkAuto->setObjectName(QString::fromUtf8("cbkAuto"));
        cbkAuto->setGeometry(QRect(150, 290, 111, 21));
        Logo = new QLabel(Login);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(50, -10, 431, 141));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/logo.png")));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0, QApplication::UnicodeUTF8));
        labelLogo->setText(QString());
        btnClose->setText(QApplication::translate("Login", "x", 0, QApplication::UnicodeUTF8));
        btnLogin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        btnMin->setText(QApplication::translate("Login", "-", 0, QApplication::UnicodeUTF8));
        labelRegist->setText(QApplication::translate("Login", "\346\263\250\345\206\214\345\270\220\345\217\267", 0, QApplication::UnicodeUTF8));
        labelForget->setText(QApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label1->setText(QString());
        lineEditUser->setInputMask(QString());
        lineEditUser->setText(QString());
        cbkAuto->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        Logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
