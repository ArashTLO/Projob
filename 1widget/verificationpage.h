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
    void on_pushButton_clicked();

    void on_lineEdit_fname_textChanged(const QString &arg1);

private:
    Ui::verificationpage *ui;
};

#endif // VERIFICATIONPAGE_H
