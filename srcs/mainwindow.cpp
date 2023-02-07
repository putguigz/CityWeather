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
        GeoCodeApi citySearcher(this->inputCity.toStdString());
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

void    MainWindow::setCurrentCityTitle(int index){
    QString cityNameRegionCountry;
    
    cityNameRegionCountry = QString::fromStdString(this->cities[index].getInfos());
    ui->currentCity->setText(cityNameRegionCountry);
}

void    MainWindow::resetSearchBar( void ){
    this->cities.clear();
    ui->cityCombo->clear();
    ui->searchBar->clear();
}

void    MainWindow::proceedSearchEntry(int index){
    setCurrentCityTitle(index);
    resetSearchBar();
    populateMeteoTiles();
}

void    MainWindow::getApiMeteo( City const &city ){
        OpenMeteoApi meteoSearcher(city);

        meteoSearcher.Get();
        this->meteoTiles = meteoSearcher.convertJsonResponseToMap();
}

void    MainWindow::populateMeteoTiles( void ){
        QHBoxLayout *layout = ui->tilesLayout;
        for (int i = 0; i < layout->count(); i++) {
            QLayoutItem *item = layout->itemAt(i);
            QWidget *widget = item->widget();

            QList<QLabel*> labels = widget->findChildren<QLabel*>();
            labels.at(0)->setText(QString::fromStdString("0"));
            labels.at(1)->setText(QString::fromStdString("1"));
            labels.at(2)->setText(QString::fromStdString("2"));
            labels.at(3)->setText(QString::fromStdString("3"));
            // cerr << labels.at(2)->text().toStdString() << endl;
            // cerr << labels.at(1)->text().toStdString() << endl;   
            // cerr << labels.at(0)->text().toStdString() << endl;  
        }
}

void MainWindow::getWeather(int index){
    try{
        getApiMeteo(this->cities[index]);
        proceedSearchEntry(index);
    }
    catch (FetchDataException &e) {
        cerr << e.what() << endl;
        return ;
    }
    catch (json::exception &e) {
        cerr << e.what() << endl;
        return ;
    }

    //TODO DELETE, just DEBUG
    for (auto meteo : meteoTiles)
        cerr << meteo << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

