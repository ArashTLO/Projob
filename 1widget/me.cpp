#include "me.h"
#include "ui_me.h"
#include "home.h"
#include "jobsuser.h"
#include "jobscompany.h"
#include "messaging.h"
#include "mynetworkuser.h"
#include "mynetworkcompany.h"
#include "addcompany.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "editinformation.h"
#include "QMessageBox"

QString Type_m;
int adad_m;
me::me(int number,QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::me)
{
    ui->setupUi(this);
    Type_m = type;
    adad_m = number;

    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    QSqlQuery q;
    if(type == "P"){
        //q.prepare("SELECT frstname,lastname,skills,imsge FROM verificationpage WHERE account_id = :number");
        q.prepare("SELECT frstname,lastname,nationality,skills,image,date_birth,start_year,end_year,school FROM verificationpage WHERE account_id = :number");
        q.bindValue(":number", number);
        q.exec();
        q.next();

        qDebug() << number;
        ui->label_fname->setText(q.value(0).toString());
        ui->label_lname->setText(q.value(1).toString());
        ui->label_lname_3->setText(q.value(3).toString());
        QByteArray imageData = q.value(4).toByteArray();
        QPixmap image;
        image.loadFromData(imageData);
        ui->label_2->setPixmap(image.scaled(476,180));

        QString Biography = "%1 %2 is a person from %3 , born in %4 and during the years %5 to %6, was trained in %7 school.";
        Biography = Biography.arg(q.value(0).toString()).arg(q.value(1).toString()).arg(q.value(2).toString()).arg(q.value(5).toString()).arg(q.value(6).toString()).arg(q.value(7).toString()).arg(q.value(8).toString());
        ui->textEdit->setPlainText(Biography);

    }
}

me::~me()
{
    delete ui;
}

void me::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_m,Type_m);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_m,Type_m);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_3_clicked()
{
    if (Type_m == "P"){

        jobsuser *w3 = new jobsuser(adad_m,Type_m);
        this->close();
        w3->show();

    }
    else if (Type_m == "C") {
        QMessageBox::warning(this, "home", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
}


void me::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(adad_m,Type_m);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_m,Type_m,nullptr);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser(adad_m,Type_m);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany(adad_m, Type_m);
    this->close();
    w3->show();
}


void me::on_pushButton_clicked()
{
    addcompany *w3 = new addcompany(adad_m);
    this->close();
    w3->show();
}


void me::on_pushButton_2_clicked()
{
    editinformation *w = new editinformation(adad_m,Type_m);
    this->close();
    w->show();
}

