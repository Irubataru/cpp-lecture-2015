/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 10:55:32 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<functional>
#include<iostream>
#include<cmath>

template <typename Func>
double integrate(double start, double stop, unsigned steps, Func func)
{
  double stepsize = (stop - start)/steps;
  double result = stepsize/2 * (func(start) + func(stop));

  for (auto i = 1; i < steps-1; ++i)
    result += stepsize * func(start + i*stepsize);

  return result;
}

template <>
double integrate(double start, double stop, unsigned steps, double (*func)(double))
{
  double stepsize = (stop - start)/steps;
  double result = stepsize/2 * ((*func)(start) + (*func)(stop));

  for (auto i = 1; i < steps-1; ++i)
    result += stepsize * (*func)(start + i*stepsize);

  return result;
}

struct Gaussian
{
  double mu, sigma;

  double operator() (double x)
  {
    return 1./std::sqrt(4*M_PI*sigma*sigma) * std::exp( -(x-mu)*(x-mu) / (4*sigma*sigma) );
  }
};

int main(int, char**)
{
  std::function<double(double)> f1 = [](double x) {return std::cos(x);};
  std::function<double(double)> f2 = Gaussian {3., 2.};

  std::cout << integrate(0,M_PI/2,1000,f1) << std::endl;
  std::cout << integrate(0,M_PI/2,1000,Gaussian {3., 2.}) << std::endl;
  
}
