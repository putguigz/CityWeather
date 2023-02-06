#include <iostream>
#include <list>
#include <nlohmann/json.hpp>

#include "City.hpp"
#include "GeoCodeApi.hpp"
#include "OpenMeteoApi.hpp"
#include "FetchDataException.hpp"
#include "Utils.hpp"
#include "gtkmm.h"

#define GEOCODE_URL     "https://geocoding-api.open-meteo.com/v1/search"
#define OPENMETEO_URL   "https://api.open-meteo.com/v1/forecast"


// for convenience
using namespace std;

namespace
{
Gtk::Window* pDialog = nullptr;
Glib::RefPtr<Gtk::Application> app;

void on_text_typed(Gtk::SearchEntry *ptr)
{
  std::string city = ptr->get_text();

  if (city.empty())
    return;
  GeoCodeApi citySearcher(GEOCODE_URL);


  citySearcher.addSpecificParameters(city);
  citySearcher.Get();
  std::vector<City> cities = citySearcher.convertJsonResponseToMap();

  for (auto city : cities)
  {
    std::cerr << city << endl;
  }
}


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

  // Get the GtkBuilder-instantiated button, and connect a signal handler:
  auto pSearchBar = refBuilder->get_widget<Gtk::SearchEntry>("SearchBar");
  if (pSearchBar)
  {
    pSearchBar->signal_changed().connect([pSearchBar] () { on_text_typed(pSearchBar); });
  }
  // It's not possible to delete widgets after app->run() has returned.
  // Delete the dialog with its child widgets before app->run() returns.
  pDialog->signal_hide().connect([] () { delete pDialog; });


  app->add_window(*pDialog);
  pDialog->set_visible(true);
}
} // anonymous namespace

int main(int argc, char** argv)
{
  app = Gtk::Application::create("CityWeather");

  app->signal_activate().connect([] () { on_app_activate(); });

  return app->run(argc, argv);
}

