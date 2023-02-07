#ifndef METEOTILE_HPP
# define METEOTILE_HPP

# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

class MeteoTile
{
	public:
		static const std::unordered_map<int, string> weatherInterpretationCodes;

		// Constructors
		MeteoTile();
		MeteoTile(const MeteoTile &copy);
		MeteoTile(float temperature, float minTemperature, float maxTemperature, float precipitation, int weatherCode);
		
		// Destructor
		~MeteoTile();
		
		// Operators
		MeteoTile & operator=(const MeteoTile &assign);
		
		// Getters / Setters
		float	getTemperature() const;
		void	setTemperature(float temperature);

		float	getMinTemperature() const;
		void	setMinTemperature(float minTemperature);

		float	getMaxTemperature() const;
		void	setMaxTemperature(float maxTemperature);

		float	getPrecipitation() const;
		void	setPrecipitation(float precipitation);

		int		getWeatherCode() const;
		void	setWeatherCode(int weatherCode);

	private:
		float	_temperature;
		float	_minTemperature;
		float	_maxTemperature;
		float	_precipitation;
		int		_weatherCode;

		void	calculateAverageTemperature();
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object);

#endif