#include "stdafx.h"
#include "StandardBloodSupply.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "Symulacja.h"


void StandardBloodSupply::execute()
{
  //czas przydatnoœci T1=300
  //ilosæ zamówionych jednostek N=17
  //add_unit_of_blood();
  for (int i = 0; i < 17; i++)
  {
   UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(300);
   blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  }
  this_event->event_type = NO_IVENT;
  Event* new_event_ptr = new Event(END_OF_VALIDITY);
  event_list->schedule_event(new_event_ptr);
  //standardowe zmównienie krwi
}

StandardBloodSupply::StandardBloodSupply(Event* event)
{
  this_event = event;
}


StandardBloodSupply::~StandardBloodSupply()
{
}
