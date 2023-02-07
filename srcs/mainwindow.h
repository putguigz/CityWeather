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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void    searchCity(void);
    void    registerText(void);
    void    getWeather(int idx);

    QString                 inputCity;
    std::vector<City>       cities;
    std::vector<MeteoTile>  meteoTiles;
};
#endif // MAINWINDOW_H
