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
    explicit home(int number,QString type,QWidget *parent = nullptr);
    ~home();

private slots:
    void on_send_Clicked(int adad_h,QString Type_h, QString text_message);

    void onLikeClicked(QString name,int post_id,QString post_type, int liked_account_id);

    void on_likelistshow_clicked(int post_id ,QString type_post,int account_id);

    void on_comment_Clicked(QString name,int id);

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
