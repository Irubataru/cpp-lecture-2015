/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 19:58:57 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include"integrate.hpp"

// Integration using the Riemann formula
double integrate(double begin, double end, unsigned steps, double(*func)(double))
{
  const double h = (end-begin)/steps;
  double result = h/2 * ( (*func)(begin) + (*func)(end) );

  for (auto i = 0; i < steps; ++i)
    result += h * (*func)(begin + i*h);

  return result;
}

// Integration using the Riemann formula
// The specified function can take an array of additional arguments
// Assume that the function itself knows how long this list should be
double integrate_w_args(double begin, double end, unsigned steps, double(*func)(double,double[]),double args[])
{
  const double h = (end-begin)/steps;
  double result = h/2 * ( (*func)(begin, args) + (*func)(end, args) );

  for (auto i = 0; i < steps; ++i)
    result += h * (*func)(begin + i*h, args);

  return result;
}
