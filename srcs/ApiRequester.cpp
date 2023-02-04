#include <sstream>
#include <cpr/cpr.h>

#include "ApiRequester.hpp"
#include "FetchDataException.hpp"

// Constructors

ApiRequester::ApiRequester( void )
{
    
}

ApiRequester::ApiRequester( string url) : _url(url)
{
}

ApiRequester::ApiRequester(const ApiRequester &copy)
{
	*this = copy;
}


// Destructor
ApiRequester::~ApiRequester()
{
}

string const	&ApiRequester::getUrl(void) const{
    return _url;
}

void			ApiRequester::setUrl(string newUrl){
    _url = newUrl;
}

std::map<string, string> const	&ApiRequester::getQueryParameters(void) const{
    return _queryParameters;
}

void    ApiRequester::setQueryParameters(std::map<string, string> const & newParam)
{
    _queryParameters = newParam;
}

void    ApiRequester::pushQueryParameter(string key, string value){
    _queryParameters.insert(std::pair<string, string>(key, value));
}

cpr::Parameters ApiRequester::generateParameters( void ) const{
    cpr::Parameters parameters;

    for (paramIterator it = _queryParameters.cbegin(); it != _queryParameters.cend(); it++)
        parameters.Add({it->first, it->second});
    return parameters;
}

string  ApiRequester::emitRequest( void ) const {
    cpr::Response   response;
    cpr::Parameters parameters = generateParameters();

    response = cpr::Get(cpr::Url{_url}, parameters);
    std::cout << response.url << std::endl;
    if (response.status_code >= 400)
        throw FetchDataException(_url);
    std::cerr << response.status_code << std::endl;
    return response.text;
}

// Operators
ApiRequester & ApiRequester::operator=(const ApiRequester &cpy)
{
	if (this != &cpy){
        _url = cpy.getUrl();
        _queryParameters = cpy.getQueryParameters();
    }
	return *this;
}