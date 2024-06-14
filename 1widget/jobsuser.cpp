#include "jobsuser.h"
#include "ui_jobsuser.h"
#include "home.h"
#include "me.h"
#include "messaging.h"
#include "mynetworkuser.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"

jobsuser::jobsuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jobsuser)
{

    ui->setupUi(this);
}

jobsuser::~jobsuser()
{
    delete ui;
}

void jobsuser::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(1);
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

