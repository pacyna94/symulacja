#include "stdafx.h"
#include "Event.h"
#include <cstdlib>
#include <iostream>
#include "Patient.h"
#include "Proces.h"
#include "UnitOfBlood.h"
#include  "StandardBloodSupply.h"
#include "Symulacja.h"
#include "EmergencyBloodSuply.h"
#include "BloodDonor.h"
#include "EndOfValidity.h"


RandomNumberGenerator* Event::randomNumberGenerator = new RandomNumberGenerator(1);
bool Event::stopFlag = false;
int Event::numberOfPntient = 0;
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
    event_time = Proces::event_list->symulation_time + randomNumberGenerator->ExpGenerator(1.0/300);
    make_event = new Patient(this);
    std::cout << "zaplanowanie kolejnego pacjenta" << std::endl;
    flag = true;
    break;
    //Odstêp czasu pomiêdzy pojawieniem siê kolejnych pacjentów 
    //wymagaj¹cych transfuzji jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym i œredniej =300
  }


  case BLOOD_DONOR:
  {
    //Czas miêdzy zg³oszeniem siê kolejnych dawców jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym i œredniej 800
    std::cout << "zaplanowanie kolejnego dawcy -> " << std::endl;
    event_type = BLOOD_DONOR;
    make_event = new BloodDonor(this);
    event_time = Proces::event_list->symulation_time + randomNumberGenerator->ExpGenerator(1.0/800);
    flag = true;
     break;
  }
  case BLOOD_SUPPLY:
  {
    event_type = BLOOD_SUPPLY;
    //Czas od wys³ania zamówienia do otrzymania krwi jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym o œredniej = 2000
    std::cout << "zaplanowanie  dostawy krwi -> " << std::endl;

    make_event = new StandardBloodSupply(this);
    event_time = Proces::event_list->symulation_time + randomNumberGenerator->ExpGenerator(1.0/2000);
    flag = true;
    break;
  }
  case EMERGENCY_BLOOD_SUPPLY:
  {
    event_type = EMERGENCY_BLOOD_SUPPLY;
    //Czas dostarczenia takiego zamówienia jest zmienn¹ losow¹ o rozk³adzie normalnym, œredniej 600 i wariancji 0.1
    std::cout << "zaplanowanie awaryjnej dostawy krwi -> " << std::endl;
    make_event = new EmergencyBloodSuply(this);
    event_time = Proces::event_list->symulation_time + randomNumberGenerator->NormalGenerator(600,0.1);
    flag = true;
    break;
  }
  default:
    {
    event_type = NO_IVENT;
    make_event = nullptr;
    flag = true;
    }
  }
  
}


Event::Event(int _event_type, int _validation_time)
{
  std::cout << "zaplanowanie koñca przydatnoœci krwi -> " << std::endl;
  event_type = END_OF_VALIDITY;
  make_event = new EndOfValidity(this);
  event_time = Proces::event_list->symulation_time + _validation_time;
  flag = true;
 

}

Event::~Event()
{
  next_event = nullptr;
  prev_event = nullptr;
  if(make_event)
  delete make_event;
 //event_phase = 0;
}
