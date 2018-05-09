#include "stdafx.h"
#include "BloodDonationPoint.h"
#include "UnitOfBlood.h"
#include "Patient.h"
#include <iostream>
#include "Event.h"
#include "Symulacja.h"


/////////////////////
//zmienne statyczne
////////////////////

const int BloodDonationPoint::min_blood_level = 20; //minimalny poziom krwi R =20


UnitOfBlood* BloodDonationPoint::unit_of_blood_list = nullptr;
UnitOfBlood* BloodDonationPoint::last_unit_of_blood_list = nullptr;

Patient* BloodDonationPoint::first_patient_from_list = nullptr;
Patient* BloodDonationPoint::last_patient_from_list = nullptr;


int BloodDonationPoint::blood_level_ = 0;

/////
//krew
////
int BloodDonationPoint::add_unit_of_blood(UnitOfBlood* ptr_UnitOFBlood)
{
  blood_level_++;
  // std::cout << blood_level_<<" ";
  if (!unit_of_blood_list) {
    unit_of_blood_list = ptr_UnitOFBlood;
    last_unit_of_blood_list = ptr_UnitOFBlood;
    return 0;
  }

  if (unit_of_blood_list->exparation_date<ptr_UnitOFBlood->exparation_date)
  {
    unit_of_blood_list->prev_blood_unit = ptr_UnitOFBlood;
    ptr_UnitOFBlood->next_blood_unit = unit_of_blood_list;
    unit_of_blood_list = ptr_UnitOFBlood;
    return 0;
  }

  UnitOfBlood* ptr_uob = unit_of_blood_list;
  while (true)
  {
    if (ptr_uob->next_blood_unit)
    {
      if (ptr_uob->next_blood_unit->exparation_date > ptr_UnitOFBlood->exparation_date)
      {
        ptr_uob = ptr_uob->next_blood_unit;
      }
      else
      {
        ptr_UnitOFBlood->next_blood_unit = ptr_uob->next_blood_unit;
        ptr_UnitOFBlood->next_blood_unit->prev_blood_unit = ptr_UnitOFBlood;
        ptr_uob->next_blood_unit = ptr_UnitOFBlood;
        ptr_UnitOFBlood->prev_blood_unit = ptr_uob;

        break;
      }
    }
    else
    {
      ptr_uob->next_blood_unit = ptr_UnitOFBlood;
      ptr_UnitOFBlood->prev_blood_unit = ptr_uob;
      last_unit_of_blood_list = ptr_UnitOFBlood;
      break;
    }
  }
  return 0;
}

int BloodDonationPoint::remove_unit_of_blood()
{
  blood_level_--;
  UnitOfBlood * ptr_uob = unit_of_blood_list;
  unit_of_blood_list = unit_of_blood_list->next_blood_unit;
  delete ptr_uob;
  return 0;
}


////
//pacjet
////

void BloodDonationPoint::add_patient_to_queue(Patient* ptr_patient)
{
  if(!first_patient_from_list)
  {
    first_patient_from_list = ptr_patient;
    last_patient_from_list = ptr_patient;
  }
  else
  {
    last_patient_from_list->next_patient_ = ptr_patient;
    last_patient_from_list = ptr_patient;
  }
}

void BloodDonationPoint::remove_first_patient_from_queue()
{
  Patient* delete_patient = first_patient_from_list;
  if(first_patient_from_list->next_patient_)
  first_patient_from_list = first_patient_from_list->next_patient_;
  else
  {
    first_patient_from_list = nullptr;
  }
  //delete delete_patient;
}

int BloodDonationPoint::which_patient_in_the_queue(Patient* ptr_patient)
{
  Patient* patient_list_ptr = first_patient_from_list;
  int counter = 0;
  while(patient_list_ptr!=ptr_patient)
  {
    patient_list_ptr = patient_list_ptr->next_patient_;
    counter++;

  }
  return counter;
}











/////////////////
//konstruktor i destruktor
////////////////



BloodDonationPoint::BloodDonationPoint()
{
  
 
}


BloodDonationPoint::~BloodDonationPoint()
{
}
