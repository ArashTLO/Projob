#include "jobsuser.h"
#include "ui_jobsuser.h"
#include "home.h"
#include "me.h"
#include "messaging.h"
#include "mynetworkuser.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include <QDebug>
#include "QGroupBox"

jobsuser::jobsuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jobsuser)
{

    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    // بازیابی مقادیر از ستون jobs
    QString selectQuery = "SELECT jobs FROM CompanyInformation";
    QSqlQuery q;

    int frameHeight = 200;
    int currentY = 3;

    ui->frame_2->setGeometry(1,10,500,frameHeight);
    ui->frame_2->setStyleSheet("background-color:rgb(255, 255, 255);");


    if (!q.exec(selectQuery)) {
        qDebug() << "Error: ";
    } else {
        int currentY = 0;
        int frameHeight = 0;

        while (q.next()) {
            QString jobsString = q.value(0).toString();
            QJsonDocument jobsDoc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray jobsArray = jobsDoc.array();

            for (const QJsonValue &jobValue : jobsArray) {
                QJsonObject jobObject = jobValue.toObject();
                QString Address = jobObject["address"].toString();
                QString jobName = jobObject["job_name"].toString();
                QString JobType = jobObject["job_type"].toString();
                QString Salary = jobObject["salary"].toString();
                QString Skills = jobObject["skills"].toString();
                int salaryint = QString::number(Salary.toFloat()).toInt();
                //QString salaryString = QString::number(salaryint);
                QString Workplase_type = jobObject["workPlace_type"].toString();

                ui->frame_2->setMinimumHeight(frameHeight);
                QGroupBox *groupBox = new QGroupBox(ui->frame_2);
                groupBox->setGeometry(1, currentY, 510, 360);
                groupBox->setStyleSheet("background-color: rgb(255, 255, 255);");

                QFont font_2("HoloLens MDL2 Assets",11, QFont::NoFontMerging);
                QLabel *namelabel = new QLabel(groupBox);
                namelabel->setText("name :");
                namelabel->setGeometry(50,25,80,35);
                namelabel->setStyleSheet("color: rgb(52, 103, 110);");
                namelabel->setFont(font_2);

                QLineEdit *nameline = new QLineEdit(groupBox);
                nameline->setText(jobName);
                nameline->setGeometry(130, 25, 200, 35);
                nameline->setStyleSheet("padding: 6px;background-color: rgb(238, 238, 238);border-radius: 13px;border: 2px solid rgb(181, 56, 75);");

                QLabel *salaryl = new QLabel(groupBox);
                salaryl->setText("salary :");
                salaryl->setGeometry(50,75,80,35);
                salaryl->setStyleSheet("color: rgb(52, 103, 110);");
                salaryl->setFont(font_2);

                QLineEdit *salaryline = new QLineEdit(groupBox);
                salaryline->setText(QString::number(salaryint));
                salaryline->setGeometry(130,75,200,35);
                salaryline->setStyleSheet("padding: 6px;background-color: rgb(238, 238, 238);border-radius: 13px;border: 2px solid rgb(181, 56, 75);");

                QLabel *skillsl = new QLabel(groupBox);
                skillsl->setText("skills :");
                skillsl->setGeometry(50,125,80,35);
                skillsl->setStyleSheet("color: rgb(52, 103, 110);");
                skillsl->setFont(font_2);

                QLineEdit *skillsline = new QLineEdit(groupBox);
                skillsline->setText(Skills);
                skillsline->setGeometry(130,125,200,35);
                skillsline->setStyleSheet("padding: 6px;background-color: rgb(238, 238, 238);border-radius: 13px;border: 2px solid rgb(181, 56, 75);");

                QLabel *addressl = new QLabel(groupBox);
                addressl->setText("address :");
                addressl->setGeometry(50,175,80,35);
                addressl->setStyleSheet("color: rgb(52, 103, 110);");
                addressl->setFont(font_2);

                QLineEdit *addressline = new QLineEdit(groupBox);
                addressline->setText(Address);
                addressline->setGeometry(130,175,200,35);
                addressline->setStyleSheet("padding: 6px;background-color: rgb(238, 238, 238);border-radius: 13px;border: 2px solid rgb(181, 56, 75);");

                QLabel *jobtypel = new QLabel(groupBox);
                jobtypel->setText("type :");
                jobtypel->setGeometry(50,225,80,35);
                jobtypel->setStyleSheet("color: rgb(52, 103, 110);");
                jobtypel->setFont(font_2);

                QLineEdit *jobtypeline = new QLineEdit(groupBox);
                jobtypeline->setText(JobType);
                jobtypeline->setGeometry(130,225,200,35);
                jobtypeline->setStyleSheet("padding: 6px;background-color: rgb(238, 238, 238);border-radius: 13px;border: 2px solid rgb(181, 56, 75);");

                QLabel *workplase = new QLabel(groupBox);
                workplase->setText("work plase :");
                workplase->setGeometry(50,275,80,35);
                workplase->setStyleSheet("color: rgb(52, 103, 110);");
                workplase->setFont(font_2);

                QLineEdit *workplaseline = new QLineEdit(groupBox);
                workplaseline->setText(Workplase_type);
                workplaseline->setGeometry(130,275,200,35);
                workplaseline->setStyleSheet("padding: 6px;background-color: rgb(238, 238, 238);border-radius: 13px;border: 2px solid rgb(181, 56, 75);");

                groupBox->show();
                currentY += 360;
                frameHeight += 360;
            }
        }
    }

    /*if (!q.exec(selectQuery)) {
        qDebug() << "Error: ";
    } else {
        while (q.next()) {
            QString jobsString = q.value(0).toString();
            QJsonDocument jobsDoc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray jobsArray = jobsDoc.array();
            QString jobType,jobName,address;

            for (const QJsonValue &jobValue : jobsArray) {
                QJsonObject jobObject = jobValue.toObject();
                address = jobObject["address"].toString();
                jobName = jobObject["job_name"].toString();
                jobType = jobObject["job_type"].toString();

            ui->frame_2->setMinimumHeight(frameHeight);
            QGroupBox *groupBox = new QGroupBox(ui->frame_2);
            groupBox->setGeometry(1,currentY, 510,360);
            groupBox->setStyleSheet("background-color:rgb(255, 255, 255);");

            QLineEdit *namelabel = new QLineEdit(groupBox);
            namelabel->setText(jobName);
            namelabel->setGeometry(50,25,200,35);
            namelabel->setStyleSheet("padding:6px;background-color:rgb(238,238,238);border-radius:13px;border:2px solid rgb(181, 56, 75);");

            groupBox->show();
            currentY += 360;
            }

            frameHeight += 360;
        }
    }*/
}

jobsuser::~jobsuser()
{
    delete ui;
}

void jobsuser::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(1);
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

