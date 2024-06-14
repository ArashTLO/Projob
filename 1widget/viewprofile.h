#ifndef VIEWPROFILE_H
#define VIEWPROFILE_H

#include <QMainWindow>

namespace Ui {
class viewprofile;
}

class viewprofile : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewprofile(QWidget *parent = nullptr);
    ~viewprofile();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::viewprofile *ui;
};

#endif // VIEWPROFILE_H
