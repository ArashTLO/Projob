#include "comment.h"
#include "ui_comment.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QLineEdit"
#include "QGroupBox"
#include "QTextEdit"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "QMessageBox"
#include "content.h"

QString name_User,type_Recieve;
int id_Post,id_Recieve;
comment::comment( QString name_user, int id_post, QString type_post, int id_recieve, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::comment)
{
    ui->setupUi(this);
    name_User = name_user;
    id_Post = id_post;
    id_Recieve = id_recieve;
    type_Recieve = type_post;
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    if(type_post == "P"){
        QSqlQuery p_info;
        p_info.prepare("SELECT posts FROM verificationpage WHERE account_id = :account_id_liked");
        p_info.bindValue(":account_id_liked", id_recieve);
        p_info.exec();

        while(p_info.next()){

        QString postsJsonString = p_info.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
        QJsonArray postsArray = doc.array();

        foreach (const QJsonValue &postValue,postsArray){

            QJsonObject postObject = postValue.toObject();

            if(id_post == postObject["post_id"].toInt()){

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
    else if(type_post == "C"){
        QSqlQuery p_info;
        p_info.prepare("SELECT posts FROM CompanyInformation WHERE id_C = :account_id_liked");
        p_info.bindValue(":account_id_liked", id_recieve);
        p_info.exec();

        while(p_info.next()){

        QString postsJsonString = p_info.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
        QJsonArray postsArray = doc.array();

        foreach (const QJsonValue &postValue,postsArray){

            QJsonObject postObject = postValue.toObject();

            if(id_post == postObject["post_id"].toInt()){

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

    int frameHeight = 265;
    int currentY = 9;

    ui->frame_2->setGeometry(10,10,200,frameHeight);
    ui->frame_2->setStyleSheet("background-color: rgb(192, 221, 190);");

    QSqlQuery q;
    q.prepare("SELECT username,textcomment FROM postComment WHERE post_id = :post_id AND id_recieve = :id_recieve AND type_recieve = :type_recieve");
    q.bindValue(":id_recieve", id_recieve);
    q.bindValue(":type_recieve", type_post);
    q.bindValue(":post_id", id_post);
    q.exec();
    while(q.next()){

        QFont font_2("Nirmala IU",12, QFont::Light);

        ui->frame_2->setMinimumHeight(frameHeight);

        QGroupBox *groupBox = new QGroupBox(ui->frame_2);

        groupBox->setGeometry(10, currentY,300,245);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);");

        QString username = q.value(0).toString();
        QString text = q.value(1).toString();

        QLineEdit *namelabel = new QLineEdit(username,groupBox);
        namelabel->setGeometry(15,10,200,35);
        namelabel->setStyleSheet("padding:6px;background-color:rgb(238,238,238);border-radius:13px;border:2px solid rgb(181, 56, 75);");

        QTextEdit *tex = new QTextEdit(groupBox);
        tex->setText(text);
        tex->setStyleSheet("padding:5px;margin:5px;background-color:rgb(242,242,242);border: 3px solid rgb(52, 103, 110); border-radius: 9px;");
        tex->setGeometry(10,50,280,170);
        tex->setReadOnly(true);
        tex->setFont(font_2);

        groupBox->show();
        frameHeight += 255;
        currentY += 255;
    }
}


comment::~comment()
{
    delete ui;
}

void comment::on_pushButton_clicked()
{
    if( !ui->textEdit->toPlainText().isEmpty()){

        Comment newComment(name_User, ui->textEdit->toPlainText(), type_Recieve, id_Recieve, id_Post);
        newComment.add_comment();
    }
    QMessageBox::information(this,"Comment","The comment was sent successfully.");
    comment *w = new comment(name_User,id_Post,type_Recieve,id_Recieve);
    this->close();
    w->show();
}


void comment::on_pushButton_2_clicked()
{
    this->close();
}

