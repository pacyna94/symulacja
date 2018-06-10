#include "stdafx.h"
#include "BloodDonor.h"
#include "Symulacja.h"
#include "Event.h"
#include "UnitOfBlood.h"
#include "EventList.h"
#include "Patient.h"
#include <iostream>
int BloodDonor::ID = 0;
void BloodDonor::execute()
{
  //przyszed³ dawca
  Event* new_event_ptr;

    new_event_ptr = new Event(BLOOD_DONOR);
    event_list->schedule_event(new_event_ptr);
    

  //czas przydatnoœci T2=500
  //dawca oddaje 1 jednostke krwi

  UnitOfBlood* unit_of_blood_ptr = new UnitOfBlood(500);
  blood_donation_point_ptr->add_unit_of_blood(unit_of_blood_ptr);
  //std::cout << "dodanie jednostki krwi od dawcy" << std::endl;
  this_event->event_type = NO_IVENT;

  new_event_ptr = new Event(END_OF_VALIDITY,500);
  event_list->schedule_event(new_event_ptr);

 if (blood_donation_point_ptr->first_patient_from_list)
 blood_donation_point_ptr->first_patient_from_list->wakeUp();
 
}

BloodDonor::BloodDonor(Event* event)
{
  this_event = event;
  id = ID++;
}


BloodDonor::~BloodDonor()
{
}
