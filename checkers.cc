#include "checkers.h"
#include "piece.h"
#include <cairomm/context.h>
#include <time.h>
#include <glibmm/main.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

checkers::checkers() :
  from_to(1)
  
{
  //makes the program redraw every 100 milliseconds
  Glib::signal_timeout().connect(sigc::mem_fun(*this, &checkers::on_timeout), 100);

  signal_draw().connect(sigc::mem_fun(*this, &checkers::on_draw), false);
}

bool checkers::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{

  Gtk::Allocation allocation = get_allocation();
  int width = allocation.get_width();
  int height = allocation.get_height();
  
  cr->set_source_rgb(1.0, 1.0, 1.0);
  cr->paint();
  
  std::vector<piece*> team_0;  
  std::vector<piece*> team_1;

// set up the board
  /*for(int j = 0; j < 8; j++){ 
    for(int i = 0; i < 8; i++){
      if((j+i)%2 == 0){	
        cr->set_source_rgb(0, 1, 0);
        cr->rectangle(i*(width/8), j*(height/8), (i+1)*(width/8), (j+1)*(height/8)); 
        cr->fill();
	if (j <= 2){
          piece *p = new piece(0, ((2*i+1)*(width/8))/2, ((2*j+1)*(height/8))/2, height/18, cr, (j*8)+i);
          team_0.push_back(p); 
         // cr->set_source_rgb(0, 0, 0); 
         // cr->arc(((2*i+1)*(width/8))/2, ((2*j+1)*(height/8))/2, height/18, 0, 2*M_PI);
         // cr->fill();
        }     
	else if (j >= 5){
	  piece *d = new piece(1, ((2*i+1)*(width/8))/2, ((2*j+1)*(height/8))/2, height/18, cr, (j*8)+i);	   
          team_1.push_back(d);
          //cr->set_source_rgb(1, 1, 1); 
          //cr->arc(((2*i+1)*(width/8))/2, ((2*j+1)*(height/8))/2, height/18, 0, 2*M_PI);
          //cr->fill();
	} 
      } 
      else {
        cr->set_source_rgb(0, 0, 1);
        cr->rectangle(i*(width/8), j*(height/8), (i+1)*(width/8), (j+1)*(height/8)); 
        cr->fill();
      } 
    } 
  }*/
  // set up the board
  
  for(int j = 0; j < 8; j++){ 
    for(int i = 0; i < 8; i++){
      if((j+i)%2 == 0){
        cr->set_source_rgb(0, 1, 0);
        slot((j*8)+i, cr, width, height);  
        if(j <= 2){
          piece *p = new piece(0, ((2*i+1)*(width/8))/2, ((2*j+1)*(height/8))/2, height/18, cr, (j*8)+i);
          team_0.push_back(p);
        }
        else if (j >= 5){
          piece *d = new piece(1, ((2*i+1)*(width/8))/2, ((2*j+1)*(height/8))/2, height/18, cr, (j*8)+i);	   
          team_1.push_back(d);
        }
      } 
      else { 
        cr->set_source_rgb(0, 0, 1); 
        slot((j*8)+i, cr, width, height);
      }
    }
  }
  std::cout << team_0[3] << std::endl;
}

void checkers::slot(int s, const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){
  int j = s/8;
  int i = s%8;
 
  cr->rectangle((i)*(width/8), (j)*(height/8), (width/8), (height/8)); 
  cr->fill();
}
void checkers::move(double x, double y){
  
  if(from_to%2 == 1)
    std::cout << "From " << x << ", " << y << std::endl;

  if(from_to%2 == 0)
    std::cout << "To " << x << ", " << y << std::endl;
 
  from_to++;
}
bool checkers::on_timeout()
{
  // force our program to redraw the entire clock.
  Glib::RefPtr<Gdk::Window> win = get_window();
  if (win) {
    Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
    win->invalidate_rect(r, false);
  }
  return true;
}
