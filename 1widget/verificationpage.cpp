#include "verificationpage.h"
#include "ui_verificationpage.h"
#include "QMessageBox"
#include "home.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "loginpage.h"
#include "QFile"
#include "QByteArray"
#include <QFileDialog>
#include "QDebug"

verificationpage::verificationpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::verificationpage)
{
    ui->setupUi(this);
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();
}
QString filePath_1;
verificationpage::~verificationpage()
{
    delete ui;
}

void verificationpage::on_pushButton_back_clicked()
{
    QString s9 = ui->lineEdit_username->text();
    QString p = ui->lineEdit_password->text();
    QString f = ui->lineEdit_fname->text();
    QString l = ui->lineEdit_lname->text();
    QString s1 = ui->lineEdit->text();
    QString s2 = ui->lineEdit_2->text();
    QString s3 = ui->lineEdit_4->text();
    QString s4 = ui->dateEdit->text();
    QString s5 = ui->lineEdit_5->text();
    QString s6 = ui->spinBox_2->text();
    QString s7 = ui->spinBox_3->text();
    QString s8 = ui->textEdit->toPlainText();

    /*QFile file(filePath_1);
    if(file.open(QIODevice::ReadOnly)){
    QByteArray imageData = file.readAll();

    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
       QMessageBox::warning(this,"verification","Please complete all information");

    else{
        QSqlQuery q;
        q.exec("INSERT INTO verificationpage(username,password,frstname,lastname,recent_job_title,emploment_type,recent_company,date_birth,school,Start_year,end_year,address,image)VALUES('"+s9+"','"+p+"','"+f+"','"+l+"','"+s5+"','"+s1+"','"+s2+"','"+s4+"','"+s3+"','"+s6+"','"+s7+"','"+s8+"','"+imageData+"')");
        loginpage *w3 = new loginpage;
        this->close();
        w3->show();
    }
    }
}*/
    QFile file(filePath_1);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray imageData = file.readAll();

        if (s1.isEmpty() || s2.isEmpty() || s3.isEmpty() || s5.isEmpty()) {
            QMessageBox::warning(this, "verification", "Please complete all information");
        } else {
            QSqlQuery q;
            q.prepare("INSERT INTO verificationpage (username, password, frstname, lastname, recent_job_title, emploment_type, recent_company, date_birth, school, Start_year, end_year, address, image) VALUES (:username, :password, :frstname, :lastname, :recent_job_title, :emploment_type, :recent_company, :date_birth, :school, :Start_year, :end_year, :address, :image)");
            q.bindValue(":username", s9);
            q.bindValue(":password", p);
            q.bindValue(":frstname", f);
            q.bindValue(":lastname", l);
            q.bindValue(":recent_job_title", s5);
            q.bindValue(":emploment_type", s1);
            q.bindValue(":recent_company", s2);
            q.bindValue(":date_birth", s4);
            q.bindValue(":school", s3);
            q.bindValue(":Start_year", s6);
            q.bindValue(":end_year", s7);
            q.bindValue(":address", s8);
            q.bindValue(":image", imageData);

            if (q.exec()) {
                loginpage *w3 = new loginpage;
                this->close();
                w3->show();
            } else {
                qDebug() << "Error: ";
            }
        }
}
}

void verificationpage::on_pushButton_select_photo_clicked()
{
        filePath_1 = QFileDialog::getOpenFileName(this,"Select Image", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

        if (!filePath_1.isEmpty()){
            QPixmap pixmap(filePath_1);
            ui->label_10->setPixmap(pixmap.scaled(ui->label_10->size(), Qt::KeepAspectRatio));
        }
}

