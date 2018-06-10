#include "stdafx.h"
#include "StandardBloodSupply.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "Symulacja.h"
#include "EventList.h"

int StandardBloodSupply::ID = 0;

void StandardBloodSupply::execute()
{
  //czas przydatnoœci T1=300
  //ilosæ zamówionych jednostek N=17
  //add_unit_of_blood();
  for (int i = 0; i < 30; i++)
  {
   UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(300);
   blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  }
  
  Event* new_event_ptr = new Event(END_OF_VALIDITY,300);
  event_list->schedule_event(new_event_ptr);
  //standardowe zmównienie krwi
  if (blood_donation_point_ptr->first_patient_from_list)
    blood_donation_point_ptr->first_patient_from_list->wakeUp();

  blood_donation_point_ptr->standard_blood_supply_on_the_way = false;
  this_event->event_type = NO_IVENT;
}

StandardBloodSupply::StandardBloodSupply(Event* event)
{
  this_event = event;
  id = ID++;
  blood_donation_point_ptr->standard_blood_supply_on_the_way = true;
//  supplyStream << event_list->symulation_time << "  |  " << number_of_standard_blood_supply << "  |  " << number_of_emergency_blood_supply << std::endl;
  //patient_ptr = _patient_ptr;
}


StandardBloodSupply::~StandardBloodSupply()
{
  this_event = nullptr;
  
}
