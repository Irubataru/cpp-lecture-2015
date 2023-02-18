/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 09:40:21 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>

class Bird
{
public:
  Bird()
    : hunger {5} {}

  void eat()
  {
    hunger /= 2;
  }

  void talk()
  {
    if (hunger > 1)
      std::cout << "Oy! I am hungy, feed me!" << std::endl;
    else
      std::cout << "Pip" << std::endl;
  }

protected:
  double hunger;
};

class Robot
{
public:
  void killAllHumans(unsigned & human_population)
  {
    human_population = 0;
  }
};

class RoboPenguin : public Robot, public Bird
{
public:
  RoboPenguin()
  {
    hunger = 0;
  }
};

int main(int, char**)
{

  unsigned human_population = 10;

  RoboPenguin bobert;
  bobert.talk();
  bobert.killAllHumans(human_population);

  Bird robert;
  robert.talk();

  std::cout << "Humans alive = " << human_population << std::endl;


  
}
