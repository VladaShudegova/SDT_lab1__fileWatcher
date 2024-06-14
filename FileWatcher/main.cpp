#include <QCoreApplication>
#include "followedfile.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FollowedFile file("C:\\dev\\SDT_lab1__fileWatcher\\FilesTest\\f.docx");
    qDebug() << file.getInfo();
    return a.exec();
}
