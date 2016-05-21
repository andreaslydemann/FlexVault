#ifndef INACTIVITYFILTER
#define INACTIVITYFILTER

#include <QtCore/QCoreApplication>
#include <QTimer>
#include "login.h"

namespace Ui {
class InactivityFilter;
}

class InactivityFilter : public QObject
{
    Q_OBJECT

public:
    explicit InactivityFilter();
    bool eventFilter(QObject *obj, QEvent *ev);
    static void resetTimer();
    static void stopTimer();

private slots:
    static void showLogin();

private:
static QTimer *timer;
static bool timerStopped;
Login* login;
};

#endif // INACTIVITYFILTER
