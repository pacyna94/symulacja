#pragma once
//#include "Proces.h"
//#include "UnitOfBlood.h"
//#include "Patient.h"

class Patient;
class UnitOfBlood;
class Event;


class BloodDonationPoint

{

 
public:
  static const int min_blood_level;
  static int blood_level_;



  static  UnitOfBlood * unit_of_blood_list;
  static  UnitOfBlood * last_unit_of_blood_list;

  static  Patient * first_patient_from_list;
  static  Patient * last_patient_from_list;

  
  static int add_unit_of_blood(UnitOfBlood* ptr_UnitOfBlood);
  static int remove_unit_of_blood();
  

 

  static  void add_patient_to_queue(Patient* ptr_patient);
  static  void remove_first_patient_from_queue();
  static int which_patient_in_the_queue(Patient* ptr_patient);
 

  BloodDonationPoint();
  ~BloodDonationPoint();
};

