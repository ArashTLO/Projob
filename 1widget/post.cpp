#include <QApplication>
#include <QMainWindow>
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
#include "content.h"
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include <QDebug>
#include "QMessageBox"

int adad_p;
QString name_p,Type_p;
QString *n;
post::post(int number,QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::post)
{
    Type_p = type;

    content myContent;
    name_p = myContent.check_type(type,number);
    numberLabel = new QLabel(name_p, this);
    numberLabel->setGeometry(41,120,210,40);
    numberLabel->setStyleSheet("padding:5px;background-color: rgb(132,183,190);border-radius:13px;border:3px solid rgb(52,103,110);");
    adad_p = number;

    connect(new loginpage, SIGNAL(sendData(int)), this, SLOT(receiveData(int)));
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();
}

QString filePath1;

post::~post()
{
    delete ui;
}
void post::on_pushButton_clicked()
{
    QString text_post = ui->textEdit_post->toPlainText();

    QFile imageFile(filePath1);

    if (imageFile.open(QIODevice::ReadOnly)) {
        QByteArray imageData = imageFile.readAll();

        if(Type_p == "P"){

        POST mypost(adad_p,text_post,imageData);
        mypost.posting_user();
        }
        else if(Type_p == "C"){

        POST mypost(adad_p,text_post,imageData);
        mypost.posting_company();
        }
}
}
void post::on_pushButton_2_clicked()
{
    filePath1 = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath1.isEmpty()) {
        QPixmap pixmap(filePath1);
        ui->label_3->setPixmap(pixmap.scaled(ui->label_3->size(), Qt::KeepAspectRatio));
    }
}

void post::on_pushButton_3_clicked()
{
    home *s = new home(adad_p,Type_p);
    this->close();
    s->show();
}
