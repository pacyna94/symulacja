#include "stdafx.h"
#include "EndOfValidity.h"
#include "Symulacja.h"
//#include <fstream>
//extern std::fstream stream;

int EndOfValidity::expiried_units_counter = 0;
void EndOfValidity::execute()
{
  //usnuñ wszystkie przeteminowane jednostki krwi
  int x = blood_donation_point_ptr->blood_level_;
  if(blood_donation_point_ptr->blood_level_)
  blood_donation_point_ptr->remove_expired_blood_units();
  //std::cout << "Usuwanie przeterminowanych jednostek krwi->" << std::endl;
 

  if ((!blood_donation_point_ptr->standard_blood_supply_on_the_way)&&(blood_donation_point_ptr->blood_level_ <= blood_donation_point_ptr->min_blood_level))
  {
    Event* new_event_ptr = new Event(BLOOD_SUPPLY);
    //std::cout << "zapalnowanie dostawy krwi -> " << std::endl;
    event_list->schedule_event(new_event_ptr);
  }
  
  this_event->event_type = NO_IVENT;
  expiried_units_counter += x - blood_donation_point_ptr->blood_level_;
    bloodStream << Proces::event_list->symulation_time<<BloodDonationPoint::blood_counter<<" "
    <<expiried_units_counter<< ((double)expiried_units_counter)/BloodDonationPoint::blood_counter<<std::endl;
}

EndOfValidity::EndOfValidity(Event * _event_ptr)
{
  this_event = _event_ptr;

}



EndOfValidity::~EndOfValidity()
{
}
