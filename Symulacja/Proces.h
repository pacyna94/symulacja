#pragma once
#include "BloodDonationPoint.h"


class Event;

class Proces
{
protected:
  Event * this_event;
 static  BloodDonationPoint* blood_donation_point_ptr;
public:
 virtual void execute()=0;
 // virtual void add_patient_to_queue(Patient* ptr_patient)=0;
 Proces();
 
};


