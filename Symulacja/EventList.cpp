#include "stdafx.h"
#include "EventList.h"
#include "Event.h"
#include <iostream>

bool EventList::endOfSymulation = false;
Event* EventList::headOfEventList = nullptr;
double EventList::symulation_time = 0;
int EventList::events_number = 0;

//class Event;

Event* EventList::remove_first_event()
{
  
 
  Event* event_ptr = headOfEventList->prev_event;
  if (BloodDonationPoint::blood_test_check(event_ptr->event_time))
  {
    event_ptr= new Event(BLOOD_TEST);
    return event_ptr;
  }
  headOfEventList->prev_event=event_ptr->prev_event;
  headOfEventList->prev_event->next_event = headOfEventList;
  event_ptr->next_event = nullptr;
  event_ptr->prev_event = nullptr;
  symulation_time = event_ptr->event_time;
  event_ptr->activate = true;   
  events_number--;
    return event_ptr;
}

void EventList::schedule_event(Event* event)
{
  events_number++;
  Event* event_ptr = headOfEventList;
  
  while (true)
  {

    if (event_ptr->next_event->event_time > event->event_time)
    {
      event_ptr = event_ptr->next_event;

    }
    else
    {
      event->next_event = event_ptr->next_event;
      event->next_event->prev_event = event;
      event_ptr->next_event = event;
      event->prev_event = event_ptr;

      break;
    }
  
    
  }

}


void EventList::reschedule_event(Event* event, Event* prev_Event)
{
  //wyciagniecie obiektu z listy jeszcze nie wiem czy potrzebne
  //event->prev_event->next_event = event->next_event;
  //event->next_event->prev_event = event->prev_event;
  // przeplanowanie zdarzenia
  event->event_time = prev_Event->event_time;
  event->next_event = prev_Event->next_event;
  event->prev_event = prev_Event;
  prev_Event->next_event->prev_event = event;
  prev_Event->next_event = event;
}

void EventList::cancel_event(Event* event)
{
  events_number--;
     if (event->event_type == NO_IVENT) 
  {
    event->next_event->prev_event = event->prev_event;
    event->prev_event->next_event = event->next_event;
    delete event;

  }
}

Event* EventList::find_patient_event(int number_of_patient)
{
  Event* event_list_ptr = headOfEventList;
  while(number_of_patient!=0)
  {
    event_list_ptr = event_list_ptr->next_event;
    if(event_list_ptr->event_type==PATIENT)
    {
      number_of_patient--;
    }
  }
  return event_list_ptr;
}

void EventList::show_list()
{
  Event* event_ptr = headOfEventList;
  std::cout << "event list:"<<std::endl;
  for(int i =0; i<events_number+2;i++)
  {
   
    switch (event_ptr->event_type)
    {
    case PATIENT:
      std::cout << "PATIENT ";
      std::cout << "       |id: " << event_ptr->make_event->id << "| ";
      break;
    case END_OF_VALIDITY:
      std::cout << "END_OF_VALIDITY ";
      break;
    case BLOOD_DONOR:
      std::cout << "BLOOD_DONOR ";
      std::cout << "   |id: " << event_ptr->make_event->id << "| ";
      break;
    case BLOOD_SUPPLY:
      std::cout << "BLOOD_SUPLY ";
      std::cout << "   |id: " << event_ptr->make_event->id << "| ";
      break;
    case EMERGENCY_BLOOD_SUPPLY:
      std::cout << "EMERGENCY_BLOOD_SUPPLY ";
      std::cout << "       |id: " << event_ptr->make_event->id << "| ";
      break;
    case BLOOD_TEST:
      std::cout << "BLOD_TESTS" << std::endl;
    default:
      std::cout << "NO_IVENT ";

      break;
    }
    
    std::cout << "(" << event_ptr->event_time << ")" << std::endl;
    event_ptr = event_ptr->next_event;
  }
}

EventList::EventList()
{
  headOfEventList = new Event();
}


EventList::~EventList()
{
}
