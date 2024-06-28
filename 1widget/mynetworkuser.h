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
    explicit mynetworkuser(int number,QString type,QWidget *parent = nullptr);
    ~mynetworkuser();

private slots:

    void on_viewProfile_user_clicked(int applicant);

    void on_viewProfile_company_clicked(int applicant);

    void on_Reject_clicked(int number,QString type_receiver,int applicant);

    void on_Reject_user_clicked(int number,QString type_receiver,int applicant);

    void on_Accept_clicked(int number,QString type_receiver,int applicant,QString type_Applicant);

    void on_Connect_Company_clicked(int number,int receiver_C);

    void on_Connect_clicked(int applicant, int receiver);

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
