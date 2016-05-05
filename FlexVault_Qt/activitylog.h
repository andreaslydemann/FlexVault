#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <QWidget>
#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QtCore>
#include <QDebug>
#include <QDateTime>
#include <QAbstractSlider>
#include <QScrollBar>

class AdminMainMenu;

namespace Ui {
class ActivityLog;
}

class ActivityLog : public QWidget
{
    Q_OBJECT

public:
    explicit ActivityLog(QWidget *parent = 0, QSqlDatabase* db = NULL);
    ~ActivityLog();
    void write(QString, QString);
    void read();

private slots:
    void on_backButton_clicked();
    void syncronizeScrollBars();

private:
    Ui::ActivityLog *ui;
    QSqlDatabase * fv_db;
    AdminMainMenu* amm;
};

#endif // ACTIVITYLOG_H
