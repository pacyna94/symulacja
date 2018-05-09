#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"

class EmergencyBloodSuply :
  public Proces
{
 
public:
  void execute() override;
  EmergencyBloodSuply(Event* event);
  ~EmergencyBloodSuply();
};

