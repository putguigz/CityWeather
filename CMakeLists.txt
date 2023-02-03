cmake_minimum_required(VERSION 3.25.2)

project(CityWeather)

include_directories("includes")

set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/ApiRequester.cpp")


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


add_executable( CityWeather ${SOURCES} )

target_link_libraries( CityWeather PRIVATE cpr::cpr)
set_property(TARGET CityWeather PROPERTY CXX_STANDARD 17)
set_property(TARGET CityWeather PROPERTY CXX_STANDARD_REQUIRED ON)
