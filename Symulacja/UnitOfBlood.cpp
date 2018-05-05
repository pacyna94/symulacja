#include "stdafx.h"
#include "UnitOfBlood.h"
#include "Event.h"
#include <iostream>
#include "Symulacja.h"


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
  std::cout << exparation_date << " ";
}

UnitOfBlood::UnitOfBlood(int _exparation_date)
{
  UnitOfBlood();
  exparation_date = event_list->symulation_time + exparation_date;
}


UnitOfBlood::~UnitOfBlood()
{
}
