#include "addcompany.h"
#include "ui_addcompany.h"
#include <QFileDialog>
#include <QPixmap>
#include "QMessageBox"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "loginpage.h"
#include "QDebug"

addcompany::addcompany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addcompany)
{
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();
}

addcompany::~addcompany()
{
    delete ui;
}
QString filePath;

void addcompany::on_pushButton_select_photo_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);
        ui->label_10->setPixmap(pixmap.scaled(ui->label_10->size(), Qt::KeepAspectRatio));
    }
}

/*
void post::on_pushButton_clicked()
{
    QString s1 = ui->textEdit_post->toPlainText();

    QFile imageFile(filePath1);

        QByteArray imageData = imageFile.readAll();

        QSqlQuery q;
        if(Type_p == "P"){
            q.prepare("INSERT INTO post(post_text, post_image, account_id, username) VALUES (:text, :imageData, :id, :username)");
            q.bindValue(":text", s1);
            q.bindValue(":imageData", imageData);
            q.bindValue(":id", adad_p);
            q.bindValue(":username", name_p);
            q.exec();

         //q.prepare("INSERT INTO postCompany(post_text_C, post_image_C, company_id, C_name) VALUES (:text, :imageData, :id, :username)");


    }
}

void post::on_pushButton_2_clicked()
{
    filePath1 = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath1.isEmpty()) {
        QPixmap pixmap(filePath1);
        ui->label_3->setPixmap(pixmap.scaled(ui->label_3->size(), Qt::KeepAspectRatio));
    }
}*/
void addcompany::on_pushButton_back_clicked()
{
    /*    QString s1 = ui->textEdit_post->toPlainText();

    QFile imageFile(filePath1);

        QByteArray imageData = imageFile.readAll();

        QSqlQuery q;
        if(Type_p == "P"){
            q.prepare("INSERT INTO post(post_text, post_image, account_id, username) VALUES (:text, :imageData, :id, :username)");
            q.bindValue(":text", s1);
            q.bindValue(":imageData", imageData);
            q.bindValue(":id", adad_p);
            q.bindValue(":username", name_p);
            q.exec();
*/
    QString name_c = ui->lineEdit_name_company->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString address = ui->textEdit_address->toPlainText();

    if (filePath.isEmpty() || !QFile::exists(filePath)) {
        QMessageBox::warning(this, "Error", "Please select an image file");
    } else {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray imageData = file.readAll();

            if (name_c.isEmpty() || phone.isEmpty() || email.isEmpty() || address.isEmpty()) {
                QMessageBox::warning(this, "Verification", "Please complete all information");
            } else {
                QSqlQuery q;
                q.prepare("INSERT INTO CompanyInformation (name,phoneNumber,email,address,image_C) VALUES (:name_c,:phone,:email,:address,:imageData)");
                q.bindValue(":name_c", name_c);
                q.bindValue(":phone", phone);
                q.bindValue(":email", email);
                q.bindValue(":address", address);
                q.bindValue(":imageData", imageData);

                if (q.exec()) {
                    loginpage *w3 = new loginpage;
                    this->close();
                    w3->show();
                } else {
                    QMessageBox::warning(this, "Verification","Error: ") ;
                }
            }
        }
    }
}
