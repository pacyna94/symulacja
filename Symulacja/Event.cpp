#include "stdafx.h"
#include "Event.h"
#include <cstdlib>
#include <iostream>
#include "Patient.h"
#include "Proces.h"
#include "UnitOfBlood.h"
#include  "StandardBloodSupply.h"
#include "Symulacja.h"
#include "EmergencyBloodSupply.h"
#include "BloodDonor.h"
#include "EndOfValidity.h"
#include "BloodTests.h"
#include <omp.h>


RandomNumberGenerator* Event::rngPatient = new RandomNumberGenerator(0 + (symulation_counter* 7) );
RandomNumberGenerator* Event::rngBloodDonor = new RandomNumberGenerator(1 + (symulation_counter * 7));
RandomNumberGenerator* Event::rngEmegrencyBloodSupply = new RandomNumberGenerator(2 + (symulation_counter * 7));
RandomNumberGenerator* Event::rngBloodSuply = new RandomNumberGenerator(3 + (symulation_counter * 7));

bool Event::stopFlag = false;
int Event::numberOfEmergencyBloodSupply = 0;
Event::Event()
{
  make_event = nullptr;
  next_event = this;
  prev_event = this;
  event_type = NO_IVENT;
  event_time = -1;
  phase = 1;
  activate =false;
  //FLAGA DO WYŒWIETLANIA
  flag = false;
  EventList::events_counter++;
  
}

Event::Event(int _event_type)
{
  Event();
  switch (_event_type)
  {
  case PATIENT:
  {
   // activate = true;
    
    event_type = PATIENT;
    event_time = Proces::event_list->symulation_time + rngPatient->ExpGenerator(1.0/300);
    make_event = new Patient(this);
    //std::cout << "zaplanowanie kolejnego pacjenta" << std::endl;
    flag = true;
    break;
    //Odstêp czasu pomiêdzy pojawieniem siê kolejnych pacjentów 
    //wymagaj¹cych transfuzji jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym i œredniej =300
  }


  case BLOOD_DONOR:
  {
    //Czas miêdzy zg³oszeniem siê kolejnych dawców jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym i œredniej 800
    //std::cout << "zaplanowanie kolejnego dawcy -> " << std::endl;
    event_type = BLOOD_DONOR;
    make_event = new BloodDonor(this);
    event_time = Proces::event_list->symulation_time + rngBloodDonor->ExpGenerator(1.0/800);
    flag = true;
     break;
  }
  case BLOOD_SUPPLY:
  {
    event_type = BLOOD_SUPPLY;
    //Czas od wys³ania zamówienia do otrzymania krwi jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym o œredniej = 2000
    //std::cout << "zaplanowanie  dostawy krwi -> " << std::endl;
    Proces::number_of_standard_blood_supply++;
    make_event = new StandardBloodSupply(this);
    event_time = Proces::event_list->symulation_time + rngBloodSuply->ExpGenerator(1.0/2000.0);
    flag = true;
    

    break;
  }
  case EMERGENCY_BLOOD_SUPPLY:
  {
    event_type = EMERGENCY_BLOOD_SUPPLY;
    //Czas dostarczenia takiego zamówienia jest zmienn¹ losow¹ o rozk³adzie normalnym, œredniej 600 i wariancji 0.1
    //std::cout << "zaplanowanie awaryjnej dostawy krwi -> " << std::endl;
    Proces::number_of_emergency_blood_supply++;
    make_event = new EmergencyBloodSupply(this);
    event_time = Proces::event_list->symulation_time + rngEmegrencyBloodSupply->NormalGenerator(600,0.1);
    flag = true;

    break;
  }
  case BLOOD_TEST:
  {
    event_type = BLOOD_TEST;
    make_event = new BloodTests(this);
    flag = true;
    event_time = Proces::event_list->symulation_time - (Proces::event_list->symulation_time - (BloodDonationPoint::blood_test_time + 300.0));
    break;
  }
  default:
    {
    event_type = NO_IVENT;
    make_event = nullptr;
    flag = true;
    }
  }
  if (EventList::end_of_transition_phase_flag)
  {
    supplyStream << EventList::symulation_time << ":" << ((double)Proces::number_of_emergency_blood_supply) / EventList::events_counter << std::endl;
    supplyStream.flush();
  }
}


Event::Event(int _event_type, int _validation_time)
{
  //std::cout << "zaplanowanie koñca przydatnoœci krwi -> " << std::endl;
  Event();
  event_type = END_OF_VALIDITY;
  make_event = new EndOfValidity(this);
  event_time = Proces::event_list->symulation_time + _validation_time;
  flag = true;
  
  if (EventList::end_of_transition_phase_flag)
  {
    supplyStream << EventList::symulation_time << ":" << ((double)Proces::number_of_emergency_blood_supply) / EventList::events_counter <<std::endl;
    supplyStream.flush();
  }

}

Event::~Event()
{
  next_event = nullptr;
  prev_event = nullptr;
  if(make_event)
  delete make_event;
 //event_phase = 0;
}
