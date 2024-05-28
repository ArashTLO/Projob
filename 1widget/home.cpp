 #include "home.h"
#include "ui_home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "mynetworkuser.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"

home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

}

home::~home()
{
    delete ui;
}

void home::on_commandLinkButton_clicked()
{
        home *w3 = new home;
        this->close();
        w3->show();
}


void home::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}


void home::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser;
    this->close();
    w3->show();
}


void home::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void home::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}
void home::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany;
    this->close();
    w3->show();
}
void home::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

