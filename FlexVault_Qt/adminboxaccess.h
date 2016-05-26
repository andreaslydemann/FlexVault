#ifndef ADMINBOXACCESS_H
#define ADMINBOXACCESS_H

#include <QWidget>

class AdminMainMenu;
class BoxRetrieval;
class SPIInterface;

namespace Ui {
class AdminBoxAccess;
}

class AdminBoxAccess : public QWidget
{
    Q_OBJECT

public:
    explicit AdminBoxAccess(QWidget *parent = 0);
    ~AdminBoxAccess();

private slots:
    void on_retrieveButton_clicked();
    void on_backButton_clicked();

private:
    Ui::AdminBoxAccess *ui;
    AdminMainMenu* amm;
    BoxRetrieval* boxret;
    SPIInterface* spi;
};

#endif // ADMINBOXACCESS_H
