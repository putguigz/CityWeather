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
    // QHBoxLayout *layout = ui->tilesLayout;
        QList<QFrame*> layout = ui->tilesLayout->findChildren<QFrame*>();
        QList<QFrame*>::iterator it1;
        for (it1 = layout.begin(); it1 != layout.end(); it1++) {
            // QWidget *widget = (*it1)->widget();

            //find all the labels in the frame
            QList<QLabel*> labels = (*it1)->findChildren<QLabel*>();
            QList<QLabel*>::iterator it;
            for (it = labels.begin(); it != labels.end(); ++it) {
                cerr << (*it)->text().toStdString() << endl;
            }
            // labels.at(2)->setText(QString::fromStdString("Prout1"));
            // labels.at(1)->setText(QString::fromStdString("Prout2"));
            // labels.at(0)->setText(QString::fromStdString("Prout3"));
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
    for (auto meteo : meteoTiles)
        cerr << meteo << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

