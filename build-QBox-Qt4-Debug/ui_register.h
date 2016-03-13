/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *labelBackgroundUp;
    QLabel *labelBackgroundDown;
    QWidget *widgetUserName;
    QLabel *labelusername;
    QLineEdit *lineEditUserName;
    QWidget *widgetPassword;
    QLabel *labelpassword;
    QLineEdit *lineEditPassword;
    QWidget *widgetConfirm;
    QLabel *labelconfirm;
    QLineEdit *lineEditConfirm;
    QWidget *widgetMail;
    QLabel *labelmail;
    QLineEdit *lineEdit_4;
    QWidget *widgetPhone;
    QLabel *labelphone;
    QLineEdit *lineEditPhone;
    QPushButton *btnRegister;
    QPushButton *btnClose;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(360, 400);
        Register->setStyleSheet(QString::fromUtf8("/*\345\205\250\345\261\200\351\231\220\345\256\232*/\n"
"* {	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\"; font-size: 15px;}\n"
"/*\344\270\212\351\203\250\350\203\214\346\231\257*/\n"
"QLabel#labelBackgroundUp\n"
"{    \n"
"	background-color: rgb(0, 170, 255);\n"
"    outline:none;\n"
"	color:#333;\n"
"}\n"
"/*\344\270\213\351\203\250\350\203\214\346\231\257*/\n"
"QLabel#labelBackgroundDown\n"
"{\n"
"    background-color: rgb(0, 170,150);\n"
"    outline:none;\n"
"	color:#333;\n"
"\n"
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
"/*\350\276\223\345\205\245\346\241\206\345\205\250\345\261\200\350\256\276\347\275\256*/\n"
"QLineEdit {\n"
"	border: none;    \n"
"	font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background: transparent;\n"
"}\n"
"/*\350\276\223\345"
                        "\205\245\351\200\211\351\241\271\350\256\276\345\256\232*/\n"
"QWidget#widgetConfirm,#widgetMail,#widgetPhone,#widgetPassword,#widgetUserName{\n"
"   border: 2px solid #c9c9c9;\n"
"}\n"
"/*\346\263\250\345\206\214\346\214\211\351\222\256*/\n"
"QPushButton#btnRegister {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"}\n"
"QPushButton#btnRegister:hover {\n"
"	border: 1px solid #c9c9c9;\n"
"	background: #ff9032;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 15px;\n"
"   \n"
"}\n"
"QPushButton#btnRegister:pressed {\n"
"	border:3px solid #c9c9c9;\n"
"	background: #569082;\n"
"	color:#ffffff;\n"
"	font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 20px;\n"
"   \n"
"}"));
        labelBackgroundUp = new QLabel(Register);
        labelBackgroundUp->setObjectName(QString::fromUtf8("labelBackgroundUp"));
        labelBackgroundUp->setGeometry(QRect(0, 0, 361, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        labelBackgroundUp->setFont(font);
        labelBackgroundUp->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/Triangle.png")));
        labelBackgroundUp->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        labelBackgroundDown = new QLabel(Register);
        labelBackgroundDown->setObjectName(QString::fromUtf8("labelBackgroundDown"));
        labelBackgroundDown->setGeometry(QRect(0, 70, 361, 331));
        labelBackgroundDown->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/Triangle.png")));
        labelBackgroundDown->setAlignment(Qt::AlignCenter);
        widgetUserName = new QWidget(Register);
        widgetUserName->setObjectName(QString::fromUtf8("widgetUserName"));
        widgetUserName->setGeometry(QRect(50, 78, 261, 41));
        labelusername = new QLabel(widgetUserName);
        labelusername->setObjectName(QString::fromUtf8("labelusername"));
        labelusername->setGeometry(QRect(6, 5, 31, 31));
        labelusername->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/person.png")));
        lineEditUserName = new QLineEdit(widgetUserName);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(50, 0, 211, 41));
        widgetPassword = new QWidget(Register);
        widgetPassword->setObjectName(QString::fromUtf8("widgetPassword"));
        widgetPassword->setGeometry(QRect(50, 128, 261, 41));
        labelpassword = new QLabel(widgetPassword);
        labelpassword->setObjectName(QString::fromUtf8("labelpassword"));
        labelpassword->setGeometry(QRect(8, 6, 31, 31));
        labelpassword->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/passwd.png")));
        lineEditPassword = new QLineEdit(widgetPassword);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(52, -1, 211, 41));
        widgetConfirm = new QWidget(Register);
        widgetConfirm->setObjectName(QString::fromUtf8("widgetConfirm"));
        widgetConfirm->setGeometry(QRect(50, 177, 261, 41));
        labelconfirm = new QLabel(widgetConfirm);
        labelconfirm->setObjectName(QString::fromUtf8("labelconfirm"));
        labelconfirm->setGeometry(QRect(7, 6, 31, 31));
        labelconfirm->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/password2.png")));
        lineEditConfirm = new QLineEdit(widgetConfirm);
        lineEditConfirm->setObjectName(QString::fromUtf8("lineEditConfirm"));
        lineEditConfirm->setGeometry(QRect(52, 0, 211, 41));
        widgetMail = new QWidget(Register);
        widgetMail->setObjectName(QString::fromUtf8("widgetMail"));
        widgetMail->setGeometry(QRect(50, 226, 261, 41));
        labelmail = new QLabel(widgetMail);
        labelmail->setObjectName(QString::fromUtf8("labelmail"));
        labelmail->setGeometry(QRect(3, 7, 41, 31));
        labelmail->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/mail.png")));
        lineEdit_4 = new QLineEdit(widgetMail);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(50, 0, 211, 41));
        widgetPhone = new QWidget(Register);
        widgetPhone->setObjectName(QString::fromUtf8("widgetPhone"));
        widgetPhone->setGeometry(QRect(50, 275, 261, 41));
        labelphone = new QLabel(widgetPhone);
        labelphone->setObjectName(QString::fromUtf8("labelphone"));
        labelphone->setGeometry(QRect(8, 4, 31, 31));
        labelphone->setPixmap(QPixmap(QString::fromUtf8(":/resource/image/login/resource/image/login/phone.png")));
        lineEditPhone = new QLineEdit(widgetPhone);
        lineEditPhone->setObjectName(QString::fromUtf8("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(50, 0, 211, 41));
        btnRegister = new QPushButton(Register);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(110, 330, 141, 41));
        btnClose = new QPushButton(Register);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(330, 0, 31, 21));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", 0, QApplication::UnicodeUTF8));
        labelBackgroundUp->setText(QString());
        labelBackgroundDown->setText(QString());
        labelusername->setText(QString());
        labelpassword->setText(QString());
        labelconfirm->setText(QString());
        labelmail->setText(QString());
        labelphone->setText(QString());
        btnRegister->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("Register", "X", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
