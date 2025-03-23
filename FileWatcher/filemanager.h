#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QVector>
#include <ILog.h>
#include <followedfile.h>
class FileManager: public QObject
{
    Q_OBJECT
private:
    FileManager(ILog*);
    ~FileManager();
    FileManager(FileManager const&) = delete; //конструктор копирования
    FileManager& operator = (FileManager const&) = delete; //удаляем оператор присваивания

public:
    static FileManager& Instance(ILog* log);

    void addFile(const QString& filePath);
    void removeFile(const QString& filePath);
    void updateFilesInfo();
    bool isEmpty();


public slots:
    void addToChangedFiles(FollowedFile* file);


private:

    QVector<FollowedFile*> files;
    QVector<FollowedFile*> changedFiles;
    ILog* logger;
};

#endif // FILEMANAGER_H
