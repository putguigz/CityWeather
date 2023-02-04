#include <iostream>
#include <list>
#include <nlohmann/json.hpp>

#include "City.hpp"
#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"

// for convenience
using namespace std;
using json = nlohmann::json;

//TODO DELETE WHEN APP GETS GRAPHICAL
static string user_input(void){
    string response;

    cout << "Enter City Name:" << std::endl;
    cin >> response;
    return response;
}

int main(void){
    string inputCity = user_input();

    // auto resultCities = jsonToCities(httpResponse);
    // for (citiesIterator it = resultCities.cbegin(); it!= resultCities.cend(); it++){
    //     cout << *it << std::endl;
    // }
}