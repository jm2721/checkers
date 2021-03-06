#include "piece.h"
#include <cairomm/context.h>
#include <glibmm/main.h>
#include <string.h>


piece::piece(int team, int iPosition, int jPosition, int radius, const Cairo::RefPtr<Cairo::Context>& cr, int slot) : 
  team(this->team),
  iPosition(this->iPosition), 
  jPosition(this->jPosition),
  radius(this->radius),
  slot(this->slot)
{
  cr->set_source_rgb(team, team, team);  
  cr->arc(iPosition, jPosition, radius, 0, 2*M_PI);
  cr->fill();
}
