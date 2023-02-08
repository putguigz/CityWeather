#ifndef __GUIEXCEPTION_HPP__
# define __GUIEXCEPTION_HPP__

# include <exception>
# include <string>

class GUIException : public std::exception
{
    public:
        GUIException( void );
        GUIException( std::string );
        virtual ~GUIException( void );
        GUIException( GUIException const &src );

        GUIException &operator=( GUIException const &src );

        const char* what() const noexcept;

    private:
        std::string         _errorMessage;
};

#endif