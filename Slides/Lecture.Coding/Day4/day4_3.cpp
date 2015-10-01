/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 10:19:01 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

class Base 
{
public:
  virtual void name() const;
};

class Derived : public Base
{
public:

  void additional() const;
};

int main(int, char**)
{
  Derived d1;
  d1.name();
  d1.additional();

  Base & dref = d1;
  dref.name();
  dref.additional();
  
}
