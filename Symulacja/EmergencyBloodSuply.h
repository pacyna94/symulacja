#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"
#include "Patient.h"

class EmergencyBloodSuply :
  public Proces
{
 
public:
  //Patient * patient_ptr;
  void execute() override;
  EmergencyBloodSuply(Event* event);
  ~EmergencyBloodSuply();
};

