#include "mynetworkuser.h"
#include "ui_mynetworkuser.h"
#include "home.h"
#include "jobsuser.h"
#include "me.h"
#include "messaging.h"
#include "jobscompany.h"
#include "mynetworkcompany.h"
#include <QSqlDatabase>  //این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QGroupBox"

int adad_m_u;
QString Type_m_u;
mynetworkuser::mynetworkuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mynetworkuser)
{
    ui->setupUi(this);
}

mynetworkuser::~mynetworkuser()
{
    delete ui;
    QSqlDatabase database; // این 4 خط رو باید همیشه وارد کنی وقتی میخوای با اس کیو ال کار کنی
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\DB_project.db");
    database.open();

    int frameHeight = 200;
    int currentY = 3;

    QSqlQuery q;
    q.exec("SELECT image FROM verificationpage ORDER BY account_id");

    while (q.next()) {

        ui->frame_2->setMinimumHeight(frameHeight);
        QGroupBox *groupBox = new QGroupBox(ui->frame_2);
        groupBox->setGeometry(1,currentY, 360,360);
        groupBox->setStyleSheet("background-color:rgb(255, 255, 255);");

        QByteArray imageData = q.value(0).toByteArray();
        QLabel *imageLabel = new QLabel(groupBox);
        QPixmap image;
        image.loadFromData(imageData);
        imageLabel->setPixmap(image.scaled(476,180));
        imageLabel->setGeometry(10,10,150,150);
        imageLabel->setScaledContents(true);

        //QString name = q.value(1).toString() + q.value(2).toString();

        groupBox->show();
        frameHeight += 360;
        currentY += 360;

    }
}


void mynetworkuser::on_commandLinkButton_clicked()
{
    home *w3 = new home(0,"s");
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_2_clicked()
{
    me *w3 = new me(adad_m_u,Type_m_u);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_3_clicked()
{
    jobsuser *w3 = new jobsuser(0);
    this->close();
    w3->show();
}



void mynetworkuser::on_commandLinkButton_4_clicked()
{
    messaging *w3 = new messaging;
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_5_clicked()
{
    mynetworkuser *w3 = new mynetworkuser;
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_7_clicked()
{
    jobscompany *w3 = new jobscompany(1);
    this->close();
    w3->show();
}


void mynetworkuser::on_commandLinkButton_6_clicked()
{
    mynetworkcompany *w3 = new mynetworkcompany;
    this->close();
    w3->show();
}

