cmake_minimum_required(VERSION 3.25.2)

project(CityWeather)

include_directories("includes")

set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/ApiRequester.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/GeoCodeApi.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/OpenMeteoApi.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/FetchDataException.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/City.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/MeteoTile.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/Utils.cpp"
    )

include(FetchContent)

FetchContent_Declare(cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400
) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
    GIT_TAG v3.11.2    
)
FetchContent_MakeAvailable(json)

add_executable( CityWeather ${SOURCES} )

target_compile_options( CityWeather PRIVATE -Wall -Wextra -Werror)
target_link_libraries( CityWeather PRIVATE cpr::cpr)
target_link_libraries( CityWeather PRIVATE nlohmann_json::nlohmann_json)

set_property(TARGET CityWeather PROPERTY CXX_STANDARD 11)
set_property(TARGET CityWeather PROPERTY CXX_STANDARD_REQUIRED ON)

