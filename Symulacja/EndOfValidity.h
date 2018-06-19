#pragma once
#include "Proces.h"
#include "Event.h"
#include "EventList.h"
#include <iostream>
#include "Symulacja.h"

class EndOfValidity :
  public Proces
{
public:
  static int expiried_units_counter;
  void execute() override;
  EndOfValidity(Event* _event_ptr);
  ~EndOfValidity();
};

