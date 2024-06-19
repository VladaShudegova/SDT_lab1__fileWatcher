#include "followedfile.h"
#include <QFileInfo>
#include <qDebug>
#include <iostream>

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

    if(!getIsExist()){

        //Файл не существует - на экран выводится информация о том что файл не существует.
        info += path + QString(" doesn't exist.");
    }

    else if(isChange){

        //Файл существует, файл был изменен - на экран выводится факт существования файла,
        //сообщение о том что файл был изменен и его размер.

        info += path + QString(" was changed. ") + QString("Size: ") +  QString::number(size);
    }
    else{

        //Файл существует , файл не  пустой - на экран выводится факт существования файла
        //и его  размер.]

        info += path + QString(" exist. ") + QString("Size: ") +  QString::number(size);


    }

    return info;
}

void FollowedFile::updatedInfo(){
    QFileInfo file(path);
    //задать вопрос: о количестве вызовов file.exists()

    bool currentExist = file.exists();
    qint64 currentSize = file.size();

    if(isExist != currentExist || size != currentSize){
          isExist = currentExist;
          size = currentSize;
          isChange = true;
          emit fileUpdated(this);
    }

}

QString FollowedFile::getPath(){
    return path;
}
