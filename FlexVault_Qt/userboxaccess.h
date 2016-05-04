#ifndef USERBOXACCESS_H
#define USERBOXACCESS_H

#include <QWidget>

namespace Ui {
class UserBoxAccess;
}

class UserBoxAccess : public QWidget
{
    Q_OBJECT

public:
    explicit UserBoxAccess(QWidget *parent = 0);
    ~UserBoxAccess();

private:
    Ui::UserBoxAccess *ui;
};

#endif // USERBOXACCESS_H
