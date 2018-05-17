#pragma once
//#include "Event.h"
//
class Event;

class EventList
{
  
public:
  static int events_number;
  static Event * headOfEventList;
  Event* remove_first_event();
  void schedule_event(Event* event);
  void reschedule_event(Event* event,Event* prev_Event);
  void cancel_event(Event* event);
  Event* find_patient_event(int number_of_patient);
  static int symulation_time;
  void show_list();
  EventList();
  ~EventList();
};



