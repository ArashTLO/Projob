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

class Content {

public:

    int id_sender;
    QString text;
    QString image;

    Content(int id_sender , QString text , QString image){

        this->id_sender = id_sender;
        this->text = text;
        this->image = image;
    }
};

class message : public Content{

public:

    int id_receiver;

    message(int id_receiver,int id_sender,QString message_text,QString message_image)
        :Content(id_sender,message_text,message_image)
    {

        this->id_receiver = id_receiver;

    }

    void send_text_message();
    void send_image_message();
};

class POST{

public:

    int id_account;
    QString post_text;
    QByteArray post_image;
    int post_id;

    POST(int i_c, QString p_text, QByteArray p_image){
        id_account = i_c;
        post_text = p_text;
        post_image = p_image;
    }
    void posting_company();
    void posting_user();
};

class Like{

public:

    QString post_type;
    QString name_liker;
    int post_id;
    int liked_account_id;

    Like(QString post_type, QString name_liker, int post_id, int liked_account_id){

        this->post_type = post_type;
        this->name_liker = name_liker;
        this->post_id = post_id;
        this->liked_account_id = liked_account_id;
    }
    void Register_like();
    QSqlQuery show_list_Like();
};

class Person{

public:

    QString lastname;
    QString frstname;
    QString Skills;

    Person(QString frstname,QString lastname,QString Skills){

        this->frstname = frstname;
        this->lastname = lastname;
        this->Skills = Skills;
    }
};


class Account: public Person{

public:

    int account_id;
    QString Email;
    int Connection;
    int follwing;
    QString posts;
    QString DM;

    Account(QString fn, QString ln, QString Sk, int account_id,QString Email)
        :Person(fn,ln,Sk){
        this->account_id = account_id;
        this->Email = Email;
    }

    Account(QString Email, int account_id)
        :Person(nullptr,nullptr,nullptr){
        this->Email = Email;
        this->account_id = account_id;
    }
    void Change_user_information(QString s9,QString P,QString school, QString start_y,QString end_y,QString birth,QString n, QByteArray imageData, QString type);
    void create_account_user(QString p, QString s9, QString school, QString start_y, QString end_y, QString birth, QString n,QByteArray imageData);
};


class Company: public Account{

public:

    QString Company_Jobs;
    QString Company_name;
    QString Employee;
    QString followers;

    Company(QString Company_name, QString Email, int account_id)
        :Account(Email,account_id){

        this->Company_Jobs = nullptr;
        this->Company_name = Company_name;
        this->Employee = nullptr;
        this->followers = nullptr;
    }
    void Creat_Company(QString phone,QString address, QString password, QString imageData);
    void set_Company_name(QString C_name);
    QString get_Compny_name();
};
class job{
    QString skills_required;
    QString address;
    int salary;
    QString workPlace_type;
    QString job_name;
    QString job_type;
    int id_company;

public:
    void job_build();
    void User_acceptance(int id_com,int id_user,int id_job);
    void Delete_request(int id_com,int id_job,int id_user);
    job(){
        skills_required = nullptr;
        address = nullptr;
        salary = 0;
        workPlace_type = nullptr;
        job_name = nullptr;
        job_type = nullptr;
        id_company = 0;
    }
    job(QString sk,QString ad,int sa,QString wo,QString jn,QString jt,int id_c){
        skills_required = sk;
        address = ad;
        salary = sa;
        workPlace_type = wo;
        job_name = jn;
        job_type = jt;
        id_company = id_c;
    }
    };

#endif // CONTENT_H
