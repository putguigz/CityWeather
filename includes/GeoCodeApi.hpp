#ifndef __GEOCODEAPI_HPP__
#define __GEOCODEAPI_HPP__

#include "ApiRequester.hpp"
#include "City.hpp"

#define GEOCODE_URL "https://geocoding-api.open-meteo.com/v1/search"

// This class is used to get the coordinates of a city
class GeoCodeApi : public ApiRequester
{
public:
    GeoCodeApi(void);
    GeoCodeApi(GeoCodeApi const &src);
    GeoCodeApi(string const &cityInputed);
    virtual ~GeoCodeApi(void);

    GeoCodeApi &operator=(GeoCodeApi const &src);

    // This function is used to add geocoding-specific parameters to the request
    // here, it's the city name
    void addSpecificParameters(string const &inputCity);

    //this parses and converts the json response to a vector of City
    std::vector<City> convertJsonResponseToMap(void);
};

#endif
