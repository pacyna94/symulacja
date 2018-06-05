#pragma once

class RandomNumberGenerator
{
private:
  int kernel_;
  static const double M;
  static const int A;
  static const int Q;
  static const int R;
public:

  double UniformGenerator();
  double UniformGenerator(int start, int end);
  double ExpGenerator(double lambda_);
  double NormalGenerator(int average , double variance);
  int GeometeicGenerator(double ave);
  

  RandomNumberGenerator(int _kernel);

  ~RandomNumberGenerator();
};

