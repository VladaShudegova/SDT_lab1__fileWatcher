#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QVector>
#include <ILog.h>
#include <followedfile.h>
class FileManager: public QObject
{
    Q_OBJECT

public:
    explicit FileManager();
    ~FileManager();

    void addFile(const QString& filePath);
    void removeFile(const QString& filePath);
    void updateFilesInfo();


public slots:
    void addToChangedFiles(FollowedFile* file);

private:

    QVector<FollowedFile*> files;
    QVector<FollowedFile*> changedFiles;
    ILog* logger;
};

#endif // FILEMANAGER_H
