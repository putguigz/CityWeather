#ifndef METEOTILE_HPP
# define METEOTILE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <unordered_map>
# include <cmath>
using namespace std;

class MeteoTile
{
	public:
		static const std::unordered_map<int, string> weatherInterpretationCodes;

		struct	Metrics{
			string	temperature;
			string	minTemperature;
			string	maxTemperature;
			string	precipitation;
			int		weatherCode;
			string	weatherReport;
		};

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

		Metrics	getMetrics() const;

	private:
		float	_temperature;
		float	_minTemperature;
		float	_maxTemperature;
		float	_precipitation;
		int		_weatherCode;

		string	convertTemperature( float const &temperature ) const;
		string	convertPrecipitation( float const &precipitation ) const;
		void	calculateAverageTemperature( void );
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object);

#endif