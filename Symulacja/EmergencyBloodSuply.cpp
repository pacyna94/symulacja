#include "stdafx.h"
#include "EmergencyBloodSuply.h"
#include "Symulacja.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "EventList.h"
#include <iostream>

void EmergencyBloodSuply::execute()
{
  // awaryjne zamówenie krwi

  //zamóienie na Q=12 jednostek 
  //czas przydatnoœci T1 =300
  std::cout <<std::endl<< "EmergencyBloodSupply execute:" << std::endl;
  std::cout << "utowrzenie jednostek krwi->" << std::endl;
  for (int i = 0; i < 12; i++)
  {
    UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(300);
    blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  }
  this_event->event_type = NO_IVENT;
  std::cout << "zaplanowanie koñca przydatnoœci krwi->" << std::endl;
  Event* new_event_ptr = new Event(END_OF_VALIDITY,300);
  
  event_list->schedule_event(new_event_ptr);
 
  
  if(blood_donation_point_ptr->first_patient_from_list)
  blood_donation_point_ptr->first_patient_from_list->wakeUp();
  
}

EmergencyBloodSuply::EmergencyBloodSuply(Event* event)
{
  this_event = event;
 
}


EmergencyBloodSuply::~EmergencyBloodSuply()
{
  this_event = nullptr;
}
