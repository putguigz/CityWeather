#ifndef MAINWINDOW_H
# define MAINWINDOW_H


# include <QMainWindow>
# include "City.hpp"
# include "MeteoTile.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const std::unordered_map<int, std::string>    weatherIcons;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void    searchCity(void);
    void    registerText(void);
    void    getWeather(int idx);
    void    setCurrentCityTitle(int index);
    void    resetSearchBar( void );
    void    proceedSearchEntry(int index);
    void    getApiMeteo( City const &city );
    void    populateMeteoTiles( void );
    string  aggregateReport( MeteoTile::Metrics const & metrics) const;
    

    QString                 inputCity;
    std::vector<City>       cities;
    std::vector<MeteoTile>  meteoTiles;
};
#endif // MAINWINDOW_H
