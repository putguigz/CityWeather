#include <fstream>
#include "ApiRequester.hpp"
#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"

//test functions for ApiRequester::Get
void test_ApiRequesterGet(void)
{
    std::fstream fileStream ("test_logs.txt", std::fstream::out | std::fstream::app);
    
    ApiRequester apiRequester;
    
    //SHOULD WORK
    try {
        string url = "http://www.google.com";
        apiRequester.setUrl(url);
        apiRequester.Get();
        fileStream << "Response body: " << apiRequester.getResponseBody() << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //WRONG_URL
    try {
        string url = "http://www.aasdsadsadsad.com";
        apiRequester.setUrl(url);
        apiRequester.Get();
        fileStream << "Response body: " << apiRequester.getResponseBody() << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //WRONG_PARAMS
    try {
        string url = "http://www.aasdsadsadsad.com";
        apiRequester.setUrl(url);
        apiRequester.Get();
        fileStream << "Response body: " << apiRequester.getResponseBody() << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }
}


void    test_GeoCodeApi(void)
{
    std::fstream fileStream ("test_logs.txt", std::fstream::out | std::fstream::app);
    
    //SHOULD WORK
    try {
        GeoCodeApi geoCodeApi("Paris");
        geoCodeApi.Get();
        fileStream << "Response body: " << geoCodeApi.getResponseBody() << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //EMPTY SHOULD NOT THROW
    try {
        GeoCodeApi geoCodeApi("");
        geoCodeApi.Get();
        fileStream << "Response body: " << geoCodeApi.getResponseBody() << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //INEXISTANT_CITY SHOULD NOT THROW
    try {
        GeoCodeApi GeoCodeApi("asdasdaasdjasjkdjaslkdsa");
        GeoCodeApi.Get();
        fileStream << "Response body: " << GeoCodeApi.getResponseBody() << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }
}

//test function for GeoCodeApiconvertJsonResponseToMap
void    test_GeoCodeApiConvertJsonResponseToMap(void)
{
    std::fstream fileStream ("test_logs.txt", std::fstream::out | std::fstream::app);
    
    //SHOULD WORK
    try {
        GeoCodeApi geoCodeApi("Paris");
        geoCodeApi.Get();
        std::vector<City> cities = geoCodeApi.convertJsonResponseToMap();
        for (auto it : cities)
            fileStream << it << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //EMPTY SHOULD THROW WHEN PARSING
    try {
        GeoCodeApi geoCodeApi("");
        geoCodeApi.Get();
        std::vector<City> cities = geoCodeApi.convertJsonResponseToMap();
        for (auto it : cities)
            fileStream << it << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //INEXISTANT_CITY SHOULD THROW WHEN PARSING
    try {
        GeoCodeApi GeoCodeApi("asdasdaasdjasjkdjaslkdsa");
        GeoCodeApi.Get();
        std::vector<City> cities = GeoCodeApi.convertJsonResponseToMap();
        for (auto it : cities)
            fileStream << it << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //MODIFIED RESPONSE SHOULD THROW WHEN PARSING
    try {
        GeoCodeApi GeoCodeApi("Paris");
        GeoCodeApi.Get();
        GeoCodeApi.setResponseBody("{'whatever':['0', '1', '2']}");
        std::vector<City> cities = GeoCodeApi.convertJsonResponseToMap();
        for (auto it : cities)
            fileStream << it << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //MODIFIED RESPONSE SHOULD THROW WHEN PARSING CAUSE LACK OF RIGHT FIELDS
    try {
        GeoCodeApi GeoCodeApi("Paris");
        GeoCodeApi.Get();
        GeoCodeApi.setResponseBody("{'results':['0', '1', '2']}");
        std::vector<City> cities = GeoCodeApi.convertJsonResponseToMap();
        for (auto it : cities)
            fileStream << it << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }

    //SHOULD NOT WORK because of NAME2
    try {
        GeoCodeApi GeoCodeApi("Paris");
        GeoCodeApi.Get();
        GeoCodeApi.setResponseBody("{'results':{'name2': 'jean', 'admin1':'jacques',\
        'country':'france', 'timezone':'Europe/France', 'latitude':0, 'longitude':0}}");
        std::vector<City> cities = GeoCodeApi.convertJsonResponseToMap();
        for (auto it : cities)
            fileStream << it << endl;
    }
    catch (FetchDataException &e) {
        fileStream << "Exception: " << e.what() << endl;
    }
}

int main(void)
{
    test_ApiRequesterGet();
    test_GeoCodeApi();
    test_GeoCodeApiConvertJsonResponseToMap
    return 0;
}