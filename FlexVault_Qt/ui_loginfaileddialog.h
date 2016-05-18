/********************************************************************************
** Form generated from reading UI file 'loginfaileddialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFAILEDDIALOG_H
#define UI_LOGINFAILEDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginFailedDialog
{
public:
    QPushButton *okButton;
    QLabel *loginFailedLabel;
    QLabel *msgLabel;

    void setupUi(QDialog *LoginFailedDialog)
    {
        if (LoginFailedDialog->objectName().isEmpty())
            LoginFailedDialog->setObjectName(QString::fromUtf8("LoginFailedDialog"));
        LoginFailedDialog->resize(280, 200);
        okButton = new QPushButton(LoginFailedDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(90, 136, 91, 41));
        loginFailedLabel = new QLabel(LoginFailedDialog);
        loginFailedLabel->setObjectName(QString::fromUtf8("loginFailedLabel"));
        loginFailedLabel->setGeometry(QRect(80, 30, 161, 21));
        msgLabel = new QLabel(LoginFailedDialog);
        msgLabel->setObjectName(QString::fromUtf8("msgLabel"));
        msgLabel->setGeometry(QRect(40, 60, 211, 61));

        retranslateUi(LoginFailedDialog);

        QMetaObject::connectSlotsByName(LoginFailedDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginFailedDialog)
    {
        LoginFailedDialog->setWindowTitle(QApplication::translate("LoginFailedDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("LoginFailedDialog", "OK", 0, QApplication::UnicodeUTF8));
        loginFailedLabel->setText(QApplication::translate("LoginFailedDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">LOGIN FAILED</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        msgLabel->setText(QApplication::translate("LoginFailedDialog", "USERNAME OR PASSWORD IS INCORRECT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginFailedDialog: public Ui_LoginFailedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFAILEDDIALOG_H
