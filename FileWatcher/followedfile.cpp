#include "followedfile.h"
#include <QFileInfo>


FollowedFile::FollowedFile(const QString& filePath)
{
    QFileInfo file(filePath);
    path = filePath;
    size = file.size();
    isExist = file.exists();
}

FollowedFile::~FollowedFile()
{ }

qint64 FollowedFile::getSize(){
    return size;
}

bool FollowedFile::getIsExist(){
    return isExist;
}

QString FollowedFile::getInfo(){
    QString info = "File ";

    if(isExist){

        //Файл существует , файл не  пустой - на экран выводится факт существования файла
        //и его  размер.]
        if(size > 0){
            info += path + QString(" exist.\n ") + QString("Size: ") +  QString::number(size);
        }

        //Файл существует, файл был изменен - на экран выводится факт существования файла,
        //сообщение о том что файл был изменен и его размер.
        else{
            info += path + QString(" was changed\n ") + QString("Size: ") +  QString::number(size);
        }
    }
    else{

        //Файл не существует - на экран выводится информация о том что файл не существует.
          info += path + QString(" doesn't exist\n ");
    }

    return info;

}


