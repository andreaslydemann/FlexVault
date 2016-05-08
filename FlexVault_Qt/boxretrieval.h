#ifndef BOXRETRIEVAL_H
#define BOXRETRIEVAL_H

#include <QWidget>

class UserPrivileges;
class AdminBoxAccess;
class UserBoxAccess;

namespace Ui {
class BoxRetrieval;
}

class BoxRetrieval : public QWidget
{
    Q_OBJECT

public:
    explicit BoxRetrieval(QWidget *parent = 0, QString = NULL, QString = NULL);
    ~BoxRetrieval();

private slots:
    void on_returnButton_clicked();

private:
    Ui::BoxRetrieval *ui;
    AdminBoxAccess* aba;
    UserBoxAccess* uba;
    UserPrivileges* upriv;
    QString prevPage;
    QString user;
};

#endif // BOXRETRIEVAL_H
