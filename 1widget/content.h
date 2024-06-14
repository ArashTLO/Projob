#ifndef CONTENT_H
#define CONTENT_H
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include "QDebug"
#include <QObject>
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"

class content : public QObject
{
    Q_OBJECT
public:
    explicit content(QObject *parent = nullptr);
    int check_id_loginpage(const QString &username, const QString &password);
    int check_id_loginCompaney(const QString &username, const QString &password);
    bool check_loginCompaney(const QString &username, const QString &password);
    bool check_loginpage(const QString &username, const QString &password);
    QString check_type(QString type, int number);
    virtual ~content(){};

signals:

};

class post_company{
public:
    int id_C;
    QString post_text;
    QByteArray post_image;
    int post_id;

    int nextPostid(int id_C){
            QSqlDatabase database;
            database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("d:\\DB_project.db");
            if(!database.open()){
                qDebug() << "hhhhhhhhhHHH ";
                return -1;
            }
            QSqlQuery q;
            q.prepare("SELECT CASE WHEN EXISTS (SELECT * FROM CompanyInformation WHERE id_C = :id_C) THEN MAX(post_id) ELSE 0 END FROM CompanyInformation WHERE id_C = :id_C");
            q.bindValue(":id_C", id_C);
            if(q.exec()){
             while(q.next()){
                qDebug() << "OK";
                return q.value(0).toInt() + 1;
            }
            } else {
                qDebug() << "Error: not found.";
                return 1;
            }
            return 0;
        }
};


class job{

    QString skills;
    QString address;
    int salary;
    QString workPlace_type;
    QString job_name;
    QString job_type;
    int id_company;
public:
    job(QString sk,QString ad,int sa,QString wo,QString jn,QString jt,int id_c){
        skills = sk;
        address = ad;
        salary = sa;
        workPlace_type = wo;
        job_name = jn;
        job_type = jt;
        id_company = id_c;
    }
    void job_build(){

    QJsonObject jobObject;
    jobObject["job_name"] = job_name;
    jobObject["address"] = address;
    jobObject["salary"] = salary;
    jobObject["skills"] = skills;
    jobObject["job_type"] = job_type;
    jobObject["workPlace_type"] = workPlace_type;

    QSqlQuery q;
    q.prepare("SELECT jobs FROM CompanyInformation WHERE rowid = :id_company");
    q.bindValue(":id_company", id_company);

    if(q.exec() && q.next()) {
        QString jobsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray jobsArray = doc.array();
        jobsArray.append(jobObject);
        QJsonDocument newDoc(jobsArray);
        //QString newJobsString = newDoc.toJson();
        QString newJobsString = newDoc.toJson();
        QString updateQuery = QString("UPDATE CompanyInformation SET jobs = '%1' WHERE rowid = %2").arg(newJobsString).arg(id_company);
        if (!q.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            qDebug() << "Record updated successfully!";
        }

        /*
        q.prepare("UPDATE CompanyInformation SET jobs = :newJobsString WHERE rowid = :id_company");
        q.bindValue(":id_company",id_company);
        q.bindValue(":newJobsString", newJobsString);

        if (!q.exec()) {
            qDebug() << "Error: ";
        } else {
            qDebug() << "Record updated successfully!";
        }*/

            } else {
            qDebug() << "Error: Failed to retrieve jobs from Database.";
            }
    }

    };

#endif // CONTENT_H
