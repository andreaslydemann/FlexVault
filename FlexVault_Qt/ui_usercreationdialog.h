/********************************************************************************
** Form generated from reading UI file 'usercreationdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCREATIONDIALOG_H
#define UI_USERCREATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>
#include "qvirtualkeyboard.h"

QT_BEGIN_NAMESPACE

class Ui_UserCreationDialog
{
public:
    QWidget *widget_2;
    QWidget *widget;
    QLabel *msgLabel;
    QLineEdit *userIDLineEdit;
    QLineEdit *passwordLineEdit;
    QDialogButtonBox *buttonBox;
    QLabel *userIDLabel;
    QLabel *passwordLabel;
    qvirtualkeyboard *virtualKeyboard;

    void setupUi(QDialog *UserCreationDialog)
    {
        if (UserCreationDialog->objectName().isEmpty())
            UserCreationDialog->setObjectName(QString::fromUtf8("UserCreationDialog"));
        UserCreationDialog->resize(480, 272);
        widget_2 = new QWidget(UserCreationDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(80, 40, 321, 211));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 301, 191));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"font: 9pt \"Sans Serif\";"));
        msgLabel = new QLabel(widget);
        msgLabel->setObjectName(QString::fromUtf8("msgLabel"));
        msgLabel->setGeometry(QRect(10, 20, 301, 21));
        userIDLineEdit = new QLineEdit(widget);
        userIDLineEdit->setObjectName(QString::fromUtf8("userIDLineEdit"));
        userIDLineEdit->setGeometry(QRect(130, 60, 151, 23));
        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(130, 100, 151, 23));
        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 150, 181, 21));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        userIDLabel = new QLabel(widget);
        userIDLabel->setObjectName(QString::fromUtf8("userIDLabel"));
        userIDLabel->setGeometry(QRect(10, 60, 111, 21));
        passwordLabel = new QLabel(widget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(10, 100, 111, 21));
        virtualKeyboard = new qvirtualkeyboard(UserCreationDialog);
        virtualKeyboard->setObjectName(QString::fromUtf8("virtualKeyboard"));
        virtualKeyboard->setGeometry(QRect(0, 190, 481, 81));

        retranslateUi(UserCreationDialog);

        QMetaObject::connectSlotsByName(UserCreationDialog);
    } // setupUi

    void retranslateUi(QDialog *UserCreationDialog)
    {
        UserCreationDialog->setWindowTitle(QApplication::translate("UserCreationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        msgLabel->setText(QApplication::translate("UserCreationDialog", "ENTER USERNAME AND PASSWORD", 0, QApplication::UnicodeUTF8));
        userIDLabel->setText(QApplication::translate("UserCreationDialog", "USERNAME:", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("UserCreationDialog", "PASSWORD:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserCreationDialog: public Ui_UserCreationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCREATIONDIALOG_H
