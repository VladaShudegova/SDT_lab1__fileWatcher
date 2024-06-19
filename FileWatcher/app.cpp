#include "app.h"
#include <thread>
#include "consolelog.h"

void App::start(){
    ConsoleLog* cmd = new(std::nothrow) ConsoleLog();

    inputFilesPath(cmd);
    FileManager manager(cmd);

    while(true){
        manager.updateFilesInfo();
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );

    }
    delete cmd;
}

void App::inputFilesPath(ILog* log){
    QTextStream input(stdin);
    QTextStream output(stdin);
    FileManager manager(log);
    output << "input count of files for following" << Qt::endl;
    int countFiles = 0;

    do
    {
        countFiles = input.readLine().toInt();
        if(countFiles <= 0){
            output << "Wrong input";
        }

    } while(countFiles <= 0);

    for (int i = 0; i < countFiles; ++i) {
        output << QString::number(i+1) + "input file path:" << Qt::endl;
        QString path = input.readLine();
        manager.addFile(path);
    }
}
