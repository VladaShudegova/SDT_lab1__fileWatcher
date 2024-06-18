#ifndef ILOG_H
#define ILOG_H


#include <QObject>

class ILog :public QObject
{
    Q_OBJECT
public:
    virtual void log(const QString& s) const = 0;   //не может изменять никакие нестатические данные-члены класса.
    virtual ~ILog() = default;
};

#endif // ILOG_H
