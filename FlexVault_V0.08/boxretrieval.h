#ifndef BOXRETRIEVAL_H
#define BOXRETRIEVAL_H

#include <QWidget>

namespace Ui {
class BoxRetrieval;
}

class BoxRetrieval : public QWidget
{
    Q_OBJECT

public:
    explicit BoxRetrieval(QWidget *parent = 0);
    ~BoxRetrieval();

private:
    Ui::BoxRetrieval *ui;
};

#endif // BOXRETRIEVAL_H
