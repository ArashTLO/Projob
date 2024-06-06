#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>

namespace Ui {
class loginpage;
}

class loginpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginpage(QWidget *parent = nullptr);
    ~loginpage();

    int getNumber() const;

signals:

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_generate_clicked();

    void on_pushButton_enter_clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

private:

    Ui::loginpage *ui;
};


#endif // LOGINPAGE_H
