/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 11:12:39 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>

class Base
{
public:
  void foo()
  {
    std::cout << "Base" << std::endl;
  }
};

class Derived : public Base
{
public:
  virtual void foo()
  {
    std::cout << "Derived" << std::endl;
  }

  void bar() {}
};

class GrandChild : public Derived
{
public:
  virtual void foo() override
  {
    std::cout << "GrandChild" << std::endl;
  }

  void bar() {}
};

void print(Base & obj)
{
  obj.foo();
}

int main(int, char**)
{
  GrandChild g1;

  //Derived & dref = g1;
  //dref.foo();

  Base & bref = g1;
  bref.foo();
  
}
