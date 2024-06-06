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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *startPage)
    {
        if (startPage->objectName().isEmpty())
            startPage->setObjectName(QString::fromUtf8("startPage"));
        startPage->resize(918, 553);
        startPage->setStyleSheet(QString::fromUtf8("QMainWindow  {\n"
"background-color:rgb(198, 235, 197);\n"
"font: 40px\n"
"}\n"
"#vorudButton {\n"
"background-color: black;\n"
"color: white;\n"
"font: bold 15px;\n"
"border-radius: 10px;\n"
"transition: 0.2s;\n"
"}\n"
"QPushButton#vorudButton:hover {\n"
"background-color: rgb(80,80,80);\n"
"}\n"
"QPushButton#vorudButton:pressed {\n"
"background-color: rgb(50, 50, 50);\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(startPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vorudButton = new QPushButton(centralwidget);
        vorudButton->setObjectName(QString::fromUtf8("vorudButton"));
        vorudButton->setGeometry(QRect(390, 220, 141, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 861, 151));
        label->setStyleSheet(QString::fromUtf8("font : 17px;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-260, 270, 1481, 331));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/pishvazpic.JPG);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 30, 161, 31));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(54, 66, 51);\n"
"font: 25px;\n"
"font-weight:bold;"));
        startPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 918, 20));
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
        vorudButton->setText(QApplication::translate("startPage", "\331\210\330\261\331\210\330\257 \330\250\331\207 \330\250\330\261\331\206\330\247\331\205\331\207", nullptr));
        label->setText(QApplication::translate("startPage", "\330\247\333\214\331\206 \330\247\331\276 \331\205\331\206\330\247\330\263\330\250 \332\206\331\207 \332\251\330\263\330\247\331\206\333\214 \330\247\330\263\330\252\330\237 \n"
"  \331\207\330\261\332\251\330\263 \332\251\331\207 \330\250\331\207 \330\257\331\206\330\250\330\247\331\204 \331\207\331\205\332\251\330\247\330\261\333\214 \331\210 \331\201\330\271\330\247\331\204\333\214\330\252 \330\257\330\261 \330\255\331\210\330\262\331\207 \330\252\330\256\330\265\330\265 \330\256\331\210\330\257\330\264 \330\247\330\263\330\252 \n"
" \330\250\330\261\330\247\333\214 \330\253\330\250\330\252 \331\206\330\247\331\205 \331\204\330\267\331\201\330\247 \330\247\331\210\331\204 \330\257\332\251\331\205\331\207 \331\210\330\261\331\210\330\257 \330\261\330\247 \331\201\330\264\330\247\330\261 \330\257\331\207\333\214\330\257", nullptr));
        label_2->setText(QApplication::translate("startPage", "1", nullptr));
        label_3->setText(QApplication::translate("startPage", "\330\256\331\210\330\264 \330\247\331\210\331\205\330\257\333\214\330\257", nullptr));
        toolBar->setWindowTitle(QApplication::translate("startPage", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startPage: public Ui_startPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
