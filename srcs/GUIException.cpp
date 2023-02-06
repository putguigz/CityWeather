#include "GUIException.hpp"

GUIException::GUIException( void ){
}

GUIException::GUIException( std::string errorMessage) : _errorMessage(errorMessage)
{
}

GUIException::~GUIException(){
}

GUIException::GUIException( GUIException const &src ){
    *this = src;
}

GUIException &GUIException::operator=( GUIException const &src ){
    if (this != &src){
        this->_errorMessage = src._errorMessage;
    }
    return *this;
}


const char* GUIException::what() const noexcept{
    return (_errorMessage.c_str());
}
