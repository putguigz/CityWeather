#include <fstream>
#include <chrono>
#include <ctime>

static std::string produceTimeStamp(void){
    using std::chrono::system_clock;

    system_clock::time_point today = system_clock::now();

    std::time_t tt = system_clock::to_time_t ( today );
    std::string formatedCurrentDate = std::string(ctime(&tt));

    // Erase '\n' for better formatting in logger
    formatedCurrentDate.erase(formatedCurrentDate.size() - 1);
    return (formatedCurrentDate);
}

void    logError(std::string errorMessage){
    std::fstream fileStream ("log.txt", std::fstream::out | std::fstream::app);

    fileStream << "[" << produceTimeStamp() << "] " << errorMessage << std::endl;
    fileStream.close();
}