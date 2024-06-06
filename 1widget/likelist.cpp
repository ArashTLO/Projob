#include "likelist.h"
#include "ui_likelist.h"

likelist::likelist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::likelist)
{
    ui->setupUi(this);
}

likelist::~likelist()
{
    delete ui;
}
