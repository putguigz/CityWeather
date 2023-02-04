# include "OpenMeteoApi.hpp"


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
    this->pushQueryParameter("daily", this->aggregateDailyFields());
}

std::string OpenMeteoApi::aggregateDailyFields( void ){
    std::string aggregatedDailyField;

    for (int i = 0; i < DAILYFIELDS_SIZE; i++)
        aggregatedDailyField += dailyFields[i];
    return aggregatedDailyField;
}

//TODO
void   OpenMeteoApi::convertJsonResponseToMap( void ) {
   return ;
}
