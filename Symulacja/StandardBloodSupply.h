#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"

class StandardBloodSupply :
  public Proces
{

  

public:
  void execute() override;
  StandardBloodSupply(Event* event);
  ~StandardBloodSupply();
};

