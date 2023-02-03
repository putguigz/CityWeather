#include <iostream>
#include "OpenMeteoApi.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

using namespace std;


static void curl_init(){
    cURLpp::initialize(CURL_GLOBAL_ALL);
}

static void curl_cleanup(){
    cURLpp::terminate();
}


int main(void){
    OpenMeteoApi openmeteo("https://api.open-meteo.com/v1/forecast");

    openmeteo.addQueryParameter("latitude", "48.52");
    openmeteo.addQueryParameter("longitude", "2.19");


    cout << openmeteo.generateRequestUrl() << endl;
    curl_init();
    curl_cleanup();
}