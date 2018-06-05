#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"
#include "Patient.h"

class StandardBloodSupply :
  public Proces
{
  static int ID;

public:

  void execute() override;
  StandardBloodSupply(Event* event);
  ~StandardBloodSupply();
};

