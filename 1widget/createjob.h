#ifndef CREATEJOB_H
#define CREATEJOB_H

#include <QMainWindow>

namespace Ui {
class createjob;
}

class createjob : public QMainWindow
{
    Q_OBJECT

public:
    explicit createjob(QWidget *parent = nullptr);
    ~createjob();

private:
    Ui::createjob *ui;
};

#endif // CREATEJOB_H
