#include "me.h"
#include "ui_me.h"
#include "home.h"
#include "jobsuser.h"
#include "jobscompany.h"
#include "messaging.h"
#include "mynetworkuser.h"
#include "mynetworkcompany.h"
#include "addcompany.h"
me::me(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::me)
{
    ui->setupUi(this);
}

me::~me()
{
    delete ui;
}

void me::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
    this->close();
    w3->show();
}


void me::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}


void me::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser(0);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(1);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void me::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void me::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}


void me::on_pushButton_clicked()
{
    addcompany *w3 = new addcompany;
    this->close();
    w3->show();
}

