#include "createjob.h"
#include "ui_createjob.h"

createjob::createjob(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createjob)
{
    ui->setupUi(this);
}

createjob::~createjob()
{
    delete ui;
}
