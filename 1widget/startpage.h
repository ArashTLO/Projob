#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class startPage; }
QT_END_NAMESPACE

class startPage : public QMainWindow
{
    Q_OBJECT

public:
    startPage(QWidget *parent = nullptr);
    ~startPage();

private slots:
    void on_vorudButton_clicked();

private:
    Ui::startPage *ui;
};
#endif // STARTPAGE_H
