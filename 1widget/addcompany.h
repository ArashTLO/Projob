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

private:
    Ui::addcompany *ui;
};

#endif // ADDCOMPANY_H
