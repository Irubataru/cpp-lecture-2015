/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 16:07:13 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<utility>
#include<iostream>

#include "unique_ptr.hpp"
#include "shared_ptr.hpp"


int main(int, char**)
{
  SharedPtr<double> p1 { new double {7.} };
  std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

  SharedPtr<double> p2 {p1};
  std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

  *p2 = 10.;
  std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

  {
    SharedPtr<double> p3 {p2};
    SharedPtr<double> p4 {p1};
    std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

    p2 = std::move(p3);
    std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

    SharedPtr<double> p5 {std::move(p2)};
    std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

    SharedPtr<double> p6;
    p6 = p4;
    std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

    p4 = p6;
    std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;
  }

  std::cout << "Val: " << *p1 << ", count: " << p1.useCount() << std::endl;

}
