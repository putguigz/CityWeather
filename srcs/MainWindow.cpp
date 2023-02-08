#include <iostream>

#include "MainWindow.hpp"
#include "./ui_mainwindow.h"

#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


using namespace std;

const std::unordered_map<int, std::string> MainWindow::weatherIcons = {
	{0,"../weather_icons/sunny.png"},
	{1,"../weather_icons/partly_cloudy.png"},
	{2,"../weather_icons/cloudy.png"},
	{3,"../weather_icons/many_clouds.png"},
	{45,"../weather_icons/fog.png"},
	{48,"../weather_icons/fog.png"},
	{51,"../weather_icons/heavy_rain.png"},
	{53,"../weather_icons/heavy_rain.png"},
	{55,"../weather_icons/heavy_rain.png"},
	{56,"../weather_icons/heavy_rain.png"},
	{57,"../weather_icons/heavy_rain.png"},
	{61,"../weather_icons/rain.png"},
	{63,"../weather_icons/rain.png"},
	{65,"../weather_icons/rain.png"},
	{66,"../weather_icons/rain.png"},
	{67,"../weather_icons/rain.png"},
	{71,"../weather_icons/snow.png"},
	{73,"../weather_icons/snow.png"}, 
	{75,"../weather_icons/snow.png"},
	{77,"../weather_icons/snow.png"},
	{80,"../weather_icons/rain.png"},
	{81,"../weather_icons/rain.png"},
	{82,"../weather_icons/rain.png"},
	{85,"../weather_icons/rain.png"},
	{86,"../weather_icons/snow.png"},
	{95,"../weather_icons/thunder.png"},
	{96,"../weather_icons/thunder.png"},
	{99,"../weather_icons/thunder.png"}
};

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
    //TODO : Add a try catch block
    try {
        std::string userInput = this->inputCity.trimmed().toStdString();
        
        GeoCodeApi citySearcher(userInput);
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
        ui->cityCombo->addItem(QString::fromUtf8(city.getInfos().c_str()));
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
    
    cityNameRegionCountry = QString::fromUtf8(this->cities[index].getInfos().c_str());
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

string  MainWindow::aggregateMetrics( MeteoTile::Metrics const & metrics) const {
    stringstream report;

    cerr << "metrics.precipitation: " << metrics.precipitation << endl;

    report << "max: " << metrics.maxTemperature << "\n";
    report << "min: " << metrics.minTemperature << "\n";
    report << "rain: " << metrics.precipitation << "\n";
    return (report.str());
}

void    MainWindow::populateMeteoTiles( void ){
        //This gives a array of layout, there are 7 layouts in the array
        QHBoxLayout *layout = ui->tilesLayout;
        for (int i = 0; i < layout->count(); i++) {
            //this returns the LayoutItem at the index i
            QLayoutItem *item = layout->itemAt(i);
            //this return the widget of the LayoutItem
            QWidget *widget = item->widget();

            QList<QLabel*> labels = widget->findChildren<QLabel*>();

            MeteoTile::Metrics metrics = this->meteoTiles[i].getMetrics();

            labels.at(1)->setPixmap(QPixmap(QString::fromStdString(MainWindow::weatherIcons.at(metrics.weatherCode)), "png"));
            labels.at(2)->setText(QString::fromStdString(metrics.temperature));
            labels.at(3)->setText(QString::fromStdString(aggregateMetrics(metrics)));
            labels.at(4)->setText(QString::fromStdString(metrics.weatherReport));
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

