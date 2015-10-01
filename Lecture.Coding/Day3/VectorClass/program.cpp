/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 14:59:19 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<utility>
#include"vector.hpp"

void printVector(const Math::Vector & vec)
{
  for (auto i = 0; i < vec.getSize(); ++i)
    std::cout << vec[i] << " ";
  
  std::cout << std::endl;
}

int main(int, char**)
{
  Math::Vector v1 {10};

  for (auto i = 0; i < v1.getSize(); ++i) {
    v1[i] = 2*i;
  }

  Math::Vector v2;

  v2 = v1;

  std::cout << "v1 = ";
  printVector(v1);

  std::cout << "v2 = ";
  printVector(v2);

}
