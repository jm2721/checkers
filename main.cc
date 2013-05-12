#include "checkers.h"
#include "cwin.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  //creates the window
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "checkers.game");
  
  //creates an exam_timer object to create the timer and the widgets
  checkersWindow w;

  //runs the program
  return app->run(w);
}
