#include <sstream>
#include <cmath>

#include "MeteoTile.hpp"
#include "Utils.hpp"

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
	calculateAverageTemperature();
}

float MeteoTile::getMaxTemperature() const
{
	return _maxTemperature;
}
void MeteoTile::setMaxTemperature(float newMaxTemperature)
{
	_maxTemperature = newMaxTemperature;
	calculateAverageTemperature();
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

void	MeteoTile::calculateAverageTemperature(){
	_temperature = (_minTemperature + _maxTemperature) / 2;
}

string MeteoTile::convertTemperature( float const &temperature ) const {
	return (to_string(lroundf(temperature)) + "॰C");
}

string MeteoTile::convertPrecipitation( float const &precipitation ) const {
	stringstream ss;

	ss << precipitation << " mm";
	return (ss.str());
}

MeteoTile::Metrics	MeteoTile::getMetrics( void ) const{
	struct Metrics	metrics;

	metrics.temperature = convertTemperature(_temperature);
	metrics.minTemperature = convertTemperature(_minTemperature);
	metrics.maxTemperature = convertTemperature(_maxTemperature);
	metrics.precipitation = convertPrecipitation(_precipitation);
	metrics.weatherCode = _weatherCode;
	try {
		metrics.weatherReport = MeteoTile::weatherInterpretationCodes.at(_weatherCode);
	}
	catch (std::out_of_range &e) {
		logError(e.what());
		metrics.weatherReport = -1;
	}
	return metrics;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object)
{
	stream << "Forecast :\nTemperature: " << object.getTemperature() \
	<< "॰C\nMin: " << object.getMinTemperature()\
	<< "॰C\nMax: " << object.getMaxTemperature()\
	<< "॰C\nRain: " << object.getPrecipitation()\
	<< "mm\nWeatherCode: " << MeteoTile::weatherInterpretationCodes.at(object.getWeatherCode())\
	<< std::endl;
	return stream;
}

//TODO add a negative value for bad or unknown weathercode
const std::unordered_map<int, string> MeteoTile::weatherInterpretationCodes = {
	{0,"Clear sky"},
	{1,"Mainly clear"},
	{2,"Partly cloudy"},
	{3,"Overcast"},
	{45,"Fog"},
	{48,"Freezing fog"},
	{51,"Light drizzle"},
	{53,"Moderate drizzle"},
	{55,"Heavy drizzle"},
	{56,"Light freezing drizzle"},
	{57,"Dense freezing drizzle"},
	{61,"Slight rain"},
	{63,"Moderate rain"},
	{65,"Heavy rain"},
	{66,"Light freezing rain"},
	{67,"Heavy freezing rain"},
	{71,"Slight snow fall"},
	{73,"Moderate snow fall"}, 
	{75,"Heavy snow fall"},
	{77,"Snow grains"},
	{80,"Slight rain showers"},
	{81,"Moderate rain showers"},
	{82,"Violent rain showers"},
	{85,"Slight snow showers"},
	{86,"Heavy snow showers"},
	{95,"Thunderstorm"},
	{96,"Thunderstorm with slight hail"},
	{99,"Thunderstorm with heavy hail"}
};