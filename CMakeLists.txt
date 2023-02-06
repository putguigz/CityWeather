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
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/GUI.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/GUIException.cpp"
    )

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)
    
link_directories( ${GTKMM_LIBRARY_DIRS} )
    
include_directories( ${GTKMM_INCLUDE_DIRS} )

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

add_executable( ${PROJECT_NAME} ${SOURCES} )

target_link_libraries( ${PROJECT_NAME} PRIVATE cpr::cpr)
target_link_libraries( ${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries( ${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES} )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
target_compile_options( ${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)

