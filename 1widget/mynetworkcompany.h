#ifndef MYNETWORKCOMPANY_H
#define MYNETWORKCOMPANY_H

#include <QMainWindow>

namespace Ui {
class mynetworkcompany;
}

class mynetworkcompany : public QMainWindow
{
    Q_OBJECT

public:
    explicit mynetworkcompany( int number, QString type, QWidget *parent = nullptr);
    ~mynetworkcompany();

private slots:

    void searchInDatabase();

    int show_follower(int id_followeng);

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

private:
    Ui::mynetworkcompany *ui;
};

#endif // MYNETWORKCOMPANY_H
