#include "startpage.h"
#include <QApplication>
#include "loginpage.h"
#include "post.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startPage w;
    w.show();
    return a.exec();

    loginpage loginpage;
    loginpage.show();
    int number = loginpage.getNumber();
    post post(number);
    post.show();
}

/*
    QApplication app(argc, argv);
    MyWindow window;
    window.show();
    return app.exec();*/
