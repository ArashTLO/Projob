#ifndef ME_H
#define ME_H

#include <QMainWindow>

namespace Ui {
class me;
}

class me : public QMainWindow
{
    Q_OBJECT

public:
    explicit me(int number,QString type,QWidget *parent = nullptr);
    ~me();

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
    Ui::me *ui;
};

#endif // ME_H
