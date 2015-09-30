/*
 * Created: 28-09-2015
 * Modified: Wed 30 Sep 2015 19:56:33 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>

double interest(double initial, double rate, double additional_savings, unsigned years);

int main(int, char**)
{
  std::cout << "Initial savings: 10.000" << std::endl;
  std::cout << "Interest rates: 5%" << std::endl;
  std::cout << "Additional savings per year: 1.000\n" << std::endl;

  for (auto i = 0; i < 10; ++i)
    std::cout << "After " << i << " years: " << interest(10000,0.05,1000,i) <<std::endl;
}

// Calculate the rates using recursion
double interest(double initial, double rate, double additional_savings, unsigned years)
{
  if (years == 0)
    return initial;

  // The total savings is the interest on "whatever you had last year" pluss the additional savings
  return (1.+rate)*interest(initial,rate,additional_savings,years-1) + additional_savings;
}
