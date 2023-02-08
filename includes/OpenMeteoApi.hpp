#ifndef __OPENMETEOAPI_HPP__
# define __OPENMETEOAPI_HPP__

# include "City.hpp"
# include "MeteoTile.hpp"
# include "ApiRequester.hpp"

# define OPENMETEO_URL   "https://api.open-meteo.com/v1/forecast"

# define DAILYFIELDS_SIZE 4

// This class is used to get the weather of a city
class OpenMeteoApi : public ApiRequester {
    public:
        //Used to add the daily fields to the request simply
        static const char *dailyFields[DAILYFIELDS_SIZE];

		OpenMeteoApi( void );
		OpenMeteoApi( OpenMeteoApi const & src );
        OpenMeteoApi( City const &city );
        virtual ~OpenMeteoApi( void );

        OpenMeteoApi &operator=(OpenMeteoApi const & src);
        
        // This function is used to add geocoding-specific parameters to the request
        // here, it's a City object
        void                    addSpecificParameters(City const &city);

        //this pasrses and converts the json response to a vector of MeteoTile
        std::vector<MeteoTile>  convertJsonResponseToMap( void );

    private:
        std::string             aggregateDailyFields( void );
};

#endif
