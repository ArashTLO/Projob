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
    explicit createjob(int number,QString type,QWidget *parent = nullptr);
    ~createjob();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::createjob *ui;
};

#endif // CREATEJOB_H
