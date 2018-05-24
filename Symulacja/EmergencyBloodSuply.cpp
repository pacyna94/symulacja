#include "stdafx.h"
#include "EmergencyBloodSuply.h"
#include "Symulacja.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "EventList.h"

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
  Event* new_event_ptr = new Event(END_OF_VALIDITY,300);
  event_list->schedule_event(new_event_ptr);
  patient_ptr->wakeUp();
  //patient_ptr->execute();
  
}

EmergencyBloodSuply::EmergencyBloodSuply(Event* event, Patient* _patient_ptr)
{
  this_event = event;
  patient_ptr = _patient_ptr;
}


EmergencyBloodSuply::~EmergencyBloodSuply()
{
}
