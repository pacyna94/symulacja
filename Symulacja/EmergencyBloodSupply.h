#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"
#include "Patient.h"

class EmergencyBloodSupply :
  public Proces
{
  
  
public:
  static int ID;
  //Patient * patient_ptr;
  void execute() override;
  EmergencyBloodSupply(Event* event);
  ~EmergencyBloodSupply();
};

