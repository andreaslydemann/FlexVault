/********************************************************************************
** Form generated from reading UI file 'userboxaccess.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERBOXACCESS_H
#define UI_USERBOXACCESS_H

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

class Ui_UserBoxAccess
{
public:
    QPushButton *retrieveButton;
    QPushButton *logOutButton;
    QListWidget *boxListWidget;
    QLabel *label;

    void setupUi(QWidget *UserBoxAccess)
    {
        if (UserBoxAccess->objectName().isEmpty())
            UserBoxAccess->setObjectName(QString::fromUtf8("UserBoxAccess"));
        UserBoxAccess->resize(480, 272);
        retrieveButton = new QPushButton(UserBoxAccess);
        retrieveButton->setObjectName(QString::fromUtf8("retrieveButton"));
        retrieveButton->setGeometry(QRect(10, 40, 151, 81));
        logOutButton = new QPushButton(UserBoxAccess);
        logOutButton->setObjectName(QString::fromUtf8("logOutButton"));
        logOutButton->setGeometry(QRect(10, 210, 151, 51));
        boxListWidget = new QListWidget(UserBoxAccess);
        boxListWidget->setObjectName(QString::fromUtf8("boxListWidget"));
        boxListWidget->setGeometry(QRect(170, 40, 301, 221));
        label = new QLabel(UserBoxAccess);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 20, 271, 17));

        retranslateUi(UserBoxAccess);

        QMetaObject::connectSlotsByName(UserBoxAccess);
    } // setupUi

    void retranslateUi(QWidget *UserBoxAccess)
    {
        UserBoxAccess->setWindowTitle(QApplication::translate("UserBoxAccess", "Form", 0, QApplication::UnicodeUTF8));
        retrieveButton->setText(QApplication::translate("UserBoxAccess", "RETRIEVE", 0, QApplication::UnicodeUTF8));
        logOutButton->setText(QApplication::translate("UserBoxAccess", "LOG OUT", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserBoxAccess", "ACCESS SAFE DEPOSIT BOXES", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserBoxAccess: public Ui_UserBoxAccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBOXACCESS_H
