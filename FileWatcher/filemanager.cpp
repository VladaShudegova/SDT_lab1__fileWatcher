#include "filemanager.h"
#include <followedfile.h>
#include <QDebug>

FileManager::FileManager(ILog* log)
{
    logger = log;

    if(!logger){
        qWarning("FileManager : Logger == nullptr");
    }
}

FileManager& FileManager::Instance(ILog* log){
    static FileManager manager(log);
    return manager;
}


FileManager::~FileManager()
{
    files.clear();
    changedFiles.clear();
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


void FileManager::updateFilesInfo(){
    for(int i = 0; i < files.size(); i++){
        files.at(i)->updatedInfo();
        //qDebug() << "Updated " << files.at(i)->getPath();
    }

    if(!changedFiles.empty()){
        if(logger){
            for(int i = 0; i < changedFiles.size(); i++){
                logger->log(changedFiles.at(i)->getInfo());
            }
            changedFiles.clear();
        }
        else{
        qWarning("updateFilesInfo() : logger == nullptr");
        }
    }
//    else{
//        qDebug() << "List of changed files is empty";
//    }

}


bool FileManager::isEmpty(){

    return files.empty();
}
