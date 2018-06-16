// Symulacja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <cstdio>
//#include "Proces.h"
#include "BloodDonationPoint.h"
#include "Patient.h"
#include "EventList.h"
#include "UnitOfBlood.h"
#include "Symulacja.h"
#include "Event.h"
#include "RandomNumberGenerator.h"
#include <fstream>
#include <omp.h>


using namespace std;

fstream stream;


int main()
{
  
  //fstream supplyStream;

 stream.open("wyniki//supplyStream.txt", ios::out);
  if (stream.good())
    cout << "plik jest otwarty" << endl;
  else
    cout << "nie udało sie " << endl;
    //stream << "czas    |   standardowe dostawy   | awaryjne dostawy " << endl;
  
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
     while (EventList::events_number)
     {
       event_ptr = Proces::event_list->remove_first_event();
       delete event_ptr;
     }

     delete Proces::event_list;
   }

   if (a != 1)
   {
     int th_id;
#pragma omp parallel private(th_id)
    { 
       th_id = omp_get_thread_num();
       printf("thread %d\n", th_id);
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



       while (EventList::events_number)
       {
         event_ptr = Proces::event_list->remove_first_event();
         delete event_ptr;
       }

       delete Proces::event_list;
     }
   }
    stream.close();
  return 0;
}
/*
int main()
{

  fstream UniformGen;
 
  UniformGen.open("wyniki//kernels.txt", ios::out);
  if (UniformGen.good() == true)
  {
    cout << "unifGen działa"<<endl;
  }
  else
  {

   cout << "unifGen nie działa" << endl;
  }
  RandomNumberGenerator* random = new RandomNumberGenerator(54937);
  for (int j = 0; j < 102; j++)
  {
    for (int i = 0; i < 10000; i++)
    {
     random->kernelGenerator();
    }
    //cout << x << endl;
    UniformGen << random->kernelGenerator() << " , ";;
    UniformGen.flush();
  }
  //UniformGen << i << " " <<  tab[i] << endl;

  UniformGen.close();
  delete random;
  return 0;
}*/