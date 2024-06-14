#ifndef JOBSCOMPANY_H
#define JOBSCOMPANY_H

#include <QMainWindow>

namespace Ui {
class jobscompany;
}

class jobscompany : public QMainWindow
{
    Q_OBJECT

public:
    explicit jobscompany(int number,QWidget *parent = nullptr);
    ~jobscompany();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::jobscompany *ui;
};

#endif // JOBSCOMPANY_H
