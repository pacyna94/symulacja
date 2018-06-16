#include "stdafx.h"
#include "RandomNumberGenerator.h"
#include <cmath>


const double RandomNumberGenerator::M = 2147483647.0;
const int RandomNumberGenerator::A = 16807;
const int RandomNumberGenerator::Q = 127773;
const int RandomNumberGenerator::R = 2836;
const int RandomNumberGenerator::kernels_tab[] = { 420414638 , 2089009194 , 947668663 , 1118002730 , 103667729 , 796632599 ,
1558415545 , 690315638 , 687382087 , 1818852332 , 1249722773 , 1329998772 , 402327468 , 788091074 , 1668517533 , 146795659 ,
1649078146 , 1614866372 , 1189368338 , 1056512753 , 1977665735 , 2048697174 , 1902116737 , 237879037 , 630071902 , 787776977 ,
901102884 , 880186831 , 1072592134 , 9707671 , 838624779 , 282191013 , 564437925 , 1999150396 , 1140471364 , 1403131985 , 
1569560571 , 1507721202 , 1780135899 , 1912418362 , 1908879477 , 1998339756 , 620862221 , 293179237 , 986165166 , 1474464689, 
2029495491 , 2023637273 , 427003054 , 702356895 , 1282830291 , 371161839 , 1643034980 , 309904740 , 253012537 , 1020843371 , 
1237098316 , 1283469264 , 84447704 , 140582896 , 630796452 , 1123588772 , 713471933 , 1260983774 , 474766472 , 1043361267 , 
2004199207 , 1878836327 , 503847196 , 673305899 , 1441912404 , 2098779261 , 520261053 , 417121069 , 1877934923 , 1173043328 ,
1763351746 , 310261831 , 1633160740 , 1383780340 , 1172311416 , 565401129 , 1687143873 , 297170162 , 1803913519 , 987284881 , 
613959448 , 2009675198 , 1560576150 , 48748832 , 43737488 , 190874641, 810775870 , 637721916 , 1794246051 , 125932212 , 
676279776 , 421131330 , 1111971240 , 1459433532 , 1364264737 , 613652408 };

int RandomNumberGenerator::kernelGenerator()
{
  int h = kernel_ / Q;
  kernel_ = A * (kernel_ - Q * h) - R * h;
  if (kernel_ < 0)
    kernel_ = kernel_ + static_cast<int>(M);
  return kernel_;
}

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

RandomNumberGenerator::RandomNumberGenerator(int _kernel_number)
{
  kernel_number = _kernel_number;
  kernel_ = kernels_tab[kernel_number];
}


RandomNumberGenerator::~RandomNumberGenerator()
{
}
