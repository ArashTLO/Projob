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
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QGroupBox"
#include "QPushButton"
#include "QCommandLinkButton"
#include "QLabel"

int adad_M,ID_receiver;
QString Type_M;
messaging::messaging(int number, QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::messaging)
{
    ui->setupUi(this);
<<<<<<< HEAD
=======

    ui->frame_3->setGeometry(0,0,786,481);
    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    int frameHeight = 50,currentY = 0;
    ui->frame_2->setGeometry(1,1,310,50);
    adad_M = number;
    Type_M = type;

    QSqlQuery q;
    q.prepare("SELECT frstname,lastname,image,account_id FROM verificationpage ");
    q.exec();

    while (q.next()) {

        ui->frame_2->setMaximumHeight(frameHeight);

        QGroupBox *group = new QGroupBox(ui->frame_2);
        group->setGeometry(0,currentY,318,53);
        group->setStyleSheet("background-color: rgb(255, 255, 255);");

        QString N1 = q.value(0).toString() + " " + q.value(1).toString();

        QFont font("Lucida Bright", 10, QFont::Light);

        QPushButton *user = new QPushButton(group);
        user->setGeometry(0,0,318,53);
        user->setText(N1);
        user->setFont(font);
        user->setStyleSheet("border-radius:1px background-color: rgb(255, 255, 255);");


        int receiver = q.value(3).toInt();

        connect(user,&QPushButton::clicked,this,[this,number,receiver](){messaging::on_user_clicked(number,receiver);});

        QLabel *imagel = new QLabel(group);
        imagel->setGeometry(259,2,46,45);
        QByteArray imageData = q.value(2).toByteArray();
        QPixmap image;
        image.loadFromData(imageData);
        imagel->setPixmap(image.scaled(476,180));
        imagel->setScaledContents(true);

        group->show();
        frameHeight += 50;
        currentY += 50;
    }
>>>>>>> 7bf3d3d4c325c304f29d15dd66f5153c9d492b99
}

messaging::~messaging()
{
    delete ui;
}

void messaging::on_user_clicked(int sender, int receiver){

    ui->frame_3->setMinimumHeight(480);
    ID_receiver = receiver;
    qDebug() << ID_receiver;

    QList<QTextEdit*> textEdits = ui->frame_3->findChildren<QTextEdit*>();
    for (QTextEdit* textEdit : textEdits) {
    textEdit->deleteLater();
    }

   QSqlQuery query;
   query.prepare("SELECT DM FROM verificationpage WHERE account_id = :sender");
   query.bindValue(":sender", sender);
   query.exec();

   while(query.next()){

   QString messagingJsonString = query.value(0).toString();
   QJsonDocument doc = QJsonDocument::fromJson(messagingJsonString.toUtf8());
   QJsonArray messagingsArray = doc.array();

   int frameHeight = 198,currentY = 15;

   foreach (const QJsonValue &messagingValue,messagingsArray){

       QJsonObject postObject = messagingValue.toObject();

       QFont font("Nirmala UI", 10, QFont::Light);

       if(postObject["id_receiver"].toInt() == receiver){

           ui->frame_3->setMinimumHeight(frameHeight);

           QTextEdit *tex = new QTextEdit(ui->frame_3);

           tex->setText(postObject["texe_messag"].toString());
           tex->setGeometry(10,currentY,280,170);
           tex->setStyleSheet("background-image: url(:/new/prefix1/bc29ca60-4b40-11ee-b6aa-afa6de34b028.jpg);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
           tex->setReadOnly(true);
           tex->setFont(font);

           frameHeight += 170;
           currentY += 170;
           tex->show();
       }
       else if(postObject["id_sender"].toInt() == receiver){

           ui->frame_3->setMinimumHeight(frameHeight);

           QTextEdit *tex = new QTextEdit(ui->frame_3);

           tex->setText(postObject["texe_messag"].toString());
           tex->setStyleSheet("background-image: url(:/new/prefix1/bc29ca60-4b40-11ee-b6aa-afa6de34b028.jpg);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
           tex->setGeometry(480,currentY,280,170);
           tex->setReadOnly(true);
           tex->setFont(font);


           frameHeight += 170;
           currentY += 170;
           tex->show();
       }
   }
}
}
void messaging::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_M,Type_M);
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

void messaging::on_pushButton_clicked()
{
    QJsonObject messagingObject_1;
    messagingObject_1["id_sender"] = adad_M;
    messagingObject_1["texe_messag"] = ui->textEdit->toPlainText();

    QSqlQuery p;
    p.prepare("SELECT DM FROM verificationpage WHERE rowid = :id");
    p.bindValue(":id", ID_receiver);

    if(p.exec() && p.next()) {
        QString jobsString = p.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray jobsArray = doc.array();
        jobsArray.append(messagingObject_1);
        QJsonDocument newDoc(jobsArray);

        QString newJobsString = newDoc.toJson();
        QString updateQuery = QString("UPDATE verificationpage SET DM = '%1' WHERE rowid = %2").arg(newJobsString).arg(ID_receiver);
        if (!p.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            qDebug() << "Record updated successfully!";
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////
    QJsonObject messagingObject;
    messagingObject["id_receiver"] = ID_receiver;
    messagingObject["texe_messag"] = ui->textEdit->toPlainText();

    QSqlQuery q;
    q.prepare("SELECT DM FROM verificationpage WHERE rowid = :id");
    q.bindValue(":id", adad_M);

    if(q.exec() && q.next()) {
        QString jobsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray jobsArray = doc.array();
        jobsArray.append(messagingObject);
        QJsonDocument newDoc(jobsArray);

        QString newJobsString = newDoc.toJson();
        QString updateQuery = QString("UPDATE verificationpage SET DM = '%1' WHERE rowid = %2").arg(newJobsString).arg(adad_M);
        if (!q.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            qDebug() << "Record updated successfully!";
        }
    }
    messaging *e = new messaging(adad_M,Type_M);
    this->close();
    e->show();
}
