/********************************************************************************
** Form generated from reading UI file 'verificationpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFICATIONPAGE_H
#define UI_VERIFICATIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verificationpage
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *verificationpage)
    {
        if (verificationpage->objectName().isEmpty())
            verificationpage->setObjectName(QString::fromUtf8("verificationpage"));
        verificationpage->resize(800, 600);
        menubar = new QMenuBar(verificationpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        verificationpage->setMenuBar(menubar);
        centralwidget = new QWidget(verificationpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verificationpage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(verificationpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        verificationpage->setStatusBar(statusbar);

        retranslateUi(verificationpage);

        QMetaObject::connectSlotsByName(verificationpage);
    } // setupUi

    void retranslateUi(QMainWindow *verificationpage)
    {
        verificationpage->setWindowTitle(QApplication::translate("verificationpage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class verificationpage: public Ui_verificationpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFICATIONPAGE_H
