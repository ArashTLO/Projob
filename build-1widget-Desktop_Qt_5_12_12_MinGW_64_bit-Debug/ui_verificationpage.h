/********************************************************************************
** Form generated from reading UI file 'verificationpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFICATIONPAGE_H
#define UI_VERIFICATIONPAGE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verificationpage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_4;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QLabel *label_9;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QStatusBar *statusBar;
    QToolBar *toolBar_4;

    void setupUi(QMainWindow *verificationpage)
    {
        if (verificationpage->objectName().isEmpty())
            verificationpage->setObjectName(QString::fromUtf8("verificationpage"));
        verificationpage->resize(918, 553);
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        verificationpage->setFont(font);
        verificationpage->setAcceptDrops(false);
        verificationpage->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"image: url(:/pishvazpic.JPG);\n"
"background-color: rgb(192, 221, 190);\n"
"font: 40px\n"
"}\n"
"\n"
"#lineEdit_4{\n"
"font: bold 15px;\n"
"border-radius: 8px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"#lineEsit{\n"
"font: bold 15px;\n"
"border-radius: 8px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"\n"
"}\n"
"QPushButton#pushButton{\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"QPushButton#pushButton:hover {\n"
"background-color: rgb(80,80,80);\n"
"font: bold 17px;\n"
"}\n"
"QPushButton#pushButton:pressed {\n"
"background-color: rgb(50,50,50);\n"
"}\n"
"\n"
"QPushButton#pushButton:focus{\n"
"box-shadow: 0 0 5px rgba(0,0,255,0.5);\n"
"font: bold 15px;\n"
"Width: 150px;\n"
"}"));
        centralwidget = new QWidget(verificationpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(918, 512));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(480, 120, 401, 231));
        QFont font1;
        font1.setPointSize(5);
        font1.setStyleStrategy(QFont::PreferDefault);
        groupBox->setFont(font1);
        groupBox->setToolTipDuration(16);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setLocale(QLocale(QLocale::Duala, QLocale::Cameroon));
        groupBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(40, 50, 321, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI"));
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        font2.setKerning(false);
        lineEdit_4->setFont(font2);
        lineEdit_4->setMouseTracking(false);
        lineEdit_4->setAcceptDrops(false);
#ifndef QT_NO_TOOLTIP
        lineEdit_4->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        lineEdit_4->setInputMask(QString::fromUtf8(""));
        lineEdit_4->setFrame(false);
        lineEdit_4->setPlaceholderText(QString::fromUtf8("Enter your school or college name"));
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(40, 170, 131, 31));
        spinBox_2->setMinimum(2010);
        spinBox_2->setMaximum(2024);
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(230, 170, 131, 31));
        spinBox_3->setMinimum(2020);
        spinBox_3->setMaximum(2030);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 20, 181, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nirmala UI"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 140, 71, 31));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 140, 141, 31));
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 350, 301, 111));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nirmala UI"));
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        font4.setKerning(false);
        textEdit->setFont(font4);
        textEdit->setStyleSheet(QString::fromUtf8("font: bold 15px;\n"
"border-radius: 8px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
""));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(50, 60, 211, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nirmala UI"));
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        lineEdit_5->setFont(font5);
        lineEdit_5->setStyleSheet(QString::fromUtf8("font: bold 15px;\n"
"border-radius: 8px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"background-color: rgb(255, 255, 255);\n"
""));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 130, 211, 31));
        lineEdit->setFont(font5);
        lineEdit->setStyleSheet(QString::fromUtf8("\n"
"font: bold 15px;\n"
"border-radius: 8px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"background-color: rgb(255, 255, 255);\n"
""));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 200, 211, 31));
        lineEdit_2->setFont(font5);
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: bold 15px;\n"
"border-radius: 8px;\n"
"border: 1px solid #0640ff;\n"
"padding: 5px;\n"
"background-color: rgb(255, 255, 255);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 121, 31));
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 100, 111, 31));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 170, 131, 31));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 240, 71, 31));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 320, 51, 31));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(54, 66, 51);"));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(50, 270, 121, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(600, 40, 161, 51));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Magneto"));
        font6.setPointSize(20);
        font6.setBold(true);
        font6.setWeight(75);
        label_9->setFont(font6);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 66, 51);\n"
"color: white;\n"
"padding: 5px;\n"
"border-top-left-radius: 40px;\n"
"border-bottom-right-radius: 40px;\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 440, 171, 51));
        pushButton->setFont(font5);
        verificationpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(verificationpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 918, 21));
        verificationpage->setMenuBar(menubar);
        toolBar = new QToolBar(verificationpage);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        verificationpage->addToolBar(Qt::BottomToolBarArea, toolBar);
        toolBar_2 = new QToolBar(verificationpage);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        verificationpage->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(verificationpage);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        verificationpage->addToolBar(Qt::BottomToolBarArea, toolBar_3);
        statusBar = new QStatusBar(verificationpage);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        verificationpage->setStatusBar(statusBar);
        toolBar_4 = new QToolBar(verificationpage);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        verificationpage->addToolBar(Qt::BottomToolBarArea, toolBar_4);

        retranslateUi(verificationpage);

        QMetaObject::connectSlotsByName(verificationpage);
    } // setupUi

    void retranslateUi(QMainWindow *verificationpage)
    {
        verificationpage->setWindowTitle(QApplication::translate("verificationpage", "MainWindow", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("verificationpage", "School or Cpllege / University :", nullptr));
        label_7->setText(QApplication::translate("verificationpage", "Start year :", nullptr));
        label_8->setText(QApplication::translate("verificationpage", "End year (or expected) :", nullptr));
        textEdit->setPlaceholderText(QApplication::translate("verificationpage", "Please enter your address", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("verificationpage", "Enter recent job title ", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("verificationpage", "Enter employment type", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("verificationpage", "Enter recent company", nullptr));
        label->setText(QApplication::translate("verificationpage", "Most recent job title :", nullptr));
        label_2->setText(QApplication::translate("verificationpage", "Employment type :", nullptr));
        label_3->setText(QApplication::translate("verificationpage", "Most recent company :", nullptr));
        label_4->setText(QApplication::translate("verificationpage", "Birth date :", nullptr));
        label_5->setText(QApplication::translate("verificationpage", "Address :", nullptr));
        label_9->setText(QApplication::translate("verificationpage", "PORJOB", nullptr));
        pushButton->setText(QApplication::translate("verificationpage", "Continue", nullptr));
        toolBar->setWindowTitle(QApplication::translate("verificationpage", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("verificationpage", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QApplication::translate("verificationpage", "toolBar_3", nullptr));
        toolBar_4->setWindowTitle(QApplication::translate("verificationpage", "toolBar_4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class verificationpage: public Ui_verificationpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFICATIONPAGE_H
