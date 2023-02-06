#include <iostream>
#include <list>
#include <nlohmann/json.hpp>

#include "City.hpp"
#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"
#include "Utils.hpp"

#define GEOCODE_URL     "https://geocoding-api.open-meteo.com/v1/search"
#define OPENMETEO_URL   "https://api.open-meteo.com/v1/forecast"


// for convenience
using namespace std;

//TODO DELETE WHEN APP GETS GRAPHICAL
// static string user_input(void){
//     string response;

//     cout << "Enter City Name:" << std::endl;
//     cin >> response;
//     return response;
// }

void on_app_activate()
{
  // Load the GtkBuilder file and instantiate its widgets:
  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("../gtk_ui/cityWeather.gtk4.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return;
  }

  // Get the GtkBuilder-instantiated dialog:
  pDialog = refBuilder->get_widget<Gtk::Window>("MainWindow");
  if (!pDialog)
  {
    std::cerr << "Could not get the dialog" << std::endl;
    return;
  }

  app->add_window(*pDialog);
//   pDialog->set_visible(true);
}


int main(int ac, char **av){


    // string inputCity = user_input();

    // GeoCodeApi      request(GEOCODE_URL);
    // request.addSpecificParameters(inputCity);
    // request.Get();

    // auto resultCities = request.convertJsonResponseToMap();
    // for (citiesIterator it = resultCities.cbegin(); it!= resultCities.cend(); it++){
    //     cout << *it << std::endl;
    // }

    // OpenMeteoApi    request2(OPENMETEO_URL);
    // request2.addSpecificParameters(resultCities[0]);
    // request2.Get();
    
    // auto resultMeteos = request2.convertJsonResponseToMap();
    // for (auto it = resultMeteos.cbegin(); it != resultMeteos.cend(); it++){
    //     cout << *it << std::endl;
    // }
}