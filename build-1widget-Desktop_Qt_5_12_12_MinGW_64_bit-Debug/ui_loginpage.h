/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginpage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QLabel *label_verify;
    QPushButton *pushButton_enter;
    QPushButton *pushButton_generate;
    QLineEdit *lineEdit_generate;
    QLineEdit *lineEdit_enter;
    QLabel *label;
    QPushButton *pushButton_login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loginpage)
    {
        if (loginpage->objectName().isEmpty())
            loginpage->setObjectName(QString::fromUtf8("loginpage"));
        loginpage->resize(918, 553);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginpage->sizePolicy().hasHeightForWidth());
        loginpage->setSizePolicy(sizePolicy);
        loginpage->setMinimumSize(QSize(0, 0));
        loginpage->setMaximumSize(QSize(16777213, 16777213));
        loginpage->setLayoutDirection(Qt::LeftToRight);
        loginpage->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"image: url(:/pishvazpic.JPG);\n"
"background-color: rgb(192, 221, 190);\n"
"font: 40px\n"
"}\n"
"\n"
"QPushButton#pushButton_login {\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"QPushButton#pushButton_login:hover {\n"
"background-color: rgb(80,80,80);\n"
"font: bold 17px;\n"
"}\n"
"QPushButton#pushButton_login:pressed {\n"
"background-color: rgb(50,50,50);\n"
"}\n"
"\n"
"QPushButton#pushButton_login:focus{\n"
"box-shadow: 0 0 5px rgba(0,0,255,0.5);\n"
"font: bold 15px;\n"
"Width: 150px;\n"
"}\n"
"\n"
"QPushButton#pushButton_enter{\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"QPushButton#pushButton_enter:hover {\n"
"background-color: rgb(80,80,80);\n"
"font: bold 17px;\n"
"}\n"
"QPushButton#pushButton_enter:pressed {\n"
"background-color: rgb(50,50,50);\n"
"}\n"
"\n"
"QPushButton#pushButton_enter:focus{\n"
"box-shadow: 0 0 5px rgba"
                        "(0,0,255,0.5);\n"
"font: bold 15px;\n"
"Width: 150px;\n"
"}\n"
"\n"
"QPushButton#pushButton_generate{\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"QPushButton#pushButton_generate:hover {\n"
"background-color: rgb(80,80,80);\n"
"font: bold 17px;\n"
"}\n"
"QPushButton#pushButton_generate:pressed {\n"
"background-color: rgb(50,50,50);\n"
"}\n"
"\n"
"QPushButton#pushButton_generate:focus{\n"
"box-shadow: 0 0 5px rgba(0,0,255,0.5);\n"
"font: bold 15px;\n"
"Width: 150px;\n"
"}"));
        loginpage->setAnimated(true);
        centralwidget = new QWidget(loginpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);\n"
""));
        groupBox->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nirmala UI"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_username->setFont(font1);
        label_username->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));

        horizontalLayout_2->addWidget(label_username);

        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(lineEdit_username->sizePolicy().hasHeightForWidth());
        lineEdit_username->setSizePolicy(sizePolicy1);
        lineEdit_username->setMinimumSize(QSize(10, 20));
        lineEdit_username->setSizeIncrement(QSize(20, 20));
        lineEdit_username->setBaseSize(QSize(20, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI"));
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        lineEdit_username->setFont(font2);
        lineEdit_username->setStyleSheet(QString::fromUtf8("font: bold 15px;\n"
"border-radius: 10px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"margin: 5px;\n"
""));
        lineEdit_username->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_username);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nirmala UI"));
        font3.setBold(true);
        font3.setWeight(75);
        label_password->setFont(font3);
        label_password->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));

        horizontalLayout_3->addWidget(label_password);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMinimumSize(QSize(40, 40));
        lineEdit_password->setFont(font2);
        lineEdit_password->setStyleSheet(QString::fromUtf8("font: bold 15px;\n"
"border-radius: 10px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"margin: 5px;\n"
""));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_password);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy2);
        radioButton->setMinimumSize(QSize(60, 30));
        radioButton->setMaximumSize(QSize(60, 30));
        radioButton->setSizeIncrement(QSize(60, 30));
        radioButton->setBaseSize(QSize(60, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nirmala UI"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        radioButton->setFont(font4);

        horizontalLayout_3->addWidget(radioButton);

        horizontalSpacer_5 = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setFont(font);
        groupBox_2->setFocusPolicy(Qt::NoFocus);
        groupBox_2->setContextMenuPolicy(Qt::PreventContextMenu);
        groupBox_2->setAcceptDrops(false);
        groupBox_2->setLayoutDirection(Qt::RightToLeft);
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QString::fromUtf8("image:l(:/pishvazpic.JPG);\n"
"color: rgb(54, 66, 51);\n"
""));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        groupBox_2->setCheckable(false);
        label_verify = new QLabel(groupBox_2);
        label_verify->setObjectName(QString::fromUtf8("label_verify"));
        label_verify->setGeometry(QRect(480, 180, 131, 23));
        pushButton_enter = new QPushButton(groupBox_2);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));
        pushButton_enter->setGeometry(QRect(480, 130, 131, 41));
        pushButton_enter->setFont(font2);
        pushButton_enter->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        pushButton_generate = new QPushButton(groupBox_2);
        pushButton_generate->setObjectName(QString::fromUtf8("pushButton_generate"));
        pushButton_generate->setGeometry(QRect(260, 150, 141, 41));
        pushButton_generate->setFont(font2);
        pushButton_generate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_generate = new QLineEdit(groupBox_2);
        lineEdit_generate->setObjectName(QString::fromUtf8("lineEdit_generate"));
        lineEdit_generate->setGeometry(QRect(260, 80, 141, 61));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(lineEdit_generate->sizePolicy().hasHeightForWidth());
        lineEdit_generate->setSizePolicy(sizePolicy4);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Jokerman"));
        font5.setPointSize(26);
        font5.setBold(false);
        font5.setItalic(true);
        font5.setUnderline(false);
        font5.setWeight(50);
        lineEdit_generate->setFont(font5);
        lineEdit_generate->setTabletTracking(true);
        lineEdit_generate->setAutoFillBackground(false);
        lineEdit_generate->setStyleSheet(QString::fromUtf8("color :rgb(165, 27, 47);\n"
"border-radius: 10px;\n"
"border: 1px solid #000000;\n"
"padding: 5px;\n"
"\n"
""));
        lineEdit_generate->setFrame(true);
        lineEdit_generate->setDragEnabled(false);
        lineEdit_generate->setClearButtonEnabled(false);
        lineEdit_enter = new QLineEdit(groupBox_2);
        lineEdit_enter->setObjectName(QString::fromUtf8("lineEdit_enter"));
        lineEdit_enter->setGeometry(QRect(480, 80, 131, 35));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(20);
        sizePolicy5.setVerticalStretch(40);
        sizePolicy5.setHeightForWidth(lineEdit_enter->sizePolicy().hasHeightForWidth());
        lineEdit_enter->setSizePolicy(sizePolicy5);
        lineEdit_enter->setMinimumSize(QSize(20, 35));
        lineEdit_enter->setMaximumSize(QSize(1000, 35));
        lineEdit_enter->setSizeIncrement(QSize(20, 40));
        lineEdit_enter->setFont(font2);
        lineEdit_enter->setStyleSheet(QString::fromUtf8("font: bold 15px;\n"
"border-radius: 10px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
""));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 150, 71, 41));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/recaptcha-v3-splash-564x315.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        verticalLayout_2->addWidget(groupBox_2);

        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(40);
        sizePolicy6.setVerticalStretch(40);
        sizePolicy6.setHeightForWidth(pushButton_login->sizePolicy().hasHeightForWidth());
        pushButton_login->setSizePolicy(sizePolicy6);
        pushButton_login->setMinimumSize(QSize(40, 45));
        pushButton_login->setMaximumSize(QSize(180, 35));
        pushButton_login->setSizeIncrement(QSize(180, 35));
        pushButton_login->setBaseSize(QSize(180, 35));
        pushButton_login->setFont(font2);
        pushButton_login->setFocusPolicy(Qt::WheelFocus);
        pushButton_login->setContextMenuPolicy(Qt::ActionsContextMenu);
        pushButton_login->setLayoutDirection(Qt::RightToLeft);
        pushButton_login->setAutoFillBackground(false);
        pushButton_login->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_login);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        loginpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loginpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 918, 21));
        loginpage->setMenuBar(menubar);
        statusbar = new QStatusBar(loginpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        loginpage->setStatusBar(statusbar);

        retranslateUi(loginpage);

        QMetaObject::connectSlotsByName(loginpage);
    } // setupUi

    void retranslateUi(QMainWindow *loginpage)
    {
        loginpage->setWindowTitle(QApplication::translate("loginpage", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("loginpage", "Login form", nullptr));
        label_username->setText(QApplication::translate("loginpage", "Username :", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_username->setToolTip(QApplication::translate("loginpage", "Enter your name", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_username->setPlaceholderText(QApplication::translate("loginpage", "Enter your name", nullptr));
        label_password->setText(QApplication::translate("loginpage", "Password :", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_password->setToolTip(QApplication::translate("loginpage", "Enter your password", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_password->setPlaceholderText(QApplication::translate("loginpage", "Enter your password", nullptr));
        radioButton->setText(QApplication::translate("loginpage", "show", nullptr));
        groupBox_2->setTitle(QApplication::translate("loginpage", "Write the generated number in the box as captcha.", nullptr));
        label_verify->setText(QApplication::translate("loginpage", "Captcha not verified!", nullptr));
        pushButton_enter->setText(QApplication::translate("loginpage", "Check Captcha", nullptr));
        pushButton_generate->setText(QApplication::translate("loginpage", "Change Captcha", nullptr));
        lineEdit_generate->setInputMask(QString());
        lineEdit_generate->setText(QString());
        lineEdit_generate->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_enter->setToolTip(QApplication::translate("loginpage", "Enter captcha", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_enter->setPlaceholderText(QApplication::translate("loginpage", "Enter captcha", nullptr));
        label->setText(QString());
        pushButton_login->setText(QApplication::translate("loginpage", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginpage: public Ui_loginpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
