#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <string>
# include <nlohmann/json.hpp>

void    logError(std::string errorMessage);

/* function that allows me to check if json tag exists.*/
/* if no, it leaves the field empty or zero-initialized in the class */
/* T : type of value you're getting in json */
/* C : type of Class you're using the setter from */
/* jsonTag : json tag you're searching example: "username" */
/* rawJson : the json you want to parse */
/* newCity : the modified object */
/* setter : the setter from the modified object */
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


/* function that allows me to check if json tag exists.*/
/* if no, it leaves the field empty or zero-initialized in the class */
/* T : type of value you're getting in json */
/* C : type of Class you're using the setter from */
/* jsonTag : json tag you're searching example: "username" */
/* rawJson : the json you want to parse */
/* meteoTile : the modified object */
/* setter : the setter from the modified object */
template <typename C, typename T>
void    setClassWithJsonFieldArray(std::string jsonTag, nlohmann::json rawJson, C *meteoTile,  int i, void (C::*setter)(T)){
    try {
        T value = rawJson.at(jsonTag)[i].get<T>();
        (meteoTile->*setter)(value);
    }
    catch (std::exception &e){
        logError(e.what());
    }
}

#endif