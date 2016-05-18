/********************************************************************************
** Form generated from reading UI file 'weightwarningdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEIGHTWARNINGDIALOG_H
#define UI_WEIGHTWARNINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeightWarningDialog
{
public:
    QLabel *titleLabel;
    QLabel *msgLabel;

    void setupUi(QWidget *WeightWarningDialog)
    {
        if (WeightWarningDialog->objectName().isEmpty())
            WeightWarningDialog->setObjectName(QString::fromUtf8("WeightWarningDialog"));
        WeightWarningDialog->resize(280, 189);
        titleLabel = new QLabel(WeightWarningDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(60, 40, 171, 41));
        msgLabel = new QLabel(WeightWarningDialog);
        msgLabel->setObjectName(QString::fromUtf8("msgLabel"));
        msgLabel->setGeometry(QRect(40, 90, 201, 51));

        retranslateUi(WeightWarningDialog);

        QMetaObject::connectSlotsByName(WeightWarningDialog);
    } // setupUi

    void retranslateUi(QWidget *WeightWarningDialog)
    {
        WeightWarningDialog->setWindowTitle(QApplication::translate("WeightWarningDialog", "Form", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("WeightWarningDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">WEIGHT WARNING</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        msgLabel->setText(QApplication::translate("WeightWarningDialog", "TOO MUCH WEIGHT IN SAFE DEPOSIT BOX", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WeightWarningDialog: public Ui_WeightWarningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEIGHTWARNINGDIALOG_H
