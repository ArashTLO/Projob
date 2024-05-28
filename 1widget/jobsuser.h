#ifndef JOBSUSER_H
#define JOBSUSER_H

#include <QMainWindow>

namespace Ui {
class jobsuser;
}

class jobsuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit jobsuser(QWidget *parent = nullptr);
    ~jobsuser();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_6_clicked();

private:
    Ui::jobsuser *ui;
};

#endif // JOBSUSER_H
