#pragma once
#include "Proces.h"
//#include "Event.h"
//#include "BloodDonationPoint.h"
class BloodDonationPoint;
class Event;

class Patient
  :public Proces
{


public:
  //protected:

 

    int needed_blood_units_; //Liczba jednostek krwi podawan pojedynczemu pacjentowi jest zmienn¹ 
                            //losow¹ o rozk³adzie geometrycznym i œredniej 100/19
    Patient * next_patient_;
   // Patient* prev_patient; mozna stwierdzic czy pacjet jest pierwszy wkolejce;
    void showPatient();
    void execute() override;
    void wait_until(Event* prev_event);

    Patient(Event* _event_ptr);
    ~Patient(); 
};

