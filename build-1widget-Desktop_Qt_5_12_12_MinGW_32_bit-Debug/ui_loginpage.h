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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton_generate;
    QLineEdit *lineEdit_generate;
    QPushButton *pushButton_enter;
    QLineEdit *lineEdit_enter;
    QLabel *label_verify;
    QPushButton *pushButton_login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loginpage)
    {
        if (loginpage->objectName().isEmpty())
            loginpage->setObjectName(QString::fromUtf8("loginpage"));
        loginpage->resize(552, 336);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginpage->sizePolicy().hasHeightForWidth());
        loginpage->setSizePolicy(sizePolicy);
        loginpage->setMaximumSize(QSize(16777213, 16777213));
        loginpage->setLayoutDirection(Qt::LeftToRight);
        loginpage->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-color: rgb(194,239,185);\n"
"}\n"
"\n"
"QPushButton#pushButton_login {\n"
"color : white;\n"
"background-color:black;\n"
"transiition:0.2s;\n"
"}\n"
"QPushButton#pushButton_login:hover {\n"
"background-color: rgb(80,80,80);\n"
"}\n"
"QPushButton#pushButton_login:pressed {\n"
"background-color: rgb(50,50,50);\n"
"}\n"
"QGroupBox#groupBox {\n"
"}"));
        loginpage->setAnimated(true);
        centralwidget = new QWidget(loginpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        horizontalLayout_2->addWidget(label_username);

        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));

        horizontalLayout_2->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(10, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        horizontalLayout_3->addWidget(label_password);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_3->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setLayoutDirection(Qt::RightToLeft);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(55, 26, 201, 91));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_generate = new QPushButton(layoutWidget);
        pushButton_generate->setObjectName(QString::fromUtf8("pushButton_generate"));
        pushButton_generate->setStyleSheet(QString::fromUtf8("\n"
"font-weight:bold"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton_generate);

        lineEdit_generate = new QLineEdit(layoutWidget);
        lineEdit_generate->setObjectName(QString::fromUtf8("lineEdit_generate"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(lineEdit_generate->sizePolicy().hasHeightForWidth());
        lineEdit_generate->setSizePolicy(sizePolicy2);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_generate);

        pushButton_enter = new QPushButton(layoutWidget);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));
        pushButton_enter->setStyleSheet(QString::fromUtf8("\n"
"font-weight:bold"));

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButton_enter);

        lineEdit_enter = new QLineEdit(layoutWidget);
        lineEdit_enter->setObjectName(QString::fromUtf8("lineEdit_enter"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_enter);

        label_verify = new QLabel(layoutWidget);
        label_verify->setObjectName(QString::fromUtf8("label_verify"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_verify);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton_login);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        loginpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loginpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 552, 20));
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
        label_username->setText(QApplication::translate("loginpage", "Username", nullptr));
        label_password->setText(QApplication::translate("loginpage", "Password", nullptr));
        groupBox_2->setTitle(QApplication::translate("loginpage", "\330\250\330\271\331\206\331\210\330\247\331\206 \332\251\331\276\332\206\330\247 \330\271\330\257\330\257 \330\252\331\210\331\204\333\214\330\257 \330\264\330\257\331\207 \330\261\330\247 \330\257\330\261 \330\250\330\247\332\251\330\263 \330\250\331\206\331\210\333\214\330\263\333\214\330\257 ", nullptr));
        pushButton_generate->setText(QApplication::translate("loginpage", "Generate", nullptr));
        lineEdit_generate->setText(QString());
        pushButton_enter->setText(QApplication::translate("loginpage", "Enter", nullptr));
        label_verify->setText(QApplication::translate("loginpage", "Captcha not verified!", nullptr));
        pushButton_login->setText(QApplication::translate("loginpage", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginpage: public Ui_loginpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
