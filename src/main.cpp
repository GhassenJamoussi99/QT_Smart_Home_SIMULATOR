#include <QApplication>
#include <QtDebug>
#include <iostream>
#include "app.h"

int main(int argc, char *argv[])
{
    qDebug() << "Starting the program";
    QApplication a(argc, argv);
    app w;
    w.show();
    return a.exec();
}
