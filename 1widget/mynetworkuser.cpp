#include "mynetworkuser.h"
#include "ui_mynetworkuser.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QGroupBox"
#include "QFrame"
#include "QLabel"
#include "QPushButton"
#include "content.h"
#include "QMessageBox"
#include "viewprofile.h"

int adad_m_u;
QString Type_m_u;
mynetworkuser::mynetworkuser(int number,QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mynetworkuser)
{
    ui->setupUi(this);
    adad_m_u = number;
    Type_m_u = type;
    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    int box_X = 6,box_Y = 6,box_Y_C = 6;

    int frameheight = 320,frameheight_C = 320;

    QSqlQuery C_proposed,p_proposed,p_applicant,C_applicant;

    //در خواست دهنده ها

    C_applicant.prepare("SELECT CompanyInformation.name,CompanyInformation.image_C,CompanyInformation.id_C FROM list_connection INNER JOIN CompanyInformation ON list_connection.Applicant = CompanyInformation.id_C WHERE list_connection.type_receiver = :type_R AND list_connection.receiver = :number AND list_connection.type_Applicant = :type");
    C_applicant.bindValue(":number" , number);
    C_applicant.bindValue(":type" , "C");
    C_applicant.bindValue(":type_R", type);

    if(!C_applicant.exec()){
        qDebug() << "Cannot execyte query";
    }
    while(C_applicant.next()){

       QString type_Applicant = "C";
       int applicant = C_applicant.value(2).toInt();
       ui->frame_3->setMinimumHeight(frameheight_C);
       QGroupBox *box = new QGroupBox(ui->frame_3);
       box->setGeometry(box_X,box_Y_C,218,315);
       box->setStyleSheet("border-radius: 5px;background-color: rgb(240,240,240);");

       QLabel *imagelabel = new QLabel(box);
       imagelabel->setGeometry(10,47,180,180);
       imagelabel->setStyleSheet("background-color: rgb(184, 184, 184);");
       QByteArray imageData = C_applicant.value(1).toByteArray();
       QPixmap image;
       image.loadFromData(imageData);
       imagelabel->setPixmap(image.scaled(178,178));
       imagelabel->setFixedSize(198,178);
       imagelabel->setScaledContents(true);

       QLabel *labelname = new QLabel(box);
       labelname->setGeometry(8,12,179,30);
       labelname->setText(C_applicant.value("name").toString());

       QPushButton *Accept = new QPushButton(box);
       Accept->setGeometry(10,240,80,23);
       Accept->setText("Accept");
       Accept->setStyleSheet("color:rgb(255, 255, 255);background-color:rgb(0, 170, 0);font:bold;");
       connect(Accept,&QPushButton::clicked,this,[this,number,type,applicant,type_Applicant](){mynetworkuser::on_Accept_clicked(number,type,applicant,type_Applicant);});

       QPushButton *Reject = new QPushButton(box);
       Reject->setStyleSheet("color:rgb(255, 255, 255);background-color:rgb(170, 0, 0);font:bold;");
       Reject->setText("Reject");
       Reject->setGeometry(128,240,80,23);
       connect(Reject,&QPushButton::clicked,this,[this,number,type,applicant](){mynetworkuser::on_Reject_clicked(number,type,applicant);});

       QPushButton *viewProfile = new QPushButton(box);
       viewProfile->setGeometry(35,265,140,50);
       viewProfile->setText("View Profile");
       connect(viewProfile,&QPushButton::clicked,this,[this,applicant](){mynetworkuser::on_viewProfile_company_clicked(applicant);});

           frameheight_C += 325;
           box_Y_C += 325;
    }

///////////////////////////////////////////////////////

    p_applicant.prepare("SELECT verificationpage.frstname,verificationpage.image,verificationpage.account_id FROM list_connection INNER JOIN verificationpage ON list_connection.Applicant = verificationpage.account_id WHERE list_connection.receiver = :number AND list_connection.type_receiver = :type_R AND list_connection.type_Applicant = :type");
    p_applicant.bindValue(":number" , number);
    p_applicant.bindValue(":type" , "P");
    p_applicant.bindValue(":type_R", type);
    if(!p_applicant.exec()){
        qDebug() << "Cannot execyte query";
    }

    while(p_applicant.next()){

       int applicant = p_applicant.value(2).toInt();
       QString type_Applicant = "P";
       ui->frame_2->setMinimumHeight(frameheight);
       QGroupBox *box = new QGroupBox(ui->frame_2);
       box->setGeometry(box_X,box_Y,218,315);
       box->setStyleSheet("border-radius: 5px;background-color: rgb(240,240,240);");

       QLabel *imagelabel = new QLabel(box);
       imagelabel->setGeometry(10,47,180,180);
       imagelabel->setStyleSheet("background-color: rgb(184, 184, 184);");
       QByteArray imageData = p_applicant.value(1).toByteArray();
       QPixmap image;
       image.loadFromData(imageData);
       imagelabel->setPixmap(image.scaled(178,178));
       imagelabel->setFixedSize(198,178);
       imagelabel->setScaledContents(true);

       QLabel *labelname = new QLabel(box);
       labelname->setGeometry(8,12,179,30);
       labelname->setText(p_applicant.value("frstname").toString());

       QPushButton *Accept = new QPushButton(box);
       Accept->setGeometry(10,240,80,23);
       Accept->setText("Accept");
       Accept->setStyleSheet("color:rgb(255, 255, 255);background-color:rgb(0, 170, 0);font:bold;");
       connect(Accept,&QPushButton::clicked,this,[this,number,type,applicant,type_Applicant](){mynetworkuser::on_Accept_clicked(number,type,applicant,type_Applicant);});

       QPushButton *Reject = new QPushButton(box);
       Reject->setStyleSheet("color:rgb(255, 255, 255);background-color:rgb(170, 0, 0);font:bold;");
       Reject->setText("Reject");
       Reject->setGeometry(128,240,80,23);
       connect(Reject,&QPushButton::clicked,this,[this,number,type,applicant](){mynetworkuser::on_Reject_user_clicked(number,type,applicant);});

       QPushButton *viewProfile = new QPushButton(box);
       viewProfile->setGeometry(35,265,140,50);
       viewProfile->setText("View Profile");
       connect(viewProfile,&QPushButton::clicked,this,[this,applicant](){mynetworkuser::on_viewProfile_user_clicked(applicant);});

           frameheight += 325;
           box_Y += 325;
    }

    // پیشنهاد شده ها

    p_proposed.exec("SELECT image,frstname,lastname,skills,account_id FROM verificationpage ORDER BY account_id");

    int frame_X = 6,frame_Y = 6,frameheight_4 = 325;

    while(p_proposed.next()){

        int receiver = p_proposed.value(4).toInt();

        ui->frame_4->setMinimumHeight(frameheight_4);
        QFrame *fram = new QFrame(ui->frame_4);
        fram->setGeometry(frame_X,frame_Y,218,315);
        fram->setStyleSheet("border-radius: 5px;background-color: rgb(255,255,255);");

        QLabel *labelimage = new QLabel(fram);
        labelimage->setGeometry(10,47,198,178);
        labelimage->setStyleSheet("background-color: rgb(184, 184, 184);");
        QByteArray imageData = p_proposed.value(0).toByteArray();
        QPixmap image;
        image.loadFromData(imageData);
        labelimage->setPixmap(image.scaled(476,180));
        labelimage->setScaledContents(true);

        QLabel *labelname = new QLabel(fram);
        labelname->setGeometry(8,12,179,30);
        labelname->setText(p_proposed.value(1).toString() + " " + p_proposed.value(2).toString());

        QLabel *labelskills = new QLabel(fram);
        labelskills->setGeometry(10,235,80,23);
        labelskills->setText(p_proposed.value(3).toString());

        QPushButton *Connect = new QPushButton(fram);
        Connect->setGeometry(49,270,120,30);
        Connect->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(72, 123, 130);background-color:rgb(0, 170, 0);");
        Connect->setText("+Connect  ");
        connect(Connect,&QPushButton::clicked,this,[this,number,receiver](){mynetworkuser::on_Connect_clicked(number,receiver);});

            frameheight_4 += 325;
            frame_Y += 325;

        fram->show();
    }
    //////////////////////////////////////////////////////////////////

    C_proposed.exec("SELECT image_C,email,name,id_C FROM CompanyInformation ORDER BY id_C");

    int frame_Y_C = 6,frameheight_5 = 321;

    while(C_proposed.next()){

        int receiver_C = C_proposed.value(3).toInt();

        ui->frame_5->setMinimumHeight(frameheight_5);
        QFrame *fram_C = new QFrame(ui->frame_5);
        fram_C->setGeometry(6,frame_Y_C,218,315);
        fram_C->setStyleSheet("border-radius: 5px;background-color: rgb(255,255,255);");

        QLabel *labelimage_C = new QLabel(fram_C);
        labelimage_C->setGeometry(10,47,198,178);
        labelimage_C->setStyleSheet("background-color: rgb(184, 184, 184)");
        QByteArray imageData_C = C_proposed.value(0).toByteArray();
        QPixmap image_C;
        image_C.loadFromData(imageData_C);
        labelimage_C->setPixmap(image_C.scaled(198,178)); // Change the size to match the label size
        labelimage_C->setScaledContents(true);

        QLabel *labelname_C = new QLabel(fram_C);
        labelname_C->setGeometry(8,12,179,30);
        labelname_C->setText(C_proposed.value(2).toString());

        QLabel *labelemail = new QLabel(fram_C);
        labelemail->setGeometry(10,235,80,23);
        labelemail->setText(C_proposed.value(1).toString());

        QPushButton *Connect_C = new QPushButton(fram_C);
        Connect_C->setGeometry(49,270,120,30);
        Connect_C->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(72, 123, 130);background-color:rgb(0, 170, 0);");
        Connect_C->setText("+Connect ");
        connect(Connect_C,&QPushButton::clicked,this,[this,number,receiver_C](){mynetworkuser::on_Connect_Company_clicked(number,receiver_C);});


        frameheight_5 += 325;
        frame_Y_C += 325;

        fram_C->show();
    }
}

mynetworkuser::~mynetworkuser()
{
    delete ui;
}

void mynetworkuser::on_viewProfile_user_clicked(int applicant){
    viewprofile *w = new viewprofile(applicant, "P");
    w->show();
}

void mynetworkuser::on_viewProfile_company_clicked(int applicant){
    viewprofile *w = new viewprofile(applicant, "C");
    w->show();
}

void mynetworkuser::on_Reject_user_clicked(int receiver,QString type_receiver,int applicant){
    QSqlQuery k;
    k.prepare("DELETE FROM list_connection WHERE Applicant = :applicant AND receiver = :number AND type_Applicant = :type_A AND type_receiver = :type_r");
    k.bindValue(":number" ,receiver);
    k.bindValue(":applicant", applicant);
    k.bindValue(":type_A" , "P");
    k.bindValue(":type_r", type_receiver);
    if(k.exec()){
        QMessageBox::information(nullptr,"job company","Your refusal to accept the cooperation request was recorded.");
        qDebug() << "Delete successful.";
    }
    mynetworkuser *w = new mynetworkuser(adad_m_u, Type_m_u);
    this->close();
    w->show();
}

void mynetworkuser::on_Reject_clicked(int number,QString type_receiver,int applicant){
    QSqlQuery k;
    k.prepare("DELETE FROM list_connection WHERE Applicant = :applicant AND receiver = :number");
    k.bindValue(":number" , number);
    k.bindValue(":applicant", applicant);
    k.bindValue(":type_A" , "C");
    k.bindValue(":type_r", type_receiver);
    if(k.exec()){
        QMessageBox::information(nullptr,"job company","Your refusal to accept the cooperation request was recorded.");
        qDebug() << "Delete successful.";
    }
    mynetworkuser *w = new mynetworkuser(adad_m_u, Type_m_u);
    this->close();
    w->show();
}

void mynetworkuser::on_Accept_clicked(int number,QString type_receiver,int applicant,QString type_Applicant){
    QSqlQuery k;
    k.prepare("DELETE FROM list_connection WHERE Applicant = :applicant AND receiver = :number AND type_receiver = :type_receiver AND type_Applicant = :type_Applicant");
    k.bindValue(":number" , number);
    k.bindValue(":applicant", applicant);
    k.bindValue(":type_Applicant" , type_Applicant);
    k.bindValue(":type_receiver" , type_receiver);

    if(k.exec()){
        qDebug() << "Delete successful.";
    }
///////////////////////////////////////////////////////////////////
    QJsonObject acceptObject_2;
    acceptObject_2["id_colleague"] = number;
    acceptObject_2["type_colleague"] = type_receiver;
    QSqlQuery p;
    if(type_Applicant == "C"){
        p.prepare("SELECT connection FROM CompanyInformation WHERE rowid = :id");
        p.bindValue(":id", applicant);
        if(p.exec() && p.next()) {
            QString jobsString = p.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray colleagueArray = doc.array();
            colleagueArray.append(acceptObject_2);
            QJsonDocument newDoc(colleagueArray);
            QString newColleague = newDoc.toJson();
            QString updateQuery = QString("UPDATE CompanyInformation SET connection = '%1' WHERE rowid = %2").arg(newColleague).arg(applicant);
            if (!p.exec(updateQuery)) {
                qDebug() << "Error: ";
            } else {
                qDebug() << "Record updated successfully!";
            }
    }
    }
    else if(type_Applicant == "P"){
        p.prepare("SELECT connection FROM verificationpage WHERE rowid = :id");
        p.bindValue(":id", applicant);
        if(p.exec() && p.next()) {
            QString jobsString = p.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray colleagueArray = doc.array();
            colleagueArray.append(acceptObject_2);
            QJsonDocument newDoc(colleagueArray);
            QString newColleague = newDoc.toJson();
            QString updateQuery = QString("UPDATE verificationpage SET connection = '%1' WHERE rowid = %2").arg(newColleague).arg(applicant);
            if (!p.exec(updateQuery)) {
                qDebug() << "Error: ";
            } else {
                qDebug() << "Record updated successfully!";
            }
        }
    }

///////////////////////////////////////////////////////////////////
    QJsonObject acceptObject;
    acceptObject["id_colleague"] = applicant;
    acceptObject["type_colleague"] = type_Applicant;
    QSqlQuery q;
    q.prepare("SELECT connection FROM verificationpage WHERE rowid = :id");
    q.bindValue(":id", number);
    if(q.exec() && q.next()) {
        QString jobsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray colleagueArray = doc.array();
        colleagueArray.append(acceptObject);
        QJsonDocument newDoc(colleagueArray);

        QString newColleague = newDoc.toJson();
        if(type_receiver == "P"){
        QString updateQuery = QString("UPDATE verificationpage SET connection = '%1' WHERE rowid = %2").arg(newColleague).arg(number);
        if (!q.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            QMessageBox::information(this,"job company","A new colleague has been added to your list of colleagues.");
            qDebug() << "Record updated successfully!";
        }
        }
        else if(type_receiver == "C"){
            QString updateQuery = QString("UPDATE CompanyInformation SET connection = '%1' WHERE rowid = %2").arg(newColleague).arg(number);
            if (!q.exec(updateQuery)) {
                qDebug() << "Error: ";
            } else {
                QMessageBox::information(this,"job company","A new colleague has been added to your list of colleagues.");
                qDebug() << "Record updated successfully!";
            }
        }
    }
    mynetworkuser *w = new mynetworkuser(adad_m_u,Type_m_u);
    this->close();
    w->show();
}

void mynetworkuser::on_Connect_Company_clicked(int applicant,int receiver_C){

    QString type_receiver = "C";
    content mycontent;
    mycontent.sand_connection_request(applicant,receiver_C,Type_m_u,type_receiver);
}
void mynetworkuser::on_Connect_clicked(int applicant,int receiver){

    qDebug() << receiver;
    QString type_receiver = "P";
    content mycontent;
    mycontent.sand_connection_request(applicant,receiver,Type_m_u,type_receiver);
}

void mynetworkuser::on_commandLinkButton_clicked()
{
    home *w3 = new home(adad_m_u,Type_m_u);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_m_u,Type_m_u);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_3_clicked()
{
    if (Type_m_u == "P"){

        jobsuser *w3 = new jobsuser(adad_m_u,Type_m_u);
        this->close();
        w3->show();

    }
    else if (Type_m_u == "C") {
        QMessageBox::warning(this, "home", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
}



void mynetworkuser::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_m_u, Type_m_u,nullptr);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser(adad_m_u,Type_m_u);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(adad_m_u,Type_m_u);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany(adad_m_u, Type_m_u);
    this->close();
    w3->show();
}

