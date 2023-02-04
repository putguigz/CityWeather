#include "FetchDataException.hpp"

FetchDataException::FetchDataException( void ){
}

FetchDataException::FetchDataException( std::string url ) : _url(url)
{
}

FetchDataException::~FetchDataException(){
}

FetchDataException::FetchDataException( FetchDataException const &src ){
    *this = src;
}

FetchDataException &FetchDataException::operator=( FetchDataException const &src ){
    if (this != &src){
        this->_url = src._url;
    }
    return *this;
}


const char* FetchDataException::what() const noexcept{
    std::string errorMessage("Error While fetching datas from ");
    errorMessage += _url;

    return errorMessage.c_str();
}
