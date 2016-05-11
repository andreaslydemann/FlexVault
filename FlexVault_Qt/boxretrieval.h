#ifndef BOXRETRIEVAL_H
#define BOXRETRIEVAL_H

#include <QWidget>

class UserPrivileges;
class AdminBoxAccess;
class UserBoxAccess;
class ActivityLog;
class WeightWarningDialog;
class SPIInterface;

namespace Ui {
class BoxRetrieval;
}

class BoxRetrieval : public QWidget
{
    Q_OBJECT

public:
    explicit BoxRetrieval(QWidget *parent = 0, QString = NULL, QString = NULL, QString = NULL);
    ~BoxRetrieval();

private slots:
    void on_returnButton_clicked();

private:
    Ui::BoxRetrieval *ui;
    AdminBoxAccess* aba;
    UserBoxAccess* uba;
    UserPrivileges* upriv;
    ActivityLog* log;
    SPIInterface* spi;
    QString prevPage;
    QString user;
    QString box;
    WeightWarningDialog* wwd;
};

#endif // BOXRETRIEVAL_H
