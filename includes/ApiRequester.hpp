#ifndef APIREQUESTER_HPP
# define APIREQUESTER_HPP

# include <iostream>
# include <string>
# include <map>
# include <cpr/cpr.h>

using namespace std;

typedef map<string, string>::const_iterator paramIterator;


class ApiRequester
{
	public:
		ApiRequester( void );
		ApiRequester( string url );
		ApiRequester( const ApiRequester &copy );
		virtual ~ApiRequester();
		
		// Operators
		ApiRequester & operator=( const ApiRequester &assign );
		
		string const						&getUrl( void ) const;
		void								setUrl( string newUrl );
		string const						&getResponseBody( void ) const;
		void								setResponseBody( string newUrl );
		map<string, string> const			&getQueryParameters(void) const;
		void								setQueryParameters(map<string, string> const & newParam);

		string const 	&Get( void );
		virtual void	search() = 0;
		virtual void	convertJsonResponseToMap() = 0;

	private:
		string						_url;
		string						_response_body;
		map<string, string>			_queryParameters;

		void			pushQueryParameter(string key, string value);
		cpr::Parameters generateParameters( void ) const;
};

#endif