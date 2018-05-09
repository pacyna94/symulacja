#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"

class BloodDonor
  :public Proces
{

public:
  void execute() override;
  BloodDonor(Event* event);
  ~BloodDonor();
};

