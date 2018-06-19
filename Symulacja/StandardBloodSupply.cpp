#include "stdafx.h"
#include "StandardBloodSupply.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "Symulacja.h"
#include "EventList.h"
#include "BloodDonationPoint.h"

int StandardBloodSupply::ID = 0;

void StandardBloodSupply::execute()
{
  //czas przydatno�ci T1=300
  //ilos� zam�wionych jednostek N=17
  //add_unit_of_blood();
  for (int i = 0; i < BloodDonationPoint::number_of_ordered_units; i++)
  {
   UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(1000);
   blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  }
  
  Event* new_event_ptr = new Event(END_OF_VALIDITY,1000);
  event_list->schedule_event(new_event_ptr);
  //standardowe zm�wnienie krwi
  
  if (blood_donation_point_ptr->first_patient_from_list)
    blood_donation_point_ptr->first_patient_from_list->wakeUp();

  blood_donation_point_ptr->standard_blood_supply_on_the_way = false;
  if (blood_donation_point_ptr->blood_level_ <= blood_donation_point_ptr->min_blood_level)
  {
    Event* new_event_ptr = new Event(BLOOD_SUPPLY);
    //std::cout << "zapalnowanie dostawy krwi -> " << std::endl;
    event_list->schedule_event(new_event_ptr);
  }
  this_event->event_type = NO_IVENT;
}

StandardBloodSupply::StandardBloodSupply(Event* event)
{
  this_event = event;
  id = ID++;
  blood_donation_point_ptr->standard_blood_supply_on_the_way = true;

  //patient_ptr = _patient_ptr;
}


StandardBloodSupply::~StandardBloodSupply()
{
  this_event = nullptr;
  
}
