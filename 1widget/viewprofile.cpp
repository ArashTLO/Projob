#include "viewprofile.h"
#include "ui_viewprofile.h"

viewprofile::viewprofile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewprofile)
{
    ui->setupUi(this);
}

viewprofile::~viewprofile()
{
    delete ui;
}
