#include "viewprofile.h"
#include "ui_viewprofile.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include "mynetworkuser.h"
#include "QTabWidget"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"
#include "QGroupBox"
#include "QByteArray"
#include "QTextEdit"
#include "QVariant"
#include "QMessageBox"

int adad_v;
QString Type_v;
viewprofile::viewprofile(int number, QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewprofile)
{
    ui->setupUi(this);

    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    adad_v = number;
    Type_v = type;

    int frameHeight = 210;
    int currentY = 5;

    if(type == "P"){
        ui->tabWidget->setCurrentIndex(0);
        QSqlQuery p_info;
        p_info.prepare("SELECT frstname,lastname,email,image,posts,skills FROM verificationpage WHERE account_id = :number");
        p_info.bindValue(":number" , number);
        p_info.exec();
        p_info.next();

        ui->label_fname->setText(p_info.value(0).toString());
        ui->label_lname->setText(p_info.value(1).toString());
        ui->label_email_p->setText(p_info.value(2).toString());
        ui->label_skills->setText(p_info.value(5).toString());

        QByteArray imageData_p = p_info.value(3).toByteArray();
        QPixmap image_profile_p;
        image_profile_p.loadFromData(imageData_p);
        ui->label_image_p->setPixmap(image_profile_p.scaled(476,180));

        QString postsJsonString = p_info.value(4).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
        QJsonArray postsArray = doc.array();

        foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_6->setMinimumHeight(frameHeight);
        QGroupBox *groupBox = new QGroupBox(ui->frame_6);
        groupBox->setGeometry(5,currentY,505,200);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);border-radius: 8px;");

        QLabel *imageLabel = new QLabel(groupBox);
        QPixmap image;
        image.loadFromData(Image_Data);
        imageLabel->setPixmap(image.scaled(476,180));
        imageLabel->setGeometry(320,20,160,160);
        imageLabel->setScaledContents(true);

        QTextEdit *tex = new QTextEdit(groupBox);
        tex->setText(postObject["post_text"].toString());
        tex->setStyleSheet("background-color:rgb(238,238,238);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
        tex->setGeometry(15,15,280,170);
        tex->setReadOnly(true);

        groupBox->show();
        frameHeight += 205;
        currentY += 205;
        }
    }
    else if(type == "C"){
        ui->tabWidget->setCurrentIndex(1);
        QSqlQuery c_info;
        c_info.prepare("SELECT name,phoneNumber,email,image_C,posts FROM CompanyInformation WHERE id_C = :number");
        c_info.bindValue(":number" , number);
        c_info.exec();
        c_info.next();

        ui->label_name_c->setText(c_info.value(0).toString());
        ui->label_phonenumber_c->setText(c_info.value(1).toString());
        ui->label_email_c->setText(c_info.value(2).toString());
        QByteArray imageData = c_info.value(3).toByteArray();
        QPixmap image_profile;
        image_profile.loadFromData(imageData);
        ui->label_image_c->setPixmap(image_profile.scaled(476,180));

        QString postsJsonString = c_info.value(4).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
        QJsonArray postsArray = doc.array();

        foreach (const QJsonValue &postValue,postsArray){

            QJsonObject postObject = postValue.toObject();
            QString postImageb64 = postObject["post_image"].toString();
            QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

            ui->frame_7->setMinimumHeight(frameHeight);
            QGroupBox *groupBox = new QGroupBox(ui->frame_7);
            groupBox->setGeometry(5,currentY,505,200);
            groupBox->setStyleSheet("background-color:rgb(255, 255, 255);border-radius: 8px;");

            QLabel *imageLabel = new QLabel(groupBox);
            QPixmap image;
            image.loadFromData(Image_Data);
            imageLabel->setPixmap(image.scaled(476,180));
            imageLabel->setGeometry(320,20,160,160);
            imageLabel->setScaledContents(true);

            QTextEdit *tex = new QTextEdit(groupBox);
            tex->setText(postObject["post_text"].toString());
            tex->setStyleSheet("background-color:rgb(238,238,238);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
            tex->setGeometry(15,15,280,170);
            tex->setReadOnly(true);

            groupBox->show();
            frameHeight += 205;
            currentY += 205;
        }
    }
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
    me *w3 = new me(0,"");
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_3_clicked()
{
    if (Type_v == "P"){

        jobsuser *w3 = new jobsuser(adad_v,Type_v);
        this->close();
        w3->show();

    }
    else if (Type_v == "C") {
        QMessageBox::warning(this, "home", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
}


void viewprofile::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(adad_v,Type_v);
    this->close();
    w3->show();
}




void viewprofile::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_v, Type_v,nullptr);
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser(adad_v,Type_v);
    this->close();
    w3->show();
}


void viewprofile::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany(adad_v, Type_v);
    this->close();
    w3->show();
}


void viewprofile::on_pushButton_3_clicked()
{
    this->close();
}


void viewprofile::on_pushButton_4_clicked()
{
    this->close();
}

