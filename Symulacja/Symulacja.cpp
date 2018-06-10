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
  
  /*fstream supplyStream;

 // supplyStream.open("wyniki//supplyStream.txt", ios::app | ios::ate | ios::out);
  if (supplyStream.good())
    cout << "plik jest otwarty" << endl;
  else
    cout << "nie udało sie " << endl;
  supplyStream << "czas    |   standardowe dostawy   | awaryjne dostawy " << endl;
  */
 Event * event_ptr;
 cout << "ile pacjentów ma być obsłużone ?" << endl;
 cin >> Event::numberOfPntient;
    

 
   event_ptr = new Event(PATIENT);
   Proces::event_list->schedule_event(event_ptr);
   event_ptr = new Event(BLOOD_DONOR);
   Proces::event_list->schedule_event(event_ptr);
   event_ptr = new Event(BLOOD_SUPPLY);
   Proces::event_list->schedule_event(event_ptr);



   int a = 1;
   int b = 0;
    cout << endl;
    cout << "krokowwo wpisz 1 , ciągle wpisz 2: " << endl;
   cin >> a;
 

   if (a == 1)
   {
     while (!EventList::endOfSymulation)
     {
       
        cout << "czas symulacji: " << Proces::event_list->symulation_time << endl;
        cout << "blood_level: " << Proces::blood_donation_point_ptr->blood_level_ << std::endl;
        Proces::event_list->show_list();
        event_ptr = Proces::event_list->remove_first_event();
        
        event_ptr->make_event->execute();
       cout << "blood_level: " << Proces::blood_donation_point_ptr->blood_level_ << std::endl;
       cout << endl;
       cout << endl;
        
       cout << endl;
       cout << endl;
        
        
        
        cout << endl;
        cout << endl;
        if (event_ptr->event_type == NO_IVENT)
          delete event_ptr;
        
        
        
        
        getchar();
        
     }
   }

   if (a != 1)
   {
     while (!EventList::endOfSymulation)
     {
       //supplyStream << Proces::event_list->symulation_time << "  |  " << Proces::number_of_standard_blood_supply << "  |  " << Proces::number_of_emergency_blood_supply << endl;
       //cout << "eventlist";
       //cout << endl;
       //cout << endl;
      // Proces::event_list->show_list();
      //cout << "blood_level: " << Proces::blood_donation_point_ptr->blood_level_ << std::endl;
       event_ptr = Proces::event_list->remove_first_event();
       event_ptr->make_event->execute();
       //cout << "blood_level: " << Proces::blood_donation_point_ptr->blood_level_ << std::endl;
       //cout << endl;
       //cout << endl;
    
       //cout << endl;
       //cout << endl;
       if (event_ptr->event_type == NO_IVENT)
         delete event_ptr;
      
     }
   }
   

   while (EventList::events_number)
   {
     event_ptr = Proces::event_list->remove_first_event();
     delete event_ptr;
   }

   delete Proces::event_list;
   
//   supplyStream.close();
  return 0;
}
/*
int main()
{

  fstream UniformGen;
 
  UniformGen.open("UniformGen.txt", ios::out);
  if (UniformGen.good() == true)
  {
    //cout << "unifGen działa"<<endl;
  }
  else
  {

    //cout << "unifGen nie działa" << endl;
  }
  RandomNumberGenerator* random = new RandomNumberGenerator(54937);
  for (int i = 0; i < 10000; i++)
  {
   UniformGen <<i<<" " << random->GeometeicGenerator(0.03) << endl;

    //UniformGen << i << " " <<  tab[i] << endl;
    UniformGen.flush();
  }
  UniformGen.close();
  delete random;
  return 0;
}*/