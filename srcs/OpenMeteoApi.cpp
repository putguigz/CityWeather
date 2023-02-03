#include "OpenMeteoApi.hpp"
#include "AMeteoApi.hpp"

// Constructors

OpenMeteoApi::OpenMeteoApi(void){
}

OpenMeteoApi::OpenMeteoApi(string url) : AMeteoApi(url)
{
}

OpenMeteoApi::OpenMeteoApi(const OpenMeteoApi &copy)
{
	*this = copy;
}


// Destructor
OpenMeteoApi::~OpenMeteoApi()
{
}


// Operators
OpenMeteoApi & OpenMeteoApi::operator=(const OpenMeteoApi &cpy)
{
	if (this != &cpy){
    }
	return *this;
}

