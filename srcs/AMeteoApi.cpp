#include <sstream>
#include "AMeteoApi.hpp"

typedef std::map<string, string>::const_iterator paramIterator;

// Constructors

AMeteoApi::AMeteoApi( void )
{
    
}

AMeteoApi::AMeteoApi( string url) : _url(url)
{
}

AMeteoApi::AMeteoApi(const AMeteoApi &copy)
{
	*this = copy;
}


// Destructor
AMeteoApi::~AMeteoApi()
{
}

string const	&AMeteoApi::getUrl(void) const{
    return _url;
}

void			AMeteoApi::setUrl(string newUrl){
    _url = newUrl;
}

std::map<string, string> const	&AMeteoApi::getQueryParameters(void) const{
    return _queryParameters;
}

void    AMeteoApi::setQueryParameters(std::map<string, string> const & newParam)
{
    _queryParameters = newParam;
}

void    AMeteoApi::addQueryParameter(string key, string value){
    _queryParameters.insert(std::pair<string, string>(key, value));
}

string    AMeteoApi::generateRequestUrl( void ) const {
    string stringifiedParameters;

    for (paramIterator it = _queryParameters.cbegin(); it != _queryParameters.cend(); it++){
        std::stringstream keyValue;
        keyValue << it->first + '=' + it->second + '&';
        
        stringifiedParameters += keyValue.str();
    }
    return (_url + '?' + stringifiedParameters);
}

// Operators
AMeteoApi & AMeteoApi::operator=(const AMeteoApi &cpy)
{
	if (this != &cpy){
        _url = cpy.getUrl();
        _queryParameters = cpy.getQueryParameters();
    }
	return *this;
}