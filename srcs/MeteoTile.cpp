#include "MeteoTile.hpp"

// Constructors
MeteoTile::MeteoTile()
{
	__temperature = "";
	__minTemperature = "";
	__maxTemperature = "";
	__precipitation = "";
	__weatherCode = "";
}

MeteoTile::MeteoTile(const MeteoTile &copy)
{
	__temperature = copy.get_temperature();
	__minTemperature = copy.get_minTemperature();
	__maxTemperature = copy.get_maxTemperature();
	__precipitation = copy.get_precipitation();
	__weatherCode = copy.get_weatherCode();
}

MeteoTile::MeteoTile(string _temperature, string _minTemperature, string _maxTemperature, string _precipitation, string _weatherCode)
{
	__temperature = _temperature;
	__minTemperature = _minTemperature;
	__maxTemperature = _maxTemperature;
	__precipitation = _precipitation;
	__weatherCode = _weatherCode;
}


// Destructor
MeteoTile::~MeteoTile()
{
}


// Operators
MeteoTile & MeteoTile::operator=(const MeteoTile &assign)
{
	__temperature = assign.get_temperature();
	__minTemperature = assign.get_minTemperature();
	__maxTemperature = assign.get_maxTemperature();
	__precipitation = assign.get_precipitation();
	__weatherCode = assign.get_weatherCode();
	return *this;
}


// Getters / Setters
string MeteoTile::get_temperature() const
{
	return __temperature;
}
void MeteoTile::set_temperature(string _temperature)
{
	__temperature = _temperature;
}

string MeteoTile::get_minTemperature() const
{
	return __minTemperature;
}
void MeteoTile::set_minTemperature(string _minTemperature)
{
	__minTemperature = _minTemperature;
}

string MeteoTile::get_maxTemperature() const
{
	return __maxTemperature;
}
void MeteoTile::set_maxTemperature(string _maxTemperature)
{
	__maxTemperature = _maxTemperature;
}

string MeteoTile::get_precipitation() const
{
	return __precipitation;
}
void MeteoTile::set_precipitation(string _precipitation)
{
	__precipitation = _precipitation;
}

string MeteoTile::get_weatherCode() const
{
	return __weatherCode;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object)
{
	stream << "Forecast :\nTemperature:" << object.get_temperature() << "\nMin:" << object.get_minTemperature() << "\nMax:" << object.get_maxTemperature() << "\nRain:" << object.get_precipitation() << "\nWeatherCode:" << object.get_weatherCode() << "" << std::endl;
	return stream;
}
