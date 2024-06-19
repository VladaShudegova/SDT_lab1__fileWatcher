#include "consolelog.h"
#include <QTextStream>

void ConsoleLog::log(const QString& s) const
{
    QTextStream out(stdout);
    out<<s<<Qt::endl;
}
