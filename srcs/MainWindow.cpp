#include <iostream>
#include <nlohmann/json.hpp>

#include "MainWindow.hpp"
#include "./ui_mainwindow.h"

#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"
#include "Utils.hpp"
#include "GUIException.hpp"

# define CHECK_NULL(ptr) \
if (ptr == nullptr) \
throw( GUIException("UI pointer is null"));

using namespace std;
using json = nlohmann::json;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //This connects user action with backend functions
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::setUserInput);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::searchCity);
    connect(ui->cityCombo, QOverload<int>::of(&QComboBox::activated), this, [=](int index){ this->getWeather(index); });
}

// Sets User Input and cleans ComboBox if needed
void MainWindow::setUserInput(){
    this->inputCity = ui->searchBar->displayText();
    if (this->cities.size() > 0)
        this->cities.clear();
    if (ui->cityCombo->count() > 0)
        ui->cityCombo->clear();
}

void MainWindow::populateComboBox( void ){
    for (auto city : this->cities)
        ui->cityCombo->addItem(QString::fromUtf8(city.getInfos().c_str()));
    ui->cityCombo->showPopup();
}

// Calls API to get list of cities and populates ComboBox
void MainWindow::searchCity(){    
    try {
        std::string userInput = this->inputCity.trimmed().toStdString();
        
        GeoCodeApi citySearcher(userInput);
        citySearcher.Get();
        this->cities = citySearcher.convertJsonResponseToMap();
    }
    catch (FetchDataException &e) {
        logError(e.what());
        return ;
    }
    catch (json::exception &e) {
        logError(e.what());
        ui->currentCity->setText("No Results");
        return ;
    }
    populateComboBox();
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
    editMeteoTilesTiles();
}

void    MainWindow::getApiMeteo( City const &city ){
        OpenMeteoApi meteoSearcher(city);

        meteoSearcher.Get();
        this->meteoTiles = meteoSearcher.convertJsonResponseToMap();
}

// Create nice output info for tiles
string  MainWindow::aggregateMetrics( MeteoTile::Metrics const & metrics) const {
    stringstream report;

    report << "max: " << metrics.maxTemperature << "\n";
    report << "min: " << metrics.minTemperature << "\n";
    report << "rain: " << metrics.precipitation << "\n";
    return (report.str());
}

string MainWindow::searchIcon( int index ){
    try {
        string icon;

        icon = MainWindow::weatherIcons.at(index);
        return icon;
    }
    catch (std::out_of_range &e) {
        logError(e.what());
        return ("");
    }
}

/* This function populates the tiles contained in QHBoxLayout. */ 
/* This is the structure of 1 tile: */
/* QHBoxLayout                      */
/* ├─ QFrame                        */
/* │   └─ QVBoxLayout               */
/* │      ├─ QLabel                 */
/* │      ├─ QLabel                 */
/* │      ├─ QLabel                 */
/* │      ├─ QLabel                 */
/* │      └─ QLabel                 */
/* This function will throw if a pointer is NULL*/
void    MainWindow::editMeteoTilesTiles( void ){
    QHBoxLayout* layout = ui->tilesLayout;
    CHECK_NULL(layout);
    for (int i = 0; i < layout->count(); i++) {
        QLayoutItem *item = layout->itemAt(i);
        CHECK_NULL(item);

        QWidget *widget = item->widget();
        CHECK_NULL(widget);

        QList<QLabel*> labels = widget->findChildren<QLabel*>();
        MeteoTile::Metrics metrics = this->meteoTiles[i].getMetrics();

        labels.at(1)->setPixmap(QPixmap(QString::fromStdString(searchIcon(metrics.weatherCode)), "png"));
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
        logError(e.what());
        return ;
    }
    catch (GUIException & e) {
        logError(e.what());
        return ;
    }
    catch (json::exception &e) {
        logError(e.what());
        return ;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Map associating weather code to icon location
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

