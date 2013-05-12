#ifndef PIECE_H
#define PIECE_H
#include <stdio.h>
#include <gtkmm/drawingarea.h>
#include <cairomm/context.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/alignment.h>
#include <gtkmm/button.h>
#include <time.h>

class piece
{
  public:
    piece(int team, int iPosition, int jPosition, int radius, const Cairo::RefPtr<Cairo::Context>& cr, int slot);
   
  private:
    int team, iPosition, jPosition, neighbors, radius, slot;
};
#endif
