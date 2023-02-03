#include <sstream>
#include "ApiRequester.hpp"

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

string    ApiRequester::generateRequestUrl( void ) const {
    string stringifiedParameters;

    for (paramIterator it = _queryParameters.cbegin(); it != _queryParameters.cend(); it++){
        std::stringstream keyValue;
        keyValue << it->first + '=' + it->second + '&';
        
        stringifiedParameters += keyValue.str();
    }
    return (_url + '?' + stringifiedParameters);
}

string  ApiRequester::emitRequest( void ) const {
	std::stringstream response;
    // cURLpp::Easy myRequest;

	// myRequest.setOpt<cURLpp::options::Url>(this->generateRequestUrl());
    // myRequest.setOpt(curlpp::options::WriteStream( &response ));
    // myRequest.perform();

    return response.str();
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