#include "post.h"
#include "ui_post.h"

post::post(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::post)
{
    ui->setupUi(this);
}

post::~post()
{
    delete ui;
}
