/*
 * Created: 30-09-2015
 * Modified: Wed 30 Sep 2015 10:59:09 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<cmath>

class Coordinate
{
friend double norm(const Coordinate &);
friend class EvilAccess;

public:

  Coordinate() {}

  Coordinate(double x0, double y0)
    : x {x0},
      y {y0} {}

private:
  double x, y;
};

double norm(const Coordinate & c)
{
  return std::sqrt(c.x * c.x + c.y * c.y);
}

int main(int, char**)
{
  Coordinate point;

  std::cout << norm(point) << std::endl;
}
