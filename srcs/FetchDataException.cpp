#include "FetchDataException.hpp"

FetchDataException::FetchDataException( void ){
}

FetchDataException::FetchDataException( cpr::Response response) : _response(response)
{
}

FetchDataException::~FetchDataException(){
}

FetchDataException::FetchDataException( FetchDataException const &src ){
    *this = src;
}

FetchDataException &FetchDataException::operator=( FetchDataException const &src ){
    if (this != &src){
        this->_response = src._response;
    }
    return *this;
}


const char* FetchDataException::what() const noexcept{
    std::stringstream errorMessage;

    errorMessage << "ERROR: " << "http_code=" << _response.status_code <<" url_requested=" << _response.url << " error_message=" << _response.text;

    return (errorMessage.str().c_str());
}
