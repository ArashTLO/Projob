#ifndef LIKELIST_H
#define LIKELIST_H

#include <QMainWindow>

namespace Ui {
class likelist;
}

class likelist : public QMainWindow
{
    Q_OBJECT

public:
    explicit likelist(QWidget *parent = nullptr);
    ~likelist();

private:
    Ui::likelist *ui;
};

#endif // LIKELIST_H
