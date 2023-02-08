#include <nlohmann/json.hpp>
#include "OpenMeteoApi.hpp"
#include "Utils.hpp"

using json = nlohmann::json;

/*please, change DAILYFIELDS_SIZE in .hpp if you add 
fields to dailyFields*/
const char *OpenMeteoApi::dailyFields[DAILYFIELDS_SIZE] = {       
        "temperature_2m_min",
        "temperature_2m_max",
        "precipitation_sum",
        "weathercode"
        };

OpenMeteoApi::OpenMeteoApi( void ) : ApiRequester(OPENMETEO_URL){
    setEncodeParameter(false);
}
OpenMeteoApi::OpenMeteoApi( OpenMeteoApi const & src ) : ApiRequester(src){
    setEncodeParameter(false);
}

OpenMeteoApi::OpenMeteoApi( City const &city ) : ApiRequester(OPENMETEO_URL){
    addSpecificParameters(city);
    setEncodeParameter(false);
}
OpenMeteoApi::~OpenMeteoApi( void ){}

OpenMeteoApi &OpenMeteoApi::operator=(OpenMeteoApi const & src){
    ApiRequester::operator=(src);
    return *this;
}

void OpenMeteoApi::addSpecificParameters(City const &city){
    this->pushQueryParameter("latitude", to_string(city.getLatitude()));
    this->pushQueryParameter("longitude", to_string(city.getLongitude()));
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
