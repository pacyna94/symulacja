#pragma once
#include "BloodDonationPoint.h"




class Event;
class EventList;


class Proces
{
protected:
  Event * this_event;
 
public:
  int id;

  static  EventList* event_list;
  static  BloodDonationPoint* blood_donation_point_ptr;

 virtual void execute()=0;
 // virtual void add_patient_to_queue(Patient* ptr_patient)=0;
 Proces();
 
};


