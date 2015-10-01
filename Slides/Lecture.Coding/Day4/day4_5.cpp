/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 11:01:21 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>

class Base
{
public:
  virtual void foo() = 0;
};

class Derived : public Base {};

class GrandChild : public Derived
{
public:
  virtual void foo() override
  {
    std::cout << "Hello world" << std::endl;
  }
};

int main(int, char**)
{
  GrandChild b1;
  b1.foo();
  
}
