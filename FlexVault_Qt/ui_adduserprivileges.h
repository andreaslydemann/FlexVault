/********************************************************************************
** Form generated from reading UI file 'adduserprivileges.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERPRIVILEGES_H
#define UI_ADDUSERPRIVILEGES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUserPrivileges
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *sdbListWidget;
    QLabel *sdbLabel;
    QLabel *titleLabel;
    QLabel *msg1Label;
    QLabel *msg2Label;
    QLabel *msg3Label;

    void setupUi(QWidget *AddUserPrivileges)
    {
        if (AddUserPrivileges->objectName().isEmpty())
            AddUserPrivileges->setObjectName(QString::fromUtf8("AddUserPrivileges"));
        AddUserPrivileges->resize(480, 272);
        buttonBox = new QDialogButtonBox(AddUserPrivileges);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 230, 168, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        sdbListWidget = new QListWidget(AddUserPrivileges);
        sdbListWidget->setObjectName(QString::fromUtf8("sdbListWidget"));
        sdbListWidget->setGeometry(QRect(250, 40, 221, 221));
        sdbLabel = new QLabel(AddUserPrivileges);
        sdbLabel->setObjectName(QString::fromUtf8("sdbLabel"));
        sdbLabel->setGeometry(QRect(280, 20, 181, 21));
        titleLabel = new QLabel(AddUserPrivileges);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(10, 0, 221, 41));
        msg1Label = new QLabel(AddUserPrivileges);
        msg1Label->setObjectName(QString::fromUtf8("msg1Label"));
        msg1Label->setGeometry(QRect(10, 50, 191, 81));
        msg2Label = new QLabel(AddUserPrivileges);
        msg2Label->setObjectName(QString::fromUtf8("msg2Label"));
        msg2Label->setGeometry(QRect(10, 150, 181, 31));
        msg3Label = new QLabel(AddUserPrivileges);
        msg3Label->setObjectName(QString::fromUtf8("msg3Label"));
        msg3Label->setGeometry(QRect(10, 180, 151, 21));

        retranslateUi(AddUserPrivileges);

        QMetaObject::connectSlotsByName(AddUserPrivileges);
    } // setupUi

    void retranslateUi(QWidget *AddUserPrivileges)
    {
        AddUserPrivileges->setWindowTitle(QApplication::translate("AddUserPrivileges", "Form", 0, QApplication::UnicodeUTF8));
        sdbLabel->setText(QApplication::translate("AddUserPrivileges", "SAFE DEPOSIT BOXES", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("AddUserPrivileges", "<html><head/><body><p><span style=\" font-size:10pt;\">ADD USER PRIVILEGES</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        msg1Label->setText(QApplication::translate("AddUserPrivileges", "<html><head/><body><p>HIGHLIGHT THE SAFE DEPOSIT BOX TO BE ADDED</p></body></html>", 0, QApplication::UnicodeUTF8));
        msg2Label->setText(QApplication::translate("AddUserPrivileges", "<html><head/><body><p><span style=\" color:#00ff00;\">GREEN</span> = NOT IN USE</p></body></html>", 0, QApplication::UnicodeUTF8));
        msg3Label->setText(QApplication::translate("AddUserPrivileges", "<html><head/><body><p><span style=\" color:#ff0000;\">RED</span> = IN USE</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddUserPrivileges: public Ui_AddUserPrivileges {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERPRIVILEGES_H
