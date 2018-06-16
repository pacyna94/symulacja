#include "stdafx.h"
#include "BloodDonationPoint.h"
#include "UnitOfBlood.h"
#include "Patient.h"
#include <iostream>
#include "Event.h"
#include "Symulacja.h"
#include "Proces.h"
#include "EventList.h"
#include <fstream>

using namespace std;

/////////////////////
//zmienne statyczne
////////////////////
bool BloodDonationPoint::standard_blood_supply_on_the_way = false;
bool BloodDonationPoint::emergency_blood_supply_on_the_way = false;
bool BloodDonationPoint::blood_test_flag = false;

const int BloodDonationPoint::min_blood_level = 20; //minimalny poziom krwi R =20

int BloodDonationPoint::blood_level_ = 0;
int BloodDonationPoint::patien_coutner = 0;
double BloodDonationPoint::blood_test_time = 0.0;
UnitOfBlood* BloodDonationPoint::unit_of_blood_list = nullptr;
UnitOfBlood* BloodDonationPoint::last_unit_of_blood_list = nullptr;

Patient* BloodDonationPoint::first_patient_from_list = nullptr;
Patient* BloodDonationPoint::last_patient_from_list = nullptr;




/////
//krew
////
int BloodDonationPoint::add_unit_of_blood(UnitOfBlood* ptr_UnitOFBlood)
{
  blood_level_++;
  std::fstream stream;
  stream.open("wyniki//bloodLevel.txt", ios::out | ios::app);
  stream << Proces::event_list->symulation_time << " " << blood_level_ << std::endl;
  stream.flush();
  stream.close();
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
  std::fstream stream;
  stream.open("wyniki//bloodLevel.txt", ios::out | ios::app);
  stream << Proces::event_list->symulation_time << " " << blood_level_ << std::endl;
  stream.flush();
  stream.close();
  
  UnitOfBlood * ptr_uob;
  if (last_unit_of_blood_list->prev_blood_unit == nullptr)
  {
    ptr_uob = last_unit_of_blood_list;
    unit_of_blood_list = nullptr;
    last_unit_of_blood_list = nullptr;
  }
  else
  {
    ptr_uob = last_unit_of_blood_list;
    last_unit_of_blood_list = last_unit_of_blood_list->prev_blood_unit;
    last_unit_of_blood_list->next_blood_unit = nullptr;
  }
  if(ptr_uob)
  delete ptr_uob;
  return 0;
}

void BloodDonationPoint::remove_expired_blood_units()
{
  while (last_unit_of_blood_list->exparation_date < Proces::event_list->symulation_time)
  {
    
    if (last_unit_of_blood_list->prev_blood_unit == nullptr)
    {
      blood_level_--;
      std::fstream stream;
      stream.open("wyniki//bloodLevel.txt", ios::out | ios::app);
      stream << Proces::event_list->symulation_time << " " << blood_level_ << std::endl;
      stream.close();
      UnitOfBlood * ptr_uob = last_unit_of_blood_list;
      unit_of_blood_list = nullptr;
      last_unit_of_blood_list = nullptr;
      delete ptr_uob;
      break;
    }
    else
    {
    
      remove_unit_of_blood();
    }
  }

 
}

bool BloodDonationPoint::blood_test_check(double this_time_ )
{
  if(blood_level_<15)
  {
   // blood_test_flag = false;//nie wiadomo czy potrzebne??
    blood_test_time = this_time_;
    return false;
  }
  else
  {
    if ((this_time_ - blood_test_time) >= 300)
      return true;
    else
    {
      
      return false;
    }
  }

}

////
//pacjet
////

void BloodDonationPoint::add_patient_to_queue(Patient* ptr_patient)
{
  patien_coutner++;
  std::fstream stream;
  stream.open("wyniki//patientLevel.txt", ios::out | ios::app);
  stream << Proces::event_list->symulation_time << " " << patien_coutner << std::endl;
  stream.close();

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
  patien_coutner--;
  std::fstream stream;
  stream.open("wyniki//patientLevel.txt", ios::out | ios::app);
  stream << Proces::event_list->symulation_time << " " << patien_coutner << std::endl;
  stream.close();
 // Patient* delete_patient = first_patient_from_list;
  if(first_patient_from_list->next_patient_)
  first_patient_from_list = first_patient_from_list->next_patient_;
  else
  {
    first_patient_from_list = nullptr;
    last_patient_from_list = nullptr;
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
  //0 == 0;
 
}


BloodDonationPoint::~BloodDonationPoint()
{

}
