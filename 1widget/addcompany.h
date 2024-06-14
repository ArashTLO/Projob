#ifndef ADDCOMPANY_H
#define ADDCOMPANY_H

#include <QMainWindow>

namespace Ui {
class addcompany;
}

class addcompany : public QMainWindow
{
    Q_OBJECT

public:
    explicit addcompany(QWidget *parent = nullptr);
    ~addcompany();

private slots:
    void on_pushButton_select_photo_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::addcompany *ui;
};

#endif // ADDCOMPANY_H
