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

int adad_c;
createjob::createjob(int number,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createjob)
{
    ui->setupUi(this);
    adad_c = number;
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
    jobscompany *w = new jobscompany(adad_c);
    this->close();
    w->show();
}


void createjob::on_pushButton_clicked()
{
    job myjob(ui->lineEdit_skills->text(),ui->textEdit_address->toPlainText(),ui->lineEdit_salary->text().toInt(),ui->comboBox_workplase->currentText(),ui->lineEdit_job_title->text(),ui->comboBox_job_type->currentText(),adad_c);
    myjob.job_build();
}
