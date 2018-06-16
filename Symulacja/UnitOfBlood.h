#pragma once
#include "Proces.h"
//#include "BloodDonationPoint.h"
//#include "Event.h"

class BloodDonationPoint;

class UnitOfBlood
{
 public:
  //BloodDonationPoint * blood_donation_point_ptr;
  UnitOfBlood * next_blood_unit;
  UnitOfBlood * prev_blood_unit;
  double exparation_date;
  void showUnitOfBlood();
  void showBackward();
  //void execute() override;
 
  UnitOfBlood();
  UnitOfBlood(int _exparation_date);
  ~UnitOfBlood();
};