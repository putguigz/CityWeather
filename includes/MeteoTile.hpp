#ifndef METEOTILE_HPP
# define METEOTILE_HPP

# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

class MeteoTile
{
	public:
		// Weather codes and their interpretation in english language
		static const std::unordered_map<int, string> weatherInterpretationCodes;

		//Struct used when sending data formated data to front-end
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

		// Converts temperature with the right number of decimals + '॰C'
		string	convertTemperature( float const &temperature ) const;

		// Converts precipitation with the right number of decimals + 'mm'
		string	convertPrecipitation( float const &precipitation ) const;

		// Calculate the average temperature and stores it in _temperature
		void	calculateAverageTemperature( void );
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object);

#endif