#ifndef MAINWINDOW_HPP
# define MAINWINDOW_HPP


# include <QMainWindow>
# include "City.hpp"
# include "MeteoTile.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/* Class managing the displayed window */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Map associating weather code to icon location
    static const std::unordered_map<int, std::string>    weatherIcons;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow          *ui;
    QString                 inputCity;
    std::vector<City>       cities;
    std::vector<MeteoTile>  meteoTiles;

    //Transform user input to list of city
    void    searchCity(void);
    
    //Register user input with every changes
    void    setUserInput(void);
    
    //Get weather for a specific city and displays it
    void    getWeather(int idx);

    void    populateComboBox( void );
    void    setCurrentCityTitle(int index);
    void    resetSearchBar( void );
    void    proceedSearchEntry(int index);
    void    getApiMeteo( City const &city );
    void    editMeteoTilesTiles( void );
    string  searchIcon( int index );
    string  aggregateMetrics( MeteoTile::Metrics const & metrics) const;
};
#endif // MAINWINDOW_H
