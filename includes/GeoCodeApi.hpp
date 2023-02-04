#ifndef __GEOCODEAPI_HPP__
# define __GEOCODEAPI_HPP__

# include "ApiRequester.hpp"
# include "City.hpp"

class GeoCodeApi : public ApiRequester {
    public:
		GeoCodeApi( void );
		GeoCodeApi( GeoCodeApi const & src );
        GeoCodeApi( string const & url );
		GeoCodeApi( const char url[] );
		virtual ~GeoCodeApi( void );

        GeoCodeApi &operator=(GeoCodeApi const & src);

        void                addSpecificParameters(string const &inputCity);
        std::vector<City>   convertJsonResponseToMap( void );
};

#endif

