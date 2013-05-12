#ifndef CHECKERSWINDOW_H
#define CHECKERSWINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/eventbox.h>
#include <gtkmm/drawingarea.h>
#include "checkers.h"

class checkersWindow : public Gtk::Window
{
  public:
    checkersWindow();
  protected:
    // Child widgets:
    Gtk::Box m_box1;    
    Gtk::EventBox ebox; 
    Gtk::Label m_label;
    checkers checkersBoard;
    virtual bool on_eventbox_button_press(GdkEventButton* event);
};

#endif //EXAM_TIME_H
