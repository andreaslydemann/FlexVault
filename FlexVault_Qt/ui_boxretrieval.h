/********************************************************************************
** Form generated from reading UI file 'boxretrieval.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXRETRIEVAL_H
#define UI_BOXRETRIEVAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxRetrieval
{
public:
    QPushButton *returnButton;
    QLabel *msgLabel;

    void setupUi(QWidget *BoxRetrieval)
    {
        if (BoxRetrieval->objectName().isEmpty())
            BoxRetrieval->setObjectName(QString::fromUtf8("BoxRetrieval"));
        BoxRetrieval->resize(480, 272);
        returnButton = new QPushButton(BoxRetrieval);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(120, 140, 241, 101));
        msgLabel = new QLabel(BoxRetrieval);
        msgLabel->setObjectName(QString::fromUtf8("msgLabel"));
        msgLabel->setGeometry(QRect(90, 40, 271, 51));

        retranslateUi(BoxRetrieval);

        QMetaObject::connectSlotsByName(BoxRetrieval);
    } // setupUi

    void retranslateUi(QWidget *BoxRetrieval)
    {
        BoxRetrieval->setWindowTitle(QApplication::translate("BoxRetrieval", "Form", 0, QApplication::UnicodeUTF8));
        returnButton->setText(QApplication::translate("BoxRetrieval", "RETURN", 0, QApplication::UnicodeUTF8));
        msgLabel->setText(QApplication::translate("BoxRetrieval", "PLEASE WAIT FOR THE SAFE DEPOSIT BOX TO BE RETRIEVED", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BoxRetrieval: public Ui_BoxRetrieval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXRETRIEVAL_H
