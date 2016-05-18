/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include "qvirtualkeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginButton;
    QLineEdit *idLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *idLabel;
    QLabel *passwordLabel;
    QLabel *flexVaultLabel;
    qvirtualkeyboard *virtualKeyboard;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(480, 272);
        Login->setStyleSheet(QString::fromUtf8("border-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(290, 20, 181, 31));
        idLineEdit = new QLineEdit(Login);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setGeometry(QRect(120, 80, 351, 41));
        passwordLineEdit = new QLineEdit(Login);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(120, 130, 351, 41));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        idLabel = new QLabel(Login);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setGeometry(QRect(20, 90, 101, 16));
        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(20, 140, 111, 16));
        flexVaultLabel = new QLabel(Login);
        flexVaultLabel->setObjectName(QString::fromUtf8("flexVaultLabel"));
        flexVaultLabel->setGeometry(QRect(20, 0, 161, 71));
        QFont font;
        font.setPointSize(36);
        flexVaultLabel->setFont(font);
        virtualKeyboard = new qvirtualkeyboard(Login);
        virtualKeyboard->setObjectName(QString::fromUtf8("virtualKeyboard"));
        virtualKeyboard->setGeometry(QRect(0, 190, 481, 81));
        QWidget::setTabOrder(idLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, loginButton);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("Login", "LOG IN", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("Login", "USERNAME:", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("Login", "PASSWORD:", 0, QApplication::UnicodeUTF8));
        flexVaultLabel->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:14pt;\">FLEX-VAULT</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
