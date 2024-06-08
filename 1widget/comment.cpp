#include "comment.h"
#include "ui_comment.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QLineEdit"
#include "QGroupBox"
#include "QTextEdit"

QString name_C;
int id_C;
comment::comment(QString name,int id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::comment)
{
    ui->setupUi(this);
    name_C = name;
    id_C = id;
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();


    QSqlQuery p;
    p.prepare("SELECT post_text,post_image,username FROM post WHERE post_id = :id");
    p.bindValue(":id", id);
    p.exec();
    p.next();
    ui->textEdit_2->setText(p.value(0).toString());
    ui->lineEdit->setText(p.value(2).toString());
    QByteArray imageData = p.value(1).toByteArray();
    QPixmap image;
    image.loadFromData(imageData);
    ui->label->setPixmap(image.scaled(476,180));

    int frameHeight = 265;
    int currentY = 9;

    ui->frame_2->setGeometry(10,10,200,frameHeight);
    ui->frame_2->setStyleSheet("background-color: rgb(192, 221, 190);");

    QSqlQuery q;
    QString query = QString("SELECT username,textcomment FROM postComment WHERE post_id = %1 ORDER BY post_id").arg(id);
    q.exec(query);
    while(q.next()){

        QFont font_2("Nirmala IU",12, QFont::Light);

        ui->frame_2->setMinimumHeight(frameHeight);

        QGroupBox *groupBox = new QGroupBox(ui->frame_2);

        groupBox->setGeometry(10, currentY,300,245);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);");

        QString username = q.value(0).toString();
        QString text = q.value(1).toString();

        QLineEdit *namelabel = new QLineEdit(username,groupBox);
        namelabel->setGeometry(15,10,200,35);
        namelabel->setStyleSheet("padding:6px;background-color:rgb(238,238,238);border-radius:13px;border:2px solid rgb(181, 56, 75);");

        QTextEdit *tex = new QTextEdit(groupBox);
        tex->setText(text);
        tex->setStyleSheet("padding:5px;margin:5px;background-color:rgb(242,242,242);border: 3px solid rgb(52, 103, 110); border-radius: 9px;");
        tex->setGeometry(10,50,280,170);
        tex->setReadOnly(true);
        tex->setFont(font_2);

        groupBox->show();
        frameHeight += 255;
        currentY += 255;
    }
}


comment::~comment()
{
    delete ui;
}

void comment::on_pushButton_clicked()
{
    if( ui->textEdit->toPlainText() != ""){
        //QString text = ui->
        QSqlQuery q;
        q.prepare("INSERT INTO postComment(post_id,textComment,username) VALUES(:id,:text,:username)");
        q.bindValue(":text",ui->textEdit->toPlainText());
        q.bindValue(":id", id_C);
        q.bindValue(":username", name_C);
        q.exec();

    }
}


void comment::on_pushButton_2_clicked()
{
    this->close();
}

