#ifndef CITY_HPP
# define CITY_HPP

# include <iostream>
# include <string>
# include <vector>
# include <nlohmann/json.hpp>

using namespace std;

class City
{
	public:
		// Constructors
		City( void );
		City(const City &copy);
		City(string name, string locality, string country, float latitude, float longitude, string timezone);
		
		// Destructor
		virtual ~City();
		
		// Operators
		City & operator=(const City &assign);
		
		// Getters / Setters
		string getName() const;
		void setName(string name);

		string getLocality() const;
		void setLocality(string locality);

		string getCountry() const;
		void setCountry(string country);

		float getLatitude() const;
		void setLatitude(float latitude);

		float getLongitude() const;
		void setLongitude(float longitude);
		
		string getTimezone() const;
		void setTimezone(string timezone);
		
	private:
		string _name;
		string _locality;
		string _country;
		float _latitude;
		float _longitude;
		string _timezone;
};

typedef std::vector<City>::const_iterator citiesIterator;

// Stream operators
std::ostream & operator<<(std::ostream &stream, const City &object);

#endif