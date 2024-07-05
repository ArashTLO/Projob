#ifndef MESSAGING_H
#define MESSAGING_H

#include <QMainWindow>

namespace Ui {
class messaging;
}

class messaging : public QMainWindow
{
    Q_OBJECT

public:
    explicit messaging(int number, QString type, QString text_message, QWidget *parent = nullptr);
    ~messaging();

private slots:

    void on_user_clicked(int sender, int receiver);

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::messaging *ui;
};

#endif // MESSAGING_H
