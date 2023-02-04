#ifndef __OPENMETEOAPI_HPP__
# define __OPENMETEOAPI_HPP__

# include "ApiRequester.hpp"
# include "City.hpp"

//CHANGE WHEN MANUALLY ADDING SIZE
# define DAILYFIELDS_SIZE 4

class OpenMeteoApi : public ApiRequester {
    public:
        static const char *dailyFields[] = {       
        "temperature_2m_max",
        "temperature_2m_min",
        "precipitation_sum",
        "weathercode"
        };

        std::string search(City const &city);
        void        convertJsonResponseToMap( void );

    private:
        std::string aggregateDailyFields( void );
}

#endif
