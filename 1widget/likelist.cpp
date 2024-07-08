#include "likelist.h"
#include "ui_likelist.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QLineEdit"
#include "QGroupBox"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "content.h"

likelist::likelist(int id,QString post_type,int account_id_liked,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::likelist)
{
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    if(post_type == "P"){
        QSqlQuery p_info;
        p_info.prepare("SELECT posts FROM verificationpage WHERE account_id = :account_id_liked");
        p_info.bindValue(":account_id_liked", account_id_liked);
        p_info.exec();

        while(p_info.next()){

        QString postsJsonString = p_info.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
        QJsonArray postsArray = doc.array();

        foreach (const QJsonValue &postValue,postsArray){

            QJsonObject postObject = postValue.toObject();

            if(id == postObject["post_id"].toInt()){

                QString postImageb64 = postObject["post_image"].toString();
                QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());
                QPixmap image;
                image.loadFromData(Image_Data);
                ui->label->setPixmap(image.scaled(476,180));

                ui->textEdit_2->setText(postObject["post_text"].toString());
            }
        }
        }
    }
    else if(post_type == "C"){
        QSqlQuery p_info;
        p_info.prepare("SELECT posts FROM CompanyInformation WHERE id_C = :account_id_liked");
        p_info.bindValue(":account_id_liked", account_id_liked);
        p_info.exec();

        while(p_info.next()){

        QString postsJsonString = p_info.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
        QJsonArray postsArray = doc.array();

        foreach (const QJsonValue &postValue,postsArray){

            QJsonObject postObject = postValue.toObject();

            if(id == postObject["post_id"].toInt()){

                QString postImageb64 = postObject["post_image"].toString();
                QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());
                QPixmap image;
                image.loadFromData(Image_Data);
                ui->label->setPixmap(image.scaled(476,180));

                ui->textEdit_2->setText(postObject["post_text"].toString());
            }
        }
        }
    }


    int frameHeight = 51;
    int currentY = 9;

    ui->frame_2->setGeometry(10,10,200,frameHeight);
    ui->frame_2->setStyleSheet("background-color: rgb(255,255,255);");

    QSqlQuery q;
    q.prepare("SELECT username FROM postLike WHERE post_id = :post_id AND post_type = :post_type AND liked_account_id = :liked_account_id");
    q.bindValue(":post_id", id);
    q.bindValue(":post_type", post_type);
    q.bindValue(":liked_account_id", account_id_liked);
    q.exec();
    while(q.next()){
        QFont font("Nirmala", 10, QFont::Light);
        ui->frame_2->setMinimumHeight(frameHeight);
        QString username = q.value(0).toString();

        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(5,currentY,190,43);

        QLineEdit *namelabel = new QLineEdit(username,groupBox);
        namelabel->setGeometry(0,0,190,43);
        namelabel->setStyleSheet("padding:9px;background-color:#fdfedb;border-radius:1px;border-bottom:2px solid rgb(181, 56, 75);");
        namelabel->setFont(font);

        groupBox->show();
        frameHeight += 43;
        currentY += 43;
    }
}

likelist::~likelist()
{
    delete ui;
}

void likelist::on_pushButton_3_clicked()
{
    this->close();
}

