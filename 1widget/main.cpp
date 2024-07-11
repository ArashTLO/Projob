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

}
