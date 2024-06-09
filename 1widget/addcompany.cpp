#include "addcompany.h"
#include "ui_addcompany.h"

addcompany::addcompany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addcompany)
{
    ui->setupUi(this);
}

addcompany::~addcompany()
{
    delete ui;
}
