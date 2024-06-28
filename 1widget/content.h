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
#include "QByteArray"
#include "QShowEvent"
#include "QFile"

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
    void sand_connection_request(int applicant, int receiver, QString type_applicant, QString type_reveiver);
    virtual ~content(){};

signals:

};

class POST{
public:
    int id_C;
    QString post_text;
    QByteArray post_image;
    int post_id;

    POST(int i_c, QString p_text, QByteArray p_image){
        id_C = i_c;
        post_text = p_text;
        post_image = p_image;
    }
    void posting_company();
    void posting_user();
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
    void job_build();
    void Delete_request(int id_com,int id_job,int id_user);
    job(){
        skills = "";
        address = "";
        salary = 0;
        workPlace_type = "";
        job_name = "";
        job_type = "";
        id_company = 0;
    }
    job(QString sk,QString ad,int sa,QString wo,QString jn,QString jt,int id_c){
        skills = sk;
        address = ad;
        salary = sa;
        workPlace_type = wo;
        job_name = jn;
        job_type = jt;
        id_company = id_c;
    }
    };

#endif // CONTENT_H
