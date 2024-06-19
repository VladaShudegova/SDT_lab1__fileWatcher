#ifndef APP_H
#define APP_H


#include <consolelog.h>
#include <filemanager.h>
#include <QTextStream>

class App
{

public:
    App() = default;
    void start();
    void inputFilesPath(ILog *log);
};

#endif // APP_H
