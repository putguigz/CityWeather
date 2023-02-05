#include "Utils.hpp"

static std::string produceTimeStamp(void){
    using std::chrono::system_clock;

    system_clock::time_point today = system_clock::now();

    std::time_t tt = system_clock::to_time_t ( today );
    std::string formatedCurrentDate = std::string(ctime(&tt));

    // Erase '\n' for better formatting in logger
    formatedCurrentDate.erase(formatedCurrentDate.size() - 1);
    return (formatedCurrentDate);
}

static bool directoryExists(std::string dir){
    struct stat st;

    memset(&st, 0, sizeof(st));
    return (stat(dir.c_str(), &st) == -1);
}

static int createDirectory(std::string dir){
    return (mkdir(dir.c_str(), 0700));
}

void    logError(std::string errorMessage){
    std::string directory("logs");

    if (directoryExists(directory))
        createDirectory(directory);

    std::fstream fileStream ("logs/log.txt", std::fstream::out | std::fstream::app);
    fileStream << "[" << produceTimeStamp() << "] " << errorMessage << std::endl;
    fileStream.close();
}
