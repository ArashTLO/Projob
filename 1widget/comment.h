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
    explicit comment(QWidget *parent = nullptr);
    ~comment();

private:
    Ui::comment *ui;
};

#endif // COMMENT_H
