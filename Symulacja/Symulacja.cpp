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
#include "RandomNumberGenerator.h"
#include <fstream>

using namespace std;

int main()
{
  


 
 Event * event_ptr;
 Event * started_events;
    
 for(int i=0; i<10; i++)
 {
 
   event_ptr = new Event(PATIENT);
   Proces::event_list->schedule_event(event_ptr);
   
 }

for (int i = 0; i<10; i++)
 {

   event_ptr = new Event(BLOOD_DONOR);
  // event_ptr->event_time = rand() % 10;
   Proces::event_list->schedule_event(event_ptr);

 }

Proces::event_list->show_list();
//EventList * patient_event_list;
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
       cout << "czas symulacji: " << Proces::event_list->symulation_time << endl;

       event_ptr = Proces::event_list->remove_first_event();
       Proces::event_list->show_list();
       event_ptr->make_event->execute();
       cout << endl;
       cout << endl;
       //cout << "eventlist"<<endl<<"/////////////////////////////////////";
       cout << endl;
       cout << endl;
       Proces::event_list->show_list();
       
       //Proces::blood_donation_point_ptr->first_patient_from_list->showPatient();
       cout << endl;
       cout << endl;
       if (event_ptr->event_type == NO_IVENT)
         delete event_ptr;
       //Proces::event_list->cancel_event(event_ptr);



       getchar();
       //continue;
     }
   }
     break;
   
 }
 if (a != 1)
 {
   while (Proces::event_list->headOfEventList->next_event != Proces::event_list->headOfEventList)
   {
     event_ptr = Proces::event_list->remove_first_event();
     event_ptr->make_event->execute();//tu sie wysypije bo niema juz eventów
     cout << endl;
     cout << endl;
     cout << "eventlist";
     cout << endl;
     cout << endl;
    // Proces::event_list->show_list();
     cout << endl;
     cout << endl;
     if (event_ptr->event_type == NO_IVENT)
       delete event_ptr;
     //Proces::event_list->cancel_event(event_ptr);
   }
 }
 

  return 0;
}

/*int main()
{

  fstream UniformGen,ExpGen;
  int tab[1000];
  for(int i=0;i<1000;i++)
    tab[i]=0;
  UniformGen.open("UniformGen.txt", ios::out);
  if (UniformGen.good() == true)
  {
    cout << "unifGen działa"<<endl;
  }
  else
  {

    cout << "unifGen nie działa" << endl;
  }
  RandomNumberGenerator* random = new RandomNumberGenerator(1);
  
for (int i = 0; i < 100000; i++)
  {
    int x = ((int)(random->UniformGenerator() * 1000)) % 1000;
    tab[x]++;

    
  }
  for (int i = 0; i < 1000; i++)
  {
    UniformGen<<i<<" " << tab[i] <<endl;
    UniformGen.flush();
  }
  UniformGen.close();
  delete random;
  return 0;
}*/