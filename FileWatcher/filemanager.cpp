#include "filemanager.h"
#include <followedfile.h>
#include <QDebug>
FileManager::FileManager()
{

}

FileManager::~FileManager()
{
    files.clear();
}

void FileManager::addFile(const QString& filePath){

    for (FollowedFile* now : files) {
        if((*now).getPath() == filePath){
            qWarning("This file was added earlier");
            return;
        }
    }

    FollowedFile* file = new FollowedFile(filePath);

    if(file){
        files.push_back(file);
        connect(file, &FollowedFile::fileUpdated, this, &FileManager::addToChangedFiles);
        qDebug() << "Added file" << file->getPath();
    }
    else{
        qWarning("FileManager::addFile : file not initialized, out of memory");
    }

}

void FileManager::addToChangedFiles(FollowedFile* file){
    changedFiles.push_back(file);
}


void FileManager::removeFile(const QString& filePath){
    for (auto it = files.begin(); it != files.end(); ++it) {
        if ((*it)->getPath() == filePath) {
            delete *it;
            files.erase(it);
            break;
        }
    }
}
