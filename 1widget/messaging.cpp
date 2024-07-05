#include "messaging.h"
#include "ui_messaging.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "mynetworkuser.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "QMessageBox"

int adad_M;
QString Type_M;
messaging::messaging(int number, QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::messaging)
{
    ui->setupUi(this);
}

messaging::~messaging()
{
    delete ui;
}

void messaging::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_M,Type_M);
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser(adad_M,Type_M);
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_M,Type_M);
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_5_clicked()
{
    if(Type_M == "P"){
    mynetworkuser *w3 = new mynetworkuser(adad_M, Type_M);
    this->close();
    w3->show();
    }
    if(Type_M == "C"){
        QMessageBox::information(this,"Login","Only individuals can enter this window and companies cannot enter this window.");
    }
}


void messaging::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(adad_M,Type_M);
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany(adad_M, Type_M);
    this->close();
    w3->show();
}

