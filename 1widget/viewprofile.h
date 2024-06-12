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

private:
    Ui::viewprofile *ui;
};

#endif // VIEWPROFILE_H
