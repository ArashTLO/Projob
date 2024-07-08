#include "content.h"
#include <QMessageBox>
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "loginpage.h"
#include "me.h"

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

void content::sand_connection_request(int applicant, int receiver, QString type_applicant, QString type_receiver){

    QSqlQuery q;
    q.prepare("INSERT INTO list_connection(Applicant,receiver,type_Applicant,type_receiver) VALUES (:applicant,:receiver,:type,:type_receiver)");
    q.bindValue(":applicant", applicant);
    q.bindValue(":receiver", receiver);
    q.bindValue(":type", type_applicant);
    q.bindValue(":type_receiver", type_receiver);

    if (q.exec()) {
        QMessageBox::information(nullptr, "my network user", "your request has been sccessfully sent.");
    } else {
        QMessageBox::information(nullptr, "my network user", "your request was not sent.");
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
    checkQuery.prepare("SELECT id_C FROM CompanyInformation WHERE name = :username AND password = :password");
    checkQuery.bindValue(":username", username);
    checkQuery.bindValue(":password", password);

    if (checkQuery.exec() && checkQuery.next()) {
        int id = checkQuery.value("id_C").toInt();
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
        q.prepare("SELECT name FROM CompanyInformation WHERE id_C = :account_id");
        q.bindValue(":account_id", number);
        q.exec();
        if(q.next())
        return q.value(0).toString();
    }
    return "null";
}
void job::job_build(){

    QJsonObject jobObject;
    jobObject["job_name"] = job_name;
    jobObject["address"] = address;
    jobObject["salary"] = salary;
    jobObject["skills"] = skills_required;
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

void POST::posting_user(){
    QJsonObject postObject;
        postObject["id_P"] = id_account;
        postObject["post_text"] = post_text;
        QString base64Image = QString(post_image.toBase64());
        postObject["post_image"] = base64Image;

        QSqlQuery q;
        q.prepare("SELECT posts FROM verificationpage WHERE rowid = :account_id");
        q.bindValue(":account_id", id_account);

        if(q.exec() && q.next()) {
            QString postsString = q.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(postsString.toUtf8());
            QJsonArray postsArray = doc.array();
            postObject["post_id"] = postsArray.size()+1;
            postsArray.append(postObject);
            QJsonDocument newDoc(postsArray);
            QString newPostsString = newDoc.toJson();

            q.prepare("UPDATE verificationpage SET posts = :newPostsString WHERE rowid = :account_id");
            q.bindValue(":account_id", id_account);
            q.bindValue(":newPostsString", newPostsString);
            if (!q.exec()) {
                qDebug() << "Error:";
            } else {
                QMessageBox::warning(nullptr, "send post", "Your post has been successfully uploaded.");

                qDebug() << "Record updated successfully!";
            }
        } else {
            qDebug() << "Error: Failed to retrieve posts from Database.";
        }
}

void POST::posting_company(){
    QJsonObject postObject;
    postObject["id_C"] = id_account;
    postObject["post_text"] = post_text;
    QString base64Image = QString(post_image.toBase64());
    postObject["post_image"] = base64Image;

    QSqlQuery q;
    q.prepare("SELECT posts FROM CompanyInformation WHERE rowid = :id_company");
    q.bindValue(":id_company",id_account);

    if(q.exec() && q.next()) {
        QString postsString = q.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(postsString.toUtf8());
        QJsonArray postsArray = doc.array();
        postObject["post_id"] = postsArray.size()+1;
        postsArray.append(postObject);
        QJsonDocument newDoc(postsArray);
        QString newPostsString = newDoc.toJson();

        q.prepare("UPDATE CompanyInformation SET posts = :newPostsString WHERE rowid = :id_company");
        q.bindValue(":id_company", id_account);
        q.bindValue(":newPostsString", newPostsString);

        if (!q.exec()) {
            qDebug() << "Error: trrrrrrr";
        } else {
            QMessageBox::warning(nullptr, "send post", "Your post has been successfully uploaded.");

            qDebug() << "Record updated successfully!";
        }
    } else {
        qDebug() << "Error: Failed to retrieve posts from Database.";
    }
}
void Account::create_account_user(QString p, QString s9, QString school, QString start_y, QString end_y, QString birth, QString n,QByteArray imageData){

    if (Email.isEmpty() || Skills.isEmpty() || school.isEmpty() || s9.isEmpty()) {
                QMessageBox::warning(nullptr, "verification", "Please complete all information");
            } else {
                QSqlQuery q;
                q.prepare("INSERT INTO verificationpage (username,password,frstname,lastname,email,skills,school,start_year,end_year,date_birth,image,nationality) VALUES (:username,:password,:frstname,:lastname,:email,:skills,:school,:Start_year,:end_year,:birth,:image,:nationality)");
                q.bindValue(":password", p);
                q.bindValue(":username", s9);
                q.bindValue(":frstname", frstname);
                q.bindValue(":lastname", lastname);
                q.bindValue(":email", Email);
                q.bindValue(":skills", Skills);
                q.bindValue(":school", school);
                q.bindValue(":Start_year", start_y);
                q.bindValue(":end_year", end_y);
                q.bindValue(":birth", birth);
                q.bindValue(":image", imageData);
                q.bindValue(":nationality", n);

                if (q.exec()) {
                    loginpage *w3 = new loginpage;
                    //this->close();
                    w3->show();
                } else {
                    qDebug() << "Error: ";
                }
            }
}

void Company::set_Company_name(QString C_name){
    Company_name = C_name;
}

QString Company::get_Compny_name(){
    return Company_name;
}
void Company::Creat_Company(QString phone,QString address, QString password, QString imageData){

    if (Company_name.isEmpty() || phone.isEmpty() || Email.isEmpty() || address.isEmpty()) {
        QMessageBox::information(nullptr, "Verification", "Please complete all information");
    } else {
        QSqlQuery q;
        q.prepare("INSERT INTO CompanyInformation (name,password,phoneNumber,email,address,image_C,id_user) VALUES (:name_c,:password,:phone,:email,:address,:imageData,:iduser)");
        q.bindValue(":name_c", Company_name);
        q.bindValue(":password", password);
        q.bindValue(":phone", phone);
        q.bindValue(":email", Email);
        q.bindValue(":address", address);
        q.bindValue(":imageData", imageData);
        q.bindValue(":iduser", account_id);

        if (q.exec()) {
            me *w3 = new me(account_id,"P");
            //this->close();
            w3->show();
        } else {
            QMessageBox::warning(nullptr, "Verification","Error: ") ;
        }
    }
}
void Account::Change_user_information(QString s9,QString P,QString school, QString start_y,QString end_y,QString birth,QString n, QByteArray imageData, QString type){

    QSqlQuery q;
        q.prepare("UPDATE verificationpage SET username = :username, password = :password, frstname = :frstname, lastname = :lastname, email = :email, skills = :skills, school = :school, start_year = :start_year, end_year = :end_year, date_birth = :date_birth, image = :image, nationality = :nationality WHERE account_id = :number");
        q.bindValue(":number", account_id);
        q.bindValue(":password", P);
        q.bindValue(":username", s9);
        q.bindValue(":frstname", frstname);
        q.bindValue(":lastname", lastname);
        q.bindValue(":email", Email);
        q.bindValue(":skills", Skills);
        q.bindValue(":school", school);
        q.bindValue(":start_year", start_y);
        q.bindValue(":end_year", end_y);
        q.bindValue(":date_birth", birth);
        q.bindValue(":image", imageData);
        q.bindValue(":nationality", n);

        QSqlQuery p;
        p.prepare("UPDATE loginpage SET username = :username, password = :password WHERE account_id = :number");
        p.bindValue(":number", account_id);
        p.bindValue(":password", P);
        p.bindValue(":username", s9);

        if (q.exec() && p.exec()) {
            me *w = new me(account_id,type);
            //this->close();
            w->show();
        } else {
            qDebug() << "Error: ";
        }
}
void job::User_acceptance(int id_com,int id_user,int id_job){

    QJsonObject acceptObject;
        acceptObject["id_user"] = id_user;
        acceptObject["id_job"] = id_job;
        QSqlQuery q;
        q.prepare("SELECT Employee FROM CompanyInformation WHERE rowid = :id_company");
        q.bindValue(":id_company", id_com);
        if(q.exec() && q.next()) {
            QString jobsString = q.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray jobsArray = doc.array();
            jobsArray.append(acceptObject);
            QJsonDocument newDoc(jobsArray);

            QString newEmployee = newDoc.toJson();
            QString updateQuery = QString("UPDATE CompanyInformation SET Employee = '%1' WHERE rowid = %2").arg(newEmployee).arg(id_com);
            if (!q.exec(updateQuery)) {
                qDebug() << "Error: ";
            } else {
                QMessageBox::information(nullptr ,"job company","A new employee has been added to your company.");
                qDebug() << "Record updated successfully!";
            }
     }
}
void message::send_text_message(){

    QJsonObject messagingObject_1;
        messagingObject_1["id_sender"] = id_sender;
        messagingObject_1["texe_messag"] = text;

        QSqlQuery p;
        p.prepare("SELECT DM FROM verificationpage WHERE rowid = :id");
        p.bindValue(":id", id_receiver);

        if(p.exec() && p.next()) {
            QString jobsString = p.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray jobsArray = doc.array();
            jobsArray.append(messagingObject_1);
            QJsonDocument newDoc(jobsArray);

            QString newJobsString = newDoc.toJson();
            QString updateQuery = QString("UPDATE verificationpage SET DM = '%1' WHERE rowid = %2").arg(newJobsString).arg(id_receiver);
            if (!p.exec(updateQuery)) {
                qDebug() << "Error: ";
            } else {
                qDebug() << "Record updated successfully!";
            }
        }
        QJsonObject messagingObject;
            messagingObject["id_receiver"] = id_receiver;
            messagingObject["texe_messag"] = text;

            QSqlQuery q;
            q.prepare("SELECT DM FROM verificationpage WHERE rowid = :id");
            q.bindValue(":id", id_sender);

            if(q.exec() && q.next()) {
                QString jobsString = q.value(0).toString();
                QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
                QJsonArray jobsArray = doc.array();
                jobsArray.append(messagingObject);
                QJsonDocument newDoc(jobsArray);

                QString newJobsString = newDoc.toJson();
                QString updateQuery = QString("UPDATE verificationpage SET DM = '%1' WHERE rowid = %2").arg(newJobsString).arg(id_sender);
                if (!q.exec(updateQuery)) {
                    qDebug() << "Error: ";
                } else {
                    qDebug() << "Record updated successfully!";
                }
            }
}
void message::send_image_message(){

    QJsonObject messagingObject_1;
    messagingObject_1["id_sender"] = id_sender;
    messagingObject_1["image_messag"] = image;

    QSqlQuery p;
    p.prepare("SELECT DM FROM verificationpage WHERE rowid = :id");
    p.bindValue(":id", id_receiver);

    if(p.exec() && p.next()) {
        QString jobsString = p.value(0).toString();
        QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
        QJsonArray jobsArray = doc.array();
        jobsArray.append(messagingObject_1);
        QJsonDocument newDoc(jobsArray);

        QString newJobsString = newDoc.toJson();
        QString updateQuery = QString("UPDATE verificationpage SET DM = '%1' WHERE rowid = %2").arg(newJobsString).arg(id_receiver);
        if (!p.exec(updateQuery)) {
            qDebug() << "Error: ";
        } else {
            qDebug() << "Record updated successfully!";
        }
    }

    QJsonObject messagingObject;
        messagingObject["id_receiver"] = id_receiver;
        messagingObject["image_messag"] = image;

        QSqlQuery q;
        q.prepare("SELECT DM FROM verificationpage WHERE rowid = :id");
        q.bindValue(":id", id_sender);

        if(q.exec() && q.next()) {
            QString jobsString = q.value(0).toString();
            QJsonDocument doc = QJsonDocument::fromJson(jobsString.toUtf8());
            QJsonArray jobsArray = doc.array();
            jobsArray.append(messagingObject);
            QJsonDocument newDoc(jobsArray);

            QString newJobsString = newDoc.toJson();
            QString updateQuery = QString("UPDATE verificationpage SET DM = '%1' WHERE rowid = %2").arg(newJobsString).arg(id_sender);
            if (!q.exec(updateQuery)) {
                qDebug() << "Error: ";
            } else {
                qDebug() << "Record updated successfully!";
            }
        }
}
void Like::Register_like(){

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM postLike WHERE username = :username AND post_id = :adad AND post_type = :post_type AND liked_account_id = :liked_account_id");
    checkQuery.bindValue(":username", name_liker);
    checkQuery.bindValue(":adad", post_id);
    checkQuery.bindValue(":post_type", post_type);
    checkQuery.bindValue(":liked_account_id", liked_account_id);
    checkQuery.exec();

    if (checkQuery.next()) {

        qDebug() << "Record already exists";
        QMessageBox::information(nullptr, "Home", "this post has already been liked by you.");
    } else {

        QSqlQuery query;
        query.prepare("INSERT INTO postLike (username, post_id, post_type, liked_account_id) VALUES (:username, :adad, :post_type, :liked_account_id)");
        query.bindValue(":username", name_liker);
        query.bindValue(":adad", post_id);
        query.bindValue(":post_type", post_type);
        query.bindValue(":liked_account_id", liked_account_id);

        if (query.exec()) {
            qDebug() << "Like saved to database";
            QMessageBox::information(nullptr, "Home", "Like saved to database");
        } else {
            qDebug() << "Error saving like to database";
        }
    }

}

QSqlQuery Like::show_list_Like() {

    QSqlQuery q;
    q.prepare("SELECT username FROM postLike WHERE post_id = :post_id AND post_type = :post_type AND liked_account_id = :liked_account_id");
    q.bindValue(":post_id", post_id);
    q.bindValue(":post_type", post_type);
    q.bindValue(":liked_account_id", liked_account_id);
    q.exec();

    return q;
}

void Comment::add_comment(){

    QSqlQuery q;
    q.prepare("INSERT INTO postComment(post_id,textComment,username,id_recieve,type_recieve) VALUES(:id,:text,:username,:id_recieve,:type_recieve)");
    q.bindValue(":text",text_comment);
    q.bindValue(":id", id_post);
    q.bindValue(":username", name_sender);
    q.bindValue(":id_recieve", id_recieve);
    q.bindValue(":type_recieve", type_post);
    q.exec();
}
