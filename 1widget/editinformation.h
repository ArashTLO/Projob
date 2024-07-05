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
    explicit editinformation(QWidget *parent = nullptr);
    ~editinformation();

private:
    Ui::editinformation *ui;
};

#endif // EDITINFORMATION_H
