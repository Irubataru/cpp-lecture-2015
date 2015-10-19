/*
 * Created: 30-09-2015
 * Modified: Mon 19 Oct 2015 11:47:53 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<utility>
#include"vector.hpp"
#include"matrix.hpp"

int main(int, char**)
{
  Math::Vector v1 ({5, 6, 7});
  Math::Matrix m1 {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

  std::cout << (m1*m1.transpose()-m1*m1) << "\n\n";

  auto v2 = m1*v1;
  std::cout << v2 << std::endl;

}
