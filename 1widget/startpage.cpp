#include "startpage.h"
#include "ui_startpage.h"
#include "QMessageBox"
#include "loginpage.h"


startPage::startPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startPage)
{
    ui->setupUi(this);
    this->setFixedSize(918,553);
}

startPage::~startPage()
{
    delete ui;
}


void startPage::on_vorudButton_clicked()
{
    loginpage *w2 = new loginpage;
    w2->setWindowTitle("Login Page");
    w2->show();
}

