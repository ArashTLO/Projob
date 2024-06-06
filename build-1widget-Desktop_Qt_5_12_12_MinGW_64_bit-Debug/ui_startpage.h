/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startPage
{
public:
    QWidget *centralwidget;
    QPushButton *vorudButton;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *startPage)
    {
        if (startPage->objectName().isEmpty())
            startPage->setObjectName(QString::fromUtf8("startPage"));
        startPage->resize(918, 553);
        startPage->setStyleSheet(QString::fromUtf8("QMainWindow  {\n"
"background-color: rgb(192, 221, 190);\n"
"font: 40px\n"
"}\n"
"\n"
"#vorudButton {\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"QPushButton#vorudButton:hover {\n"
"background-color: rgb(80,80,80);\n"
"font: bold 17px;\n"
"}\n"
"QPushButton#vorudButton:pressed {\n"
"background-color: rgb(50, 50, 50);\n"
"}\n"
"\n"
"\n"
"#vorudButton {\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"\n"
"#vorudButton:focus{\n"
"box-shadow: 0 0 5px rgba(0,0,255,0.5);\n"
"Width: 150px;\n"
"}\n"
"/*#vorudButton:hover{\n"
"font:bold  16px;\n"
"background-color: #2c2c2c;\n"
"Width: 150px;\n"
"}\n"
"/*QPushButton#vorudButton:hover {\n"
"background-color: rgb(80,80,80);\n"
"}\n"
"QPushButton#vorudButton:pressed {\n"
"background-color: rgb(50, 50, 50);\n"
"}\n"
""));
        centralwidget = new QWidget(startPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vorudButton = new QPushButton(centralwidget);
        vorudButton->setObjectName(QString::fromUtf8("vorudButton"));
        vorudButton->setGeometry(QRect(350, 220, 181, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-260, 270, 1481, 331));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/pishvazpic.JPG);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 130, 581, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 160, 321, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 110, 191, 20));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 20, 301, 51));
        QFont font1;
        font1.setPointSize(29);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 20, 181, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Magneto"));
        font2.setPointSize(23);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 66, 51);\n"
"color: white;\n"
"padding: 5px;\n"
"border-top-left-radius: 40px;\n"
"border-bottom-right-radius: 40px;"));
        startPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 918, 21));
        startPage->setMenuBar(menubar);
        statusbar = new QStatusBar(startPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        startPage->setStatusBar(statusbar);
        toolBar = new QToolBar(startPage);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        startPage->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(startPage);
        QObject::connect(vorudButton, SIGNAL(clicked()), startPage, SLOT(close()));

        QMetaObject::connectSlotsByName(startPage);
    } // setupUi

    void retranslateUi(QMainWindow *startPage)
    {
        startPage->setWindowTitle(QApplication::translate("startPage", "startPage", nullptr));
        vorudButton->setText(QApplication::translate("startPage", "Login", nullptr));
        label_2->setText(QApplication::translate("startPage", "1", nullptr));
        label_4->setText(QApplication::translate("startPage", " anyone who is looking for cooperation and activity in his field of expxrtise", nullptr));
        label_5->setText(QApplication::translate("startPage", " please press the login button to register.", nullptr));
        label->setText(QApplication::translate("startPage", "who is this app suitable ?", nullptr));
        label_3->setText(QApplication::translate("startPage", "welcome to the ", nullptr));
        label_6->setText(QApplication::translate("startPage", "PROJOB", nullptr));
        toolBar->setWindowTitle(QApplication::translate("startPage", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startPage: public Ui_startPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
