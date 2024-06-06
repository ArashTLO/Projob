#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include "post.h"
#include "ui_post.h"
#include "home.h"
#include "loginpage.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QFile"
#include "QByteArray"
#include "QShowEvent"
#include "QLabel"


int adad_p;
QString name_p;
post::post(int number,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::post)
{
    //ui->label_3->setPixmap(QPixmap());
    QSqlQuery q;
    q.prepare("SELECT username FROM loginpage WHERE account_id = :account_id");
    q.bindValue(":account_id", number);
    q.exec();
    if(q.next()){
        name_p = q.value("username").toString();
        numberLabel = new QLabel(name_p, this);
        numberLabel->setGeometry(41,120,210,40);
        numberLabel->setStyleSheet("padding:5px;background-color: rgb(132,183,190);border-radius:13px;border:3px solid rgb(52,103,110);");
    }
    adad_p = number;
    //name_p = name;
    //numberLabel = new QLabel("Received number: " + QString::number(number), this);
    //numberLabel = new QLabel(name_p, this);
    //numberLabel->setGeometry(90,160,300,30);
    connect(new loginpage, SIGNAL(sendData(int)), this, SLOT(receiveData(int)));
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();
}

QString filePath;


post::~post()
{
    delete ui;
}

void post::on_pushButton_clicked()
{
    QString s1 = ui->textEdit_post->toPlainText();

    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
    QByteArray imageData = file.readAll();

    QSqlQuery q;
    q.prepare("INSERT INTO post(post_text,post_image,account_id,username) VALUES(:text,:imageData,:id,:username)");
    q.bindValue(":text",s1);
    q.bindValue(":imageData",imageData);
    q.bindValue(":id", adad_p);
    q.bindValue(":username", name_p);
    q.exec();
    file.close();
    }
}

void post::on_pushButton_2_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,"Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty()){
        QPixmap pixmap(filePath);
        ui->label_3->setPixmap(pixmap.scaled(ui->label_3->size(), Qt::KeepAspectRatio));
    }
}


void post::on_pushButton_3_clicked()
{
    home *s = new home(adad_p);
    this->close();
    s->show();
}

