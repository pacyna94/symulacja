#include "stdafx.h"
#include "Patient.h"
#include <cstdlib>
#include <iostream>
#include "Event.h"
#include "BloodDonationPoint.h"
#include "Symulacja.h"
//EventList* event_list;




void Patient::showPatient()
{
  if (next_patient_)
  {
    std::cout << needed_blood_units_<<" ";
    next_patient_->showPatient();
  }
  else
  {
    std::cout << needed_blood_units_ << " ";
  }

}

void Patient::execute(Event* this_event)
{
  //event_ptr_=this_event
  std::cout<<std::endl<<std::endl << "patient execute"<< std::endl<<std::endl;
  while (event_ptr_->activate)
  {
    switch (event_ptr_->phase)
    {
      case 0:
      {

        Event* new_event_ptr = new Event(PATIENT,(Proces*)blood_donation_point_ptr);
        event_list->schedule_event(new_event_ptr);
        std::cout << "zaplanowanie  nowego pacjêta -> " << std::endl;
        blood_donation_point_ptr->add_patient_to_queue(this);
        std::cout << "wstawienie pacjêta do kolejki " << std::endl;
        

        event_ptr_->phase++;
        break;
      }
      case 1:
      {
        if (blood_donation_point_ptr->first_patient_from_list != this)
        {
          //poczekaj a¿ bedzie pierwszy
          
          wait_until( event_list->find_patient_event(blood_donation_point_ptr->which_patient_in_the_queue(this)));
          std::cout << "przeplanowanie pacjêta -> " << std::endl;
          event_ptr_->activate = false;
          break;
        }
      }
      case 2:
      {
        if (BloodDonationPoint::blood_level_ > needed_blood_units_)
        {
          for (int i = 0; i < needed_blood_units_; i++)
          {
            blood_donation_point_ptr->remove_unit_of_blood();
          }
          std::cout << "transfuzja krwi -> "<<std::endl;
          event_ptr_->phase++;
        }
        else
        {
          //zaplanuj zdarznie awaryjnej dostawy krwi

          Event* new_event_ptr = new Event(EMERGENCY_BLOOD_SUPPLY,blood_donation_point_ptr);
          event_list->schedule_event(new_event_ptr);
          std::cout << "zaplanowana awaryjn¹ dostawe krwi -> ";
          std::cout << "pacjêt czeka az jednostki przyjad¹ -> ";
          //poczekaj a¿ przyjd¹ jednostki;
          wait_until(new_event_ptr);
          event_ptr_->activate = false;
          
        }
          break;
      }
      case 3:
      {
          if(blood_donation_point_ptr->blood_level_<=blood_donation_point_ptr->min_blood_level)
          {
            Event* new_event_ptr = new Event(BLOOD_SUPPLY,blood_donation_point_ptr);
            std::cout << "zapalnowanie dostawy krwi -> " << std::endl;
            event_list->schedule_event(new_event_ptr);
          }
        blood_donation_point_ptr->remove_first_patient_from_queue();
        //usuñ zdarzenie
      }
    }
  }
}

void Patient::wait_until(Event* prevEvent)
{
  event_list->reschedule_event(event_ptr_,prevEvent);
}


Patient::Patient(Event* _event_ptr,BloodDonationPoint* bdp_ptr)
{
  blood_donation_point_ptr = bdp_ptr;
  needed_blood_units_ = rand()%10;
  std::cout << needed_blood_units_<<" ";
  next_patient_ = nullptr;
  event_ptr_ = _event_ptr;
}


Patient::~Patient()
{
  next_patient_ = nullptr;
}
