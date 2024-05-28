#include "verificationpage.h"
#include "ui_verificationpage.h"
#include "QMessageBox"
#include "home.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

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

verificationpage::~verificationpage()
{
    delete ui;
}

void verificationpage::on_pushButton_clicked()
{

    QString s1 = ui->lineEdit->text();
    QString s2 = ui->lineEdit_2->text();
    QString s3 = ui->lineEdit_4->text();
    QString s4 = ui->dateEdit->text();
    QString s5 = ui->lineEdit_5->text();
    QString s6 = ui->spinBox_2->text();
    QString s7 = ui->spinBox_3->text();
    QString s8 = ui->textEdit->toPlainText();

    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
       QMessageBox::warning(this,"verification","Please complete all information");

    else{
        QSqlQuery q;
        q.exec("INSERT INTO verificationpage(recent_job_title,emploment_type,recent_company,date_birth,school,Start_year,end_year,address)VALUES('"+s5+"','"+s1+"','"+s2+"','"+s4+"','"+s3+"','"+s6+"','"+s7+"','"+s8+"')");
        home *w3 = new home;
        this->close();
        w3->show();
    }
}
