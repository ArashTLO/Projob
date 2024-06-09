#ifndef VERIFICATIONPAGE_H
#define VERIFICATIONPAGE_H

#include <QMainWindow>

namespace Ui {
class verificationpage;
}

class verificationpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit verificationpage(QWidget *parent = nullptr);
    ~verificationpage();

private slots:

    void on_pushButton_back_clicked();

    void on_pushButton_select_photo_clicked();

private:
    Ui::verificationpage *ui;
};

#endif // VERIFICATIONPAGE_H
