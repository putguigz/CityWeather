#include <nlohmann/json.hpp>
#include "Utils.hpp"
#include "GeoCodeApi.hpp"

using json = nlohmann::json;

//sets automatically right url
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

// This function is used to add geocoding-specific parameters to the request
void GeoCodeApi::addSpecificParameters(string const &inputCity){
    this->addQueryParameter("name", inputCity);
    this->addQueryParameter("count", "10");
}

// This parse and gets data from the json response
std::vector<City>   GeoCodeApi::convertJsonResponseToMap( void ) {
    std::vector<City> resultCities;

    //this throws if error
    json parsedJson = json::parse(this->getResponseBody());
    for (auto it : parsedJson.at("results")){
        City newCity;

        //these throws if error
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