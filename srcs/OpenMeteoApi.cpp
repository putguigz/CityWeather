#include <nlohmann/json.hpp>
#include "OpenMeteoApi.hpp"

using json = nlohmann::json;

/*please, change DAILYFIELDS_SIZE in .hpp if you add 
fields to dailyFields*/
const char *OpenMeteoApi::dailyFields[DAILYFIELDS_SIZE] = {       
        "temperature_2m_max",
        "temperature_2m_min",
        "precipitation_sum",
        "weathercode"
        };

OpenMeteoApi::OpenMeteoApi( void ){}
OpenMeteoApi::OpenMeteoApi( OpenMeteoApi const & src ) : ApiRequester(src){}
OpenMeteoApi::OpenMeteoApi( string const & url ) : ApiRequester(url){}
OpenMeteoApi::OpenMeteoApi( const char url[] ) : ApiRequester(url) {}
OpenMeteoApi::~OpenMeteoApi( void ){}

OpenMeteoApi &OpenMeteoApi::operator=(OpenMeteoApi const & src){
    ApiRequester::operator=(src);
    return *this;
}

void OpenMeteoApi::addSpecificParameters(City const &city){
    this->pushQueryParameter("latitude", city.getLatitude());
    this->pushQueryParameter("longitude", city.getLongitude());
    this->pushQueryParameter("timezone", city.getTimezone());
    this->pushQueryParameter("daily", aggregateDailyFields());
}

std::string OpenMeteoApi::aggregateDailyFields( void ){
    std::string aggregatedDailyField;

    for (int i = 0; i < DAILYFIELDS_SIZE; i++){
        aggregatedDailyField += dailyFields[i];
        if (i < DAILYFIELDS_SIZE - 1)
            aggregatedDailyField += ",";
    }
    return aggregatedDailyField;
}

std::vector<MeteoTile>  OpenMeteoApi::convertJsonResponseToMap( void ) {
    std::vector<MeteoTile> sevenDaysMeteo;
    
    json parsedJson = json::parse(this->getResponseBody());
    json sevenDaysForecast = parsedJson.at("daily");
    for (int i = 0; i != 7; i++){
        MeteoTile newMeteoDay;

        //TODO THROW CATCH OR PROTECTION AGAINST NON-EXISTENT FIELDS
        newMeteoDay.setMinTemperature(to_string(sevenDaysForecast.at("temperature_2m_min")[i].get<float>()));
        newMeteoDay.setMaxTemperature(to_string(sevenDaysForecast.at("temperature_2m_max")[i].get<float>()));
        newMeteoDay.setPrecipitation(to_string(sevenDaysForecast.at("precipitation_sum")[i].get<float>()));
        newMeteoDay.setWeatherCode(to_string(sevenDaysForecast.at("weathercode")[i].get<int>()));

        sevenDaysMeteo.push_back(newMeteoDay);
    }
    return sevenDaysMeteo;
}
