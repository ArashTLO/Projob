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
    QByteArray imageData = q.value(11).toByteArray();
    QPixmap image;
    image.loadFromData(imageData);
    ui->label_10->setPixmap(image.scaled(476,180));
    ui->dateEdit->setDate(q.value(10).toDate());
}

editinformation::~editinformation()
{
    delete ui;
}

void editinformation::on_pushButton_select_photo_clicked()
{
    filePath_2 = QFileDialog::getOpenFileName(this,"Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath_2.isEmpty()){
        QPixmap pixmap(filePath_2);
        ui->label_10->setPixmap(pixmap.scaled(ui->label_10->size(), Qt::KeepAspectRatio));
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
}
