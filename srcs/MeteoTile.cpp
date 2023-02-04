#include "MeteoTile.hpp"

// Constructors
MeteoTile::MeteoTile()
{
	_temperature = "";
	_minTemperature = "";
	_maxTemperature = "";
	_precipitation = "";
	_weatherCode = "";
}

MeteoTile::MeteoTile(const MeteoTile &copy)
{
	_temperature = copy.getTemperature();
	_minTemperature = copy.getMinTemperature();
	_maxTemperature = copy.getMaxTemperature();
	_precipitation = copy.getPrecipitation();
	_weatherCode = copy.getWeatherCode();
}

MeteoTile::MeteoTile(string _temperature, string _minTemperature, string _maxTemperature, string _precipitation, string _weatherCode)
{
	_temperature = _temperature;
	_minTemperature = _minTemperature;
	_maxTemperature = _maxTemperature;
	_precipitation = _precipitation;
	_weatherCode = _weatherCode;
}


// Destructor
MeteoTile::~MeteoTile()
{
}


// Operators
MeteoTile & MeteoTile::operator=(const MeteoTile &assign)
{
	_temperature = assign.getTemperature();
	_minTemperature = assign.getMinTemperature();
	_maxTemperature = assign.getMaxTemperature();
	_precipitation = assign.getPrecipitation();
	_weatherCode = assign.getWeatherCode();
	return *this;
}


// Getters / Setters
string MeteoTile::getTemperature() const
{
	return _temperature;
}
void MeteoTile::setTemperature(string newTemperature)
{
	_temperature = newTemperature;
}

string MeteoTile::getMinTemperature() const
{
	return _minTemperature;
}
void MeteoTile::setMinTemperature(string newMinTemperature)
{
	_minTemperature = newMinTemperature;
}

string MeteoTile::getMaxTemperature() const
{
	return _maxTemperature;
}
void MeteoTile::setMaxTemperature(string newMaxTemperature)
{
	_maxTemperature = newMaxTemperature;
}

string MeteoTile::getPrecipitation() const
{
	return _precipitation;
}
void MeteoTile::setPrecipitation(string newPrecipitation)
{
	_precipitation = newPrecipitation;
}

string MeteoTile::getWeatherCode() const
{
	return _weatherCode;
}

void	MeteoTile::setWeatherCode(string newWeatherCode){
	_weatherCode = newWeatherCode;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object)
{
	stream << "Forecast :\nTemperature: " << object.getTemperature() << "॰C\nMin: " << object.getMinTemperature() << "॰C\nMax: " << object.getMaxTemperature() << "॰C\nRain: " << object.getPrecipitation() << "mm\nWeatherCode: " << object.getWeatherCode() << std::endl;
	return stream;
}
