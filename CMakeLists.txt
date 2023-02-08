cmake_minimum_required(VERSION 3.25.2)

project(CityWeather)

include_directories("includes")

# Needed for Qt5 (.ui compilation etc...)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Don't Use Glob, says the CMake documentation
set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/ApiRequester.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/GeoCodeApi.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/OpenMeteoApi.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/FetchDataException.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/City.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/MeteoTile.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/Utils.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/GUIException.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/MainWindow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/srcs/mainwindow.ui"
    )


find_package(Qt5 COMPONENTS Widgets REQUIRED)


include(FetchContent)

# This installs cpr::cpr
FetchContent_Declare(cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400
)
FetchContent_MakeAvailable(cpr)

# This installs nlohmann::json
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
    GIT_TAG v3.11.2    
)
FetchContent_MakeAvailable(json)

# This creates the executable
add_executable( ${PROJECT_NAME} ${SOURCES} )

# This links the libraries
target_link_libraries( ${PROJECT_NAME} PRIVATE cpr::cpr)
target_link_libraries( ${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries( ${PROJECT_NAME} PRIVATE Qt5::Widgets)

# This sets the C++ appropriate flags and version
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)

