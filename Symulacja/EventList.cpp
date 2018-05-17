#include "stdafx.h"
#include "EventList.h"
#include "Event.h"
#include <iostream>

Event* EventList::headOfEventList = nullptr;
int EventList::symulation_time = 0;
int EventList::events_number = 0;
//class Event;

Event* EventList::remove_first_event()
{
  //events_number--;
  Event* event_ptr = headOfEventList->next_event;
  headOfEventList->next_event=event_ptr->next_event;
  headOfEventList->next_event->prev_event = headOfEventList;
 // event_ptr->next_event = nullptr;
 // event_ptr->prev_event = nullptr;
  symulation_time = event_ptr->event_time;
  event_ptr->activate = true;
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
  event->prev_event->next_event = event->next_event;
  event->next_event->prev_event = event->prev_event;
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
  for(int i =0; i<events_number+2;i++)
  {
    std::cout << event_ptr->event_type<<" ";
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
