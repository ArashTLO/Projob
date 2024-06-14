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
#include "post.h"
#include "QSqlRecord"
#include "content.h"
#include "addcompany.h"


loginpage::loginpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginpage)
{
    ui->setupUi(this);

    ui->lineEdit_generate->setReadOnly(true);
    int a;
    a=rand()%9000000+10000;
    ui->lineEdit_generate->setText(QString::number(a));
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
void loginpage::on_radioButton_clicked(){
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
    if(!ui->lineEdit_username->text().isEmpty() && !ui->lineEdit_password->text().isEmpty()){

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    content myContent;
    if(ui->lineEdit_enter->text() != ui->lineEdit_generate->text()){
        QMessageBox::warning(this,"Login","Captcha is not verified!");
    }
    else if(myContent.check_loginpage(username,password)){
        QMessageBox::warning(this,"Login","You are already registered, please login");
    }
    else {
        QSqlQuery q;
        q.prepare("INSERT INTO loginpage(username,password)VALUES(:username,:password)");
        q.bindValue(":username", username);
        q.bindValue(":password", password);
        q.exec();

        verificationpage *w3 = new verificationpage;
        this->close();
        w3->show();
    }
    }
///////////////////////////////////////////////////////////////////////////////////////////

    else if(!ui->lineEdit_C_name->text().isEmpty() && !ui->lineEdit_C_password->text().isEmpty()){
        QString C_name = ui->lineEdit_C_name->text();
        QString C_password = ui->lineEdit_C_password->text();
        content myContent;

        if(ui->lineEdit_enter->text() != ui->lineEdit_generate->text()){
            QMessageBox::warning(this,"Login","Captcha is not verified!");
        }
        else if(myContent.check_loginCompaney(C_name,C_password)){
            QMessageBox::warning(this,"Login","You are already registered, please login");
        }
        else {
            QSqlQuery q;
            q.prepare("INSERT INTO loginCompany (C_name,C_password)VALUES(:username,:password)");
            q.bindValue(":username", C_name);
            q.bindValue(":password", C_password);
            q.exec();

            addcompany *w3 = new addcompany;
            this->close();
            w3->show();
    }
    }
}
void loginpage::on_pushButton_login_clicked()
{

    if(!ui->lineEdit_username->text().isEmpty() && !ui->lineEdit_password->text().isEmpty()){
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    content myContent;

    if(ui->lineEdit_enter->text() != ui->lineEdit_generate->text()){
        QMessageBox::warning(this,"Login","Captcha is not verified!");
    }
    else if(myContent.check_id_loginpage(username,password) != 0){
        home *w3 = new home(myContent.check_id_loginpage(username,password), "P");
        this->close();
        w3->show();
    }
    else {
        QMessageBox::warning(this, "Login", "You have not registered before, please register");
    }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    else if(!ui->lineEdit_C_name->text().isEmpty() && !ui->lineEdit_C_password->text().isEmpty()){
        QString C_name = ui->lineEdit_C_name->text();
        QString C_password = ui->lineEdit_C_password->text();
        content myContent;

        if(ui->lineEdit_enter->text() != ui->lineEdit_generate->text()){
            QMessageBox::warning(this,"Login","Captcha is not verified!");
        }
        else if(myContent.check_id_loginCompaney(C_name,C_password) != 0){

            home *w3 = new home(myContent.check_id_loginCompaney(C_name,C_password), "C");
            this->close();
            w3->show();
        }
        else {
            QMessageBox::warning(this, "Login", "You have not registered before, please register");
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    else{
        QMessageBox::warning(this, "Login", "please enter your information in the appropriate line edit");
    }
}

