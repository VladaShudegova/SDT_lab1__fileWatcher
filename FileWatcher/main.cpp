#include <QCoreApplication>
#include "app.h"
#include <QDebug>

#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    App files;
    files.start();
    return a.exec();
}
