#pragma once
#include "Proces.h"
#include "BloodDonationPoint.h"

class BloodDonor
  :public Proces
{
  static int ID;
public:
  void execute() override;
  BloodDonor(Event* event);
  ~BloodDonor();
};

