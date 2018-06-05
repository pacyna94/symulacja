#include "stdafx.h"
#include "EndOfValidity.h"
//#include "Symulacja.h"




void EndOfValidity::execute()
{
  //usnuñ wszystkie przeteminowane jednostki krwi
  std::cout << "event list/////////////////////////////////////////////" << std::endl;
  event_list->show_list();
  blood_donation_point_ptr->remove_expired_blood_units();
  std::cout << "Usuwanie przeterminowanych jednostek krwi->" << std::endl;
  std::cout << "event list" << std::endl;
  event_list->show_list();
  std::cout << "//////////////////////////////////////////////////" << std::endl;

  if (blood_donation_point_ptr->blood_level_ <= blood_donation_point_ptr->min_blood_level)
  {
    Event* new_event_ptr = new Event(BLOOD_SUPPLY);
    // std::cout << "zapalnowanie dostawy krwi -> " << std::endl;
    event_list->schedule_event(new_event_ptr);
  }
  
  this_event->event_type = NO_IVENT;
}

EndOfValidity::EndOfValidity(Event * _event_ptr)
{
  this_event = _event_ptr;

}



EndOfValidity::~EndOfValidity()
{
}
