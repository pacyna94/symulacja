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
#include "EmergencyBloodSupply.h"
#include "RandomNumberGenerator.h"
#include "BloodTests.h"
#include "EndOfValidity.h"
#include <fstream>
#include <omp.h>
#include <string>


using namespace std;

fstream stream;
fstream bloodStream;
fstream supplyStream;
int symulation_counter;

int main()
{
  
  fstream SymulationResults;


 
 cout << "ile awaryjnych dostaw krwi ?" << endl;
 cin >> Event::numberOfEmergencyBloodSupply;
    
 cout << "-----------Wybierz parametry symulacji-------------------- " << endl;
 cout << "minimalny poziom krwi: ";
 cin >> BloodDonationPoint::min_blood_level;
 cout << endl << "Ilość zamawianych jednostek krwi: ";
 cin >> BloodDonationPoint::number_of_ordered_units;
 
 string fileName1 = "wyniki//symulationResults" + to_string(symulation_counter) + "R=" + to_string(BloodDonationPoint::min_blood_level) + "N="
   + to_string(BloodDonationPoint::number_of_ordered_units) + ".txt";

 SymulationResults.open(fileName1, ios::out);

 SymulationResults << "numer symulacji " << "    prawodopodobienstwo awaryjnego zamówienia  " << "   stosunek usuwanych do wysstkich jednostek krwi" << endl;

   int a = 1;
   int b = 0;
    cout << endl;
    cout << "krokowwo wpisz 1 , ciągle wpisz 2: " << endl;
   cin >> a;
 

   if (a == 1)
   {
     Event * event_ptr;
     event_ptr = new Event(PATIENT);
     Proces::event_list->schedule_event(event_ptr);
     event_ptr = new Event(BLOOD_DONOR);
     Proces::event_list->schedule_event(event_ptr);
     event_ptr = new Event(BLOOD_SUPPLY);
     Proces::event_list->schedule_event(event_ptr);
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
     //EventList::end_of_transition_phase_flag = true;
     cout << "ile symulacji wykonac?" << endl;
     int number_of_symulation;
     cin >> number_of_symulation;
     for (symulation_counter ; symulation_counter < number_of_symulation; symulation_counter++)
     {
       cout << endl << "symulacja numer: " << symulation_counter << endl;
       string folderName = "wyniki//BloodStream" + to_string(symulation_counter) + "R=" + to_string(BloodDonationPoint::min_blood_level) + "N="
         + to_string(BloodDonationPoint::number_of_ordered_units) + ".txt";
       string fileName = "wyniki//supplyStream" + to_string(symulation_counter)+"R="+ to_string(BloodDonationPoint::min_blood_level)+"N="
         +to_string(BloodDonationPoint::number_of_ordered_units) + ".txt";
       bloodStream.open(folderName, ios::out);
       supplyStream.open(fileName, ios::out);

       Event * event_ptr;
       event_ptr = new Event(PATIENT);
       Proces::event_list->schedule_event(event_ptr);
       event_ptr = new Event(BLOOD_DONOR);
       Proces::event_list->schedule_event(event_ptr);
       event_ptr = new Event(BLOOD_SUPPLY);
       Proces::event_list->schedule_event(event_ptr);

       
       
      
       while (!EventList::endOfSymulation)
       {
         //supplyStream << Proces::event_list->symulation_time << "  |  " << Proces::number_of_standard_blood_supply << "  |  " << Proces::number_of_emergency_blood_supply << endl;
         //cout << "eventlist";
         //cout << endl;
         //cout << endl;
         //Proces::event_list->show_list();
        //cout << "blood_level: " << Proces::blood_donation_point_ptr->blood_level_ << std::endl;
         if ((!EventList::end_of_transition_phase_flag) && (EventList::events_counter > EventList::end_of_transition_phase))
         {
           EventList::events_counter = 0;
           EventList::end_of_transition_phase_flag = true;
           Proces::number_of_emergency_blood_supply = 0;
           EmergencyBloodSupply::ID = 0;
           //supplyStream << "koniec_fazy poczatkowej" << endl;
         }
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
       SymulationResults << symulation_counter << "                                    " << ((double)Proces::number_of_emergency_blood_supply) / EventList::events_counter << "                             " << ((double)EndOfValidity::expiried_units_counter) / BloodDonationPoint::blood_counter << endl;
      
       bloodStream.close();
       supplyStream.close();
       //if(BloodDonationPoint::first_patient_from_list)
       //BloodDonationPoint::first_patient_from_list->showPatient();
      
       while (BloodDonationPoint::first_patient_from_list)
       {
         Patient* patient = BloodDonationPoint::first_patient_from_list;
         BloodDonationPoint::remove_first_patient_from_queue();
         delete patient;
       }
       while (BloodDonationPoint::blood_level_)
       {
         BloodDonationPoint::remove_unit_of_blood();
       }
    
       while (EventList::events_number)
       {
         event_ptr = Proces::event_list->remove_first_event();
         delete event_ptr;
       }
       EventList::endOfSymulation = false;
       EventList::end_of_transition_phase_flag = false;
       EventList::symulation_time = 0.0;
       EventList::events_counter = 0;
       EmergencyBloodSupply::ID = 0;
       Proces::number_of_emergency_blood_supply = 0;
       Proces::number_of_standard_blood_supply = 0;
       BloodDonationPoint::blood_counter = 0;
       EndOfValidity::expiried_units_counter = 0;
       delete Event::rngPatient;
       delete Event::rngBloodDonor;
       delete Event::rngEmegrencyBloodSupply;
       delete Event::rngBloodSuply;
       delete Patient::rng_needed_blood_units;
       delete BloodTests::rngBloodTests;

       Event::rngPatient = new RandomNumberGenerator(0 + ((symulation_counter+1) * 7));
       Event::rngBloodDonor = new RandomNumberGenerator(1 + ((symulation_counter+1) * 7));
       Event::rngEmegrencyBloodSupply = new RandomNumberGenerator(2 + ((symulation_counter+1) * 7));
       Event::rngBloodSuply = new RandomNumberGenerator(3 + ((symulation_counter+1) * 7));
       Patient::rng_needed_blood_units = new RandomNumberGenerator(4 + ((symulation_counter+1)* 7));
       BloodTests::rngBloodTests = new RandomNumberGenerator(5 * ((symulation_counter+1) * 7));
       //delete Proces::event_list;
     }
     SymulationResults.close();
   }
 
  return 0;
}
/*

int main()
{

  fstream UniformGen;
 
  UniformGen.open("wyniki//GeoGenTest.txt", ios::out);
  if (UniformGen.good() == true)
  {
    cout << "unifGen działa"<<endl;
  }
  else
  {

   cout << "unifGen nie działa" << endl;
  }
  RandomNumberGenerator* random = new RandomNumberGenerator(11);
 
    for (int i = 0; i < 100000; i++)
    {
      UniformGen << i<<" "<< random->UniformGenerator()<<endl;
    }
    //cout << x << endl;
     
    //UniformGen.flush();

  //UniformGen << i << " " <<  tab[i] << endl;

  UniformGen.close();
  delete random;
  return 0;
}*/