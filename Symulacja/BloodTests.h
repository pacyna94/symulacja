#pragma once
#include "Proces.h"
#include "RandomNumberGenerator.h"
class BloodTests :
  public Proces
{
public:

  static RandomNumberGenerator * rngBloodTests; 
  void execute() override;
  BloodTests( Event* this_event_);
  ~BloodTests();
};

