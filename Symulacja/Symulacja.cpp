// Symulacja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "Proces.h"
#include "BloodDonationPoint.h"
#include "Patient.h"
#include "EventList.h"
#include "UnitOfBlood.h"
#include "Symulacja.h"
#include "Event.h"

using namespace std;
EventList* event_list;
//class Patient;

int main()
{
  
 event_list = new EventList();
//  BloodDonationPoint* blood_donation_point_ptr = new BloodDonationPoint();
 
 Event * event_ptr;
    
 for(int i=0; i<10; i++)
 {
 
   event_ptr = new Event(PATIENT);
  event_list->schedule_event(event_ptr);
   
 }
// event_list->show_list();
//cout << "show patient" << endl;
  //Patient::blood_donation_point_ptr->first_patient_from_list->showPatient();
 //Patient::blood_donation_point_ptr = new BloodDonationPoint();
/* for (int i = 0; i<10; i++)
 {

   event_ptr = new Event(BLOOD_SUPPLY);
   event_ptr->event_time = rand() % 10;
   event_list->schedule_event(event_ptr);

 }*/

 /*cout << endl;
 cout << endl;
 cout << endl;
 //cout << "eventlist";
 cout << endl;
 cout << endl;
 //event_list->show_list();
 cout << endl;
 cout << endl;

 */
for (int i = 0; i<10; i++)
 {

   event_ptr = new Event(BLOOD_DONOR);
  // event_ptr->event_time = rand() % 10;
   event_list->schedule_event(event_ptr);

 }
 //cout << endl;
 //cout << endl;
 event_list->show_list();
 //cout << endl;
// cout << endl;
 //cout << "początek symulacji" << endl;
 //cout << endl;
 int a = 1;
 int b = 0;
 cout << endl;
 cout << "krokowwo wpisz 1 , ciągle wpisz 2: " << endl;
 cin >> a;
 while (true)
 {
   if (a == 1)
   {
     while (true)//for (int i = 0; i < 20; i++)// 
     {
       event_ptr = event_list->remove_first_event();
       event_ptr->make_event->execute();
       cout << endl;
       cout << endl;
       cout << "eventlist";
       cout << endl;
       cout << endl;
       event_list->show_list();
       cout << endl;
       cout << endl;
       event_list->cancel_event(event_ptr);

       cin >> b;
       continue;
     }
   }
     break;
   
 }
 if (a != 1)
 {
   while (event_list->headOfEventList->next_event != event_list->headOfEventList)
   {
     event_ptr = event_list->remove_first_event();
     event_ptr->make_event->execute();
     cout << endl;
     cout << endl;
     cout << "eventlist";
     cout << endl;
     cout << endl;
     event_list->show_list();
     cout << endl;
     cout << endl;
     event_list->cancel_event(event_ptr);
   }
 }
 
 /* for (int i = 0; i < 10; i++)
  {
    Patient* ptr_patient = new Patient(nullptr);
    blood_donation_point_ptr->add_patient_to_queue(ptr_patient);

  }
  cout << endl;
  blood_donation_point_ptr->first_patient_from_list->showPatient();
  cout << endl;
  for (int i = 0; i < 10; i++)
    blood_donation_point_ptr->remove_first_patient_from_queue();

  ///////////UnitOfBlood test
/*
  cout << endl;
  cout << endl;
  cout << "unit of blood test" << endl;
  cout << endl;

  for (int i = 0; i < 10; i++)
  {
    UnitOfBlood* ptr_UnitOfBlood = new UnitOfBlood();
    blood_donation_point_ptr->add_unit_of_blood(ptr_UnitOfBlood);
    //cout << BloodDonationPoint::last_unit_of_blood_list->exparation_date << "..";


  }
  cout << endl;
  blood_donation_point_ptr->unit_of_blood_list->showUnitOfBlood();
  cout << endl;
  for(int i =0; i<10;i++)
  {
    blood_donation_point_ptr->remove_unit_of_blood();
  }

  delete blood_donation_point_ptr;
  */
  return 0;
}

