#include <iostream>
#include <list>
#include <nlohmann/json.hpp>

#include "City.hpp"
#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"

#define GEOCODE_URL    "https://geocoding-api.open-meteo.com/v1/search"
#define OPENMETEO_URL  "https://api.open-meteo.com/v1/forecast"


// for convenience
using namespace std;

//TODO DELETE WHEN APP GETS GRAPHICAL
static string user_input(void){
    string response;

    cout << "Enter City Name:" << std::endl;
    cin >> response;
    return response;
}

int main(void){
    string inputCity = user_input();

    GeoCodeApi      request(GEOCODE_URL);
    request.addSpecificParameters(inputCity);
    request.Get();

    auto resultCities = request.convertJsonResponseToMap();
    for (citiesIterator it = resultCities.cbegin(); it!= resultCities.cend(); it++){
        cout << *it << std::endl;
    }

    OpenMeteoApi    request2(OPENMETEO_URL);
    request2.addSpecificParameters(resultCities[0]);
    request2.Get();

    auto resultMeteos = request2.convertJsonResponseToMap();
    for (auto it = resultMeteos.cbegin(); it != resultMeteos.cend(); it++){
        cout << *it << std::endl;
    }
}