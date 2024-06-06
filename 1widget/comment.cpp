#include "comment.h"
#include "ui_comment.h"

comment::comment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::comment)
{
    ui->setupUi(this);
}

comment::~comment()
{
    delete ui;
}
