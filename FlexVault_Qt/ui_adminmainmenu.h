/********************************************************************************
** Form generated from reading UI file 'adminmainmenu.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINMENU_H
#define UI_ADMINMAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMainMenu
{
public:
    QPushButton *usersButton;
    QPushButton *sdbButton;
    QPushButton *logButton;
    QPushButton *logOutButton;
    QLabel *manageFVLabel;

    void setupUi(QWidget *AdminMainMenu)
    {
        if (AdminMainMenu->objectName().isEmpty())
            AdminMainMenu->setObjectName(QString::fromUtf8("AdminMainMenu"));
        AdminMainMenu->resize(480, 272);
        usersButton = new QPushButton(AdminMainMenu);
        usersButton->setObjectName(QString::fromUtf8("usersButton"));
        usersButton->setGeometry(QRect(10, 90, 141, 91));
        sdbButton = new QPushButton(AdminMainMenu);
        sdbButton->setObjectName(QString::fromUtf8("sdbButton"));
        sdbButton->setGeometry(QRect(170, 90, 141, 91));
        logButton = new QPushButton(AdminMainMenu);
        logButton->setObjectName(QString::fromUtf8("logButton"));
        logButton->setGeometry(QRect(330, 90, 141, 91));
        logOutButton = new QPushButton(AdminMainMenu);
        logOutButton->setObjectName(QString::fromUtf8("logOutButton"));
        logOutButton->setGeometry(QRect(10, 220, 141, 41));
        manageFVLabel = new QLabel(AdminMainMenu);
        manageFVLabel->setObjectName(QString::fromUtf8("manageFVLabel"));
        manageFVLabel->setGeometry(QRect(150, 30, 191, 31));
        QFont font;
        font.setPointSize(11);
        manageFVLabel->setFont(font);

        retranslateUi(AdminMainMenu);

        QMetaObject::connectSlotsByName(AdminMainMenu);
    } // setupUi

    void retranslateUi(QWidget *AdminMainMenu)
    {
        AdminMainMenu->setWindowTitle(QApplication::translate("AdminMainMenu", "Form", 0, QApplication::UnicodeUTF8));
        usersButton->setText(QApplication::translate("AdminMainMenu", "USERS", 0, QApplication::UnicodeUTF8));
        sdbButton->setText(QApplication::translate("AdminMainMenu", "SDB", 0, QApplication::UnicodeUTF8));
        logButton->setText(QApplication::translate("AdminMainMenu", "LOG", 0, QApplication::UnicodeUTF8));
        logOutButton->setText(QApplication::translate("AdminMainMenu", "LOG OUT", 0, QApplication::UnicodeUTF8));
        manageFVLabel->setText(QApplication::translate("AdminMainMenu", "MANAGE FLEX-VAULT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdminMainMenu: public Ui_AdminMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINMENU_H
