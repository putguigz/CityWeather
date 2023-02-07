#include <nlohmann/json.hpp>
#include "Utils.hpp"
#include "GeoCodeApi.hpp"

using json = nlohmann::json;

GeoCodeApi::GeoCodeApi( void ) : ApiRequester(GEOCODE_URL){}
GeoCodeApi::GeoCodeApi( GeoCodeApi const & src ) : ApiRequester(src){}
GeoCodeApi::GeoCodeApi( string const & cityInputed ) : ApiRequester(GEOCODE_URL) {
    addSpecificParameters(cityInputed);
}
GeoCodeApi::~GeoCodeApi( void ){}

GeoCodeApi &GeoCodeApi::operator=(GeoCodeApi const & src){
    ApiRequester::operator=(src);
    return *this;
}

void GeoCodeApi::addSpecificParameters(string const &inputCity){
    this->pushQueryParameter("name", inputCity);
    this->pushQueryParameter("count", "10");
}

std::vector<City>   GeoCodeApi::convertJsonResponseToMap( void ) {
    std::vector<City> resultCities;

    json parsedJson = json::parse(this->getResponseBody());
    if (parsedJson.find("results") == parsedJson.end())
        return resultCities;
    for (auto it : parsedJson.at("results")){
        City newCity;

        setClassWithJsonField<City, string>("name", it, &newCity, &City::setName);
        setClassWithJsonField<City, string>("admin1", it, &newCity, &City::setLocality);
        setClassWithJsonField<City, string>("country", it, &newCity, &City::setCountry);
        setClassWithJsonField<City, string>("timezone", it, &newCity, &City::setTimezone);
        setClassWithJsonField<City, float>("latitude", it, &newCity, &City::setLatitude);
        setClassWithJsonField<City, float>("longitude", it, &newCity, &City::setLongitude);
        
        resultCities.push_back(newCity);
    }
    return resultCities;
}