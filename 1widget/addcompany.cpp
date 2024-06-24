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
#include "me.h"

int adad_add;
addcompany::addcompany(int number,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addcompany)
{
    ui->setupUi(this);
    adad_add = number;
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();
    qDebug() << adad_add + adad_add;

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


void addcompany::on_pushButton_back_clicked()
{

    QString name_c = ui->lineEdit_name_company->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString address = ui->textEdit_address->toPlainText();
    QString password = ui->lineEdit_password->text();

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
                q.prepare("INSERT INTO CompanyInformation (name,password,phoneNumber,email,address,image_C,id_user) VALUES (:name_c,:password,:phone,:email,:address,:imageData,:iduser)");
                q.bindValue(":name_c", name_c);
                q.bindValue(":password", password);
                q.bindValue(":phone", phone);
                q.bindValue(":email", email);
                q.bindValue(":address", address);
                q.bindValue(":imageData", imageData);
                q.bindValue(":iduser", adad_add);

                if (q.exec()) {
                    me *w3 = new me(adad_add,"P");
                    this->close();
                    w3->show();
                } else {
                    QMessageBox::warning(this, "Verification","Error: ") ;
                }
            }
        }
    }
}
