#include "FetchDataException.hpp"

FetchDataException::FetchDataException( void ){
}

FetchDataException::FetchDataException( cpr::Response response) : _response(response)
{
    std::stringstream tmp;
    
    tmp << "ERROR: " << "http_code=" << _response.status_code <<" url_requested=" << _response.url << " error_message=" << _response.text;
    _errorMessage = tmp.str();
}

FetchDataException::~FetchDataException(){
}

FetchDataException::FetchDataException( FetchDataException const &src ){
    *this = src;
}

FetchDataException &FetchDataException::operator=( FetchDataException const &src ){
    if (this != &src){
        this->_response = src._response;
        this->_errorMessage = src._errorMessage;
    }
    return *this;
}


const char* FetchDataException::what() const noexcept{
    return (_errorMessage.c_str());
}
