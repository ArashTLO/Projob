#include "content.h"
#include <QMessageBox>
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"

content::content(QObject *parent) : QObject(parent)
{
    QSqlDatabase database;    // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
       database = QSqlDatabase::addDatabase("QSQLITE");
       database.setDatabaseName("d:\\DB_project.db");
       database.open();
    if (!database.open()){
        qDebug() <<"Error connecting to database";

        QMessageBox::warning(nullptr, "Database Error", "Could not open database.");
    }
}

int content::check_id_loginpage(const QString& username,const QString& password){

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT account_id FROM loginpage WHERE username = :username");
        checkQuery.bindValue(":username", username);
        checkQuery.bindValue(":password", password);

        if (checkQuery.exec() && checkQuery.next()) {
            int id = checkQuery.value("account_id").toInt();
            return id;
        } else {
            return 0;
        }
}
int content::check_id_loginCompaney(const QString &username, const QString &password){

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT company_id FROM loginCompany WHERE C_name = :username AND C_password = :password");
    checkQuery.bindValue(":username", username);
    checkQuery.bindValue(":password", password);

    if (checkQuery.exec() && checkQuery.next()) {
        int id = checkQuery.value("company_id").toInt();
        return id;
        } else {
        return 0;
        }
}
bool content::check_loginCompaney(const QString &username, const QString &password){
    QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM loginCompany WHERE C_name = :username AND C_password = :password");
        checkQuery.bindValue(":username", username);
        checkQuery.bindValue(":password", password);

        if (checkQuery.exec() && checkQuery.next()) {
            return true;
            } else {
            return false;
            }
}
bool content::check_loginpage(const QString &username, const QString &password){
    QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM loginpage WHERE username = :username AND password = :password");
        checkQuery.bindValue(":username", username);
        checkQuery.bindValue(":password", password);

        if (checkQuery.exec() && checkQuery.next()) {
            return true;
            } else {
            return false;
            }
}
QString content::check_type(QString type,int number){
    if(type == "P"){
        QSqlQuery q;
        q.prepare("SELECT username FROM loginpage WHERE account_id = :account_id");
        q.bindValue(":account_id", number);
        q.exec();
        if(q.next())
        return  q.value("username").toString();
    }
    else if(type == "C"){
        QSqlQuery q;
        q.prepare("SELECT C_name FROM loginCompany WHERE company_id = :account_id");
        q.bindValue(":account_id", number);
        q.exec();
        if(q.next())
        return q.value("C_name").toString();
    }
}


