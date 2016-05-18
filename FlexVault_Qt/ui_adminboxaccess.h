/********************************************************************************
** Form generated from reading UI file 'adminboxaccess.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINBOXACCESS_H
#define UI_ADMINBOXACCESS_H

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

class Ui_AdminBoxAccess
{
public:
    QListWidget *boxListWidget;
    QPushButton *backButton;
    QPushButton *retrieveButton;
    QLabel *label_2;

    void setupUi(QWidget *AdminBoxAccess)
    {
        if (AdminBoxAccess->objectName().isEmpty())
            AdminBoxAccess->setObjectName(QString::fromUtf8("AdminBoxAccess"));
        AdminBoxAccess->resize(480, 272);
        boxListWidget = new QListWidget(AdminBoxAccess);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        new QListWidgetItem(boxListWidget);
        boxListWidget->setObjectName(QString::fromUtf8("boxListWidget"));
        boxListWidget->setGeometry(QRect(140, 50, 331, 211));
        backButton = new QPushButton(AdminBoxAccess);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 210, 121, 51));
        retrieveButton = new QPushButton(AdminBoxAccess);
        retrieveButton->setObjectName(QString::fromUtf8("retrieveButton"));
        retrieveButton->setGeometry(QRect(10, 140, 121, 51));
        label_2 = new QLabel(AdminBoxAccess);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 30, 281, 17));

        retranslateUi(AdminBoxAccess);

        QMetaObject::connectSlotsByName(AdminBoxAccess);
    } // setupUi

    void retranslateUi(QWidget *AdminBoxAccess)
    {
        AdminBoxAccess->setWindowTitle(QApplication::translate("AdminBoxAccess", "Form", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = boxListWidget->isSortingEnabled();
        boxListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = boxListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 1", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = boxListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 2", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = boxListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 3", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = boxListWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 4", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = boxListWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 5", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = boxListWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 6", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = boxListWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 7", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = boxListWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 8", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = boxListWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 9", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = boxListWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 10", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = boxListWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 11", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem11 = boxListWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 12", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem12 = boxListWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 13", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem13 = boxListWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 14", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem14 = boxListWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 15", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem15 = boxListWidget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 16", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem16 = boxListWidget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 17", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem17 = boxListWidget->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 18", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem18 = boxListWidget->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 19", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem19 = boxListWidget->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("AdminBoxAccess", "SAFE DEPOSIT BOX 20", 0, QApplication::UnicodeUTF8));
        boxListWidget->setSortingEnabled(__sortingEnabled);

        backButton->setText(QApplication::translate("AdminBoxAccess", "BACK", 0, QApplication::UnicodeUTF8));
        retrieveButton->setText(QApplication::translate("AdminBoxAccess", "RETRIEVE", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdminBoxAccess", "ACCESS SAFE DEPOSIT BOXES", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdminBoxAccess: public Ui_AdminBoxAccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINBOXACCESS_H
