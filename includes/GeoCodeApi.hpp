#ifndef __GEOCODEAPI_HPP__
# define __GEOCODEAPI_HPP__

# include "ApiRequester.hpp"

class GeoCodeApi : public ApiRequester {
    public:
        void                search(string const &inputCity);
        std::vector<City>   convertJsonResponseToMap( void );
}

#endif

