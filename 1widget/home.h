#ifndef HOME_H
#define HOME_H

#include <QMainWindow>

namespace Ui {
class home;
}

class home : public QMainWindow
{
    Q_OBJECT

public:
    explicit home(int number,QWidget *parent = nullptr);
    ~home();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
