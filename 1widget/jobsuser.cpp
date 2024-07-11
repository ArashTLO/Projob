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
#include "QIntValidator"
#include "QPushButton"
#include "QMessageBox"
#include "content.h"
#include "QTextEdit"
#include "QVariantList"
#include "QListWidgetItem"

int adad_ju;
QString Type_ju;
jobsuser::jobsuser(int number, QString type ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jobsuser)
{
    ui->setupUi(this);
    Type_ju = type;
    adad_ju = number;
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    QString selectQuery = "SELECT jobs FROM CompanyInformation";
    QSqlQuery q;
    q.prepare("SELECT skills FROM verificationpage WHERE account_id = :number");
    q.bindValue(":number", number);
    q.exec();
    q.next();
    ui->label_2->setText(q.value(0).toString());

    int frameHeight = 333;
    int currentY = 3;

    ui->frame_2->setGeometry(1,10,500,frameHeight);
    ui->frame_2->setStyleSheet("background-color:rgb(255, 255, 255);");

    if (!q.exec(selectQuery)) {
        qDebug() << "Error: ";
    } else {

        while (q.next()) {
            QString jobsString = q.value(0).toString();
            QJsonDocument jobsDoc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray jobsArray = jobsDoc.array();

            for (const QJsonValue &jobValue : jobsArray) {

                QJsonObject jobObject = jobValue.toObject();
                QString Address = jobObject["address"].toString();
                QString jobName = jobObject["job_name"].toString();
                QString JobType = jobObject["job_type"].toString();
                QString Skills = jobObject["skills"].toString();
                int Salary = jobObject["salary"].toInt();
                QString Workplase_type = jobObject["workPlace_type"].toString();
                qDebug() << jobObject["id_compny"];

                ui->frame_2->setMinimumHeight(frameHeight);
                QGroupBox *groupBox = new QGroupBox(ui->frame_2);
                groupBox->setGeometry(1, currentY, 510, 330);
                groupBox->setStyleSheet("background-color: rgb(255, 255, 255);");

                QFont font_2("HoloLens MDL2 Assets",11, QFont::NoFontMerging);
                QFont font("Nirmala", 10, QFont::Light);

                QLabel *namelabel = new QLabel(groupBox);
                namelabel->setText("name :");
                namelabel->setGeometry(40,35,80,35);
                namelabel->setStyleSheet("color: rgb(52, 103, 110);");
                namelabel->setFont(font_2);

                QLineEdit *nameline = new QLineEdit(groupBox);
                nameline->setText(jobName);
                nameline->setGeometry(120, 35, 200, 35);
                nameline->setStyleSheet("color: rgb(52, 103, 110);background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                nameline->setFont(font);

                QPushButton *applying = new QPushButton(groupBox);
                applying->setGeometry(360,35,115,35);
                applying->setText(check_request(adad_ju,jobObject["id_compny"].toInt(),jobObject["job_id"].toInt()));
                applying->setStyleSheet("background-color:#b71540;color:rgb(255,255,255);border-radius:5px;padding: 5px;border-top-left-radius: 30px;border-bottom-right-radius: 30px;");
                connect(applying,&QPushButton::clicked,this,[this,number,jobObject,applying](){jobsuser::on_apply_clicked(number,jobObject["id_compny"].toInt(),jobObject["job_id"].toInt(),applying->text());});

                QLabel *salaryl = new QLabel(groupBox);
                salaryl->setText("salary :");
                salaryl->setGeometry(40,85,80,35);
                salaryl->setStyleSheet("color: rgb(52, 103, 110);");
                salaryl->setFont(font_2);

                QLabel *salaryline = new QLabel(groupBox);
                salaryline->setText(QString::number(Salary));
                salaryline->setGeometry(120,85,200,35);
                salaryline->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                salaryline->setFont(font);

                QLabel *skillsl = new QLabel(groupBox);
                skillsl->setText("skills :");
                skillsl->setGeometry(40,130,80,35);
                skillsl->setStyleSheet("color: rgb(52, 103, 110);");
                skillsl->setFont(font_2);

                QLineEdit *skillsline = new QLineEdit(groupBox);
                skillsline->setText(Skills);
                skillsline->setGeometry(120,135,300,35);
                skillsline->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                skillsline->setFont(font);

                QLabel *addressl = new QLabel(groupBox);
                addressl->setText("address :");
                addressl->setGeometry(40,185,80,35);
                addressl->setStyleSheet("color: rgb(52, 103, 110);");
                addressl->setFont(font_2);

                QTextEdit *addressline = new QTextEdit(groupBox);
                addressline->setText(Address);
                addressline->setGeometry(120,185,300,60);
                addressline->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                addressline->setFont(font);

                QLabel *jobtypel = new QLabel(groupBox);
                jobtypel->setText("type :");
                jobtypel->setGeometry(260,260,80,35);
                jobtypel->setStyleSheet("color: rgb(52, 103, 110);");
                jobtypel->setFont(font_2);

                QLineEdit *jobtypeline = new QLineEdit(groupBox);
                jobtypeline->setText(JobType);
                jobtypeline->setGeometry(320,260,100,35);
                jobtypeline->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                jobtypeline->setFont(font);

                QLabel *workplase = new QLabel(groupBox);
                workplase->setText("work plase :");
                workplase->setGeometry(40,260,80,35);
                workplase->setStyleSheet("color: rgb(52, 103, 110);");
                workplase->setFont(font_2);

                QLineEdit *workplaseline = new QLineEdit(groupBox);
                workplaseline->setText(Workplase_type);
                workplaseline->setGeometry(120,260,100,35);
                workplaseline->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
                workplaseline->setFont(font);

                groupBox->show();
                currentY += 330;
                frameHeight += 330;
            }
        }
    }

    connect(ui->lineEdit_Search, &QLineEdit::textChanged, this, &jobsuser::searchInDatabase);
}

jobsuser::~jobsuser()
{
    delete ui;
}

void jobsuser::searchInDatabase()
{
    QString searchUsername = ui->lineEdit_Search->text();

    if (searchUsername.isEmpty()) {
        ui->listWidget->clear();
        ui->listWidget->setVisible(false);
        return;
    }

    else if(!searchUsername.isEmpty()){
        ui->listWidget->setVisible(true);
    }
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    QSqlQuery query;
    query.prepare("SELECT username FROM verificationpage WHERE username LIKE :search");
    query.bindValue(":search", "%" + searchUsername + "%");

    if (!query.exec()) {
        qDebug() << "Query failed";
        return;
    }
    ui->listWidget->clear();

    ui->listWidget->setMinimumHeight(0);

    while (query.next()) {
        QString username = query.value(0).toString();
        QListWidgetItem *item = new QListWidgetItem(username);
        ui->listWidget->addItem(item);

        ui->listWidget->setMinimumHeight(qMax(ui->listWidget->minimumHeight(), ui->listWidget->sizeHintForColumn(0) + 20));
    }
}

QString jobsuser::check_request(int id_Man, int id_com, int id_job){

    QSqlQuery q;
    QSqlQuery query;
    query.prepare("SELECT Employee FROM CompanyInformation WHERE id_C = :id_company");
    query.bindValue(":id_company", id_com);

    if (query.exec() && query.next()) {
        QString employeeData = query.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(employeeData.toUtf8());
        QJsonArray employees = doc.array();

        for (const QJsonValue &value : employees) {
            QJsonObject obj = value.toObject();
            int currentJobId = obj["id_job"].toInt();
            int currentUserId = obj["id_user"].toInt();

            if (currentJobId == id_job && currentUserId == id_Man) {
                return "You are Accepted";
            }
        }
    }

    q.prepare("SELECT * FROM waiting_list WHERE id_user = :id_Man AND id_company = :id_com AND id_job = :id_job");
    q.bindValue(":id_Man", id_Man);
    q.bindValue(":id_com", id_com);
    q.bindValue(":id_job", id_job);

    if(q.exec() && q.next()){
        return "Pending";
    } else {
        return "Apply";
    }
}
void jobsuser::on_apply_clicked(int i_Man, int i_com, int i_job, QString situation){
    QSqlQuery q;
    qDebug() << i_com;
    if(situation == "You are Accepted"){
        QMessageBox::information(this,"job user","you have already been accepted to the desired job.");
    }
    else if(situation == "Apply"){
        q.prepare("INSERT INTO waiting_list(id_user,id_company,id_job) VALUES (:iman,:icom,:ijob)");
        q.bindValue(":iman", i_Man);
        q.bindValue(":icom",i_com);
        q.bindValue(":ijob", i_job);
        if (q.exec()) {
            QMessageBox::information(this,"job user","your request has been sent.");
        }
        else {
            QMessageBox::information(this,"job user","your request was not sent.");
        }
        jobsuser *w = new jobsuser(adad_ju,Type_ju);
        this->close();
        w->show();
    }
    else if(situation == "Pending") {
        QMessageBox::information(this,"job user","your request is being reviewed by the company");
    }

}
void jobsuser::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_ju,Type_ju,10);
    this->close();
    w3->show();
}


void jobsuser::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_ju,Type_ju);
    this->close();
    w3->show();
}



void jobsuser::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_ju,Type_ju,nullptr);
    this->close();
    w3->show();
}

void jobsuser::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser(adad_ju,Type_ju);
    this->close();
    w3->show();
}

void jobsuser::on_commandLinkButton_7_clicked()
{
    if(Type_ju == "P"){
        QMessageBox::warning(this, "Job User" , "Only companies can enter the desired window.");
    }
    else if(Type_ju == "C"){
    jobscompany *w3 = new jobscompany(adad_ju,Type_ju);
    this->close();
    w3->show();
    }
}

void jobsuser::on_commandLinkButton_6_clicked()
{
    if(Type_ju == "P"){
        QMessageBox::warning(this, "Job User" , "Only companies can enter the desired window.");
    }
    else if(Type_ju == "C"){
        mynetworkcompany *w3 = new mynetworkcompany(adad_ju,Type_ju);
        this->close();
        w3->show();
    }
}

