#include "City.hpp"

// Constructors
City::City() : _latitude(0), _longitude(0){
}

City::City(const City &copy){
	*this = copy;
}

City::City(
	string name,
	string locality,
	string country,
	float latitude,
	float longitude,
	string timezone)
{
	_name = name;
	_locality = locality;
	_country = country;
	_latitude = latitude;
	_longitude = longitude;
	_timezone = timezone;
}


// Destructor
City::~City()
{
}


// Operators
City & City::operator=(const City &assign)
{
	if (this != &assign)
	{	
		_name = assign.getName();
		_locality = assign.getLocality();
		_country = assign.getCountry();
		_latitude = assign.getLatitude();
		_longitude = assign.getLongitude();
		_timezone = assign.getTimezone();
	}
	return *this;
}


// Getters / Setters
string City::getName() const
{
	return _name;
}
void City::setName(string name)
{
	_name = name;
}

string City::getLocality() const
{
	return _locality;
}
void City::setLocality(string locality)
{
	_locality = locality;
}

string City::getCountry() const
{
	return _country;
}
void City::setCountry(string country)
{
	_country = country;
}

float City::getLatitude() const
{
	return _latitude;
}
void City::setLatitude(float latitude)
{
	_latitude = latitude;
}

float City::getLongitude() const
{
	return _longitude;
}
void City::setLongitude(float longitude)
{
	_longitude = longitude;
}

string City::getTimezone() const
{
	return _timezone;
}
void City::setTimezone(string timezone)
{
	_timezone = timezone;
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const City &object)
{
	stream << "City of " << object.getName() << ", " << object.getLocality() << ", " << object.getCountry() << "" << std::endl;
	return stream;
}

