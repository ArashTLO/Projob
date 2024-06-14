#ifndef POST_H
#define POST_H

#include <QMainWindow>
#include <loginpage.h>
#include <QLabel>

namespace Ui {
class post;
}

class post : public QMainWindow
{
    Q_OBJECT

public:

    explicit post(int number,QString type,QWidget *parent = nullptr);
    ~post();

public slots:

    void on_pushButton_clicked();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QLineEdit *lineEdit_3;
    QLabel *numberLabel;
    Ui::post *ui;
};

#endif // POST_H
