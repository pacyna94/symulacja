#include "stdafx.h"
#include "Patient.h"
#include <cstdlib>
#include <iostream>
#include "Event.h"
#include "BloodDonationPoint.h"
#include "Symulacja.h"
#include "EventList.h"
//EventList* event_list;


int Patient::ID = 0;



void Patient::showPatient()
{
  if (next_patient_)
  {
    std::cout << id<<" "<<needed_blood_units_<<std::endl;
    next_patient_->showPatient();
  }
  else
  {
    std::cout <<id<<" "<< needed_blood_units_ << " " << std::endl;;
  }

}

void Patient::wakeUp()
{
  this_event->activate = true;
  this_event->event_time = event_list->symulation_time;
  event_list->schedule_event(this_event);
  //execute();
}

void Patient::execute()
{
  //event_ptr_=this_event
  std::cout<<std::endl<<std::endl << "patient id: "<<id<<" needed_blood_units_: "<<needed_blood_units_<< std::endl<<std::endl;
  while (this_event->activate)
  {
    switch (this_event->phase)
    {
      case 0:
      {
        Event* new_event_ptr;
        if (id > Event::numberOfPntient)
          Event::stopFlag = true;
        if(!this_event->stopFlag)
        {
          new_event_ptr = new Event(PATIENT);
          event_list->schedule_event(new_event_ptr);
          std::cout << "zaplanowanie  nowego pacjêta -> " << std::endl;
        }
        blood_donation_point_ptr->add_patient_to_queue(this);
        std::cout << "wstawienie pacjêta do kolejki-> " << std::endl;
        

        this_event->phase++;
        break;
      }
      case 1:
      {
        if (blood_donation_point_ptr->first_patient_from_list != this)
        {
          std::cout << "pacjêt czeka az bedzie 1 w kolejce-> " << std::endl;
          this_event->activate = false;
          break;
        }
        this_event->phase++;
          break;
      }
      case 2:
      {
        if (BloodDonationPoint::blood_level_ > needed_blood_units_)
        {
          for (int i = 0; i < needed_blood_units_; i++)
          {
            blood_donation_point_ptr->remove_unit_of_blood();
          }
         
          std::cout << "transfuzja krwi -> " << std::endl;
          this_event->phase++;
        }
        else
        {
          


          Event* new_event_ptr = new Event(EMERGENCY_BLOOD_SUPPLY);
          event_list->schedule_event(new_event_ptr);
          std::cout << "zaplanowana awaryjn¹ dostawe krwi -> ";
          std::cout << "pacjêt czeka az jednostki przyjad¹ -> ";
          this_event->activate = false;

        }
        break;
      }
      case 3:
      {
          if(blood_donation_point_ptr->blood_level_<=blood_donation_point_ptr->min_blood_level)
          {
            Event* new_event_ptr = new Event(BLOOD_SUPPLY);
            std::cout << "zapalnowanie dostawy krwi -> " << std::endl;
            event_list->schedule_event(new_event_ptr);
          }
        blood_donation_point_ptr->remove_first_patient_from_queue();
        if(blood_donation_point_ptr->first_patient_from_list)
       blood_donation_point_ptr->first_patient_from_list->wakeUp();
        this_event->event_type = NO_IVENT;
        this_event->activate = false;
          break;
          
      }
    }
  }
}

void Patient::wait_until(Event* prevEvent)
{
 //trzeba wyj¹æ z kolejki zaczêtych eventów i dopiero wstawiæ
  event_list->reschedule_event(this_event,prevEvent);
}


Patient::Patient(Event* _event_ptr)
{
 
  needed_blood_units_ = this_event->randomNumberGenerator->GeometeicGenerator(0.19);
  std::cout << needed_blood_units_<<" ";
  next_patient_ = nullptr;
  this_event= _event_ptr;
  id = ID++;
}


Patient::~Patient()
{
  next_patient_ = nullptr;
  this_event = nullptr;
}
