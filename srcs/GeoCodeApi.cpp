#include <nlohmann/json.hpp>
#include "GeoCodeApi.hpp"

void GeoCodeApi::search(string const &inputCity){
    this.pushQueryParameter("name", inputCity);
    this.pushQueryParameter("count", "10");
    
    //TODO protect against no URL
    this.Get();
}

std::vector<City>   GeoCodeApi::convertJsonResponseToMap( void ) {
    std::vector<City> resultCities;
    json Hello = json::parse(httpResponse);

    for (auto it : Hello.at("results")){
        City newCity;

        //TODO THROW CATCH OR PROTECTION AGAINST NON-EXISTENT FIELDS
        newCity.setName(it.at("name").get<std::string>());
        newCity.setLocality(it.at("admin1").get<std::string>());
        newCity.setCountry(it.at("country").get<std::string>());
        newCity.setLatitude(to_string(it.at("latitude").get<double>()));
        newCity.setLongitude(to_string(it.at("longitude").get<double>()));

        resultCities.push_back(newCity);
    }
    return resultCities;
}