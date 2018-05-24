#pragma once
#include "Proces.h"
#include "Event.h"
#include "EventList.h"
#include <iostream>


class EndOfValidity :
  public Proces
{
public:

  void execute() override;
  EndOfValidity(Event* _event_ptr);
  ~EndOfValidity();
};

