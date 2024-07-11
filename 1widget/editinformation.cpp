#include "editinformation.h"
#include "ui_editinformation.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QByteArray"
#include "QFileDialog"
#include "me.h"
#include "QMessageBox"
#include "QDebug"
#include "content.h"

QString filePath_2,Type_e;
int adad_e;
QByteArray imageData;
editinformation::editinformation(int number, QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editinformation)
{
    ui->setupUi(this);
    adad_e = number;
    Type_e = type;

    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    if(type == "P"){
         ui->tabWidget->setCurrentIndex(0);
    QSqlQuery q;
    q.prepare("SELECT username,password,frstname,lastname,email,skills,nationality,school,start_year,end_year,date_birth,image FROM verificationpage WHERE account_id = :number");
    q.bindValue(":number", number);
    q.exec();
    q.next();

    ui->lineEdit_username->setText(q.value(0).toString());
    ui->lineEdit_password->setText(q.value(1).toString());
    ui->lineEdit_fname->setText(q.value(2).toString());
    ui->lineEdit_lname->setText(q.value(3).toString());
    ui->lineEdit_email->setText(q.value(4).toString());
    ui->lineEdit_skills->setText(q.value(5).toString());
    ui->lineEdit_na->setText(q.value(6).toString());
    ui->lineEdit_school->setText(q.value(7).toString());
    ui->spinBox_start_year->setValue(q.value(8).toInt());
    ui->spinBox_end_year->setValue(q.value(9).toInt());
    imageData = q.value(11).toByteArray();
    QPixmap image;
    image.loadFromData(imageData);
    ui->label_10->setPixmap(image.scaled(476,180));
    ui->dateEdit->setDate(q.value(10).toDate());
    }
    else if(type == "C"){
        ui->tabWidget->setCurrentIndex(1);
        QSqlQuery p;
        p.prepare("SELECT name,password,phoneNumber,email,address,image_C FROM CompanyInformation WHERE id_C = :number");
        p.bindValue(":number", number);
        p.exec();
        p.next();

        ui->lineEdit_name_company->setText(p.value(0).toString());
        ui->lineEdit_password_2->setText(p.value(1).toString());
        ui->lineEdit_phone->setText(p.value(2).toString());
        ui->lineEdit_email_2->setText(p.value(3).toString());
        ui->textEdit_address->setText(p.value(4).toString());
        imageData = p.value(5).toByteArray();
        QPixmap image_c;
        image_c.loadFromData(imageData);
        ui->label_12->setPixmap(image_c.scaled(181,161));
    }
}

editinformation::~editinformation()
{
    delete ui;
}

int Sw = 0;

void editinformation::on_pushButton_select_photo_clicked()
{
    Sw = 1;

    filePath_2 = QFileDialog::getOpenFileName(this,"Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath_2.isEmpty()){
        QPixmap pixmap(filePath_2);
        ui->label_10->setPixmap(pixmap.scaled(ui->label_10->size(), Qt::KeepAspectRatio));
    }
}
int Sw_1 = 0;

void editinformation::on_pushButton_select_photo_2_clicked()
{
    Sw_1 = 1;

    filePath_2 = QFileDialog::getOpenFileName(this,"Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath_2.isEmpty()){
        QPixmap pixmap(filePath_2);
        ui->label_12->setPixmap(pixmap.scaled(ui->label_10->size(), Qt::KeepAspectRatio));
    }
}

void editinformation::on_pushButton_back_clicked()
{
    QString s9 = ui->lineEdit_username->text();
    QString P = ui->lineEdit_password->text();
    QString f = ui->lineEdit_fname->text();//
    QString l = ui->lineEdit_lname->text();//
    QString e = ui->lineEdit_email->text();//
    QString sk = ui->lineEdit_skills->text();//
    QString school = ui->lineEdit_school->text();
    QString start_y = ui->spinBox_start_year->text();
    QString end_y = ui->spinBox_end_year->text();
    QString birth = ui->dateEdit->text();
    QString n = ui->lineEdit_na->text();


    QFile file(filePath_2);
    if (file.open(QIODevice::ReadOnly)) {

        QByteArray imageData = file.readAll();

        Account myAccount(f,l,sk,adad_e,e);
        myAccount.Change_user_information(s9,P,school,start_y,end_y,birth,n,imageData,Type_e);
        this->close();
    }
    else if (Sw == 0) {

        Account myAccount(f,l,sk,adad_e,e);
        myAccount.Change_user_information(s9,P,school,start_y,end_y,birth,n,imageData,Type_e);
        this->close();
    }
}

void editinformation::on_pushButton_change_user_2_clicked()
{
    QString n_C = ui->lineEdit_name_company->text();
    QString P = ui->lineEdit_password_2->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email_2->text();
    QString address_C = ui->textEdit_address->toPlainText();

    QFile file(filePath_2);
    if (file.open(QIODevice::ReadOnly)) {

        QByteArray imageData = file.readAll();

        QSqlQuery c;
        c.prepare("UPDATE CompanyInformation SET name = :name,password = :password,phoneNumber = :phoneNumber, email = :email, address = :address, image_C = :image WHERE id_C = :number");
        c.bindValue(":number", adad_e);
        c.bindValue(":name", n_C);
        c.bindValue(":password", P);
        c.bindValue(":phoneNumber", phone);
        c.bindValue(":email", email);
        c.bindValue(":address",address_C);
        c.bindValue(":image" , imageData);

        if(c.exec()){
            me *w = new me(adad_e,Type_e);
            this->close();
            w->show();
        }
        else {
            qDebug() << " hjjjjjjjjjjjjjjjg";
        }
    }
    else if (Sw_1 == 0) {

        QSqlQuery c;
        c.prepare("UPDATE CompanyInformation SET name = :name,password = :password,phoneNumber = :phoneNumber, email = :email, address = :address, image_C = :image WHERE id_C = :number");
        c.bindValue(":number", adad_e);
        c.bindValue(":name", n_C);
        c.bindValue(":password", P);
        c.bindValue(":phoneNumber", phone);
        c.bindValue(":email", email);
        c.bindValue(":address",address_C);
        c.bindValue(":image" , imageData);

        if(c.exec()){
            me *w = new me(adad_e,Type_e);
            this->close();
            w->show();
        }
        else {
            qDebug() << " hjjjjjjjjjjjjjjjg";
        }
    }

}


void editinformation::on_pushButton_back_2_clicked()
{
    me *w = new me(adad_e,Type_e);
    this->close();
    w->show();
}

void editinformation::on_pushButton_back_3_clicked()
{
    me *w = new me(adad_e,Type_e);
    this->close();
    w->show();
}
