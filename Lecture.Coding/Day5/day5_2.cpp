/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 10:37:25 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>

struct Greater
{
  bool operator() (double a, double b)
  {
    return a > b;
  }
};

int main()
{
  Greater greater;

  std::cout << "5 > 7: " << greater(5,7) << std::endl;

}
