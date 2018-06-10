#include "stdafx.h"
#include "Proces.h"
#include "EventList.h"


int Proces::number_of_standard_blood_supply = 0;
int Proces::number_of_emergency_blood_supply = 0;
BloodDonationPoint* Proces::blood_donation_point_ptr = new BloodDonationPoint();
EventList* Proces::event_list = new EventList();

Proces::Proces()
{
}


