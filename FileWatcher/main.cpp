#include <QCoreApplication>
#include "followedfile.h"
#include <QDebug>
#include <thread>
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FollowedFile file("C:\\dev\\SDT_lab1__fileWatcher\\FilesTest\\f.docx");
    while(true){

    qDebug() << file.getInfo();
    std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }
    return a.exec();
}
