#include "cwin.h"
#include "checkers.h" 
#include <iostream>

checkersWindow::checkersWindow() :
  m_box1(Gtk::ORIENTATION_VERTICAL, 5),
  m_label("Iama label")
{

  //adds all of the boxes/widgets to the window
  set_title("Checkers");
  set_border_width(10);
  
  add(ebox); 
  ebox.add(checkersBoard);
  checkersBoard.set_size_request(500, 500);

 //for reference:
 //m_stop_button.signal_clicked().connect(sigc::mem_fun(*this, &exam_timer::stop) ); 
  //m_box1.pack_start(checkersBoard);
  //checkersBoard.set_size_request(500, 500);
  ebox.set_events(Gdk::BUTTON_PRESS_MASK);
  ebox.signal_button_press_event().connect(sigc::mem_fun(*this, &checkersWindow::on_eventbox_button_press));
 
  show_all_children();
}

bool checkersWindow::on_eventbox_button_press(GdkEventButton* event)
{
  
  checkersBoard.move(event->x, event->y);
  return true;
}
