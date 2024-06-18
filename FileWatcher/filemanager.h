#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QVector>
#include <followedfile.h>
class FileManager: public QObject
{
    Q_OBJECT

public:
    explicit FileManager();
    ~FileManager();

    void addFile(const QString& filePath);
    void removeFile(const QString& filePath);

public slots:
    void addToChangedFiles(FollowedFile* file);

private:
    QVector<FollowedFile*> files;
    QVector<FollowedFile*> changedFiles;
};

#endif // FILEMANAGER_H
