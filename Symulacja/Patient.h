#pragma once
#include "Proces.h"
//#include "Event.h"
//#include "BloodDonationPoint.h"
#include "RandomNumberGenerator.h"
class BloodDonationPoint;
class Event;

class Patient
  :public Proces
{
  

public:
  //protected:
  static int ID;
  
    int needed_blood_units_; //Liczba jednostek krwi podawan pojedynczemu pacjentowi jest zmienn� 
    static RandomNumberGenerator* rng_needed_blood_units;                       //losow� o rozk�adzie geometrycznym i �redniej 100/19
    Patient * next_patient_;
   // Patient* prev_patient; mozna stwierdzic czy pacjet jest pierwszy wkolejce;
    void showPatient();
    void execute() override;
    void wakeUp();
 
    

    Patient(Event* _event_ptr);
    ~Patient(); 
};

