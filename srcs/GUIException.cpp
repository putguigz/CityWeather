#include "GUIException.hpp"

GuiException::GuiException( void ){
}

GuiException::GuiException( string errorMessage) : _errorMessage(errorMessage)
{
}

GuiException::~GuiException(){
}

GuiException::GuiException( GuiException const &src ){
    *this = src;
}

GuiException &GuiException::operator=( GuiException const &src ){
    if (this != &src){
        this->_errorMessage = src._errorMessage;
    }
    return *this;
}


const char* GuiException::what() const noexcept{
    return (_errorMessage.c_str());
}
