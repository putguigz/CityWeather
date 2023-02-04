#include <iostream>
#include "ApiRequester.hpp"

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

    ApiRequester city("https://geocoding-api.open-meteo.com/v1/search");
    city.pushQueryParameter("name", inputCity);
    city.pushQueryParameter("count", "1");
    cout << city.emitRequest() << endl;
    
    // ApiRequester openmeteo("https://api.open-meteo.com/v1/forecast");
    // openmeteo.pushQueryParameter("latitude", "48.52");
    // openmeteo.pushQueryParameter("longitude", "2.19");
    // cout << openmeteo.emitRequest() << endl;
}