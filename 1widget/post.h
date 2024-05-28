#ifndef POST_H
#define POST_H

#include <QMainWindow>

namespace Ui {
class post;
}

class post : public QMainWindow
{
    Q_OBJECT

public:
    explicit post(QWidget *parent = nullptr);
    ~post();

private:
    Ui::post *ui;
};

#endif // POST_H
