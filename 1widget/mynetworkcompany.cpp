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
#include "QGroupBox"

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

    QSqlQuery query;
    query.prepare("SELECT following FROM CompanyInformation WHERE rowid = :id");
    query.bindValue(":id", number);



    if (query.exec() && query.next()) {

        QByteArray jsonData = query.value(0).toByteArray();
        QJsonDocument doc = QJsonDocument::fromJson(jsonData);
        QJsonArray followingArray = doc.array();

        int frameHeight = 209, Xbox = 0;

        for (const QJsonValue &val : followingArray) {
            QJsonObject itemObject = val.toObject();
            if (itemObject["type_follower"].toString() == "P") {

                QSqlQuery p;
                p.prepare("SELECT frstname,lastname,image,skills FROM verificationpage WHERE account_id = :id");
                p.bindValue(":id", itemObject["id_follower"].toInt());
                p.exec();
                p.next();

                qDebug() << itemObject["id_follower"].toInt() << endl;

                QGroupBox *box = new QGroupBox(ui->frame_2);
                ui->frame_2->setMinimumWidth(frameHeight);
                box->setGeometry(Xbox,0,203,283);
                box->setStyleSheet("border-radius: 5px;background-color: rgb(255,255,255);");

                QByteArray imageData = p.value(2).toByteArray();
                QPixmap image;

                QLabel *imageLabel = new QLabel(box);
                image.loadFromData(imageData);
                imageLabel->setPixmap(image.scaled(170,170));
                imageLabel->setGeometry(15,15,173,170);
                imageLabel->setStyleSheet("background-color:rgb(20,54,54);");
                imageLabel->setScaledContents(true);

                QFont font_2("HoloLens MDL2 Assets",11, QFont::NoFontMerging);
                QFont font("Nirmala", 10, QFont::Light);

                QLineEdit *linename = new QLineEdit(box);
                linename->setGeometry(10,202,180,30);
                linename->setText(p.value(0).toString() + " " + p.value(1).toString());
                linename->setStyleSheet("color: rgb(52, 103, 110);background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                linename->setFont(font);

                QLineEdit *skillsline = new QLineEdit(box);
                skillsline->setText(p.value(3).toString());
                skillsline->setGeometry(10,243,180,30);
                skillsline->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                skillsline->setFont(font);


                box->show();
                frameHeight += 207;
                Xbox += 207;

            }
        }
    }
}

mynetworkcompany::~mynetworkcompany()
{
    delete ui;
}
int mynetworkcompany::show_follower(int id_following){

    QSqlQuery query;
    query.prepare("SELECT following FROM verificationpage WHERE rowid = :id");
    query.bindValue(":id", id_following);

    if (query.exec() && query.next()) {

        QString followingData = query.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(followingData.toUtf8());
        QJsonArray followingArray = doc.array();

        for (auto item : followingArray) {

            QJsonObject itemObject = item.toObject();
            if (itemObject["type_follower"].toString() == "P")
                return itemObject["id_follower"].toInt();

            else
                return 0;
        }
    }
}

void mynetworkcompany::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_m_c,Type_m_c,10);
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
    if (Type_m_c == "P"){
        jobsuser *w3 = new jobsuser(adad_m_c,Type_m_c);
        this->close();
        w3->show();
    }
    else if (Type_m_c == "C") {
        QMessageBox::warning(this, "home", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
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

