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
    explicit messaging(QWidget *parent = nullptr);
    ~messaging();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_6_clicked();

private:
    Ui::messaging *ui;
};

#endif // MESSAGING_H
