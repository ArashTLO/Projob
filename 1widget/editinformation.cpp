#include "editinformation.h"
#include "ui_editinformation.h"

editinformation::editinformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editinformation)
{
    ui->setupUi(this);
}

editinformation::~editinformation()
{
    delete ui;
}
