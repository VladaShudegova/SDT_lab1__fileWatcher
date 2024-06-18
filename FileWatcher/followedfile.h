#ifndef FOLLOWEDFILE_H
#define FOLLOWEDFILE_H

#include <QObject>
#include <QString>


class FollowedFile: public QObject
{
    Q_OBJECT
public:
     // Объявление явного конструктора,
    //ПРЕДОТВРАЩАЕТ ошибку преобразования строки fileName в объект класса : FollowedFile file = fileName;
    explicit FollowedFile(const QString& fileName);
    ~FollowedFile();
    qint64 getSize();
    bool getIsExist();
    void updatedInfo();
    QString getInfo();
    QString getPath();


signals:
    void fileUpdated(FollowedFile*);




private:
    QString path;
    qint64 size;    //при работе с файлами, превышающими 4ГБ, поддерживает дробную часть
    bool isExist;
    bool isChange;
};

#endif // FOLLOWEDFILE_H
