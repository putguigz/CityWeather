#ifndef METEOTILE_HPP
# define METEOTILE_HPP

# include <iostream>
# include <string>

using namespace std;

class MeteoTile
{
	public:
		// Constructors
		MeteoTile();
		MeteoTile(const MeteoTile &copy);
		MeteoTile(string temperature, string minTemperature, string maxTemperature, string precipitation, string weatherCode);
		
		// Destructor
		~MeteoTile();
		
		// Operators
		MeteoTile & operator=(const MeteoTile &assign);
		
		// Getters / Setters
		string	getTemperature() const;
		void	setTemperature(string temperature);

		string	getMinTemperature() const;
		void	setMinTemperature(string minTemperature);

		string	getMaxTemperature() const;
		void	setMaxTemperature(string maxTemperature);

		string	getPrecipitation() const;
		void	setPrecipitation(string precipitation);

		string	getWeatherCode() const;
		void	setWeatherCode(string weatherCode);

	private:
		string _temperature;
		string _minTemperature;
		string _maxTemperature;
		string _precipitation;
		string _weatherCode;

		void	dailyAverageTemperature(void);
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object);

#endif