#pragma once
//#include "Proces.h"
//#include "UnitOfBlood.h"
//#include "Patient.h"
#include <fstream>

class Patient;
class UnitOfBlood;
class Event;
//using namespace std;

class BloodDonationPoint
{
 
public:
 

  static bool standard_blood_supply_on_the_way;
  static bool emergency_blood_supply_on_the_way;
  static bool blood_test_flag;
  static int min_blood_level;
  static int blood_level_;
  static int blood_counter;
  static int number_of_ordered_units;
  static int patien_coutner;
  static double blood_test_time;

  static  UnitOfBlood * unit_of_blood_list;
  static  UnitOfBlood * last_unit_of_blood_list;

  static  Patient * first_patient_from_list;
  static  Patient * last_patient_from_list;

  
  static int add_unit_of_blood(UnitOfBlood* ptr_UnitOfBlood);
  static int remove_unit_of_blood();
  static void remove_expired_blood_units();

  static bool blood_test_check(double this_time_);
  

 

  static  void add_patient_to_queue(Patient* ptr_patient);
  static  void remove_first_patient_from_queue();
  static int which_patient_in_the_queue(Patient* ptr_patient);
 

  BloodDonationPoint();
  ~BloodDonationPoint();
};

