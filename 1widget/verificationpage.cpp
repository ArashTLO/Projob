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
#include "content.h"

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
    QString e = ui->lineEdit_email->text();
    QString sk = ui->lineEdit_skills->text();
    QString school = ui->lineEdit_school->text();
    QString start_y = ui->spinBox_start_year->text();
    QString end_y = ui->spinBox_end_year->text();
    QString birth = ui->dateEdit->text();
    QString n = ui->lineEdit_na->text();

    QFile file(filePath_1);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray imageData = file.readAll();

        Account newaccount(f,l,sk,0,e);
        newaccount.create_account_user(p,s9,school,start_y,end_y,birth,n,imageData);

        this->close(); 
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

