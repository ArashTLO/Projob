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
#include "QVariantList"
#include "QListWidgetItem"

int adad_h;
QVariant id;
QString name_h,Type_h;

home::home(int number,QString type,int number_post_show,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    qDebug() << number_post_show;
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

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &home::searchInDatabase);

    int frameHeight = 368,currentY = 8,frameHeight_3 = 368,currentY_3 = 8;


    ui->frame_2->setGeometry(1,10, 500, frameHeight);

    QSqlQuery c_info;
    c_info.prepare("SELECT posts FROM CompanyInformation");
    c_info.exec();
    c_info.seek(-1);

    int i = 0;

    while(c_info.next()){

    QString postsJsonString = c_info.value(0).toString();
    QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
    QJsonArray postsArray = doc.array();

    foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        int id_Company = postObject["id_C"].toInt();

        if(check_follower(number,type,"C",id_Company) == "Followed" && i < number_post_show){

        QSqlQuery q;
        q.prepare("SELECT name FROM CompanyInformation WHERE id_C = :id");
        q.bindValue(":id", id_Company);
        q.exec();
        q.next();

        QString name = q.value(0).toString();

        int id_post = postObject["post_id"].toInt();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_3->setMinimumHeight(frameHeight_3);
        ui->frame_3->setStyleSheet("background-color:rgb(235, 235, 235);");
        QGroupBox *groupBox = new QGroupBox(ui->frame_3);
        groupBox->setGeometry(5,currentY_3,505,370);
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

        QLineEdit *time_Date = new QLineEdit(groupBox);
        time_Date->setGeometry(15,335,160,25);
        time_Date->setText(postObject["Time_and_Date"].toString());
        time_Date->setReadOnly(true);

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
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_Company](){on_comment_Clicked(name_user,id_post,"C",id_Company);});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        QIcon iconRepost(":/download (2).png");
        connect(repost, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_repost_Clicked(number,type,postObject["post_image"].toString(),postObject["post_text"].toString());});
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
        follow->setGeometry(305,25,110,40);
        follow->setStyleSheet("color: rgb(24, 110, 170);");
        follow->setText(check_follower(number,type,"C",id_Company));
        QIcon iconfollow(":/2795.png");
        follow->setIcon(iconfollow);
        follow->setFont(font_1);
        connect(follow, &QCommandLinkButton::clicked, this,[this,number,type,id_Company](){on_follow_Clicked(number,type,"C",id_Company);});

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(QString::number(id_post));
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_Company](){onLikeClicked(name_user,id_post,"C",id_Company);});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(325,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_post,id_Company](){home::on_likelistshow_clicked(id_post,"C",id_Company);});

        if( i >= number_post_show - 10){
        groupBox->show();
        frameHeight_3 += 380;
        currentY_3 += 380;
        }
        i++;
    }
    }
}

    c_info.seek(-1);

    while(c_info.next()){

    QString postsJsonString = c_info.value(0).toString();
    QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
    QJsonArray postsArray = doc.array();

    foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        int id_Company = postObject["id_C"].toInt();

        if(check_follower(number,type,"C",id_Company) == "Follow" && i < number_post_show){

        QSqlQuery q;
        q.prepare("SELECT name FROM CompanyInformation WHERE id_C = :id");
        q.bindValue(":id", id_Company);
        q.exec();
        q.next();

        QString name = q.value(0).toString();

        int id_post = postObject["post_id"].toInt();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_3->setMinimumHeight(frameHeight_3);
        ui->frame_3->setStyleSheet("background-color:rgb(235, 235, 235);");
        QGroupBox *groupBox = new QGroupBox(ui->frame_3);
        groupBox->setGeometry(5,currentY_3,505,370);
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

        QLineEdit *time_Date = new QLineEdit(groupBox);
        time_Date->setGeometry(15,335,160,25);
        time_Date->setText(postObject["Time_and_Date"].toString());
        time_Date->setReadOnly(true);

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
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_Company](){on_comment_Clicked(name_user,id_post,"C",id_Company);});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        QIcon iconRepost(":/download (2).png");
        repost->setIcon(iconRepost);
        repost->setFont(font);
        connect(repost, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_repost_Clicked(number,type,postObject["post_image"].toString(),postObject["post_text"].toString());});

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
        follow->setGeometry(305,25,110,40);
        follow->setStyleSheet("color: rgb(24, 110, 170);");
        follow->setText(check_follower(number,type,"C",id_Company));
        QIcon iconfollow(":/2795.png");
        follow->setIcon(iconfollow);
        follow->setFont(font_1);
        connect(follow, &QCommandLinkButton::clicked, this,[this,number,type,id_Company](){on_follow_Clicked(number,type,"C",id_Company);});

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(QString::number(id_post));
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_Company](){onLikeClicked(name_user,id_post,"C",id_Company);});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(325,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_post,id_Company](){home::on_likelistshow_clicked(id_post,"C",id_Company);});

        if( i >= number_post_show - 10){
        groupBox->show();
        frameHeight_3 += 380;
        currentY_3 += 380;
        }
        i++;
    }
    }
}
    ui->frame_3->setMinimumHeight(frameHeight_3 - 325);
    QPushButton *seemore_C = new QPushButton(ui->frame_3);
    seemore_C->setGeometry(15,currentY_3 ,90,33);
    seemore_C->setStyleSheet("color: rgb(52, 103, 110); border-radius: 10px;");
    seemore_C->setText("See More ... ");
    connect(seemore_C, &QPushButton::clicked,this,[this,number,type,number_post_show](){home::on_SeeMore_clicked(number,type,number_post_show);});

///////////////////////////////////////////////////

    int j = 0;
    QSqlQuery p_info;
    p_info.prepare("SELECT posts FROM verificationpage");
    p_info.exec();
    p_info.seek(-1);

    while(p_info.next()){

    QString postsJsonString = p_info.value(0).toString();
    QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
    QJsonArray postsArray = doc.array();

    foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        int id_person = postObject["id_P"].toInt();

        if(check_follower(number,type,"P",id_person) == "Connect" && j < number_post_show ){

        QSqlQuery q;
        q.prepare("SELECT frstname,lastname FROM verificationpage WHERE account_id = :id_person");
        q.bindValue(":id_person", id_person);
        q.exec();
        q.next();

        QString name = q.value(0).toString() + " " + q.value(1).toString();

        int id_post = postObject["post_id"].toInt();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_2->setMinimumHeight(frameHeight);
        ui->frame_2->setStyleSheet("background-color:rgb(235, 235, 235);");
        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(5,currentY,505,370);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);border-radius: 8px;");

        QLineEdit *namelabel = new QLineEdit(name,groupBox);
        namelabel->setGeometry(50,25,200,35);
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

        QLineEdit *time_Date = new QLineEdit(groupBox);
        time_Date->setGeometry(15,335,160,25);
        time_Date->setText(postObject["Time_and_Date"].toString());
        time_Date->setReadOnly(true);

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
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_person](){on_comment_Clicked(name_user,id_post,"P",id_person);});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        QIcon iconRepost(":/download (2).png");
        repost->setIcon(iconRepost);
        repost->setFont(font);
        connect(repost, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_repost_Clicked(number,type,postObject["post_image"].toString(),postObject["post_text"].toString());});

        QCommandLinkButton *send = new QCommandLinkButton(in_groupBox);
        send->setGeometry(400,10, 82,40);
        send->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        send->setText("Send");
        QIcon iconSend(":/images (9).png");
        send->setIcon(iconSend);
        send->setFont(font);
        connect(send, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_send_Clicked(number,type,postObject["post_text"].toString());});

        QFont font_1("Segoe IU", 13, QFont::Bold);
        QCommandLinkButton *Connection = new QCommandLinkButton(groupBox);
        Connection->setGeometry(305,25,160,40);
        Connection->setStyleSheet("color: rgb(24, 110, 170);");
        Connection->setText(check_follower(number,type,"P",id_person));
        QIcon iconfollow(":/2795.png");
        Connection->setIcon(iconfollow);
        Connection->setFont(font_1);
        connect(Connection, &QCommandLinkButton::clicked, this,[this,number,type,id_person](){on_follow_Clicked(number,type,"P",id_person);});

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(QString::number(id_post));
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_person](){onLikeClicked(name_user,id_post,"P",id_person);});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(325,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_post,id_person](){home::on_likelistshow_clicked(id_post,"P",id_person);});

        if( j >= number_post_show - 10){
        groupBox->show();
        frameHeight += 380;
        currentY += 380;
        }
        j++;
        }
    }
    }
    p_info.seek(-1);

    while(p_info.next()){

    QString postsJsonString = p_info.value(0).toString();
    QJsonDocument doc = QJsonDocument::fromJson(postsJsonString.toUtf8());
    QJsonArray postsArray = doc.array();

    foreach (const QJsonValue &postValue,postsArray){

        QJsonObject postObject = postValue.toObject();
        int id_person = postObject["id_P"].toInt();

        if(check_follower(number,type,"P",id_person) == "Connection" && j < number_post_show ){

        QSqlQuery q;
        q.prepare("SELECT frstname,lastname FROM verificationpage WHERE account_id = :id_person");
        q.bindValue(":id_person", id_person);
        q.exec();
        q.next();

        QString name = q.value(0).toString() + " " + q.value(1).toString();

        int id_post = postObject["post_id"].toInt();
        QString postImageb64 = postObject["post_image"].toString();
        QByteArray Image_Data = QByteArray::fromBase64(postImageb64.toUtf8());

        ui->frame_2->setMinimumHeight(frameHeight);
        ui->frame_2->setStyleSheet("background-color:rgb(235, 235, 235);");
        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(5,currentY,505,370);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);border-radius: 8px;");

        QLineEdit *namelabel = new QLineEdit(name,groupBox);
        namelabel->setGeometry(50,25,200,35);
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

        QLineEdit *time_Date = new QLineEdit(groupBox);
        time_Date->setGeometry(15,335,160,25);
        time_Date->setText(postObject["Time_and_Date"].toString());
        time_Date->setReadOnly(true);

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
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_person](){on_comment_Clicked(name_user,id_post,"P",id_person);});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        QIcon iconRepost(":/download (2).png");
        repost->setIcon(iconRepost);
        repost->setFont(font);
        connect(repost, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_repost_Clicked(number,type,postObject["post_image"].toString(),postObject["post_text"].toString());});

        QCommandLinkButton *send = new QCommandLinkButton(in_groupBox);
        send->setGeometry(400,10, 82,40);
        send->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        send->setText("Send");
        QIcon iconSend(":/images (9).png");
        send->setIcon(iconSend);
        send->setFont(font);
        connect(send, &QCommandLinkButton::clicked, this,[this,number,type,postObject](){on_send_Clicked(number,type,postObject["post_text"].toString());});

        QFont font_1("Segoe IU", 13, QFont::Bold);
        QCommandLinkButton *Connection = new QCommandLinkButton(groupBox);
        Connection->setGeometry(305,25,160,40);
        Connection->setStyleSheet("color: rgb(24, 110, 170);");
        Connection->setText(check_follower(number,type,"P",id_person));
        QIcon iconfollow(":/2795.png");
        Connection->setIcon(iconfollow);
        Connection->setFont(font_1);
        connect(Connection, &QCommandLinkButton::clicked, this,[this,number,type,id_person](){on_follow_Clicked(number,type,"P",id_person);});

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(QString::number(id_post));
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_user,id_post,id_person](){onLikeClicked(name_user,id_post,"P",id_person);});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(325,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_post,id_person](){home::on_likelistshow_clicked(id_post,"P",id_person);});

        if(j >= number_post_show - 10){
        groupBox->show();
        frameHeight += 380;
        currentY += 380;
        }
        j++;
        }
    }
    }

    ui->frame_2->setMinimumHeight(frameHeight - 325);
    QPushButton *seemore_P = new QPushButton(ui->frame_2);
    seemore_P->setGeometry(15,currentY ,90,33);
    seemore_P->setStyleSheet("color: rgb(52, 103, 110); border-radius: 10px;");
    seemore_P->setText("See More ... ");
    connect(seemore_P, &QPushButton::clicked,this,[this,number,type,number_post_show](){home::on_SeeMore_clicked(number,type,number_post_show);});

}

void home::on_SeeMore_clicked(int number,QString type,int number_post_show){

    number_post_show += 10;
    home *w = new home(number,type,number_post_show);
    this->close();
    w->show();
}
void home::searchInDatabase()
{
    QString searchUsername = ui->lineEdit->text();

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

QString home::check_follower(int id_follower, QString type_follower, QString type_following, int id_following){

    QJsonObject follow;
    follow["id_follower"] = id_follower;
    follow["type_follower"] = type_follower;

    if (type_following == "C") {
        QSqlQuery query;
        query.prepare("SELECT following FROM CompanyInformation WHERE rowid = :id");
        query.bindValue(":id", id_following);

        if (query.exec() && query.next()) {
            QString followingData = query.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(followingData.toUtf8());
            QJsonArray followingArray = doc.array();

            bool dataExists = false;
            for (auto item : followingArray) {
                QJsonObject itemObject = item.toObject();
                if (itemObject["id_follower"].toInt() == id_follower && itemObject["type_follower"].toString() == type_follower) {
                    dataExists = true;
                    break;
                }
            }
            if (!dataExists) {
                return "Follow";
            } else {
                return "Followed";
            }
        }
    }
    if (type_following == "P") {
        QSqlQuery query;
        query.prepare("SELECT following FROM verificationpage WHERE rowid = :id");
        query.bindValue(":id", id_following);

        if (query.exec() && query.next()) {
            QString followingData = query.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(followingData.toUtf8());
            QJsonArray followingArray = doc.array();

            bool dataExists = false;
            for (auto item : followingArray) {
                QJsonObject itemObject = item.toObject();
                if (itemObject["id_follower"].toInt() == id_follower && itemObject["type_follower"].toString() == type_follower) {
                    dataExists = true;
                    break;
                }
            }

            if (!dataExists) {
                return "Connection";
            } else {
                return "Connect";
            }
        }
    }
}
void home::on_repost_Clicked(int number,QString type,QString repost_image,QString repost_text){

    post *w = new post(number,type,repost_image,repost_text);
    this->close();
    w->show();
}
void home::on_follow_Clicked(int id_follower, QString type_follower, QString type_post, int id_following){

    QJsonObject follow;
    follow["id_follower"] = id_follower;
    follow["type_follower"] = type_follower;

    if (type_post == "C") {
        QSqlQuery query;
        query.prepare("SELECT following FROM CompanyInformation WHERE rowid = :id");
        query.bindValue(":id", id_following);

        if (query.exec() && query.next()) {
            QString followingData = query.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(followingData.toUtf8());
            QJsonArray followingArray = doc.array();

            bool dataExists = false;
            for (auto item : followingArray) {
                QJsonObject itemObject = item.toObject();
                if (itemObject["id_follower"].toInt() == id_follower && itemObject["type_follower"].toString() == type_follower) {
                    dataExists = true;
                    break;
                }
            }
            if (!dataExists) {
                followingArray.append(QJsonValue::fromVariant(follow));
                QJsonDocument newDoc(followingArray);
                QString newFollowingData = newDoc.toJson();

                QString updateQuery = QString("UPDATE CompanyInformation SET following = '%1' WHERE rowid = %2").arg(newFollowingData).arg(id_following);

                QSqlQuery updateQueryExec;
                if (!updateQueryExec.exec(updateQuery)) {
                    qDebug() << "Error updating the record!";
                } else {
                    QMessageBox::information(this, "Home", "The desired post has been followed successfully");
                }
            } else {
                QMessageBox::information(this, "Home", "You have already followed this company.");
            }
        }
    }
    if (type_post == "P") {
        QSqlQuery query;
        query.prepare("SELECT following FROM verificationpage WHERE rowid = :id");
        query.bindValue(":id", id_following);

        if (query.exec() && query.next()) {
            QString followingData = query.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(followingData.toUtf8());
            QJsonArray followingArray = doc.array();

            bool dataExists = false;
            for (auto item : followingArray) {
                QJsonObject itemObject = item.toObject();
                if (itemObject["id_follower"].toInt() == id_follower && itemObject["type_follower"].toString() == type_follower) {
                    dataExists = true;
                    break;
                }
            }

            if (!dataExists) {
                followingArray.append(QJsonValue::fromVariant(follow));
                QJsonDocument newDoc(followingArray);
                QString newFollowingData = newDoc.toJson();

                QString updateQuery = QString("UPDATE verificationpage SET following = '%1' WHERE rowid = %2").arg(newFollowingData).arg(id_following);

                QSqlQuery updateQueryExec;
                if (!updateQueryExec.exec(updateQuery)) {
                    qDebug() << "Error updating the record!";
                } else {
                    qDebug() << "Record updated successfully!";
                    QMessageBox::information(this, "Home", "The desired post has been followed successfully");
                }
            } else {
                QMessageBox::information(this, "Home", "You have already followed this person.");
            }
        }
    }
    home *W = new home(adad_h,Type_h,10);
    this->close();
    W->show();
}
void home::on_send_Clicked(int number,QString type,QString text_message){

    messaging *w = new messaging(number,type,text_message);
    w->show();

}
void home::on_comment_Clicked( QString name_user, int id_post, QString type_post, int id_receive){
    comment *w = new comment(name_user,id_post,type_post,id_receive);
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
        home *w3 = new home(adad_h,Type_h,10);
        this->close();
        w3->show();
}


void home::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_h,Type_h);
    this->close();
    w3->show();
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
    else if (Type_h == "C"){
    jobscompany *w3 = new jobscompany(adad_h,Type_h);
    this->close();
    w3->show();
    }
}
void home::on_commandLinkButton_6_clicked()
{
    if(Type_h == "P"){
        QMessageBox::warning(this, "home" , "Only companies can enter the desired window.");
    }
    else if (Type_h == "C") {
    mynetworkcompany *w3 = new mynetworkcompany(adad_h,Type_h);
    this->close();
    w3->show();
    }
}
void home::on_pushButton_clicked()
{
    post *w3 = new post(adad_h,Type_h,nullptr,nullptr);
    this->close();
    w3->show();
}
