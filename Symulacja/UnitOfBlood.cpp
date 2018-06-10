#include "stdafx.h"
#include "UnitOfBlood.h"
#include "Event.h"
#include <iostream>
#include "Proces.h"
#include "EventList.h"


void UnitOfBlood::showUnitOfBlood()
{

  if (next_blood_unit)
  {
    std::cout << exparation_date << " ";
    next_blood_unit->showUnitOfBlood();
    
  }
  else
  {
    std::cout << exparation_date << " ";
    std::cout << std::endl;
    showBackward();
  }
}

void UnitOfBlood::showBackward()
{
  if (prev_blood_unit)
  {
    std::cout << exparation_date << " ";
    prev_blood_unit->showBackward();

  }
  else
  {
    std::cout << exparation_date << " ";

  }
}

/*void UnitOfBlood::execute()
{
  
}
*/

UnitOfBlood::UnitOfBlood()
{
  next_blood_unit = nullptr;
  prev_blood_unit = nullptr;
  exparation_date = -1;
 
}

UnitOfBlood::UnitOfBlood(int _exparation_date)
{
  UnitOfBlood();
  exparation_date = Proces::event_list->symulation_time + _exparation_date;
}


UnitOfBlood::~UnitOfBlood()
{
  next_blood_unit = nullptr;
  prev_blood_unit = nullptr;
}
