#include "GUI.hpp"

// Constructors
GUI::GUI()
{
	_mainWindow = nullptr;
	_pathToGlade = "";
	_app = Gtk::Application::create("cityWeather");
}

GUI::GUI(const GUI &copy)
{
	*this = copy;
}

GUI::GUI(string pathToGlade)
{
	_pathToGlade = pathToGlade;
}


// Destructor
GUI::~GUI()
{
}


// Operators
GUI & GUI::operator=(const GUI &assign)
{
	if (this != &assign)
	{
		_app = assign.getApp();
		//TODO ENSURE DEEP COPY
		_mainWindow = assign.getMainWindow();
		_pathToGlade = assign.getPathToGlade();
	}
	return *this;
}


// Getters / Setters
Gtk::Window* GUI::getMainWindow() const
{
	return _mainWindow;
}
Glib::RefPtr<Gtk::Application> GUI::getApp() const
{
	return _app;
}
string GUI::getPathToGlade() const
{
	return _pathToGlade;
}

void	GUI::init(void){
	if (string.empty)
		throw ();
	_app->signal_activate().connect([] () { this->on_app_activate(); });
}

int		GUI::run(int ac, char **av){
	return _app->run(ac, av);
}

void on_app_activate(void){

}
