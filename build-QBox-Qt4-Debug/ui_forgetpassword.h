/********************************************************************************
** Form generated from reading UI file 'forgetpassword.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASSWORD_H
#define UI_FORGETPASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgetPassword
{
public:
    QLabel *labelBackground;
    QLabel *labelForeground;
    QPushButton *btnPhone;
    QPushButton *btnMail;
    QPushButton *btnClose;

    void setupUi(QWidget *ForgetPassword)
    {
        if (ForgetPassword->objectName().isEmpty())
            ForgetPassword->setObjectName(QString::fromUtf8("ForgetPassword"));
        ForgetPassword->resize(359, 210);
        ForgetPassword->setStyleSheet(QString::fromUtf8("/*\345\205\250\345\261\200\350\256\276\347\275\256*/\n"
"* {	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; font-size: 15px;}\n"
"/*\350\203\214\346\231\257*/\n"
"QLabel#labelBackground {\n"
"    background: #569082;\n"
"	outline:none;\n"
"	color:#333;	\n"
"}\n"
"/*\345\211\215\346\231\257*/\n"
"QLabel#labelForeground {\n"
"    background: #569762;\n"
"	color:#433;	\n"
"    \n"
"	font: 75 28pt \"\346\226\271\346\255\243\347\262\227\350\260\255\351\273\221\347\256\200\344\275\223\";\n"
"}\n"
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
"/*\351\202\256\347\256\261\351\200\232\347\237\245*/\n"
"QPushButton#btnMail {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"}\n"
""
                        "QPushButton#btnMail:hover {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #ff9032;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"   \n"
"}\n"
"QPushButton#btnMail:pressed {\n"
"	border:3px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 20px;\n"
"\n"
"}\n"
"\n"
"/*\347\224\265\350\257\235\351\200\232\347\237\245*/\n"
"QPushButton#btnPhone {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"}\n"
"QPushButton#btnPhone:hover {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #ff9032;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"\n"
"}\n"
"QPushButton#btnPhone:pressed {\n"
"	border:3px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
""
                        "	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 20px;\n"
"\n"
"}\n"
""));
        labelBackground = new QLabel(ForgetPassword);
        labelBackground->setObjectName(QString::fromUtf8("labelBackground"));
        labelBackground->setGeometry(QRect(0, 0, 361, 211));
        labelForeground = new QLabel(ForgetPassword);
        labelForeground->setObjectName(QString::fromUtf8("labelForeground"));
        labelForeground->setGeometry(QRect(30, 30, 301, 101));
        labelForeground->setAlignment(Qt::AlignCenter);
        labelForeground->setWordWrap(false);
        btnPhone = new QPushButton(ForgetPassword);
        btnPhone->setObjectName(QString::fromUtf8("btnPhone"));
        btnPhone->setGeometry(QRect(80, 160, 75, 23));
        btnMail = new QPushButton(ForgetPassword);
        btnMail->setObjectName(QString::fromUtf8("btnMail"));
        btnMail->setGeometry(QRect(210, 160, 75, 23));
        btnClose = new QPushButton(ForgetPassword);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(340, 0, 21, 21));

        retranslateUi(ForgetPassword);
        QObject::connect(btnClose, SIGNAL(clicked()), labelBackground, SLOT(close()));

        QMetaObject::connectSlotsByName(ForgetPassword);
    } // setupUi

    void retranslateUi(QWidget *ForgetPassword)
    {
        ForgetPassword->setWindowTitle(QApplication::translate("ForgetPassword", "Form", 0, QApplication::UnicodeUTF8));
        labelBackground->setText(QString());
        labelForeground->setText(QApplication::translate("ForgetPassword", "\346\211\276\345\233\236\346\210\221\347\232\204\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        btnPhone->setText(QApplication::translate("ForgetPassword", "\347\224\265\350\257\235\351\200\232\347\237\245", 0, QApplication::UnicodeUTF8));
        btnMail->setText(QApplication::translate("ForgetPassword", "\351\202\256\347\256\261\351\200\232\347\237\245", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("ForgetPassword", "X", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ForgetPassword: public Ui_ForgetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASSWORD_H
