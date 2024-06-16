#include "jobscompany.h"
#include "ui_jobscompany.h"
#include "mynetworkcompany.h"
#include "mynetworkuser.h"
#include "ui_mynetworkuser.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "createjob.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "QGroupBox"
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include "QMessageBox"
#include "content.h"

int adad_j_c;
jobscompany::jobscompany(int number,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jobscompany)
{
    ui->setupUi(this);

    adad_j_c = number;

    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();


    QSqlQuery query;
    query.prepare("SELECT loginpage.username, waiting_list.id_user, waiting_list.id_job "
                  "FROM waiting_list "
                  "JOIN loginpage ON waiting_list.id_user = loginpage.account_id "
                  "WHERE waiting_list.id_company = :company_id");
    query.bindValue(":company_id", number);

    int frameHeight = 203;
    int currentY = 3;

    ui->frame_2->setGeometry(1,10,500,frameHeight);
    ui->frame_2->setStyleSheet("background-color:rgb(255, 255, 255);");

    if (query.exec()) {
        while (query.next()) {
            ui->frame_2->setMinimumHeight(frameHeight);
            QGroupBox *groupBox = new QGroupBox(ui->frame_2);
            groupBox->setGeometry(1,currentY, 510,200);
            groupBox->setStyleSheet("background-color:rgb(255, 255, 255);");

            QFont font_2("HoloLens MDL2 Assets",11, QFont::NoFontMerging);
            QFont font("Nirmala", 10, QFont::Light);

            QString username = query.value(0).toString();
            int id_user = query.value(1).toInt();
            int id_job = query.value(2).toInt();

            QLabel *o = new QLabel(groupBox);
            o->setText(QString::number(id_user));

            QLabel *namelabel = new QLabel(groupBox);
            namelabel->setText("username :");
            namelabel->setGeometry(40,35,80,35);
            namelabel->setStyleSheet("color: rgb(52, 103, 110);");
            namelabel->setFont(font_2);

            QLineEdit *name = new QLineEdit(groupBox);
            name->setText(username);
            name->setGeometry(120, 35, 200, 35);
            name->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
            name->setFont(font);
            name->setReadOnly(true);

            QPushButton *accept = new QPushButton(groupBox);
            accept->setGeometry(70,130,80,35);
            accept->setText("Accept");
            accept->setStyleSheet("background-color:#b71540;color:rgb(255,255,255);border-radius:5px;padding: 5px;border-top-left-radius: 30px;border-bottom-right-radius: 30px;");
            connect(accept,&QPushButton::clicked,this,[this,number,id_user,id_job](){jobscompany::on_accept_clicked(number,id_user,id_job);});

            QPushButton *ignor = new QPushButton(groupBox);
            ignor->setGeometry(220,130,80,35);
            ignor->setText("Ignor");
            ignor->setStyleSheet("background-color:#b71540;color:rgb(255,255,255);border-radius:5px;padding: 5px;border-top-left-radius: 30px;border-bottom-right-radius: 30px;");
            connect(ignor,&QPushButton::clicked,this,[this,number,id_user,id_job](){jobscompany::on_ignor_clicked(number,id_user,id_job);});

            groupBox->show();
            frameHeight += 200;
            currentY += 200;
        }
    } else {
        qDebug() << "Error: " ;
    }


}

jobscompany::~jobscompany()
{
    delete ui;
}
void jobscompany::on_ignor_clicked(int number,int id_user,int id_job){
    QMessageBox::information(this,"job company","the user request was deleted by you.");
    job delet;
    delet.Delete_request(number,id_job,id_user);

    jobscompany *w = new jobscompany(adad_j_c);
    this->close();
    w->show();
}
void jobscompany::on_accept_clicked(int number,int id_user,int id_job){
    QJsonObject acceptObject;
    acceptObject["id_user"] = id_user;
    acceptObject["id_job"] = id_job;
    QSqlQuery q;
    q.prepare("SELECT Employee FROM CompanyInformation WHERE rowid = :id_company");
    q.bindValue(":id_company", number);
    if(q.exec() && q.next()) {
        QString jobsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray jobsArray = doc.array();
        jobsArray.append(acceptObject);
        QJsonDocument newDoc(jobsArray);

        QString newEmployee = newDoc.toJson();
        QString updateQuery = QString("UPDATE CompanyInformation SET Employee = '%1' WHERE rowid = %2").arg(newEmployee).arg(number);
        if (!q.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            QMessageBox::information(this,"job company","A new employee has been added to your company.");
            qDebug() << "Record updated successfully!";
        }
    }
    job delet;
    delet.Delete_request(number,id_job,id_user);

    jobscompany *w = new jobscompany(adad_j_c);
    this->close();
    w->show();
}
void jobscompany::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
    this->close();
    w3->show();
}



void jobscompany::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}



void jobscompany::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser(adad_j_c);
    this->close();
    w3->show();
}


void jobscompany::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(adad_j_c);
    this->close();
    w3->show();
}


void jobscompany::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void jobscompany::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void jobscompany::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}


void jobscompany::on_pushButton_clicked()
{
    createjob *w = new createjob(adad_j_c);
    this->close();
    w->show();
}

