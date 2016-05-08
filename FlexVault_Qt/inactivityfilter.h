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
    explicit InactivityFilter()
    {
        timer = new QTimer(this);
        timer->setSingleShot(true);

        connect(timer, SIGNAL(timeout()), this, SLOT(showLogin()));
        timer->start(12000);
    }

    bool eventFilter(QObject *obj, QEvent *ev)
    {
      if(ev->type() == QEvent::KeyPress ||
         ev->type() == QEvent::MouseMove)
           resetTimer();

      return QObject::eventFilter(obj, ev);
    }

    void resetTimer()
    {
        timer->start(12000);
    }

public slots:
    void showLogin()
    {
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }

private:
QTimer *timer;
Login* login;
};

#endif // INACTIVITYFILTER
