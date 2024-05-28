#include "loginpage.h"
#include "ui_loginpage.h"
#include "QMessageBox"
#include "verificationpage.h"
#include <QtSql>
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "home.h"

loginpage::loginpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginpage)
{
    ui->setupUi(this);
    ui->lineEdit_generate->setReadOnly(true);
    int a;
    a=rand()%9000000+10000;
    ui->lineEdit_generate->setText(QString::number(a));
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
       database = QSqlDatabase::addDatabase("QSQLITE");
       database.setDatabaseName("d:\\DB_project.db");
       database.open();
    if (!database.open()){
        qDebug() <<"Error connecting to database";
        QMessageBox::warning(this,"Login","Error connecting to database");
    }
}
int sw=1;
loginpage::~loginpage()
{
    delete ui;
}

void loginpage::on_pushButton_generate_clicked()
{
    int a;
    a=rand()%9000000+100000;
    ui->lineEdit_generate->setText(QString::number(a));
}
void loginpage::on_pushButton_enter_clicked()
{
    if(ui->lineEdit_enter->text()==ui->lineEdit_generate->text()){
        sw=1;
        ui->label_verify->setText("Captcha verified!");
        ui->label_verify->setStyleSheet("color:rgb(0,128,0)");
        ui->pushButton_generate->setEnabled(false);
        ui->pushButton_enter->setEnabled(false);
        ui->lineEdit_enter->setEnabled(false);
    }
    else if(ui->lineEdit_enter->text()!=ui->lineEdit_generate->text()){
        ui->label_verify->setText("Invalid captcha entered!");
        ui->label_verify->setStyleSheet("color:rgb(255,0,0)");
    }
}
int p = 0;
void loginpage::on_radioButton_clicked()
{
    if(p == 0){
            ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
            p = 1;
        }
        else if(p == 1){
            ui->lineEdit_password->setEchoMode(QLineEdit::Password);
            p = 0;
}
}
void loginpage::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QSqlQuery checkQuery;
       checkQuery.prepare("SELECT * FROM loginpage WHERE username = :username AND password = :password");
       checkQuery.bindValue(":username", username);
       checkQuery.bindValue(":password", password);
       checkQuery.exec();

    if(ui->lineEdit_enter->text() != ui->lineEdit_generate->text()){
        QMessageBox::warning(this,"Login","Captcha is not verified!");
    }
    else if(checkQuery.next()){
        QMessageBox::warning(this,"Login","You are already registered, please login");
    }
    else if(!checkQuery.next()){
        QSqlQuery q;
        q.exec("INSERT INTO loginpage(username,password)VALUES('"+username+"','"+password+"')");
         verificationpage *w3 = new verificationpage;
         this->close();
         w3->show();
    }
}

void loginpage::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QSqlQuery checkQuery;
       checkQuery.prepare("SELECT * FROM loginpage WHERE username = :username AND password = :password");
       checkQuery.bindValue(":username", username);
       checkQuery.bindValue(":password", password);
       checkQuery.exec();
       if(ui->lineEdit_enter->text() != ui->lineEdit_generate->text()){
           QMessageBox::warning(this,"Login","Captcha is not verified!");
       }
       else if(checkQuery.next()){
           home *w3 = new home;
           this->close();
           w3->show();
       }
       else if(username == "" || password =="" ){
           QMessageBox::warning(this,"Login","Plese enter your name and password");
       }
       else if(!checkQuery.next()){
           QMessageBox::warning(this, "Login", "You have not registered before, please register");
       }

}
