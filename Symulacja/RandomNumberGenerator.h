#pragma once

class RandomNumberGenerator
{
private:
  int kernel_;
  int kernel_number;
  static const double M;
  static const int A;
  static const int Q;
  static const int R;
  static const int kernels_tab[];
public:

  int kernelGenerator();

  double UniformGenerator();
  double UniformGenerator(int start, int end);
  double ExpGenerator(double lambda_);
  double NormalGenerator(int average , double variance);
  int GeometeicGenerator(double ave);
  

  RandomNumberGenerator(int _kernel);

  ~RandomNumberGenerator();
};

