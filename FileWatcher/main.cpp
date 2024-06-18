#include <QCoreApplication>
//#include "followedfile.h"
#include "filemanager.h"
#include <QDebug>
#include <thread>
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FollowedFile f("C:\\dev\\SDT_lab1__fileWatcher\\FilesTest\\f.docx");
    //qDebug() << f.getPath();
    QString fileName1 = "C:\\dev\\FW\\SDT_lab1__fileWatcher\\FilesTest\\f.docx";//"C:\\dev\\SDT_lab1__fileWatcher\\FilesTest\\f.docx";
   // QString fileName2 = "C:\\dev\\SDT_lab1__fileWatcher\\FilesTest\\file1.txt";
    QString fileName2 = "C:\\dev\\FW\\SDT_lab1__fileWatcher\\FilesTest\\file1.txt";

    FileManager manager;
    manager.addFile(fileName1);
    manager.addFile(fileName2);

    while(true){

        //qDebug() << file.getInfo();
        manager.updateFilesInfo();
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }
    return a.exec();
}
