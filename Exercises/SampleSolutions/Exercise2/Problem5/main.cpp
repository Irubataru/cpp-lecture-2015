/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 19:59:04 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<cmath>
#include"integrate.hpp"

double gaussian(double x, double args[])
{
  double mu = args[0];
  double sigma = args[1];

  return 1./std::sqrt(4 * M_PI * sigma*sigma) * std::exp( - (x*x - mu*mu)/(4*sigma*sigma) );
}

int main(int, char**)
{
  std::cout << "Integral of cos from 0 to pi/2 is: "
    << integrate(0, M_PI/2, 1000, std::cos) << std::endl;

  std::cout << std::endl;

  double args1[] = {0, 1};
  double args2[] = {1, 5};

  std::cout << "Integral of the gaussian distribution with parameters:\n"
    << "    mu = " << args1[0] << "\n"
    << " sigma = " << args1[1] << "\n"
    << "from -5 to 5 is: " << integrate_w_args(-5,5,1000,gaussian,args1) << std::endl;

  std::cout << std::endl;

  std::cout << "Integral of the gaussian distribution with parameters:\n"
    << "    mu = " << args2[0] << "\n"
    << " sigma = " << args2[1] << "\n"
    << "from -1 to 4 is: " << integrate_w_args(-5,5,1000,gaussian,args2) << std::endl;

}
