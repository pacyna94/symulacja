#pragma once
//#include "Event.h"
//
class Event;

class EventList
{
  
public:
  static bool endOfSymulation;
  static bool end_of_transition_phase_flag;
  static int events_counter;
  static int events_number;
  static Event * headOfEventList;
  static const int end_of_transition_phase;
  Event* remove_first_event();
  void schedule_event(Event* event);
  void reschedule_event(Event* event,Event* prev_Event);
  void cancel_event(Event* event);
  Event* find_patient_event(int number_of_patient);
  static double symulation_time;
  void show_list();
  EventList();
  ~EventList();
};



