#include <sstream>
#include <cpr/cpr.h>

#include "ApiRequester.hpp"
#include "FetchDataException.hpp"

// Constructors

ApiRequester::ApiRequester( void )
{
    
}

ApiRequester::ApiRequester( const char url[] )
{
    _url = string(url);
}

ApiRequester::ApiRequester( string const &url) : _url(url)
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

string const	&ApiRequester::getResponseBody(void) const{
    return _response_body;
}

void			ApiRequester::setResponseBody( string newResponse ){
    _response_body = newResponse;
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
    { 
        parameters.Add({it->first, it->second});
    }
    return parameters;
}

string const &ApiRequester::Get( void ) {
    cpr::Response   response;
    cpr::Parameters parameters = generateParameters();
    parameters.encode = false;
    
    //TODO BETTER MANAGE ERRORS
    response = cpr::Get(cpr::Url{_url}, parameters);
    cerr << response.url << std::endl;
    if (response.status_code >= 400)
    {
        cerr << response.text << std::endl;
        throw FetchDataException(_url);
    }
    
    _response_body = response.text;
    return _response_body;
}

// Operators
ApiRequester & ApiRequester::operator=(const ApiRequester &cpy)
{
	if (this != &cpy){
        _url = cpy.getUrl();
        _response_body = cpy.getResponseBody();
        _queryParameters = cpy.getQueryParameters();
    }
	return *this;
}