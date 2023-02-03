#ifndef APIREQUESTER_HPP
# define APIREQUESTER_HPP

# include <iostream>
# include <string>
# include <map>

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
		map<string, string> const			&getQueryParameters(void) const;
		void								setQueryParameters(map<string, string> const & newParam);

		void			pushQueryParameter(string key, string value);
		string			generateRequestUrl( void ) const;
		string		emitRequest( void ) const;

	private:
		string						_url;
		map<string, string>	_queryParameters;
};

#endif