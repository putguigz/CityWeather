#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <string>
# include <fstream>
# include <chrono>
# include <ctime>
# include <sys/stat.h>
# include <string.h>
# include <nlohmann/json.hpp>

void    logError(std::string errorMessage);

/* function that allows me to check if json tag exists.*/
/* if no, it leaves the field empty or zero-initialized in the class */
/* T : type of value you're getting in json */
/* C : type of Class you're using the setter from */
template <typename C, typename T>
void    setClassWithJsonField(std::string jsonTag, nlohmann::json rawJson, C *newCity, void (C::*setter)(T)){
    try {
        T value = rawJson.at(jsonTag).get<T>();
        (newCity->*setter)(value);
    }
    catch (std::exception &e){
        logError(e.what());
    }
}

#endif