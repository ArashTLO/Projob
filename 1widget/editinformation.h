#ifndef EDITINFORMATION_H
#define EDITINFORMATION_H

#include <QMainWindow>

namespace Ui {
class editinformation;
}

class editinformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit editinformation(int number, QString type,QWidget *parent = nullptr);
    ~editinformation();

private slots:
    void on_pushButton_select_photo_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_back_2_clicked();

    void on_pushButton_select_photo_2_clicked();

    void on_pushButton_back_3_clicked();

    void on_pushButton_change_user_2_clicked();

private:
    Ui::editinformation *ui;
};

#endif // EDITINFORMATION_H
