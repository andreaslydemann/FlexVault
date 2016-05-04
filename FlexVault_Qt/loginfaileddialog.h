#ifndef LOGINFAILEDDIALOG_H
#define LOGINFAILEDDIALOG_H

#include <QDialog>

namespace Ui {
class LoginFailedDialog;
}

class LoginFailedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginFailedDialog(QWidget *parent = 0);
    ~LoginFailedDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::LoginFailedDialog *ui;
};

#endif // LOGINFAILEDDIALOG_H
