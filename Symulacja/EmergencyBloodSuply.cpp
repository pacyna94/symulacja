#include "stdafx.h"
#include "EmergencyBloodSuply.h"
#include "Symulacja.h"
#include "Event.h"
#include "UnitOfBlood.h"

void EmergencyBloodSuply::execute()
{
  // awaryjne zamówenie krwi

  //zamóienie na Q=12 jednostek 
  //czas przydatnoœci T1 =300
  for (int i = 0; i < 12; i++)
  {
    UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(300);
    blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  }
  this_event->event_type = NO_IVENT;
  Event* new_event_ptr = new Event(END_OF_VALIDITY);
  event_list->schedule_event(new_event_ptr);
}

EmergencyBloodSuply::EmergencyBloodSuply(Event* event)
{
  this_event = event;
}


EmergencyBloodSuply::~EmergencyBloodSuply()
{
}
