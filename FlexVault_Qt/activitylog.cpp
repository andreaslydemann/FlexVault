#include "activitylog.h"
#include "ui_activitylog.h"
#include "adminmainmenu.h"

ActivityLog::ActivityLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActivityLog)
{
    ui->setupUi(this);

    read();

    // syncronize scroll bars
    connect(ui->userListWidget->verticalScrollBar(), SIGNAL(valueChanged(int)),
            ui->actionListWidget->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->userListWidget->verticalScrollBar(), SIGNAL(valueChanged(int)),
            ui->timeListWidget->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->actionListWidget->verticalScrollBar(), SIGNAL(valueChanged(int)),
            ui->userListWidget->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->actionListWidget->verticalScrollBar(), SIGNAL(valueChanged(int)),
            ui->timeListWidget->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->timeListWidget->verticalScrollBar(), SIGNAL(valueChanged(int)),
            ui->userListWidget->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->timeListWidget->verticalScrollBar(), SIGNAL(valueChanged(int)),
            ui->actionListWidget->verticalScrollBar(), SLOT(setValue(int)));

    if(ui->userListWidget->count() != 0)
    ui->userListWidget->takeItem(ui->userListWidget->count() - 1);
}

ActivityLog::~ActivityLog()
{
    delete ui;
}

void ActivityLog::write(QString user, QString activity)
{
    QFile log("/home/stud/FV/FlexVault/FlexVault_Qt/log.txt");
    //QFile log("/home/root/log.txt");

    if(log.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&log);

        QDateTime time;

        stream << user << " " << activity << " " << time.currentDateTime().toString() << "\n";

        log.flush();
        log.close();
    }
}

void ActivityLog::read()
{
    QFile log("/home/stud/FV/FlexVault/FlexVault_Qt/log.txt");
    //QFile log("/home/root/log.txt");

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
    amm = new AdminMainMenu();
    amm->showFullScreen();
    this->close();
}
