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
    explicit likelist(int id, QString post_type,int account_id_liked,QWidget *parent = nullptr);
    ~likelist();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::likelist *ui;
};

#endif // LIKELIST_H
