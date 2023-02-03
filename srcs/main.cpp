#include <iostream>

#include "ApiRequester.hpp"

using namespace std;


//Needed to set up cleanly curlpp
// static void curl_init(){
//     curlpp::initialize(CURL_GLOBAL_ALL);
// }

// //Needed to terminate cleanly curlpp
// static void curl_cleanup(){
//     curlpp::terminate();
// }


//TODO DELETE WHEN APP GETS GRAPHICAL
// static string user_input(void){
//     string response;

//     cout << "Enter City Name:" << std::endl;
//     cin >> response;
//     return response;
// }

int main(void){
    // curl_init();
    
    // string inputCity = user_input(void);

    // ApiRequester city("https://geocoding-api.open-meteo.com/v1/search");
    // string inputCity;
    // city.pushQueryParameter("name", inputCity);
    // city.pushQueryParameter("count", "1");
    // cout << city.emitRequest() << endl;
    
    // ApiRequester openmeteo("https://api.open-meteo.com/v1/forecast");
    // openmeteo.pushQueryParameter("latitude", "48.52");
    // openmeteo.pushQueryParameter("longitude", "2.19");
    // cout << openmeteo.emitRequest() << endl;

    // curl_cleanup();
}