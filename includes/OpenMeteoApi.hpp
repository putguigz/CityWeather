#ifndef OPENMETEOAPI_HPP
# define OPENMETEOAPI_HPP

# include <iostream>
# include <string>
# include "AMeteoApi.hpp"

class OpenMeteoApi : public AMeteoApi
{
	public:
		OpenMeteoApi( void );
		OpenMeteoApi( string url );
		OpenMeteoApi( const OpenMeteoApi &copy );
		~OpenMeteoApi();
		
		OpenMeteoApi & operator=(const OpenMeteoApi &assign);
		
	private:		
};

#endif