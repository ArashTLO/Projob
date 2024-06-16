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
    else {
        QSqlQuery q;
        q.prepare("SELECT C_name FROM loginCompany WHERE company_id = :account_id");
        q.bindValue(":account_id", number);
        q.exec();
        if(q.next())
        return q.value("C_name").toString();
    }
    return "null";
}
void job::job_build(){

    QJsonObject jobObject;
    jobObject["job_name"] = job_name;
    jobObject["address"] = address;
    jobObject["salary"] = salary;
    jobObject["skills"] = skills;
    jobObject["job_type"] = job_type;
    jobObject["workPlace_type"] = workPlace_type;
    jobObject["id_compny"] = id_company;

    QSqlQuery q;
    q.prepare("SELECT jobs FROM CompanyInformation WHERE rowid = :id_company");
    q.bindValue(":id_company", id_company);

    if(q.exec() && q.next()) {
        QString jobsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray jobsArray = doc.array();
        jobObject["job_id"] = jobsArray.size()+1;
        jobsArray.append(jobObject);
        QJsonDocument newDoc(jobsArray);

        QString newJobsString = newDoc.toJson();
        QString updateQuery = QString("UPDATE CompanyInformation SET jobs = '%1' WHERE rowid = %2").arg(newJobsString).arg(id_company);
        if (!q.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            qDebug() << "Record updated successfully!";
        }

    } else {
        qDebug() << "Error: Failed to retrieve jobs from Database.";
    }
}
void job::Delete_request(int id_com,int id_job,int id_user){
        QSqlQuery query;
        query.prepare("DELETE FROM waiting_list WHERE id_company = :id_company AND id_job = :id_job AND id_user = :id_man");
        query.bindValue(":id_company", id_com);
        query.bindValue(":id_job", id_job);
        query.bindValue(":id_man", id_user);
        query.exec();
}
void POST::posting_company(){
    QJsonObject postObject;
    postObject["id_C"] = id_C;
    postObject["post_text"] = post_text;
    QString base64Image = QString(post_image.toBase64());
    postObject["post_image"] = base64Image;

    QSqlQuery q;
    q.prepare("SELECT posts FROM CompanyInformation WHERE rowid = :id_company");
    q.bindValue(":id_company", id_C);

    if(q.exec() && q.next()) {
        QString postsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsString.toUtf8());
        QJsonArray postsArray = doc.array();
        postObject["post_id"] = postsArray.size()+1;
        postsArray.append(postObject);
        QJsonDocument newDoc(postsArray);
        QString newPostsString = newDoc.toJson();

        q.prepare("UPDATE CompanyInformation SET posts = :newPostsString WHERE rowid = :id_company");
        q.bindValue(":id_company", id_C);
        q.bindValue(":newPostsString", newPostsString);

        if (!q.exec()) {
            qDebug() << "Error: trrrrrrr";
        } else {
            qDebug() << "Record updated successfully!";
        }
    } else {
        qDebug() << "Error: Failed to retrieve posts from Database.";
    }
}
