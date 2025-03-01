#include "createjob.h"
#include "ui_createjob.h"
#include "jobscompany.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "content.h"
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include "QDebug"
#include "QMessageBox"

int adad_c;
QString Type_c;
createjob::createjob(int number,QString type,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createjob)
{
    ui->setupUi(this);
    adad_c = number;
    Type_c = type;
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

}

createjob::~createjob()
{
    delete ui;
}

void createjob::on_pushButton_2_clicked()
{
    if(Type_c == "P"){
        QMessageBox::warning(this, "My network Company" , "Only companies can enter the desired window.");
    }
    else if(Type_c == "C"){
    jobscompany *w = new jobscompany(adad_c,Type_c);
    this->close();
    w->show();
    }
}


void createjob::on_pushButton_clicked()
{
    job myjob(ui->lineEdit_skills->text(),ui->textEdit_address->toPlainText(),ui->lineEdit_salary->text().toInt(),ui->comboBox_workplase->currentText(),ui->lineEdit_job_title->text(),ui->comboBox_job_type->currentText(),adad_c);
    myjob.job_build();
}
