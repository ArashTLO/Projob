#ifndef COMMENT_H
#define COMMENT_H

#include <QMainWindow>

namespace Ui {
class comment;
}

class comment : public QMainWindow
{
    Q_OBJECT

public:
    explicit comment( QString nema, int id, QString type_post, int id_recieve, QWidget *parent = nullptr);
    ~comment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::comment *ui;
};

#endif // COMMENT_H
