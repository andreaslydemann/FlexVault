#include "inactivityfilter.h"

QTimer* InactivityFilter::timer = new QTimer;
bool InactivityFilter::timerStopped = false;

InactivityFilter::InactivityFilter()
{
    timer->setSingleShot(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(showLogin()));
    resetTimer();
}

bool InactivityFilter::eventFilter(QObject *obj, QEvent *ev)
{
  if(((ev->type() == QEvent::KeyPress ||
     ev->type() == QEvent::MouseMove)) && timerStopped == false)
       resetTimer();

  return QObject::eventFilter(obj, ev);
}

void InactivityFilter::resetTimer()
{
    timerStopped = false;
    timer->start(120000);
}

void InactivityFilter::stopTimer()
{
    timerStopped = true;
    timer->stop();
}

void InactivityFilter::showLogin()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
