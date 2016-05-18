/********************************************************************************
** Form generated from reading UI file 'userprivileges.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPRIVILEGES_H
#define UI_USERPRIVILEGES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserPrivileges
{
public:
    QListWidget *sdbListWidget;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *retrieveButton;
    QPushButton *backButton;
    QLabel *sdbLabel;
    QLabel *userIDLabel;
    QLabel *userPrivilegesLabel;
    QTextBrowser *userIDTextBrowser;

    void setupUi(QWidget *UserPrivileges)
    {
        if (UserPrivileges->objectName().isEmpty())
            UserPrivileges->setObjectName(QString::fromUtf8("UserPrivileges"));
        UserPrivileges->resize(480, 272);
        sdbListWidget = new QListWidget(UserPrivileges);
        sdbListWidget->setObjectName(QString::fromUtf8("sdbListWidget"));
        sdbListWidget->setGeometry(QRect(150, 50, 321, 211));
        addButton = new QPushButton(UserPrivileges);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(10, 100, 131, 41));
        deleteButton = new QPushButton(UserPrivileges);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(10, 140, 131, 41));
        retrieveButton = new QPushButton(UserPrivileges);
        retrieveButton->setObjectName(QString::fromUtf8("retrieveButton"));
        retrieveButton->setGeometry(QRect(10, 180, 131, 41));
        backButton = new QPushButton(UserPrivileges);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 220, 131, 41));
        sdbLabel = new QLabel(UserPrivileges);
        sdbLabel->setObjectName(QString::fromUtf8("sdbLabel"));
        sdbLabel->setGeometry(QRect(230, 30, 181, 17));
        userIDLabel = new QLabel(UserPrivileges);
        userIDLabel->setObjectName(QString::fromUtf8("userIDLabel"));
        userIDLabel->setGeometry(QRect(10, 40, 101, 17));
        userPrivilegesLabel = new QLabel(UserPrivileges);
        userPrivilegesLabel->setObjectName(QString::fromUtf8("userPrivilegesLabel"));
        userPrivilegesLabel->setGeometry(QRect(10, 0, 151, 31));
        QFont font;
        font.setPointSize(10);
        userPrivilegesLabel->setFont(font);
        userIDTextBrowser = new QTextBrowser(UserPrivileges);
        userIDTextBrowser->setObjectName(QString::fromUtf8("userIDTextBrowser"));
        userIDTextBrowser->setGeometry(QRect(10, 60, 131, 31));

        retranslateUi(UserPrivileges);

        QMetaObject::connectSlotsByName(UserPrivileges);
    } // setupUi

    void retranslateUi(QWidget *UserPrivileges)
    {
        UserPrivileges->setWindowTitle(QApplication::translate("UserPrivileges", "Form", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("UserPrivileges", "ADD", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("UserPrivileges", "DELETE", 0, QApplication::UnicodeUTF8));
        retrieveButton->setText(QApplication::translate("UserPrivileges", "RETRIEVE", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("UserPrivileges", "BACK", 0, QApplication::UnicodeUTF8));
        sdbLabel->setText(QApplication::translate("UserPrivileges", "SAFE DEPOSIT BOXES", 0, QApplication::UnicodeUTF8));
        userIDLabel->setText(QApplication::translate("UserPrivileges", "USERNAME:", 0, QApplication::UnicodeUTF8));
        userPrivilegesLabel->setText(QApplication::translate("UserPrivileges", "<html><head/><body><p>USER PRIVILEGES</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserPrivileges: public Ui_UserPrivileges {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPRIVILEGES_H
