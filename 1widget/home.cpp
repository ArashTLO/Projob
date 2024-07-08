#include "home.h"
#include "ui_home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "mynetworkuser.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include "post.h"
#include "QScrollArea"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QPixmap"
#include "QWidget"
#include "QLabel"
#include "QGroupBox"
#include "QTextEdit"
#include "QDebug"
#include "likelist.h"
#include "comment.h"
#include "QMessageBox"
#include "viewprofile.h"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "content.h"

int adad_h;
QVariant id;
QString name_h,Type_h;

home::home(int number,QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    Type_h = type;
    QString name_user;
    ////////////////////////////////////////////////////////////////////////////
    if(type == "P"){
    QSqlQuery findname;
    findname.prepare("SELECT username FROM loginpage WHERE account_id = :number");
    findname.bindValue(":number", number);
    if(findname.exec()&&findname.next()){
    name_user = findname.value(0).toString();
    }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(type == "C"){
    QSqlQuery findname;
    findname.prepare("SELECT name FROM CompanyInformation WHERE id_C = :number");
    findname.bindValue(":number", number);
    if(findname.exec()&&findname.next()){
    name_user = findname.value(0).toString();
    }
    }
    ///////////////////////////////////////////////////////////////////////////
    adad_h = number;

    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();


    int frameHeight = 368,currentY = 8,frameHeight_3 = 368,currentY_3 = 8;


    ui->frame_2->setGeometry(1,10, 500, frameHeight);

    QSqlQuery c_info;
    c_info.prepare("SELECT posts FROM CompanyInformation");
    c_info.exec();

    while(c_info.next()){

    QString postsJsonString = c_info.value(0).toString();
    QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
    QJsonArray postsArray = doc.array();

    foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        int id_Company = postObject["id_C"].toInt();
        QSqlQuery q;
        q.prepare("SELECT name FROM CompanyInformation WHERE id_C = :id");
        q.bindValue(":id", id_Company);
        q.exec();
        q.next();

        QString name = q.value(0).toString();

        int id_p = postObject["post_id"].toInt();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_3->setMinimumHeight(frameHeight_3);
        ui->frame_3->setStyleSheet("background-color:rgb(235, 235, 235);");
        QGroupBox *groupBox = new QGroupBox(ui->frame_3);
        groupBox->setGeometry(5,currentY_3,505,350);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);border-radius: 8px;");

        QLineEdit *namelabel = new QLineEdit(name,groupBox);
        namelabel->setGeometry(50,25,200,35);
        namelabel->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
        namelabel->setStyleSheet("padding:6px;background-color:rgb(238,238,238);border-radius:13px;border:2px solid rgb(181, 56, 75);");

        QLabel *imageLabel = new QLabel(groupBox);
        QPixmap image;
        image.loadFromData(Image_Data);
        imageLabel->setPixmap(image.scaled(476,180));
        imageLabel->setGeometry(315,75,170,150);
        imageLabel->setScaledContents(true);

        QTextEdit *tex = new QTextEdit(groupBox);
        tex->setText(postObject["post_text"].toString());
        tex->setStyleSheet("background-color:rgb(238,238,238);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
        tex->setGeometry(15,80,280,170);
        tex->setReadOnly(true);

        QGroupBox *in_groupBox = new QGroupBox(groupBox);
        in_groupBox->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(181, 56, 75); border-radius:9px;");
        in_groupBox->setGeometry(10,270,485,60);

        QFont font("Nirmala", 10, QFont::Light);
        QFont font_2("Nirmala IU",12, QFont::Light);

        QCommandLinkButton *like = new QCommandLinkButton(in_groupBox);
        like->setGeometry(20,10,70,40);
        like->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        like->setText("Like");
        like->setFont(font);
        QIcon iconLike(":/unnamed.jpg");
        like->setIcon(iconLike);

        QCommandLinkButton *comment = new QCommandLinkButton(in_groupBox);
        comment->setGeometry(140,10,100,40);
        comment->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        comment->setText("Comment");
        comment->setFont(font);
        QIcon iconComment(":/425269-icone-de-bate-papo-de-gratis-vetor.jpg");
        comment->setIcon(iconComment);
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_user,id_p](){on_comment_Clicked(name_user,id_p);});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        QIcon iconRepost(":/download (2).png");
        repost->setIcon(iconRepost);
        repost->setFont(font);

        QCommandLinkButton *send = new QCommandLinkButton(in_groupBox);
        send->setGeometry(400,10, 82,40);
        send->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        send->setText("Send");
        QIcon iconSend(":/images (9).png");
        send->setIcon(iconSend);
        send->setFont(font);
        connect(send, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_send_Clicked(number,type,postObject["post_text"].toString());});

        QFont font_1("Segoe IU", 13, QFont::Bold);
        QCommandLinkButton *follow = new QCommandLinkButton(groupBox);
        follow->setGeometry(335,25,110,40);
        follow->setStyleSheet("color: rgb(24, 110, 170);");
        follow->setText("Follow");
        QIcon iconfollow(":/2795.png");
        follow->setIcon(iconfollow);
        follow->setFont(font_1);

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(QString::number(id_p));
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_user,id_p,id_Company](){onLikeClicked(name_user,id_p,"C",id_Company);});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(325,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_p,id_Company](){home::on_likelistshow_clicked(id_p,"C",id_Company);});

        groupBox->show();
        frameHeight_3 += 360;
        currentY_3 += 360;
    }
}
///////////////////////////////////////////////////

    QSqlQuery p_info;
    p_info.prepare("SELECT posts FROM verificationpage");
    p_info.exec();

    while(p_info.next()){

    QString postsJsonString = p_info.value(0).toString();
    QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
    QJsonArray postsArray = doc.array();

    foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        int id_person = postObject["id_P"].toInt();
        QSqlQuery q;
        q.prepare("SELECT frstname,lastname FROM verificationpage WHERE account_id = :id_person");
        q.bindValue(":id_person", id_person);
        //q.next();
        q.exec();
        q.next();

        QString name = q.value(0).toString() + " " + q.value(1).toString();

        int id_p = postObject["post_id"].toInt();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_2->setMinimumHeight(frameHeight);
        ui->frame_2->setStyleSheet("background-color:rgb(235, 235, 235);");
        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(5,currentY,505,350);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);border-radius: 8px;");

        QLineEdit *namelabel = new QLineEdit(name,groupBox);
        namelabel->setGeometry(50,25,200,35);
        namelabel->setStyleSheet("background-color: rgb(202, 243, 250);color: rgb(0, 0, 0);border-radius: 10px;padding: 10px;");
        namelabel->setStyleSheet("padding:6px;background-color:rgb(238,238,238);border-radius:13px;border:2px solid rgb(181, 56, 75);");

        QLabel *imageLabel = new QLabel(groupBox);
        QPixmap image;
        image.loadFromData(Image_Data);
        imageLabel->setPixmap(image.scaled(476,180));
        imageLabel->setGeometry(315,75,170,150);
        imageLabel->setScaledContents(true);

        QTextEdit *tex = new QTextEdit(groupBox);
        tex->setText(postObject["post_text"].toString());
        tex->setStyleSheet("background-color:rgb(238,238,238);border:2px solid rgb(52, 103, 110);border-radius: 13px; padding: 6px;");
        tex->setGeometry(15,80,280,170);
        tex->setReadOnly(true);

        QGroupBox *in_groupBox = new QGroupBox(groupBox);
        in_groupBox->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(181, 56, 75); border-radius:9px;");
        in_groupBox->setGeometry(10,270,485,60);

        QFont font("Nirmala", 10, QFont::Light);
        QFont font_2("Nirmala IU",12, QFont::Light);

        QCommandLinkButton *like = new QCommandLinkButton(in_groupBox);
        like->setGeometry(20,10,70,40);
        like->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        like->setText("Like");
        like->setFont(font);
        QIcon iconLike(":/unnamed.jpg");
        like->setIcon(iconLike);

        QCommandLinkButton *comment = new QCommandLinkButton(in_groupBox);
        comment->setGeometry(140,10,100,40);
        comment->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        comment->setText("Comment");
        comment->setFont(font);
        QIcon iconComment(":/425269-icone-de-bate-papo-de-gratis-vetor.jpg");
        comment->setIcon(iconComment);
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_user,id_p](){on_comment_Clicked(name_user,id_p);});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        QIcon iconRepost(":/download (2).png");
        repost->setIcon(iconRepost);
        repost->setFont(font);

        QCommandLinkButton *send = new QCommandLinkButton(in_groupBox);
        send->setGeometry(400,10, 82,40);
        send->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        send->setText("Send");
        QIcon iconSend(":/images (9).png");
        send->setIcon(iconSend);
        send->setFont(font);
        connect(send, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_send_Clicked(number,type,postObject["post_text"].toString());});

        QFont font_1("Segoe IU", 13, QFont::Bold);
        QCommandLinkButton *follow = new QCommandLinkButton(groupBox);
        follow->setGeometry(335,25,110,40);
        follow->setStyleSheet("color: rgb(24, 110, 170);");
        follow->setText("Follow");
        QIcon iconfollow(":/2795.png");
        follow->setIcon(iconfollow);
        follow->setFont(font_1);

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(QString::number(id_p));
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_user,id_p,id_person](){onLikeClicked(name_user,id_p,"P",id_person);});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(325,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_p,id_person](){home::on_likelistshow_clicked(id_p,"P",id_person);});

        groupBox->show();
        frameHeight += 360;
        currentY += 360;


    }
    }

}

void home::on_send_Clicked(int number,QString type,QString text_message){

    messaging *w = new messaging(number,type,text_message);
    w->show();

}
void home::on_comment_Clicked(QString name_Comment,int id){
    comment *w = new comment(name_Comment,id,Type_h);
    w->show();
}

void home::on_likelistshow_clicked(int post_id, QString post_type,int account_id){
    likelist *w = new likelist(post_id,post_type,account_id);
    w->show();
}

void home::onLikeClicked(QString username_like,int post_id,QString post_type, int liked_account_id) {

    Like addlike( post_type, username_like, post_id, liked_account_id);
    addlike.Register_like();

}
home::~home()
{
    delete ui;
}

void home::on_commandLinkButton_clicked()
{
        home *w3 = new home(adad_h,Type_h);
        this->close();
        w3->show();
}


void home::on_commandLinkButton_2_clicked()
{
    if(Type_h == "C"){
        QMessageBox::information(this,"Login","Only individuals can enter this window and companies cannot enter this window.");
    }
    else{
    me *w3 = new me(adad_h,Type_h);
    this->close();
    w3->show();
    }
}


void home::on_commandLinkButton_3_clicked()
{
    if (Type_h == "P"){

        jobsuser *w3 = new jobsuser(adad_h,Type_h);
        this->close();
        w3->show();
    }
    else if (Type_h == "C") {
        QMessageBox::warning(this, "home", "Only persons can enter the desired window.");
    }
    else{
        QMessageBox::warning(this, "home", "the account is valid.");
    }
}
void home::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging(adad_h,Type_h,nullptr);
    this->close();
    w3->show();
}
void home::on_commandLinkButton_5_clicked()
{

    mynetworkuser *w3 = new mynetworkuser(adad_h,Type_h);
    this->close();
    w3->show();
}
void home::on_commandLinkButton_7_clicked()
{
    if(Type_h == "P"){
        QMessageBox::warning(this, "home" , "Only companies can enter the desired window.");
    }
    else{
    jobscompany *w3 = new jobscompany(adad_h,Type_h);
    this->close();
    w3->show();
    }
}
void home::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany(adad_h,Type_h);
    this->close();
    w3->show();
}
void home::on_pushButton_clicked()
{
    post *w3 = new post(adad_h,Type_h);
    this->close();
    w3->show();
}
