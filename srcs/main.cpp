#include <iostream>
#include <list>
#include <nlohmann/json.hpp>

#include "City.hpp"
#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"
#include "Utils.hpp"

// for convenience
using namespace std;

#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
