# include "OpenMeteoApi.hpp"

std::string OpenMeteoApi::search(City const &city){
    string requestedFields;

    this.pushQueryParameter("latitude", city.getLatitude());
    this.pushQueryParameter("longitude", city.getLongitude());
    this.pushQueryParameter("timezone", city.getTimezone());
    this.pushQueryParameter("daily", city.getTimezone());

    std::string httpResponse = this.Get();
    return httpResponse;
}

std::string OpenMeteoApi::aggregateDailyFields( void ){
    std::string aggregatedDailyField;

    for (int i = 0; i < DAILYFIELDS_SIZE; i++)
        aggregatedDailyField += dailyFields[i];
    return aggregatedDailyField;
}

//TODO
void   GeoCodeApi::convertJsonResponseToMap( void ) {
   return ;
}
