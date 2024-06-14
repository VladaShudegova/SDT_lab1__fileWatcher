#ifndef FOLLOWEDFILE_H
#define FOLLOWEDFILE_H

#include <QObject>
#include <QString>
class FollowedFile: public QObject
{
    Q_OBJECT
public:
    FollowedFile(const QString& fileName);
    ~FollowedFile();

private:
    QString path;
    qint64 size;    //при работе с файлами, превышающими 4ГБ, поддерживает дробную часть
    bool isExist;

};

#endif // FOLLOWEDFILE_H
