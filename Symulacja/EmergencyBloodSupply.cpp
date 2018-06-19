#include "stdafx.h"
#include "EmergencyBloodSupply.h"
#include "Symulacja.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "EventList.h"
#include <iostream>
#include <fstream>

int EmergencyBloodSupply::ID = 0;
void EmergencyBloodSupply::execute()
{
  // awaryjne zamówenie krwi

  //zamóienie na Q=12 jednostek 
  //czas przydatnoœci T1 =300
  //std::cout <<std::endl<< "EmergencyBloodSupply execute:" << std::endl;
  //std::cout << "utowrzenie jednostek krwi->" << std::endl;
  for (int i = 0; i < 12; i++)
  {
    UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(1000);
    blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  }
  this_event->event_type = NO_IVENT;
  //std::cout << "zaplanowanie koñca przydatnoœci krwi->" << std::endl;
  Event* new_event_ptr = new Event(END_OF_VALIDITY,1000);
  
  event_list->schedule_event(new_event_ptr);
 
  
  if(blood_donation_point_ptr->first_patient_from_list)
  blood_donation_point_ptr->first_patient_from_list->wakeUp();
  blood_donation_point_ptr->emergency_blood_supply_on_the_way = false;
  if (id % ((int)Event::numberOfEmergencyBloodSupply / 100) == 0)
    std::cout << "#";
  if (id >= Event::numberOfEmergencyBloodSupply)
  {
    EventList::endOfSymulation = true;
    if(BloodDonationPoint::first_patient_from_list)
    BloodDonationPoint::remove_first_patient_from_queue();
  }
}

EmergencyBloodSupply::EmergencyBloodSupply(Event* event)
{
  this_event = event;
  id = ID++;
  blood_donation_point_ptr->emergency_blood_supply_on_the_way = true;
/*
  if (EventList::end_of_transition_phase_flag)
  {
  supplyStream << event_list->symulation_time << "  |  " << EventList::events_counter << "  |  " <<
   number_of_emergency_blood_supply << "|" << ((double)number_of_emergency_blood_supply) / EventList::events_counter << std::endl;
  supplyStream.flush();
  }*/
}


EmergencyBloodSupply::~EmergencyBloodSupply()
{
  this_event = nullptr;
}
