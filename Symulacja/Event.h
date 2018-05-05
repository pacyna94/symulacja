#pragma once
#include "Proces.h"

class Event
{
public:
  Proces * make_event;
  int event_time;
  int event_type;
  int phase;
  bool flag;
  bool activate;

  Event * next_event;
  Event * prev_event;

  void showEvents();

  Event();
  Event(int _event_type, Proces* _make_event_BDP);
  Event(int _event_type, Proces* _make_event_BDP, int _event_time);
 

 
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
