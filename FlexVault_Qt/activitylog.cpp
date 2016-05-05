#include "activitylog.h"
#include "ui_activitylog.h"
#include "adminmainmenu.h"

ActivityLog::ActivityLog(QWidget *parent, QSqlDatabase* db) :
    QWidget(parent),
    ui(new Ui::ActivityLog)
{
    ui->setupUi(this);

    fv_db = db;

    read();

    //connect(ui->userListWidget->verticalScrollBar(), SIGNAL(&QAbstractSlider::valueChanged()),
    //        this, SLOT(syncronizeScrollBars()));

    if(ui->userListWidget->count() != 0)
    ui->userListWidget->takeItem(ui->userListWidget->count() - 1);
}

void ActivityLog::syncronizeScrollBars()
{
    ui->actionListWidget->verticalScrollBar()->setValue(ui->userListWidget->verticalScrollBar()->value());
}

ActivityLog::~ActivityLog()
{
    delete ui;
}

void ActivityLog::write(QString user, QString activity)
{
    QFile log("/home/stud/FV/FlexVault/log.txt");

    if(log.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&log);

        QDateTime time;

        stream << user << " " << activity << " " << time.currentDateTime().toString() << "\n";

        log.flush();
        log.close();

        qDebug() << "Activity written to log";
    }
}

void ActivityLog::read()
{
    QFile log("/home/stud/FV/FlexVault/log.txt");

    if(log.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&log);

        QString activity;
        QString time;
        int count = 0;

        do
        {
            stream >> activity;

            if(count == 0)
            ui->userListWidget->addItem(activity);

            if(count == 1)
            ui->actionListWidget->addItem(activity);

            if(count == 2)
            {
                for(int i = 0; i < 4; i++)
                {
                    stream >> activity;
                    time += " " + activity;
                }

                ui->timeListWidget->addItem(time);

                time = "";
            }

            count++;

            if(count >= 3)
                count = 0;

        }while(!activity.isNull());

        log.close();
    }
}

void ActivityLog::on_backButton_clicked()
{
    amm = new AdminMainMenu(0, fv_db);
    amm->show(); // change to showFullScreen() for BeagleBone
    this->close();
}
