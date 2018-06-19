#include "stdafx.h"
#include "BloodTests.h"
//#include "RandomNumberGenerator.h"
#include "iostream"
#include <math.h>
#include <omp.h>
#include "Symulacja.h"


RandomNumberGenerator* BloodTests::rngBloodTests = new RandomNumberGenerator(5 * (symulation_counter * 7));

void BloodTests::execute()
{
  
  int  number_of_blood_units = rngBloodTests->UniformGenerator(5, 11);

    for (int i = 0; i < number_of_blood_units; i++)
    {
      //if (blood_donation_point_ptr->blood_level_ > 0;)
      blood_donation_point_ptr->remove_unit_of_blood();
    }
    //std::cout << "na badania oddano tyle jednostek krwi: " << number_of_blood_units << std::endl;
}

BloodTests::BloodTests(Event* this_event_)
{
  this_event = this_event_;
}


BloodTests::~BloodTests()
{
}
