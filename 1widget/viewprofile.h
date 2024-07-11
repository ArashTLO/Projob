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
    explicit viewprofile(int number , QString type, QWidget *parent = nullptr);
    ~viewprofile();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::viewprofile *ui;
};

#endif // VIEWPROFILE_H
