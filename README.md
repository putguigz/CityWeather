# CityWeather

This project is called CityWeather and as its name suggests, it shows you the meteo for the next 7 days, including the current one. It has been coded with C++ and includes some external libraries

<p align="center">
<img src="datas_readme/city_weather.gif" width="600" centered="true" />
</p>

***

# Requirements

- Linux
- Cmake
- make
- qt5

***

# Installation

The project uses a Cmake for installation. All the needed libraries will be installed, and some of them are imported over the internet & GitHub, so it might take a little while.

## About Qt

Qt is needed to run this program. There are tree ways for installing it:

1. your package manager (`brew`, `apt-get`, `dnf`,...)
2. Qt wizard installer ([Qt Installer](https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4))
3. Downloading and building from sources ([Qt Building from Sources](https://wiki.qt.io/Building_Qt_6_from_Git))

## CMake

First, place yourself in the current directory of the project.
Then, here are a few commands to compile the project :

```bash
mkdir build
cd build
cmake ..
make -j
```

## Install Script

If you prefer, you can just launch this little script who will install the binary for you and place it in the `build` folder.  Launch that command from inside the build directory.

The command is :
``` bash
./quick_install.sh
cd build
./CityWeather
```

***

# Librairies

I used **several** libraries for this project. 

Just installing them and compiling them from the sources was a challenge, since I had never come across a Cmake.

**Conan** and  **vcpkg** were both usable options, but configuration was time consumming, and I prefered to learn simple cmakes instead.

I used : 
- __*libcpr*__ to generate simple HTTP requests. It is well documented and highly maintained on GitHub. Feel free to check : https://github.com/libcpr/cpr
- __*nlohmann/json*__ to convert GET requests into simple json objects, without parsing them manually. This project is really well documented and also highly maintained. Github: https://github.com/nlohmann/json

*** 

# API

The 2 A.P.Is used are both part of the same provider. They are free and great to use, and can be found at https://open-meteo.com/. No API key is required and the doc is plain simple. Easy.

To make my app run, I consume 2 A.P.Is : 

1. *Open-Meteo* **GeoCoding API**, that allows me to convert a city name into latitude and longitude datas.
2. *Open-Meteo* **WeatherForecast API**, that will use my previously acquired datas of latitude and longitude to obtains meteo metrics for the next 7 days.

***

# Backend

I tried to heavily implement and use OOP. 

Let's take for example the classes :
 - ApiRequester
 - GeoCodeApi
 - OpenMeteoApi

For these **classes**, I :
1. created a base class `ApiRequester` to emit simple requests
2. made both class `GeoCodeApi` and `OpenMeteoApi` **inherit** from this class
3. implement their own way of managing parameters of the URL with method `addSpecificParameters()`. 

The `Get()` method is encapsulated in `ApiRequester` class and everything is happening behind closed doors. 

I also included methods that allows to convert the stored responses in easily usable objects called `convertJsonResponseToMap`.


# Frontend

## gtkmm
It all started with gtkmm and Glade for UI...but it didn't do anything more than make me lose a full day...

 Gtkmm is just C++ bindings of C-Gtk so it is pretty hard to use in an OOP way that allows to preserve good architecture. The documentation is pretty bad, no good tutorial...

So I switched to ...🌟 Qt 🌟 !

## QT
Easy to use and learn, took me less than a day to have a graphical interface binded with my datas ! 

Thanks to their extremely rich documentation (+ coverture on stackoverflow, youtube,...) I designed the ui with QtCreator and binded the objects through pointers then populated them with data. The entire UI holds in 170 lines of code. Thanks QT !

# What I learned or improved

- Cmake
- better OOP programming
- c++17
- librairies installation from cmake
- and more...

# Licences

- libcpr/cpr : https://github.com/libcpr/cpr
- nlohmann : https://github.com/nlohmann/json
- qt : https://www.qt.io/
- icons : https://www.flaticon.com/fr/auteurs/mnauliady, 
https://www.flaticon.com/fr/auteurs/karlop19
