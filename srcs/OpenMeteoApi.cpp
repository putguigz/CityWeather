#include <nlohmann/json.hpp>

#include "Utils.hpp"
#include "OpenMeteoApi.hpp"

using json = nlohmann::json;

/* This allows easy setting of the daily fields to request */ 
/* if you add new fields, modify accordingly DAILYFIELDS_SIZE in OpenMeteoApi.hpp */ 
/* "aggregateDailyFields()" will automatically do the rest*/
const char *OpenMeteoApi::dailyFields[DAILYFIELDS_SIZE] = {       
        "temperature_2m_min",
        "temperature_2m_max",
        "precipitation_sum",
        "weathercode"
        };

/* Sets automatically the url */
/* Encoding is disabled to allow city names with spaces or accents */
OpenMeteoApi::OpenMeteoApi( void ) : ApiRequester(OPENMETEO_URL){
    setEncodeParameter(false);
}
OpenMeteoApi::OpenMeteoApi( OpenMeteoApi const & src ) : ApiRequester(src){
    setEncodeParameter(false);
}

/* Instanciates with a City object */
OpenMeteoApi::OpenMeteoApi( City const &city ) : ApiRequester(OPENMETEO_URL){
    addSpecificParameters(city);
    setEncodeParameter(false);
}
OpenMeteoApi::~OpenMeteoApi( void ){}

OpenMeteoApi &OpenMeteoApi::operator=(OpenMeteoApi const & src){
    ApiRequester::operator=(src);
    return *this;
}

// This function is used to add OpenMeteo-specific parameters to the request
void OpenMeteoApi::addSpecificParameters(City const &city){
    this->addQueryParameter("latitude", to_string(city.getLatitude()));
    this->addQueryParameter("longitude", to_string(city.getLongitude()));
    this->addQueryParameter("timezone", city.getTimezone());
    this->addQueryParameter("daily", aggregateDailyFields());
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

// This parse and gets data from the json response
// OpenMeteoAPI is a bit different from the other APIs for daily forecasts
// day {today, tomorrow, day after tomorrow, ...}
// temperature_2m_min { today, tomorrow, day after tomorrow, ...}
// ...
std::vector<MeteoTile>  OpenMeteoApi::convertJsonResponseToMap( void ) {
    std::vector<MeteoTile> sevenDaysMeteo(7);

    //TODO if json throws...do something
    json parsedJson = json::parse(this->getResponseBody());
    
    //TODO protect if daily doesn't exist
    json sevenDayForecast = parsedJson.at("daily");
    
    int day = 0;
    for (auto it = sevenDaysMeteo.begin(); it != sevenDaysMeteo.end(); it++, day++){
        MeteoTile &dayForecast = *it;
        
        setClassWithJsonFieldArray<MeteoTile, float>("temperature_2m_min", sevenDayForecast, &dayForecast, day, &MeteoTile::setMinTemperature);
        setClassWithJsonFieldArray<MeteoTile, float>("temperature_2m_max", sevenDayForecast, &dayForecast, day, &MeteoTile::setMaxTemperature);
        setClassWithJsonFieldArray<MeteoTile, float>("precipitation_sum", sevenDayForecast, &dayForecast, day, &MeteoTile::setPrecipitation);
        setClassWithJsonFieldArray<MeteoTile, int>("weathercode", sevenDayForecast, &dayForecast, day, &MeteoTile::setWeatherCode);
    }
    return sevenDaysMeteo;
}
