#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include <QObject>
#include <ilog.h>

class ConsoleLog : public ILog
{
    Q_OBJECT
public:
    ConsoleLog() = default;
    virtual void log(const QString& s) const override;
    virtual ~ConsoleLog() = default;
};

#endif // CONSOLELOG_H
