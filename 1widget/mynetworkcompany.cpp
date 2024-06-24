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

int adad_m_c;
mynetworkcompany::mynetworkcompany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mynetworkcompany)
{
    ui->setupUi(this);
    ///////////////

    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();


        QSqlQuery q;
        q.prepare("SELECT posts FROM CompanyInformation WHERE rowid = 1");

        if (q.exec()) {
            while (q.next()) {
                QByteArray jsonData = q.value(0).toByteArray();
                QJsonDocument doc = QJsonDocument::fromJson(jsonData);
                QJsonArray postArray = doc.array();
                for (const QJsonValue &postValue : postArray) {
                    QJsonObject postObject = postValue.toObject();
                    QString postId = postObject["post_id"].toString();
                    QString postText = postObject["post_text"].toString();
                    QString base64Image = postObject["post_image"].toString();
                    QByteArray imageData = QByteArray::fromBase64(base64Image.toLatin1());

                    // Process the retrieved data as needed
                    // For example, convert the image data back to QPixmap and display it
                    QPixmap pixmap;
                    pixmap.loadFromData(imageData);
                    // Display the post text and image
                    qDebug() << "Post ID: " << postId;
                    qDebug() << "Post Text: " << postText;

                }
            }
        } else {
            qDebug() << "Error in retrieving company posts from database: ";
        }

}

mynetworkcompany::~mynetworkcompany()
{
    delete ui;
}

void mynetworkcompany::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
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
    jobsuser *w3 = new jobsuser(0);
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(1);
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void mynetworkcompany::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

