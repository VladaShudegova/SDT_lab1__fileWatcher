#ifndef FOLLOWEDFILE_H
#define FOLLOWEDFILE_H

#include <QObject>
#include <QString>


class FollowedFile: public QObject
{
    Q_OBJECT
public:
    explicit FollowedFile(const QString& fileName);
    ~FollowedFile();
    qint64 getSize();
    bool getIsExist();

    QString getInfo();
    void updatedInfo();

signals:
    void fileUpdated(FollowedFile*);

private:
    QString path;
    qint64 size;    //при работе с файлами, превышающими 4ГБ, поддерживает дробную часть
    bool isExist;
    bool isChange;
};

#endif // FOLLOWEDFILE_H
