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
#include "QDateTime"
#include "QVariantList"
#include "QListWidgetItem"

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


    connect(ui->lineEdit, &QLineEdit::textChanged, this, &me::searchInDatabase);

    QDateTime dateANDtime = QDateTime::currentDateTime();
    qDebug() << "Date Time : " << dateANDtime.toString();

    QDate date = dateANDtime.date();
    qDebug() << "Date : " << date.toString();

    QSqlQuery q,p;
    if(type == "C"){
        p.prepare("SELECT id_user FROM CompanyInformation WHERE id_C = :number");
        p.bindValue(":number", number);
        p.exec();
        p.next();
    }

        q.prepare("SELECT frstname,lastname,nationality,skills,image,date_birth,start_year,end_year,school FROM verificationpage WHERE account_id = :number");
        if(type == "P"){
            ui->label_4->setText("User information : ");
            q.bindValue(":number", number);
        }
        else if(type == "C"){
            ui->label_4->setText("Company manufacturer information : ");
            q.bindValue(":number", p.value(0).toInt());
        }
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

me::~me()
{
    delete ui;
}

void me::searchInDatabase()
{
    QString searchUsername = ui->lineEdit->text();

    if (searchUsername.isEmpty()) {
        ui->listWidget->clear();
        ui->listWidget->setVisible(false);
        return;
    }

    else if(!searchUsername.isEmpty()){
        ui->listWidget->setVisible(true);
    }
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    QSqlQuery query;
    query.prepare("SELECT username FROM verificationpage WHERE username LIKE :search");
    query.bindValue(":search", "%" + searchUsername + "%");

    if (!query.exec()) {
        qDebug() << "Query failed";
        return;
    }
    ui->listWidget->clear();

    ui->listWidget->setMinimumHeight(0);

    while (query.next()) {
        QString username = query.value(0).toString();
        QListWidgetItem *item = new QListWidgetItem(username);
        ui->listWidget->addItem(item);

        ui->listWidget->setMinimumHeight(qMax(ui->listWidget->minimumHeight(), ui->listWidget->sizeHintForColumn(0) + 20));
    }
}

void me::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_m,Type_m,10);
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
        QMessageBox::warning(this, "Me", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
}


void me::on_commandLinkButton_7_clicked()
{
    if(Type_m == "P"){
        QMessageBox::warning(this, "Me" , "Only companies can enter the desired window.");
    }
    else if(Type_m == "C"){
    jobscompany *w3 = new jobscompany(adad_m,Type_m);
    this->close();
    w3->show();
    }
}


void me::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_m,Type_m,nullptr);
    this->close();
    w3->show();
}


void me::on_commandLinkButton_5_clicked()
{
    if(Type_m == "P"){
    mynetworkuser *w3 = new mynetworkuser(adad_m,Type_m);
    this->close();
    w3->show();
    }
    else if (Type_m == "C")
         QMessageBox::warning(this, "Me", "Only persons can enter the desired window.");
}


void me::on_commandLinkButton_6_clicked()
{
    if(Type_m== "P"){
        QMessageBox::warning(this, "Me" , "Only companies can enter the desired window.");
    }
    else if(Type_m == "C"){
        mynetworkcompany *w3 = new mynetworkcompany(adad_m, Type_m);
        this->close();
        w3->show();
    }
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

