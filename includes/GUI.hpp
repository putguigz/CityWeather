#ifndef GUI_HPP
# define GUI_HPP

# include <iostream>
# include <string>
#include <gtkmm.h>

class GUI
{
	public:
		// Constructors
		GUI();
		GUI(const GUI &copy);
		GUI(string pathToGlade);
		
		// Destructor
		virtual ~GUI();
		
		// Operators
		GUI & operator=(const GUI &assign);
		
		// Getters / Setters
		Gtk::Window*					getMainWindow() const;
		Glib::RefPtr<Gtk::Application>	getApp() const;
		string							getPathToGlade() const;

		void	init(void);
		int		run(int ac, char **av);		
	
	private:
		string 							_pathToGlade;
		Gtk::Window*					_mainWindow;
		Glib::RefPtr<Gtk::Application>	_app;

		void on_app_activate(void);
		
};

#endif