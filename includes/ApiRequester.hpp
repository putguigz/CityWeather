#ifndef APIREQUESTER_HPP
# define APIREQUESTER_HPP

# include <iostream>
# include <string>
# include <map>
# include <cpr/cpr.h>

using namespace std;

typedef map<string, string>::const_iterator paramIterator;

// This is a Base Class for any ApiClass
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
		
		string const 	&Get( void );

	protected:
		void			pushQueryParameter(string key, string value);

	private:
		string						_url;
		string						_response_body;
		bool						_encodeParameter;
		map<string, string>			_queryParameters;

		cpr::Parameters 			generateParameters( void ) const;
};

#endif