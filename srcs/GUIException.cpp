#include "GUIException.hpp"
#include <sstream>

GUIException::GUIException( void ){
}

GUIException::GUIException( std::string errorMessage)
{
    std::stringstream tmp;
    
    tmp << "GUI ERROR: " << errorMessage;
    _errorMessage = tmp.str();
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
