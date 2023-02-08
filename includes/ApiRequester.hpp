#ifndef APIREQUESTER_HPP
# define APIREQUESTER_HPP

# include <iostream>
# include <string>
# include <map>
# include <cpr/cpr.h>

using namespace std;

typedef map<string, string>::const_iterator paramIterator;

// This is a Base Class for any API-Class
class ApiRequester
{
	public:
		ApiRequester( void );
		ApiRequester( const char url[] );
		ApiRequester( string const & url );
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
		
		bool const							&getEncodeParameter( void ) const;
		void								setEncodeParameter( bool parameter );
		

		// Emits HTTP GET to the _url with _queryParameters as parameters
		string const 	&Get( void );

		// Allows user hand adding of parameters
		void			addQueryParameter(string key, string value);

	private:
		// URL of the target API
		string						_url;
		// Response body of the last request
		string						_response_body;
		// Choose to encode or not the parameters. Automatically set to true
		bool						_encodeParameter;
		// Parameters to be sent with the request
		map<string, string>			_queryParameters;

		// Generates request-needed cpr::Parameters from _queryParameters
		cpr::Parameters 			generateParameters( void ) const;
};

#endif