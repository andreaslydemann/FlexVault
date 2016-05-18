/********************************************************************************
** Form generated from reading UI file 'activitylog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYLOG_H
#define UI_ACTIVITYLOG_H

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

class Ui_ActivityLog
{
public:
    QPushButton *backButton;
    QListWidget *timeListWidget;
    QListWidget *actionListWidget;
    QListWidget *userListWidget;
    QLabel *usernameLabel;
    QLabel *actionLabel;
    QLabel *timeLabel;
    QLabel *label;

    void setupUi(QWidget *ActivityLog)
    {
        if (ActivityLog->objectName().isEmpty())
            ActivityLog->setObjectName(QString::fromUtf8("ActivityLog"));
        ActivityLog->resize(480, 272);
        backButton = new QPushButton(ActivityLog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(360, 10, 111, 41));
        timeListWidget = new QListWidget(ActivityLog);
        timeListWidget->setObjectName(QString::fromUtf8("timeListWidget"));
        timeListWidget->setGeometry(QRect(310, 80, 161, 181));
        QFont font;
        font.setPointSize(8);
        timeListWidget->setFont(font);
        actionListWidget = new QListWidget(ActivityLog);
        actionListWidget->setObjectName(QString::fromUtf8("actionListWidget"));
        actionListWidget->setGeometry(QRect(160, 80, 151, 181));
        actionListWidget->setFont(font);
        userListWidget = new QListWidget(ActivityLog);
        userListWidget->setObjectName(QString::fromUtf8("userListWidget"));
        userListWidget->setGeometry(QRect(10, 80, 151, 181));
        userListWidget->setFont(font);
        usernameLabel = new QLabel(ActivityLog);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(40, 60, 91, 17));
        actionLabel = new QLabel(ActivityLog);
        actionLabel->setObjectName(QString::fromUtf8("actionLabel"));
        actionLabel->setGeometry(QRect(200, 60, 69, 17));
        timeLabel = new QLabel(ActivityLog);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(370, 60, 41, 17));
        label = new QLabel(ActivityLog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 31));

        retranslateUi(ActivityLog);

        QMetaObject::connectSlotsByName(ActivityLog);
    } // setupUi

    void retranslateUi(QWidget *ActivityLog)
    {
        ActivityLog->setWindowTitle(QApplication::translate("ActivityLog", "Form", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("ActivityLog", "Back", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("ActivityLog", "USERNAME", 0, QApplication::UnicodeUTF8));
        actionLabel->setText(QApplication::translate("ActivityLog", "ACTION", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("ActivityLog", "TIME", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ActivityLog", "<html><head/><body><p><span style=\" font-size:11pt;\">ACTIVITY LOG</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ActivityLog: public Ui_ActivityLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYLOG_H
