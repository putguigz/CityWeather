#include <iostream>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::registerText);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::searchCity);
    //Qoverload resolve typing issue as described here: https://forum.qt.io/topic/117072/qcombobox-signal-and-slot-connection-problems/3?lang=en-US
    connect(ui->cityCombo, QOverload<int>::of(&QComboBox::activated), this, [=](int index){ this->getWeather(index); });
}

void MainWindow::searchCity(){
    cerr << this->inputCity.toStdString() << endl;
    
    //TODO : Add a try catch block
    try {
        GeoCodeApi citySearcher(GEOCODE_URL);
        citySearcher.addSpecificParameters(this->inputCity.toStdString());
        citySearcher.Get();
        this->cities = citySearcher.convertJsonResponseToMap();
    }
    catch (FetchDataException &e) {
        cerr << e.what() << endl;
        return ;
    }
    catch (json::exception &e) {
        cerr << e.what() << endl;
        return ;
    }

    for (auto city : this->cities)
        ui->cityCombo->addItem(QString::fromStdString(city.getInfos()));
    ui->cityCombo->showPopup();
}

void MainWindow::registerText(){
    this->inputCity = ui->searchBar->displayText();
    if (this->cities.size() > 0)
        this->cities.clear();
    if (ui->cityCombo->count() > 0)
        ui->cityCombo->clear();
}

void MainWindow::getWeather(int idx){
    try{
        OpenMeteoApi meteoSearcher(OPENMETEO_URL);
        meteoSearcher.addSpecificParameters(this->cities[idx]);
        meteoSearcher.Get();
        this->meteoTiles = meteoSearcher.convertJsonResponseToMap();
        ui->currentCity->setText(QString::fromStdString(this->cities[idx].getInfos()));
        this->cities.clear();
        ui->cityCombo->clear();
        ui->searchBar->clear();
    }
    catch (FetchDataException &e) {
        cerr << e.what() << endl;
        return ;
    }
    catch (json::exception &e) {
        cerr << e.what() << endl;
        return ;
    }
    
    for (auto meteo : meteoTiles){
        cerr << meteo << endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

