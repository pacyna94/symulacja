#pragma once


class Event;

class Proces
{
public:
 virtual void execute(Event* this_event)=0;
 // virtual void add_patient_to_queue(Patient* ptr_patient)=0;
 Proces();
 
};


