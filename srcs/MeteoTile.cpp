#include "MeteoTile.hpp"

//TODO add a negative value for bad or unknown weathercode
const std::unordered_map<int, string> MeteoTile::weatherInterpretationCodes = {
	{0,"Clear sky"},
	{1,"Mainly clear"},
	{2,"Partly cloudy"},
	{3,"Overcast"},
	{45,"Fog"},
	{48,"Freezing fog"},
	{51,"Light Drizzle"},
	{53,"Moderate Drizzle"},
	{55,"Heavy Drizzle"},
	{56,"Light Freezing Drizzle"},
	{57,"Dense Freezing Drizzle"},
	{61,"Slight Rain"},
	{63,"Moderate Rain"},
	{65,"Heavy Rain"},
	{66,"Light Freezing Rain"},
	{67,"Heavy Freezing Rain"},
	{71,"Slight Snow fall"},
	{73,"Moderate Snow fall"}, 
	{75,"Heavy Snow fall"},
	{77,"Snow grains"},
	{80,"Slight Rain Showers"},
	{81,"Moderate Rain Showers"},
	{82,"Violent Rain Showers"},
	{85,"Slight Snow showers"},
	{86,"Heavy Snow showers"},
	{95,"Thunderstorm"},
	{96,"Thunderstorm with slight hail"},
	{99,"Thunderstorm with heavy hail"}
};

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
