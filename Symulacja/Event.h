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
  static int numberOfEmergencyBloodSupply;
  static RandomNumberGenerator* rngPatient;
  static RandomNumberGenerator* rngBloodDonor;
  static RandomNumberGenerator* rngEmegrencyBloodSupply;
  static RandomNumberGenerator* rngBloodSuply;
 
  Event * next_event;
  Event * prev_event;

 
  Event();
  Event(int _event_type);
  Event(int _event_type,int _validation_time);
  
 

 
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
  BLOOD_TEST,
  NO_IVENT
};
