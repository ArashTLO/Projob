#include "viewprofile.h"
#include "ui_viewprofile.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include "mynetworkuser.h"

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


void viewprofile::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"c");
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser;
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(0);
    this->close();
    w3->show();
}




void viewprofile::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}


void viewprofile::on_pushButton_3_clicked()
{
    home *w3 = new home(0,"c");
    this->close();
    w3->show();
}

