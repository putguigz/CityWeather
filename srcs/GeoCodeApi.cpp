#include <nlohmann/json.hpp>
#include "GeoCodeApi.hpp"

using json = nlohmann::json;

GeoCodeApi::GeoCodeApi( void ){}
GeoCodeApi::GeoCodeApi( GeoCodeApi const & src ) : ApiRequester(src){}
GeoCodeApi::GeoCodeApi( string const & url ) : ApiRequester(url){}
GeoCodeApi::GeoCodeApi( const char url[] ) : ApiRequester(url) {}
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
    json Hello = json::parse(this->getResponseBody());

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