/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 20:14:30 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<cmath>
#include<iostream>
#include<functional>

double integrate(double start, double stop, unsigned steps, std::function<double(double)> func)
{
  double h = (stop - start)/steps;
  auto result = h/2 * (func(start) + func(stop));
  
  for (auto i = 0; i < steps; ++i) {
    result += h * func(start + i*h);
  }

  return result;
}

int main(int, char**)
{
  std::function<double(double)> int_func = [](double x){return std::cos(x);};

  double mu = 1., sigma = 4.;
  std::function<double(double)> gaussian = [mu, sigma](double x)
  {
    return 1./(4 * M_PI * sigma*sigma) * std::exp( - (x - mu)*(x - mu) / (4*sigma*sigma) );
  };

  std::cout << integrate(0, M_PI/2, 1000, gaussian) << std::endl;
  
}
