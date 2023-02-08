#include <iostream>
#include <list>
#include <nlohmann/json.hpp>
#include <QApplication>

#include "MainWindow.hpp"



int main(int ac, char *av[])
{
    QApplication cityWeather(ac, av);

    MainWindow window;
    window.show();
    return cityWeather.exec();
}
