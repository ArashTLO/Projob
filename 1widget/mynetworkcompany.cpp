#include "mynetworkcompany.h"
#include "ui_mynetworkcompany.h"
#include "mynetworkuser.h"
#include "ui_mynetworkuser.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "jobscompany.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include <QDebug>
#include "QMessageBox"

int adad_m_c;
QString Type_m_c;
mynetworkcompany::mynetworkcompany(int number,QString type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mynetworkcompany)
{
    ui->setupUi(this);
    adad_m_c = number;
    Type_m_c = type;
    ///////////////

    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();
}

mynetworkcompany::~mynetworkcompany()
{
    delete ui;
}

void mynetworkcompany::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_m_c,Type_m_c);
    this->close();
    w3->show();
}

void mynetworkcompany::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_m_c,"C");
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser(adad_m_c,Type_m_c);
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(adad_m_c,Type_m_c);
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_m_c,Type_m_c,nullptr);
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_5_clicked()
{
        QMessageBox::information(this,"Login","Only individuals can enter this window and companies cannot enter this window.");
}


void mynetworkcompany::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany(adad_m_c, Type_m_c);
    this->close();
    w3->show();
}

