/********************************************************************************
** Form generated from reading UI file 'userconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCONFIGURATION_H
#define UI_USERCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserConfiguration
{
public:
    QListWidget *userListWidget;
    QPushButton *backButton;
    QPushButton *privilegesButton;
    QPushButton *deleteButton;
    QPushButton *createButton;
    QLabel *usersLabel;
    QLabel *ucLabel;

    void setupUi(QWidget *UserConfiguration)
    {
        if (UserConfiguration->objectName().isEmpty())
            UserConfiguration->setObjectName(QString::fromUtf8("UserConfiguration"));
        UserConfiguration->resize(480, 272);
        userListWidget = new QListWidget(UserConfiguration);
        userListWidget->setObjectName(QString::fromUtf8("userListWidget"));
        userListWidget->setGeometry(QRect(140, 70, 331, 191));
        backButton = new QPushButton(UserConfiguration);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 220, 121, 41));
        privilegesButton = new QPushButton(UserConfiguration);
        privilegesButton->setObjectName(QString::fromUtf8("privilegesButton"));
        privilegesButton->setGeometry(QRect(10, 170, 121, 41));
        deleteButton = new QPushButton(UserConfiguration);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(10, 120, 121, 41));
        createButton = new QPushButton(UserConfiguration);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(10, 70, 121, 41));
        usersLabel = new QLabel(UserConfiguration);
        usersLabel->setObjectName(QString::fromUtf8("usersLabel"));
        usersLabel->setGeometry(QRect(270, 50, 81, 21));
        ucLabel = new QLabel(UserConfiguration);
        ucLabel->setObjectName(QString::fromUtf8("ucLabel"));
        ucLabel->setGeometry(QRect(10, 0, 241, 41));

        retranslateUi(UserConfiguration);

        QMetaObject::connectSlotsByName(UserConfiguration);
    } // setupUi

    void retranslateUi(QWidget *UserConfiguration)
    {
        UserConfiguration->setWindowTitle(QApplication::translate("UserConfiguration", "Form", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("UserConfiguration", "BACK", 0, QApplication::UnicodeUTF8));
        privilegesButton->setText(QApplication::translate("UserConfiguration", "PRIVILEGES", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("UserConfiguration", "DELETE", 0, QApplication::UnicodeUTF8));
        createButton->setText(QApplication::translate("UserConfiguration", "CREATE", 0, QApplication::UnicodeUTF8));
        usersLabel->setText(QApplication::translate("UserConfiguration", "<html><head/><body><p><span style=\" font-size:10pt;\">USERS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ucLabel->setText(QApplication::translate("UserConfiguration", "<html><head/><body><p><span style=\" font-size:11pt;\">USER CONFIGURATION</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserConfiguration: public Ui_UserConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCONFIGURATION_H
