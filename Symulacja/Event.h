#pragma once
#include "Proces.h"
#include "RandomNumberGenerator.h"
class Event
{
public:
  Proces * make_event;
  double event_time;
  int event_type;
  static int ID;
  int id;
  int phase;
  bool flag;
  bool activate;
  static bool stopFlag;
  static int numberOfPntient;
  static RandomNumberGenerator* randomNumberGenerator;

  Event * next_event;
  Event * prev_event;

  //void showEvents();

  Event();
  Event(int _event_type);
  Event(int _event_type,Patient* _patient_ptr);
  Event(int _event_type,int _validation_time);
  //Event(int _event_type, Proces* _make_event_BDP, int _event_time);
 

 
  ~Event();
};

enum
{
  PATIENT,
  UNIT_OF_BLOOD,
  END_OF_VALIDITY,
  BLOOD_SUPPLY,
  EMERGENCY_BLOOD_SUPPLY,
  BLOOD_DONOR,
  NO_IVENT
};
