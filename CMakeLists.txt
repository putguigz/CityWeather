cmake_minimum_required(VERSION 3.25.2)

project(CityWeather)

include_directories("includes")

set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/ApiRequester.cpp")

    
add_executable( CityWeather ${SOURCES} )

set_property(TARGET CityWeather PROPERTY CXX_STANDARD 17)
set_property(TARGET CityWeather PROPERTY CXX_STANDARD_REQUIRED ON)
