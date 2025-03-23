#include "app.h"
#include <thread>
#include <qDebug.h>
#include "consolelog.h"

void App::start(){
    ConsoleLog* cmd = new(std::nothrow) ConsoleLog();


    while(true){
        inputFilesPath(cmd);
        if(FileManager::Instance(cmd).isEmpty()){
            qWarning("File Manager have not files for following");
            continue;
        }
        break;
    }

    while(true){
        FileManager::Instance(cmd).updateFilesInfo();
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );

    }
    delete cmd;
}

void App::inputFilesPath(ILog* log){
    QTextStream input(stdin);
    QTextStream output(stdout);

    output << "input count of files for following" << Qt::endl;

    int countFiles = 1;

    while(true)
    {
        countFiles = input.readLine().toInt();
        if(countFiles <= 0){
            output << " Wrong input "<< Qt::endl;
            break; //continue;
        }
        break;
    }
    for (int i = 0; i < countFiles; ++i) {
        output << QString::number(i+1) + " input file path:" << Qt::endl;
        QString path = input.readLine();
        FileManager::Instance(log).addFile(path);
    }
}
