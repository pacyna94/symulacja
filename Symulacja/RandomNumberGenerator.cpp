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

double RandomNumberGenerator::NormalGenerator(int mi, double sigma)
{
  double k = UniformGenerator();
  return -sigma*sqrt(2.0*3.14159)*log(pow(k-mi,2)/(2*sigma*sigma));
}

double RandomNumberGenerator::GeometeicGenerator(double ave)
{
  double k = UniformGenerator();
  return 1 - pow(1.0 - k, 1/ave);
}

RandomNumberGenerator::RandomNumberGenerator(int _kernel)
{
  kernel_ = _kernel;
}


RandomNumberGenerator::~RandomNumberGenerator()
{
}
