#include "stdafx.h"
#include "RandomNumberGenerator.h"
#include <cmath>


const double RandomNumberGenerator::M = 2147483647.0;
const int RandomNumberGenerator::A = 16807;
const int RandomNumberGenerator::Q = 127773;
const int RandomNumberGenerator::R = 2836;

double RandomNumberGenerator::UniformGenerator()
{
  int h = kernel_ / Q;
  kernel_ = A * (kernel_ - Q * h) - R * h;
  if (kernel_ < 0)
    kernel_ = kernel_ + static_cast<int>(M);
  return kernel_ / M;
  return 0.0;
}

double RandomNumberGenerator::UniformGenerator(int start, int end)
{
  return UniformGenerator()*(end - start) + start;
}

double RandomNumberGenerator::ExpGenerator(double lambda_)
{
  double k = UniformGenerator();
  return -(1.0 / lambda_)*log(k);
}

double RandomNumberGenerator::NormalGenerator(int average, double variance)
{
  double k = UniformGenerator();
  double x=0;
  for (int i = 0; i < 12; i++)
  {
    x += UniformGenerator();
  }
  x = (x - 6);
  x = sqrt(variance)*x + average;
  return x;
 // return -sigma*sqrt(2.0*3.14159)*log(pow(k-mi,2)/(2*sigma*sigma));
}

int RandomNumberGenerator::GeometeicGenerator(double ave)
{
  //double k = UniformGenerator();
  int i = 1;
    while (UniformGenerator() > ave) ++i;
  return i;
}

RandomNumberGenerator::RandomNumberGenerator(int _kernel)
{
  kernel_ = _kernel;
}


RandomNumberGenerator::~RandomNumberGenerator()
{
}
