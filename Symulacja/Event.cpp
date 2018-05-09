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


void Event::showEvents()
{
 
  if (!flag)
  {
    std::cout << event_type << " ";
    flag = true;
    next_event->showEvents();
    
  }
 
}

Event::Event()
{
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
    event_time =event_list->symulation_time+ rand() % 13;
    make_event = new Patient(this);
    std::cout << "zaplanowanie kolejnego pacjenta" << std::endl;
    break;
    //Odstêp czasu pomiêdzy pojawieniem siê kolejnych pacjentów 
    //wymagaj¹cych transfuzji jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym i œredniej =300
  }

  case END_OF_VALIDITY:
  {
    event_type = END_OF_VALIDITY;
    //nie jest okreslony zmienn¹ losow¹ tylko wglêdem czasu symulacji;
   // make_event=_make_event_BDP;
    break;
  }
  case BLOOD_SUPPLY:
  {
    event_type = BLOOD_SUPPLY;
    //Czas od wys³ania zamówienia do otrzymania krwi jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym o œredniej = 2000
    std::cout << "zaplanowanie  dostawy krwi -> "<< std::endl;
    make_event = new StandardBloodSupply(this);
    event_time = event_list->symulation_time + rand() % 10;
    break;  
  }
  case EMERGENCY_BLOOD_SUPPLY:
  {
    event_type = EMERGENCY_BLOOD_SUPPLY;
    //Czas dostarczenia takiego zamówienia jest zmienn¹ losow¹ o rozk³adzie normalnym, œredniej 600 i wariancji 0.1
    std::cout << "zaplanowanie awaryjnej dostawy krwi -> " << std::endl;
    make_event = new EmergencyBloodSuply(this);
    event_time = event_list->symulation_time + rand() % 10;
    break;
  }
  case BLOOD_DONOR:
  {
    //Czas miêdzy zg³oszeniem siê kolejnych dawców jest zmienn¹ losow¹ o rozk³adzie wyk³adniczym i œredniej 800
    std::cout << "zaplanowanie kolejnego dawcy -> " << std::endl;
    event_type = BLOOD_DONOR;
    make_event = new BloodDonor(this);
    event_time = event_list->symulation_time + rand() % 10;
     break;
  }
  default:
    {
    event_type = NO_IVENT;
    }
  }
  
}



Event::~Event()
{
  next_event = nullptr;
  prev_event = nullptr;
 //event_phase = 0;
}
