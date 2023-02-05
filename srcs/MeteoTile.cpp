#include "MeteoTile.hpp"

// Constructors
MeteoTile::MeteoTile() : 
	_temperature(0),
	_minTemperature(0),
	_maxTemperature(0),
	_precipitation(0),
	_weatherCode(0)
{}

MeteoTile::MeteoTile(const MeteoTile &copy)
{
	_temperature = copy.getTemperature();
	_minTemperature = copy.getMinTemperature();
	_maxTemperature = copy.getMaxTemperature();
	_precipitation = copy.getPrecipitation();
	_weatherCode = copy.getWeatherCode();
}

MeteoTile::MeteoTile(float temperature, float minTemperature, float maxTemperature, float precipitation, int weatherCode)
{
	_temperature = temperature;
	_minTemperature = minTemperature;
	_maxTemperature = maxTemperature;
	_precipitation = precipitation;
	_weatherCode = weatherCode;
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
float MeteoTile::getTemperature() const
{
	return _temperature;
}
void MeteoTile::setTemperature(float newTemperature)
{
	_temperature = newTemperature;
}

float MeteoTile::getMinTemperature() const
{
	return _minTemperature;
}
void MeteoTile::setMinTemperature(float newMinTemperature)
{
	_minTemperature = newMinTemperature;
}

float MeteoTile::getMaxTemperature() const
{
	return _maxTemperature;
}
void MeteoTile::setMaxTemperature(float newMaxTemperature)
{
	_maxTemperature = newMaxTemperature;
}

float MeteoTile::getPrecipitation() const
{
	return _precipitation;
}
void MeteoTile::setPrecipitation(float newPrecipitation)
{
	_precipitation = newPrecipitation;
}

int MeteoTile::getWeatherCode() const
{
	return _weatherCode;
}

void	MeteoTile::setWeatherCode(int newWeatherCode){
	_weatherCode = newWeatherCode;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object)
{
	stream << "Forecast :\nTemperature: " << object.getTemperature() << "॰C\nMin: " << object.getMinTemperature() << "॰C\nMax: " << object.getMaxTemperature() << "॰C\nRain: " << object.getPrecipitation() << "mm\nWeatherCode: " << object.getWeatherCode() << std::endl;
	return stream;
}
