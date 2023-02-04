#ifndef FETCHDATAEXCEPTION_HPP
# define FETCHDATAEXCEPTION_HPP

# include <exception>
# include <string>

class FetchDataException : public std::exception
{
public:
    FetchDataException( void );
    FetchDataException( std::string );
    virtual ~FetchDataException( void );
    FetchDataException( FetchDataException const &src );

    FetchDataException &operator=( FetchDataException const &src );

    const char* what() const noexcept;

private:
    std::string      _url;
};

#endif