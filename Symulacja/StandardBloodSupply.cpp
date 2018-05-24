#include "stdafx.h"
#include "StandardBloodSupply.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "Symulacja.h"
#include "EventList.h"


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
  Event* new_event_ptr = new Event(END_OF_VALIDITY,300);
  event_list->schedule_event(new_event_ptr);
  //standardowe zmównienie krwi
  patient_ptr->wakeUp();
}

StandardBloodSupply::StandardBloodSupply(Event* event, Patient* _patient_ptr)
{
  this_event = event;
  patient_ptr = _patient_ptr;
}


StandardBloodSupply::~StandardBloodSupply()
{
}
