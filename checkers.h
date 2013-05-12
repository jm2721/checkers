#ifndef CHECKERS_H
#define CHECKERS_H
#include <stdio.h>
#include <gtkmm/drawingarea.h>
#include <cairomm/context.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/alignment.h>
#include <gtkmm/button.h>
#include <time.h>

class checkers : public Gtk::DrawingArea
{
  public:
    checkers();
    
    void move(double x, double y);   
    void slot(int s, const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
  protected:
    //gets the system time
    
    //drawing function for the board
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    bool on_timeout();
 private:
    int from_to;
    void draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};
#endif //CHECKERS_H
