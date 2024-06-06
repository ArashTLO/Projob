#ifndef MYNETWORKUSER_H
#define MYNETWORKUSER_H

#include <QMainWindow>

namespace Ui {
class mynetworkuser;
}

class mynetworkuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit mynetworkuser(QWidget *parent = nullptr);
    ~mynetworkuser();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_6_clicked();

private:
    Ui::mynetworkuser *ui;
};

#endif // MYNETWORKUSER_H
