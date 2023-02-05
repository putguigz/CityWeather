#ifndef FETCHDATAEXCEPTION_HPP
# define FETCHDATAEXCEPTION_HPP

# include <exception>
# include <cpr/cpr.h>
# include <string>
# include <sstream>

class FetchDataException : public std::exception
{
    public:
        FetchDataException( void );
        FetchDataException( cpr::Response );
        virtual ~FetchDataException( void );
        FetchDataException( FetchDataException const &src );

        FetchDataException &operator=( FetchDataException const &src );

        const char* what() const noexcept;

    private:
        cpr::Response       _response;
        std::string         _errorMessage;

};

#endif