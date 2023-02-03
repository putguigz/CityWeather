#ifndef AMETEOAPI_HPP
# define AMETEOAPI_HPP

# include <iostream>
# include <string>
# include <map>

using namespace std;

class AMeteoApi
{
	public:
		AMeteoApi( void );
		AMeteoApi( string url );
		AMeteoApi( const AMeteoApi &copy );
		virtual ~AMeteoApi();
		
		// Operators
		AMeteoApi & operator=( const AMeteoApi &assign );
		
		string const						&getUrl( void ) const;
		void								setUrl( string newUrl );
		std::map<string, string> const		&getQueryParameters(void) const;
		void								setQueryParameters(std::map<string, string> const & newParam);

		void			addQueryParameter(string key, string value);
		string			generateRequestUrl( void ) const;

	private:
		string						_url;
		std::map<string, string>	_queryParameters;
};

#endif