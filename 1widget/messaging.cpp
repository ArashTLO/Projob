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
messaging::messaging(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::messaging)
{
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
       database = QSqlDatabase::addDatabase("QSQLITE");
       database.setDatabaseName("d:\\DB_project.db");
       database.open();
    if (!database.open()){
        qDebug() <<"Error connecting to database";

        QMessageBox::warning(nullptr, "Database Error", "Could not open database.");
    }

    QSqlQuery query;
    query.prepare("SELECT post_video FROM post WHERE post_id = :postId");
    query.bindValue(":postId", 9);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
                QMessageBox::warning(this, "Database Error", "Error executing query");
        return;
    }

    if (query.next()) {
        QByteArray videoData = query.value(0).toByteArray();

        QImage image;
        image.loadFromData(videoData); // Load the image data


        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->label->show();

    } else {
        qDebug() << "No video found for post_id=9";
        QMessageBox::warning(this, "Database Error", "No video found for post_id=9");
    }

    database.close();
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
    jobsuser *w3 = new jobsuser(0);
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(1);
    this->close();
    w3->show();
}


void messaging::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

