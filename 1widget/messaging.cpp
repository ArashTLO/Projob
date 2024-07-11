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
#include "QFile"
#include "QFileDialog"
#include "QModelIndex"
#include "QModelIndexList"
#include "QSqlQueryModel"
#include "content.h"

int adad_M,ID_receiver;
QString Type_M,text_Message;
messaging::messaging(int number, QString type, QString text_message, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::messaging)
{
    ui->setupUi(this);

    if(text_message != nullptr){
        ui->textEdit->setText(text_message);
    }
    //ui->frame_3->setGeometry(0,0,786,481);
    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    int frameHeight = 50,currentY = 0;
    ui->frame_2->setGeometry(1,1,310,50);
    adad_M = number;
    Type_M = type;
    text_Message = text_message;

    QSqlQuery q;
    q.prepare("SELECT frstname,lastname,image,account_id FROM verificationpage ");
    q.exec();

    while (q.next()) {

        ui->frame_2->setMinimumHeight(frameHeight);
        qDebug() << "frameHeight : " <<frameHeight;
        QGroupBox *group = new QGroupBox(ui->frame_2);
        group->setGeometry(0,currentY,318,53);
        group->setStyleSheet("background-color: rgb(255, 255, 255);");

        QString N1 = q.value(0).toString() + " " + q.value(1).toString();

        QFont font("Lucida Bright", 10, QFont::Light);

        QPushButton *user = new QPushButton(group);
        user->setGeometry(0,0,318,53);
        user->setText(N1);
        user->setFont(font);
        user->setStyleSheet("border-radius:1px; background-color: rgb(255, 255, 255);");


        int receiver = q.value(3).toInt();

        connect(user,&QPushButton::clicked,this,[this,number,receiver](){messaging::on_user_clicked(number,receiver);});

        QLabel *imagel = new QLabel(group);
        imagel->setGeometry(259,2,46,45);
        QByteArray imageData = q.value(2).toByteArray();
        QPixmap image;
        image.loadFromData(imageData);
        imagel->setPixmap(image.scaled(476,180));
        imagel->setStyleSheet("border-radius:3px;");
        imagel->setScaledContents(true);

        group->show();
        frameHeight += 50;
        currentY += 50;
    }
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

    QList<QLabel*> labels = ui->frame_3->findChildren<QLabel*>();
    for (QLabel* label : labels) {
        label->deleteLater();
    }

    QList<QLineEdit*> LineEdits = ui->frame_3->findChildren<QLineEdit*>();
    for (QLineEdit* LineEdit : LineEdits) {
        LineEdit->deleteLater();
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

/////////////////////////////////////////////////////////////////////////

            if(postObject["texe_messag"].toString() != nullptr){

                QTextEdit *tex = new QTextEdit(ui->frame_3);
                tex->setText(postObject["texe_messag"].toString());
                tex->setGeometry(10,currentY,280,170);
                tex->setStyleSheet("background-image: url(:/new/prefix1/bc29ca60-4b40-11ee-b6aa-afa6de34b028.jpg);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
                tex->setReadOnly(true);
                tex->setFont(font);

                QLineEdit *time_Date = new QLineEdit(tex);
                time_Date->setGeometry(10,137,200,27);
                time_Date->setText(postObject["Time_and_Date"].toString());
                time_Date->setStyleSheet("background-color:transparent; border:1pc solid gray; color: black;");

                frameHeight += 178;
                currentY += 178;
                tex->show();
                time_Date->show();
            }
            if (!postObject["image_messag"].isNull()) {
                QString imagePath = postObject["image_messag"].toString();
                QPixmap image(imagePath);

                if (!image.isNull()) {
                    QLabel *imageLabel = new QLabel(ui->frame_3);
                    imageLabel->setPixmap(image.scaled(476, 180));
                    imageLabel->setGeometry(14, currentY, 170, 150);
                    imageLabel->setStyleSheet("border-radius: 13px;");
                    imageLabel->setScaledContents(true);

                    QLineEdit *time_Date = new QLineEdit(ui->frame_3);
                    time_Date->setGeometry(14,currentY + 160,170,27);
                    time_Date->setStyleSheet("background-color:white; background-image: url(:/new/prefix1/f2a416d0-4ac9-11ee-9715-5d1e9c9f2803.jpg);border:1pc solid gray; color: black;");
                    time_Date->setText(postObject["Time_and_Date"].toString());
                    time_Date->setReadOnly(true);

                    frameHeight += 197;
                    currentY += 197;
                    imageLabel->show();
                    time_Date->show();
                } else {
                    qDebug() << "Failed to load image from file: " << imagePath;
                }
            }

///////////////////////////////////////////////////////////////////////////
       }
       else if(postObject["id_sender"].toInt() == receiver){

           ui->frame_3->setMinimumHeight(frameHeight);

           if(postObject["texe_messag"].toString() != nullptr){

           QTextEdit *tex = new QTextEdit(ui->frame_3);
           tex->setText(postObject["texe_messag"].toString());
           tex->setStyleSheet("background-image: url(:/new/prefix1/bc29ca60-4b40-11ee-b6aa-afa6de34b028.jpg);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
           tex->setGeometry(480,currentY,280,170);
           tex->setReadOnly(true);
           tex->setFont(font);

           QLineEdit *time_Date = new QLineEdit(tex);
           time_Date->setGeometry(480,137,280,27);
           time_Date->setText(postObject["Time_and_Date"].toString());
           time_Date->setStyleSheet("background-color:transparent; border:1pc solid gray; color: black;");

           frameHeight += 178;
           currentY += 178;
           tex->show();
           time_Date->show();
           }
           if (!postObject["image_messag"].isNull()) {
               QString imagePath = postObject["image_messag"].toString();
               QPixmap image(imagePath);

               if (!image.isNull()) {
                   QLabel *imageLabel = new QLabel(ui->frame_3);
                   imageLabel->setPixmap(image.scaled(476, 180));
                   imageLabel->setGeometry(584,currentY, 170, 150);
                   imageLabel->setStyleSheet("border-radius: 13px;");
                   imageLabel->setScaledContents(true);

                   QLineEdit *time_Date = new QLineEdit(ui->frame_3);
                   time_Date->setGeometry(584,currentY + 160,170,27);
                   time_Date->setText(postObject["Time_and_Date"].toString());
                   time_Date->setStyleSheet("background-color:white;background-image: url(:/new/prefix1/f2a416d0-4ac9-11ee-9715-5d1e9c9f2803.jpg); border:1pc solid gray; color: black;");

                   frameHeight += 197;
                   currentY += 197;
                   imageLabel->show();
                   time_Date->show();
               } else {
                   qDebug() << "Failed to load image from file: " << imagePath;
               }
           }
       }
   }
}
}
void messaging::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_M,Type_M,10);
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
    if (Type_M == "P"){
        jobsuser *w3 = new jobsuser(adad_M,Type_M);
        this->close();
        w3->show();

    }
    else if (Type_M == "C") {
        QMessageBox::warning(this, "Messaging", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
}


void messaging::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_M,Type_M,text_Message);
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
    if(Type_M == "C")
        QMessageBox::warning(this, "Messaging", "Only persons can enter the desired window.");
}


void messaging::on_commandLinkButton_7_clicked()
{
    if(Type_M == "P"){
        QMessageBox::warning(this, "Messaging" , "Only companies can enter the desired window.");
    }
    else if(Type_M == "C"){
    jobscompany *w3 = new jobscompany(adad_M,Type_M);
    this->close();
    w3->show();
    }
}


void messaging::on_commandLinkButton_6_clicked()
{
    if(Type_M == "P"){
        QMessageBox::warning(this, "Messaging" , "Only companies can enter the desired window.");
    }
    else if(Type_M == "C"){
        mynetworkcompany *w3 = new mynetworkcompany(adad_M, Type_M);
        this->close();
        w3->show();
    }
}

void messaging::on_pushButton_clicked()
{
    message newmessage(ID_receiver,adad_M,ui->textEdit->toPlainText(),nullptr);
    newmessage.send_text_message();

    messaging *e = new messaging(adad_M,Type_M,text_Message);
    this->close();
    e->show();
}

void messaging::on_pushButton_2_clicked()
{
    QString filePath1 = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath1.isEmpty()) {

        message newmessage(ID_receiver,adad_M,nullptr,filePath1);
        newmessage.send_image_message();

            messaging *e = new messaging(adad_M,Type_M,text_Message);
            this->close();
            e->show();
    }
}

