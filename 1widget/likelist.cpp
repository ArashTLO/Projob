#include "likelist.h"
#include "ui_likelist.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QLineEdit"
#include "QGroupBox"

likelist::likelist(int id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::likelist)
{
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    QSqlQuery p;
    p.prepare("SELECT post_text,post_image FROM post WHERE post_id = :id");
    p.bindValue(":id", id);
    p.exec();
    p.next();

    ui->textEdit_2->setText(p.value(0).toString());
   // ui->lineEdit->setText(p.value(2).toString());
    QByteArray imageData = p.value(1).toByteArray();
    QPixmap image;
    image.loadFromData(imageData);
    ui->label->setPixmap(image.scaled(476,180));


    int frameHeight = 51;
    int currentY = 9;

    ui->frame_2->setGeometry(10,10,200,frameHeight);
    ui->frame_2->setStyleSheet("background-color: rgb(255,255,255);");

    QSqlQuery q;
    QString query = QString("SELECT username FROM postLike WHERE post_id = %1 ORDER BY post_id").arg(id);
    q.exec(query);
    while(q.next()){
        QFont font("Nirmala", 10, QFont::Light);
        ui->frame_2->setMinimumHeight(frameHeight);
        QString username = q.value(0).toString();

        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(5,currentY,190,43);

        QLineEdit *namelabel = new QLineEdit(username,groupBox);
        namelabel->setGeometry(0,0,190,43);
        namelabel->setStyleSheet("padding:9px;background-color:#fdfedb;border-radius:1px;border-bottom:2px solid rgb(181, 56, 75);");
        namelabel->setFont(font);

        groupBox->show();
        frameHeight += 43;
        currentY += 43;
    }
}

likelist::~likelist()
{
    delete ui;
}

void likelist::on_pushButton_3_clicked()
{
    this->close();
}

