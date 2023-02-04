#ifndef METEOTILE_HPP
# define METEOTILE_HPP

# include <iostream>
# include <string>

class MeteoTile
{
	public:
		// Constructors
		MeteoTile();
		MeteoTile(const MeteoTile &copy);
		MeteoTile(string _temperature, string _minTemperature, string _maxTemperature, string _precipitation, string _weatherCode);
		
		// Destructor
		~MeteoTile();
		
		// Operators
		MeteoTile & operator=(const MeteoTile &assign);
		
		// Getters / Setters
		string get_temperature() const;
		void set_temperature(string _temperature);
		string get_minTemperature() const;
		void set_minTemperature(string _minTemperature);
		string get_maxTemperature() const;
		void set_maxTemperature(string _maxTemperature);
		string get_precipitation() const;
		void set_precipitation(string _precipitation);
		string get_weatherCode() const;
		
	private:
		string __temperature;
		string __minTemperature;
		string __maxTemperature;
		string __precipitation;
		string __weatherCode;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const MeteoTile &object);

#endif