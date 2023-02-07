#ifndef __OPENMETEOAPI_HPP__
# define __OPENMETEOAPI_HPP__

# include "ApiRequester.hpp"
# include "City.hpp"
# include "MeteoTile.hpp"

# define OPENMETEO_URL   "https://api.open-meteo.com/v1/forecast"

# define DAILYFIELDS_SIZE 4

class OpenMeteoApi : public ApiRequester {
    public:
        static const char *dailyFields[DAILYFIELDS_SIZE];

		OpenMeteoApi( void );
		OpenMeteoApi( OpenMeteoApi const & src );
        OpenMeteoApi( City const &city );
        virtual ~OpenMeteoApi( void );

        OpenMeteoApi &operator=(OpenMeteoApi const & src);
        
        void                    addSpecificParameters(City const &city);
        std::vector<MeteoTile>  convertJsonResponseToMap( void );

    private:
        std::string             aggregateDailyFields( void );
};

#endif
