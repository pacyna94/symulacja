#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"
#include "Patient.h"

class StandardBloodSupply :
  public Proces
{
  //Patient* patient_ptr;
  

public:

  void execute() override;
  StandardBloodSupply(Event* event);
  ~StandardBloodSupply();
};

