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
#include "viewprofile.h"

int adad_h;
QVariant id;
QString name_h;

home::home(int number,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    QString name_L_or_C;
    QSqlQuery findname;
    findname.prepare("SELECT username FROM loginpage WHERE account_id = :number");
    findname.bindValue(":number", number);
    if(findname.exec()&&findname.next()){
    name_L_or_C = findname.value(0).toString();
    }
    adad_h = number;

    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();


    int frameHeight = 200;
    int currentY = 9;

    ui->frame_2->setGeometry(10, 10, 500, frameHeight);
    ui->frame_2->setStyleSheet("background-color:rgb(235, 235, 235);");

    QSqlQuery q;
    q.exec("SELECT post_text,post_image,username,post_id FROM post ORDER BY account_id");

    while(q.next()){

        ui->frame_2->setMinimumHeight(frameHeight);
        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(10, currentY, 510,360);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);");

        QString text = q.value(0).toString();
        QByteArray imageData = q.value(1).toByteArray();
        QString username = q.value(2).toString();
        QString id_p = q.value(3).toString();

        QLabel *imageLabel = new QLabel(groupBox);
        QPixmap image;
        image.loadFromData(imageData);
        imageLabel->setPixmap(image.scaled(476,180));
        imageLabel->setGeometry(315,95,150,125);
        imageLabel->setScaledContents(true);
        QFont font("Nirmala", 10, QFont::Light);
        QFont font_2("Nirmala IU",12, QFont::Light);

        QLineEdit *namelabel = new QLineEdit(username,groupBox);
        namelabel->setGeometry(50,25,200,35);
        namelabel->setStyleSheet("padding:6px;background-color:rgb(238,238,238);border-radius:13px;border:2px solid rgb(181, 56, 75);");
        QTextEdit *tex = new QTextEdit(groupBox);
        tex->setText(text);
        tex->setStyleSheet("background-color:rgb(242,242,242);border: 3px solid rgb(52, 103, 110); border-radius: 9px;");
        tex->setGeometry(10,75,280,170);
        tex->setReadOnly(true);

        QGroupBox *in_groupBox = new QGroupBox(groupBox);
        in_groupBox->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(181, 56, 75); border-radius:9px;");
        in_groupBox->setGeometry(10,270,485,60);

        QCommandLinkButton *like = new QCommandLinkButton(in_groupBox);
        like->setGeometry(20,10,70,40);
        like->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        like->setText("Like");
        like->setFont(font);

        QCommandLinkButton *comment = new QCommandLinkButton(in_groupBox);
        comment->setGeometry(130,10,100,40);
        comment->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        comment->setText("Comment");
        comment->setFont(font);
        connect(comment, &QCommandLinkButton::clicked, this,[this,name_L_or_C,id_p](){on_comment_Clicked(name_L_or_C,id_p.toInt());});

        QCommandLinkButton *repost = new QCommandLinkButton(in_groupBox);
        repost->setGeometry(270,10,100,40);
        repost->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        repost->setText("Repot");
        repost->setFont(font);

        QCommandLinkButton *send = new QCommandLinkButton(in_groupBox);
        send->setGeometry(390,10, 82,40);
        send->setStyleSheet("color:rgb(0, 0, 0); border:3px solid rgb(255, 255, 255); border-radius:9px;");
        send->setText("Send");
        send->setFont(font);

        QFont font_1("Segoe IU", 13, QFont::Bold);
        QCommandLinkButton *follow = new QCommandLinkButton(groupBox);
        follow->setGeometry(335,25,110,40);
        follow->setStyleSheet("color: rgb(14, 90, 230);");
        follow->setText("Follow");
        follow->setFont(font_1);

        QLineEdit *post_number_lineEdit = new QLineEdit(groupBox);
        post_number_lineEdit->setText(id_p);
        post_number_lineEdit->setGeometry(5,5,30,20);
        post_number_lineEdit->setStyleSheet(" border:3px solid rgb(255,255,255)");
        connect(like, &QCommandLinkButton::clicked, this,[this,name_L_or_C,id_p](){onLikeClicked(name_L_or_C,id_p.toInt());});

        QPushButton *whoLike = new QPushButton(groupBox);
        whoLike->setGeometry(315,234,150,30);
        whoLike->setText("who like this");
        whoLike->setFont(font_2);
        whoLike->setStyleSheet("background-color:rgb(255,255,255);color:#2980b9;border-radius:2px;");
        connect(whoLike, &QPushButton::clicked,this,[this,id_p](){home::on_likelistshow_clicked(id_p.toInt());});

        groupBox->show();
        frameHeight += 360;
        currentY += 360;
        //i++;
    }

    ui->frame_2->setFixedHeight(currentY);

    QScrollArea *s = new QScrollArea;
    s->setWidgetResizable(true);

}

void home::on_comment_Clicked(QString name_Comment,int id){
    comment *w = new comment(name_Comment,id);
    w->show();
}

void home::on_likelistshow_clicked(int id){
    likelist *w = new likelist(id);
    w->show();
}

void home::onLikeClicked(QString username_like,int id) {
       QSqlQuery query;
       query.prepare("INSERT INTO postLike (username,post_id) VALUES (:username,:adad)");
       query.bindValue(":username", username_like);
       query.bindValue(":adad",id);
       //id.clear();

       if(query.exec()) {
           qDebug() << "Like saved to database";
       } else {
           qDebug() << "Error saving like to database";
       }
   }
home::~home()
{
    delete ui;
}

void home::on_commandLinkButton_clicked()
{
        home *w3 = new home(adad_h);
        this->close();
        w3->show();
}


void home::on_commandLinkButton_2_clicked()
{
    me *w3 = new me;
    this->close();
    w3->show();
}


void home::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser;
    this->close();
    w3->show();
}


void home::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void home::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}
void home::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany;
    this->close();
    w3->show();
}
void home::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

void home::on_pushButton_clicked()
{
    //int number = o;
    post *w3 = new post(adad_h);
    this->close();
    w3->show();
}
