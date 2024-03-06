#include "mainwindow.h"
#include "book.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Book res;
    MainWindow w;
    w.show();
    return a.exec();
}
