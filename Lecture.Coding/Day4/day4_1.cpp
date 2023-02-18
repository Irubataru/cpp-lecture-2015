/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 10:47:13 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>

class LoudClass
{
public:
  LoudClass()
  {
    std::cout << "I am being constructed" << std::endl;
  }

  virtual ~LoudClass()
  {
    std::cout << "Base being destructed" << std::endl;
  }

};

class DerivedLoudClass : public LoudClass
{
public:
  DerivedLoudClass()
  {
    std::cout << "Derived being constructed" << std::endl;
  }

  virtual ~DerivedLoudClass()
  {
    std::cout << "Derived being destructed" << std::endl;
  }


};

int main(int, char**)
{
  //DerivedLoudClass dlc;

  LoudClass * lptr = new DerivedLoudClass {};
  delete lptr;
  
}
